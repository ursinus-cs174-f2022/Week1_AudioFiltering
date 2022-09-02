#include "AudioFile.h"
#include "utils.h"
#include <stdlib.h>


/**
 * @brief Filter the audio by loudness or by consonants/vowels
 * 
 * @param x Audio samples
 * @param N Length of audio
 * @param win Window to use when filtering
 * @param thresh Threshold to use when filtering
 * @return double* Filtered array
 */
double* filter(double* x, int N, int win, double thresh) {
  // Make a new array that's as long as the original one, but
  // lots of samples at the end may be untouched
  double* y = new double[N];
  // TODO: Fill this in

  return y; 
}


int main(int argc, char* argv[]) {
    AudioFile<double> file;
    file.load(argv[1]);
    int N;
    double* samples = extractAudioSamples(file, &N);
    
    int win = 4001;
    double thresh = 0.001; // TODO: Update this
    double* filtered = filter(samples, N, win, thresh);

    copyAudioSamples(file, filtered, N);
    delete[] filtered;
    delete[] samples;
    file.save("filtered.wav");
}
