/*
 *  Copyright (C) 2007 Jolien Creighton, B.S. Sathyaprakash, Thomas Cokelaer
 *  Copyright (C) 2012 Leo Singer, Evan Ochsner, Les Wade, Alex Nitz, Walter Del Pozzo
 *  Assembled from code found in:
 *    - LALInspiralStationaryPhaseApproximation2.c
 *    - LALInspiralChooseModel.c
 *    - LALInspiralSetup.c
 *    - LALSimInspiralTaylorF2ReducedSpin.c
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with with program; see the file COPYING. If not, write to the
 *  Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 *  MA  02111-1307  USA
 */

#include <stdlib.h>
#include <math.h>
#include <lal/Date.h>
#include <lal/FrequencySeries.h>
#include <lal/LALConstants.h>
#include <lal/LALDatatypes.h>
#include <lal/LALSimInspiral.h>
#include <lal/LALSimInspiralEOS.h>
#include <lal/Units.h>
#include <lal/XLALError.h>
#include "LALSimInspiralPNCoefficients.c"

/**
 * Computes the stationary phase approximation to the Fourier transform of
 * a chirp waveform with phase given by \eqref{eq_InspiralFourierPhase_f2}
 * and amplitude given by expanding \f$1/\sqrt{\dot{F}}\f$. If the PN order is
 * set to -1, then the highest implemented order is used.
 *
 * See arXiv:0810.5336 and arXiv:astro-ph/0504538 for spin corrections
 * to the phasing.
 * See arXiv:1303.7412 for spin-orbit phasing corrections at 3 and 3.5PN order
 * The testing GR implementation is described in arXiv:1110.0530
 */

