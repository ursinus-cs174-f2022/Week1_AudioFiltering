#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Create a new array with the elements as the reverse of 
 * an original array
 * 
 * @param arr Original array
 * @param N Length of array
 * @return double* Reversed array
 */
double* reverseArray(double* arr, int N);

/**
 * @brief Compute the windowed zero crossings of an array
 * 
 * @param x Array
 * @param N Length of array
 * @param win Window length to use
 * @return double* Zero crossings in the array
 */
int* getCrossings(double* x, int N, int win);


/**
 * @brief Compute the windowed energy of an array
 * 
 * @param x Array
 * @param N Length of array
 * @param win Window length to use
 * @return double* Energy in the array
 */
double* getEnergy(double* x, int N, int win);

#endif