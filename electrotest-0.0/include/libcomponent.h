#ifndef E_RESISTANCE_H
#define E_RESISTANCE_H

/**@file libcomponent.h */

/*! \fn int e_resistance(float orig_resistance, float *res_array );
    \brief Search function for E12-series components
    \param orig_resistance is an argument for the total amount of resistance being used
    \param *res_array is a pointer that returns the values from the E12-series resistance found in the struct
    \return an integer which show the amount of components found 
 * 
 */



int e_resistance(float orig_resistance, float *res_array );

#endif
