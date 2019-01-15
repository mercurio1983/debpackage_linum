#include <stdio.h>
#include <math.h>
// libpower.c beräknar effekten som utvecklas när en spänningskälla kopplas till en resistans

float calc_power_r(float volt, float resistance) {
    if ( (resistance == 0.0) || ! isfinite(volt*volt/resistance) ) {
        fprintf( stderr, "Invalid denominator in division when calculating the power with U^2/R\n");
    }
    return volt*volt/resistance;
}

float calc_power_i(float volt, float current) {
    return volt*current;
}