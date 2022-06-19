#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <complex>
#include <cmath>
#include <iterator>
//#include "FormaPequeña.h"
#include "TransformarImagen.h"
//#include "FFT.h"
//#include "2dFFT.h"
//#include "AudioFile.h"
//#include "ManageAudio.h"


using namespace cv;
using namespace std;

int main()
{

    /*typedef complex<double> cx;
    cx a[] = { cx(0,0), cx(1,1), cx(3,3), cx(4,4),
      cx(4, 4), cx(3, 3), cx(1,1), cx(0,0) };
    cx b[8];
    fft(a, b, 3);
    for (int i = 0; i < 8; ++i)
        cout << b[i] << "\n";*/

    string image_path = "E:\\imagenes\\shark.jpg";
    ProcesarImagen2(image_path);
    //fft2d(2);
    /*
    string audio_path = "C:/Users/USER/Music/Hehehe.wav";
    AudioFile<double> testAudio = ReadAudio(audio_path);
    AudioFile<double> copyTestAudio = testAudio;
    vector<complex<double>> samples = GetSamples(copyTestAudio);

    
    Mat AudioMat = cv::Mat_<complex<double>>(samples.size(),1);
    memcpy(AudioMat.data, samples.data(), samples.size() * sizeof(complex<double>));
    dft(samples, samples);
    UpdateSamples(samples, copyTestAudio);
    copyTestAudio.save("C:/Users/USER/Music/audio_test_2.wav");
    dft(samples, samples, cv::DFT_INVERSE | cv::DFT_REAL_OUTPUT);
    UpdateSamples(samples, copyTestAudio);
    copyTestAudio.save("C:/Users/USER/Music/audio_test_3.wav");
    
    /*
    vector<complex<double>> v = {0.0045, 0.043, 0.04345, 0.676, 0.453,  0.04345, 0.676, 0.453};
    fft(v);
    //fft_t(v, false);
    for (auto& x : v)
        cout<<x<<" ";
    cout << endl;

    //fft_t(v, true);
    ifft(v);
     for (auto& x : v)
        cout<<x<<" ";
     cout << endl;
     

    fft(samples);
    complex<double> aux(250, 50);
    for (auto it = samples.begin(); it != samples.end(); it++)
        *it *= aux;
    //*max_element(samples.begin(), samples.end()) = (*max_element(samples.begin(), samples.end()))/aux;
    //*min_element(samples.begin(), samples.end()) = (*min_element(samples.begin(), samples.end()))*aux;
    UpdateSamples(samples, copyTestAudio);
    copyTestAudio.save("C:/Users/USER/Music/audio_test_2.wav");
    ifft(samples);
    UpdateSamples(samples, copyTestAudio);
    copyTestAudio.save("C:/Users/USER/Music/audio_test_3.wav");
    */
}