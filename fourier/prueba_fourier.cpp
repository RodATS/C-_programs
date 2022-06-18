#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
#define PI 3.1416


void calculateDFT(Mat& scr, Mat& dst)
{
	// define mat consists of two mat, one for real values and the other for complex values
	Mat planes[] = { scr, Mat::zeros(scr.size(), CV_32F) };
	Mat complexImg;
	merge(planes, 2, complexImg);
	dft(complexImg, complexImg);
	dst = complexImg;
}
//------------------------------------------------------------------------------------------------------------------------
void fftshift(const Mat& input_img, Mat& output_img)
{
	output_img = input_img.clone();
	int cx = output_img.cols / 2;
	int cy = output_img.rows / 2;
	Mat q1(output_img, Rect(0, 0, cx, cy));
	Mat q2(output_img, Rect(cx, 0, cx, cy));
	Mat q3(output_img, Rect(0, cy, cx, cy));
	Mat q4(output_img, Rect(cx, cy, cx, cy));
	Mat temp;
	q1.copyTo(temp);
	q4.copyTo(q1);
	temp.copyTo(q4);
	q2.copyTo(temp);
	q3.copyTo(q2);
	temp.copyTo(q3);
}


//------------------------------------------------------------------------------------------------------------------------
int main()
{
	Mat img = imread("E:\\imagenes\\shark.jpg", 0);
	img.convertTo(img, CV_32F);
	// expand input image to optimal size
	Mat padded,img3,freq, dst;
	int m = getOptimalDFTSize(img.rows);
	int n = getOptimalDFTSize(img.cols);
	copyMakeBorder(img, padded, 0, m - img.rows, 0, n - img.cols, BORDER_CONSTANT, Scalar::all(0));

	
	//Transformada de coseno discreta (Discrete cosine transform)
	img3 = Mat(padded.rows, padded.cols, CV_64F);
	padded.convertTo(img3, CV_64F); // Let's do the DCT now: image => frequencies 
	dct(img3, freq); // Visualiza los coeficientes de la DCT 
	imshow("FDCT", freq); waitKey(0);

	idct(freq, dst);
	normalize(dst, dst, 0, 1, NORM_MINMAX);
	imshow("FIDCT", dst);	waitKey(0);
	


	// calculate DFT
	Mat DFT_image;
	calculateDFT(padded, DFT_image);

	//The result of the transformation is complex numbers.
	//Displaying this is possible via a magnitude.

	Mat real, imaginary;
	Mat planes[] = { real, imaginary };
	split(DFT_image, planes);

	//cout << planes[0][0] << endl;

	Mat mag_image;
	magnitude(planes[0], planes[1], mag_image);
	

	//phase(planes[0], planes[1],PI/3 , true);

	// switch to a logarithmic scale
	mag_image += Scalar::all(1);
	log(mag_image, mag_image);
	mag_image = mag_image(Rect(0, 0, mag_image.cols & -2, mag_image.rows & -2));
	Mat shifted_DFT;
	fftshift(mag_image, shifted_DFT);
	normalize(shifted_DFT, shifted_DFT, 0, 1, NORM_MINMAX);
	imshow("DFT", shifted_DFT);
	waitKey(0);


	//calculating the idft
	cv::Mat inverseTransform;
	cv::dft(DFT_image, inverseTransform, cv::DFT_INVERSE | cv::DFT_REAL_OUTPUT);
	normalize(inverseTransform, inverseTransform, 0, 1, NORM_MINMAX);
	imshow("Reconstructed", inverseTransform);
	waitKey(0);

	return 0;
}
