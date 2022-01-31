#include "AudioFile.h"
#include <stdlib.h>

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
        if (x[i+1] > 0 && x[i] < 0 || x[i+1] < 0 && x[i+1] > 0) {
            count++;
        }
        csum[i] = count;
    }
    int* crossings = new int[N];
    for (int i = 0; i < N; i++) {
      if (i >= win/2 && i < N-win/2) {
        crossings[i] = csum[i+win/2] - csum[i-win/2];
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
      if (i >= win/2 && i < N-win/2) {
        energy[i] = csum[i+win/2] - csum[i-win/2];
      }
      else {
        energy[i] = 0;
      }
    }
    delete[] csum;
    return energy;
}

/**
 * @brief Filter the audio by loudness or by consonants/vowels
 * 
 * @param x Audio samples
 * @param N Length of audio
 * @param NOut Reference to int holding length of filtered array
 * @param win Window to use when filtering
 * @param thresh Threshold to use when filtering
 * @return double* Filtered array
 */
double* filter(double* x, int N, int* NOut, int win, double thresh) {
  
  return NULL; // TODO: This is a dummy value
}

/**
 * @brief Extract the audio samples from an audio object
 * 
 * @param aobj Audio object
 * @param N Length of samples, by reference (set as a side effect)
 * @return double* The extracted audio samples
 */
double* extractAudioSamples(AudioFile<double>& aobj, int* N) {
  *N = (int)aobj.getNumSamplesPerChannel();
  double* ret = new double[*N];
  for (int i = 0; i < *N; i++) {
    ret[i] = aobj.samples[0][i];
  }
  return ret;
}

/**
 * @brief Copy an array of audio samples into an audio object
 * 
 * @param file Audio object
 * @param samples 
 * @param N 
 */
void copyAudioSamples(AudioFile<double>& aobj, double* samples, int N) {
    AudioFile<double>::AudioBuffer buffer;
    buffer.resize(1);
    buffer[0].resize(N);
    for (size_t i = 0; i < N; i++) {
        buffer[0][i] = samples[i];
    }
    aobj.setAudioBuffer(buffer);
}

int main(int argc, char* argv[]) {
    AudioFile<double> file;
    file.load(argv[1]);
    int N;
    double* samples = extractAudioSamples(file, &N);
    
    int NOut;
    double* res = filter(samples, N, &NOut, 1000, 40);


    copyAudioSamples(file, res, NOut);
    delete[] res;
    delete[] samples;
    file.save("filtered.wav");
}
