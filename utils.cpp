#include "utils.h"

/**
 * @brief Create a new array with the elements as the reverse of 
 * an original array
 * 
 * @param arr Original array
 * @param N Length of array
 * @return double* Reversed array
 */
double* reverseArray(double* arr, int N) {
    double* rev = new double[N];
    for (int i = 0; i < N; i++) {
        rev[N-i-1] = arr[i];
    }
    return rev;
}

/**
 * @brief Compute the windowed zero crossings of an array
 * 
 * @param x Array
 * @param N Length of array
 * @param win Window length to use
 * @return double* Zero crossings in the array
 */
int* getCrossings(double* x, int N, int win) {
    int count = 0;
    int* csum = new int[N];
    for (int i = 0; i < N-1; i++) {
        if ( (x[i+1] > 0 && x[i] < 0) || (x[i+1] < 0 && x[i+1] > 0) ) {
            count++;
        }
        csum[i] = count;
    }
    int* crossings = new int[N];
    for (int i = 0; i < N; i++) {
      if (i >= win && i < N-win) {
        crossings[i] = csum[i+win] - csum[i-win];
      }
      else {
        crossings[i] = 0;
      }
    }
    delete[] csum;
    return crossings;
}


/**
 * @brief Compute the windowed energy of an array
 * 
 * @param x Array
 * @param N Length of array
 * @param win Window length to use
 * @return double* Energy in the array
 */
double* getEnergy(double* x, int N, int win) {
    double accum = 0;
    double* csum = new double[N];
    for (int i = 0; i < N-1; i++) {
        accum += x[i]*x[i];
        csum[i] = accum;
    }
    double* energy = new double[N];
    for (int i = 0; i < N; i++) {
      if (i >= win && i < N-win) {
        energy[i] = (csum[i+win] - csum[i-win])/(2*win+1);
      }
      else {
        energy[i] = 0;
      }
    }
    delete[] csum;
    return energy;
}