int XLALSimInspiralTaylorF2Test(
        COMPLEX16FrequencySeries **htilde_out, /**< FD waveform */
        const REAL8 phi_ref,                      /**< orbital coalescence phase (rad) */
        const REAL8 deltaF,                    /**< frequency resolution */
        const REAL8 m1_SI,                     /**< mass of companion 1 (kg) */
        const REAL8 m2_SI,                     /**< mass of companion 2 (kg) */
        const REAL8 S1z,                       /**<  z component of the spin of companion 1 */
        const REAL8 S2z,                       /**<  z component of the spin of companion 2  */
        const REAL8 fStart,                    /**< start GW frequency (Hz) */
        const REAL8 fEnd,                      /**< highest GW frequency (Hz) of waveform generation - if 0, end at Schwarzschild ISCO */
        const REAL8 f_ref,                     /**< Reference GW frequency (Hz) - if 0 reference point is coalescence */
        const REAL8 r,                         /**< distance of source (m) */
        const REAL8 quadparam1,                /**< quadrupole deformation parameter of body 1 (dimensionless, 1 for BH) */
        const REAL8 quadparam2,                /**< quadrupole deformation parameter of body 2 (dimensionless, 1 for BH) */
        const REAL8 lambda1,                   /**< (tidal deformation of body 1)/(mass of body 1)^5 */
        const REAL8 lambda2,                   /**< (tidal deformation of body 2)/(mass of body 2)^5 */
        const LALSimInspiralSpinOrder spinO,  /**< twice PN order of spin effects */
        const LALSimInspiralTidalOrder tideO,  /**< flag to control tidal effects */
        const INT4 phaseO,                     /**< twice PN phase order */
        const INT4 amplitudeO,                 /**< twice PN amplitude order */
        const LALSimInspiralTestGRParam *extraParams /**< structure of testing parameters */
        )
{
    /* external: SI; internal: solar masses */
    const REAL8 m1 = m1_SI / LAL_MSUN_SI;
    const REAL8 m2 = m2_SI / LAL_MSUN_SI;
    const REAL8 m = m1 + m2;
    const REAL8 m_sec = m * LAL_MTSUN_SI;  /* total mass in seconds */
    const REAL8 eta = m1 * m2 / (m * m);
    const REAL8 piM = LAL_PI * m_sec;
    const REAL8 vISCO = 1. / sqrt(6.);
    const REAL8 fISCO = vISCO * vISCO * vISCO / piM;
    const REAL8 m1OverM = m1 / m;
    const REAL8 m2OverM = m2 / m;
    const REAL8 chi1 = m1 / m;
    const REAL8 chi2 = m2 / m;
    REAL8 shft, amp0, f_max, fCONT;
    size_t i, n, iStart;
    COMPLEX16 *data = NULL;
    LIGOTimeGPS tC = {0, 0};


    fCONT = XLALSimInspiralContactFrequency(m1, lambda1, m2, lambda2);

    /* phasing coefficients */
    PNPhasingSeries pfa;
    XLALSimInspiralPNPhasing_F2(&pfa, m1, m2, S1z, S2z, S1z*S1z, S2z*S2z, S1z*S2z, quadparam1, quadparam2, spinO);

    REAL8 pfaN = 0.; REAL8 pfa1 = 0.;
    REAL8 pfa2 = 0.; REAL8 pfa3 = 0.; REAL8 pfa4 = 0.;
    REAL8 pfa5 = 0.; REAL8 pfl5 = 0.;
    REAL8 pfa6 = 0.; REAL8 pfl6 = 0.;
    REAL8 pfa7 = 0.;

    switch (phaseO)
    {
        case -1:
        case 7:
            pfa7 = pfa.v[7];
        case 6:
            pfa6 = pfa.v[6];
            pfl6 = pfa.vlogv[6];
        case 5:
            pfa5 = pfa.v[5];
            pfl5 = pfa.vlogv[5];
        case 4:
            pfa4 = pfa.v[4];
        case 3:
            pfa3 = pfa.v[3];
        case 2:
            pfa2 = pfa.v[2];
        case 1:
            XLALPrintWarning( "There is no 0.5PN phase coefficient, returning Newtonian-order phase.\n" );
        case 0:
            pfaN = pfa.v[0];
            break;
        default:
            XLAL_ERROR(XLAL_ETYPE, "Invalid phase PN order %d", phaseO);
    }
    /* modify the PN coefficients by perturbing around their central GR value */
    if (extraParams!=NULL)
    {
        if (XLALSimInspiralTestGRParamExists(extraParams,"dchi0")) pfaN*=(1.0+XLALSimInspiralGetTestGRParam(extraParams,"dchi0"));
        if (XLALSimInspiralTestGRParamExists(extraParams,"dchi1")) pfa1 = XLALSimInspiralGetTestGRParam(extraParams,"dchi1");
        if (XLALSimInspiralTestGRParamExists(extraParams,"dchi2")) pfa2*=(1.0+XLALSimInspiralGetTestGRParam(extraParams,"dchi2"));
        if (XLALSimInspiralTestGRParamExists(extraParams,"dchi3")) pfa3*=(1.0+XLALSimInspiralGetTestGRParam(extraParams,"dchi3"));
        if (XLALSimInspiralTestGRParamExists(extraParams,"dchi4")) pfa4*=(1.0+XLALSimInspiralGetTestGRParam(extraParams,"dchi4"));
        if (XLALSimInspiralTestGRParamExists(extraParams,"dchi5")) pfa5*=(1.0+XLALSimInspiralGetTestGRParam(extraParams,"dchi5"));
        if (XLALSimInspiralTestGRParamExists(extraParams,"dchi5l")) pfl5*=(1.0+XLALSimInspiralGetTestGRParam(extraParams,"dchi5l"));
        if (XLALSimInspiralTestGRParamExists(extraParams,"dchi6")) pfa6*=(1.0+XLALSimInspiralGetTestGRParam(extraParams,"dchi6"));
        if (XLALSimInspiralTestGRParamExists(extraParams,"dchi6l")) pfl6*=(1.0+XLALSimInspiralGetTestGRParam(extraParams,"dchi6l"));
        if (XLALSimInspiralTestGRParamExists(extraParams,"dchi7")) pfa7*=(1.0+XLALSimInspiralGetTestGRParam(extraParams,"dchi7"));
    }
    /* Validate expansion order arguments.
     * This must be done here instead of in the OpenMP parallel loop
     * because when OpenMP parallelization is turned on, early exits
     * from loops (via return or break statements) are not permitted.
     */

    /* Validate amplitude PN order. */
    switch (amplitudeO)
    {
        case -1:
        case 7:
        case 6:
        case 5:
        case 4:
        case 3:
        case 2:
        case 0:
            break;
        default:
            XLAL_ERROR(XLAL_ETYPE, "Invalid amplitude PN order %d", amplitudeO);
    }

    /* Generate tidal terms separately.
     * Enums specifying tidal order are in LALSimInspiralWaveformFlags.h
     */
    REAL8 pft10 = 0.;
    REAL8 pft12 = 0.;
    REAL8 pft13 = 0.;
    REAL8 pft14 = 0.;
    REAL8 pft15 = 0.;
    switch( tideO )
    {
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_ALL:
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_75PN:
            pft15 = lambda2* chi2*chi2*chi2*chi2 * 1.L/28.L*LAL_PI*(27719.L - 22127.L*chi2 + 7022.L*chi2*chi2 - 10232.L*chi2*chi2*chi2)
                + lambda1* chi1*chi1*chi1*chi1 * 1.L/28.L*LAL_PI*(27719.L - 22127.L*chi1 + 7022.L*chi1*chi1 - 10232.L*chi1*chi1*chi1);
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_7PN:
            pft14 = - lambda2 * chi2*chi2*chi2*chi2 * 24.L*(39927845.L/508032.L                           - 480043345.L/9144576.L*chi2 + 9860575.L/127008.L*chi2*chi2 - 421821905.L/2286144.L*chi2*chi2*chi2 + 4359700.L/35721.L*chi2*chi2*chi2*chi2 - 10578445.L/285768.L*chi2*chi2*chi2*chi2*chi2)
                   - lambda1 * chi1*chi1*chi1*chi1 * 24.L*(39927845.L/508032.L
                - 480043345.L/9144576.L*chi1 + 9860575.L/127008.L*chi1*chi1 - 421821905.L/2286144.L*chi1*chi1*chi1 + 4359700.L/35721.L*chi1*chi1*chi1*chi1 - 10578445.L/285768.L*chi1*chi1*chi1*chi1*chi1);
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_65PN:
            pft13 =  lambda2 * chi2*chi2*chi2*chi2 * 24.L*(12.L - 11.L*chi2)*LAL_PI
                    + lambda1 * chi1*chi1*chi1*chi1 * 24.L*(12.L - 11.L*chi1)*LAL_PI;
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_6PN:
            pft12 = pfaN * ( XLALSimInspiralTaylorF2Phasing_12PNTidalCoeff(m1OverM, lambda1)
                            + XLALSimInspiralTaylorF2Phasing_12PNTidalCoeff(m2OverM, lambda2) );
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_5PN:
            pft10 = pfaN * ( XLALSimInspiralTaylorF2Phasing_10PNTidalCoeff(m1OverM, lambda1)
                            + XLALSimInspiralTaylorF2Phasing_10PNTidalCoeff(m2OverM, lambda2) );
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_0PN:
            break;
        default:
            XLAL_ERROR(XLAL_EINVAL, "Invalid tidal PN order %d", tideO);
    }

    /* The flux and energy coefficients below are used to compute SPA amplitude corrections */

    /* flux coefficients */
    const REAL8 FTaN = XLALSimInspiralPNFlux_0PNCoeff(eta);
    const REAL8 FTa2 = XLALSimInspiralPNFlux_2PNCoeff(eta);
    const REAL8 FTa3 = XLALSimInspiralPNFlux_3PNCoeff(eta);
    const REAL8 FTa4 = XLALSimInspiralPNFlux_4PNCoeff(eta);
    const REAL8 FTa5 = XLALSimInspiralPNFlux_5PNCoeff(eta);
    const REAL8 FTl6 = XLALSimInspiralPNFlux_6PNLogCoeff(eta);
    const REAL8 FTa6 = XLALSimInspiralPNFlux_6PNCoeff(eta);
    const REAL8 FTa7 = XLALSimInspiralPNFlux_7PNCoeff(eta);

    /* energy coefficients */
    const REAL8 dETaN = 2. * XLALSimInspiralPNEnergy_0PNCoeff(eta);
    const REAL8 dETa1 = 2. * XLALSimInspiralPNEnergy_2PNCoeff(eta);
    const REAL8 dETa2 = 3. * XLALSimInspiralPNEnergy_4PNCoeff(eta);
    const REAL8 dETa3 = 4. * XLALSimInspiralPNEnergy_6PNCoeff(eta);


    COMPLEX16FrequencySeries *htilde;

    /* Perform some initial checks */
    if (!htilde_out) XLAL_ERROR(XLAL_EFAULT);
    if (*htilde_out) XLAL_ERROR(XLAL_EFAULT);
    if (m1_SI <= 0) XLAL_ERROR(XLAL_EDOM);
    if (m2_SI <= 0) XLAL_ERROR(XLAL_EDOM);
    if (fStart <= 0) XLAL_ERROR(XLAL_EDOM);
    if (f_ref < 0) XLAL_ERROR(XLAL_EDOM);
    if (r <= 0) XLAL_ERROR(XLAL_EDOM);

    /* allocate htilde */
    if ( fEnd <= 0.0 )
        f_max = (fISCO < fCONT) ? fISCO : fCONT; // Use min{fISCO,fCONT} as termination frequency
    else
        f_max = fEnd; // End at user-specified freq.
    if (f_max <= fStart) XLAL_ERROR(XLAL_EDOM);

    //printf("fISCO = %e\n", fISCO);
    //printf("fCONT = %e\n", fCONT);
    //printf("f_max = %e\n", f_max);
    n = (size_t) (f_max / deltaF + 1);
    XLALGPSAdd(&tC, -1 / deltaF);  /* coalesce at t=0 */
    htilde = XLALCreateCOMPLEX16FrequencySeries("htilde: FD waveform", &tC, 0.0, deltaF, &lalStrainUnit, n);
    if (!htilde) XLAL_ERROR(XLAL_EFUNC);
    memset(htilde->data->data, 0, n * sizeof(COMPLEX16));
    XLALUnitDivide(&htilde->sampleUnits, &htilde->sampleUnits, &lalSecondUnit);

    /* extrinsic parameters */
    amp0 = -4. * m1 * m2 / r * LAL_MRSUN_SI * LAL_MTSUN_SI * sqrt(LAL_PI/12.L);
    shft = LAL_TWOPI * (tC.gpsSeconds + 1e-9 * tC.gpsNanoSeconds);

    const REAL8 log4=log(4.0);

    /* Fill with non-zero vals from fStart to f_max */
    iStart = (size_t) ceil(fStart / deltaF);
    data = htilde->data->data;

    /* Compute the SPA phase at the reference point
     * N.B. f_ref == 0 means we define the reference time/phase at "coalescence"
     * when the frequency approaches infinity. In that case,
     * the integrals Eq. 3.15 of arXiv:0907.0700 vanish when evaluated at
     * f_ref == infinity. If f_ref is finite, we must compute the SPA phase
     * evaluated at f_ref, store it as ref_phasing and subtract it off.
     */
    REAL8 ref_phasing = 0.;
    if( f_ref != 0. ) {
        const REAL8 vref = cbrt(piM*f_ref);
        const REAL8 logvref = log(vref);
        const REAL8 v2ref = vref * vref;
        const REAL8 v3ref = vref * v2ref;
        const REAL8 v4ref = vref * v3ref;
        const REAL8 v5ref = vref * v4ref;
        const REAL8 v6ref = vref * v5ref;
        const REAL8 v7ref = vref * v6ref;
        const REAL8 v8ref = vref * v7ref;
        const REAL8 v9ref = vref * v8ref;
        const REAL8 v10ref = vref * v9ref;
        const REAL8 v12ref = v2ref * v10ref;
        const REAL8 v13ref = v3ref * v10ref;
        const REAL8 v14ref = v4ref * v10ref;
        const REAL8 v15ref = v5ref * v10ref;
        ref_phasing += pfa7 * v7ref;
        ref_phasing += (pfa6 + pfl6 * logvref) * v6ref;
        ref_phasing += (pfa5 + pfl5 * logvref) * v5ref;
        ref_phasing += pfa4 * v4ref;
        ref_phasing += pfa3 * v3ref;
        ref_phasing += pfa2 * v2ref;
        ref_phasing += pfa1 * vref;
        ref_phasing += pfaN;

        /* Tidal terms in reference phasing */
        ref_phasing += pft15 * v15ref;
        ref_phasing += pft14 * v14ref;
        ref_phasing += pft13 * v13ref;
        ref_phasing += pft12 * v12ref;
        ref_phasing += pft10 * v10ref;

        ref_phasing /= v5ref;
    } /* End of if(f_ref != 0) block */

#pragma omp parallel for
    for (i = iStart; i < n; i++) {
        const REAL8 f = i * deltaF;
        const REAL8 v = cbrt(piM*f);
        const REAL8 logv = log(v);
        const REAL8 v2 = v * v;
        const REAL8 v3 = v * v2;
        const REAL8 v4 = v * v3;
        const REAL8 v5 = v * v4;
        const REAL8 v6 = v * v5;
        const REAL8 v7 = v * v6;
        const REAL8 v8 = v * v7;
        const REAL8 v9 = v * v8;
        const REAL8 v10 = v * v9;
        const REAL8 v12 = v2 * v10;
        const REAL8 v13 = v3 * v10;
        const REAL8 v14 = v4 * v10;
        const REAL8 v15 = v5 * v10;
        REAL8 phasing = 0.;
        REAL8 dEnergy = 0.;
        REAL8 flux = 0.;
        REAL8 amp;

        phasing += pfa7 * v7;
        phasing += (pfa6 + pfl6 * logv) * v6;
        phasing += (pfa5 + pfl5 * logv) * v5;
        phasing += pfa4 * v4;
        phasing += pfa3 * v3;
        phasing += pfa2 * v2;
        phasing += pfa1 * v;
        phasing += pfaN;

        /* Tidal terms in phasing */
        phasing += pft15 * v15;
        phasing += pft14 * v14;
        phasing += pft13 * v13;
        phasing += pft12 * v12;
        phasing += pft10 * v10;

        /* WARNING! Amplitude orders beyond 0 have NOT been reviewed!
         * Use at your own risk. The default is to turn them off.
         * These do not currently include spin corrections.
         * Note that these are not higher PN corrections to the amplitude.
         * They are the corrections to the leading-order amplitude arising
         * from the stationary phase approximation. See for instance
         * Eq 6.9 of arXiv:0810.5336
         */
        switch (amplitudeO)
        {
            case 7:
                flux += FTa7 * v7;
            case 6:
                flux += (FTa6 + FTl6*2.0*(log4+logv)) * v6;
                dEnergy += dETa3 * v6;
            case 5:
                flux += FTa5 * v5;
            case 4:
                flux += FTa4 * v4;
                dEnergy += dETa2 * v4;
            case 3:
                flux += FTa3 * v3;
            case 2:
                flux += FTa2 * v2;
                dEnergy += dETa1 * v2;
            case -1: /* Default to no SPA amplitude corrections */
            case 0:
                flux += 1.;
                dEnergy += 1.;
        }

        phasing /= v5;
        flux *= FTaN * v10;
        dEnergy *= dETaN * v;
        // Note the factor of 2 b/c phi_ref is orbital phase
        phasing += shft * f - 2.*phi_ref - ref_phasing;
        amp = amp0 * sqrt(-dEnergy/flux) * v;
        data[i] = amp * cos(phasing - LAL_PI_4)
        - amp * sin(phasing - LAL_PI_4) * 1.0j;
    }

    *htilde_out = htilde;
    return XLAL_SUCCESS;
}