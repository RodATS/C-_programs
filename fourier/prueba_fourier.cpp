//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//    string image_path = "E:\\imagenes\\shark.jpg";
//    Mat image = imread(image_path, IMREAD_COLOR);
//    resize(image, image, { 500,500 }, 0, 0, cv::INTER_NEAREST);
//
//    imshow("Image", image);
//    waitKey(0);
//}

/*
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


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
Mat IDFT(Mat src)
{
	Mat I = src;
	Mat padded;                            //expand input image to optimal size
	int m = getOptimalDFTSize(I.rows);
	int n = getOptimalDFTSize(I.cols); // on the border add zero values
	copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));

	Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

	dft(complexI, complexI, DFT_INVERSE);            // this way the result may fit in the source matrix

	// compute the magnitude and switch to logarithmic scale
	// => log(1 + sqrt(Re(IDFT(I))^2 + Im(IDFT(I))^2))
	split(complexI, planes);                   // planes[0] = Re(IDFT(I), planes[1] = Im(IDFT(I))
	magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
	Mat magI = planes[0];

	magI += Scalar::all(1);                    // switch to logarithmic scale
	log(magI, magI);


	normalize(magI, magI, 0, 1, CV_MINMAX);

	imshow("forged map", magI);


	return magI;
}



//------------------------------------------------------------------------------------------------------------------------
int main()
{
	Mat img = imread("E:\\imagenes\\shark.jpg", 0);
		img.convertTo(img, CV_32F);

		// expand input image to optimal size
		Mat padded;
		int m = getOptimalDFTSize(img.rows);
		int n = getOptimalDFTSize(img.cols);
		copyMakeBorder(img, padded, 0, m - img.rows, 0, n - img.cols, BORDER_CONSTANT, Scalar::all(0));

		// calculate DFT
		Mat DFT_image;
		calculateDFT(padded, DFT_image);

		
		//The result of the transformation is complex numbers.
		//Displaying this is possible via a magnitude.
		
		Mat real, imaginary;
		Mat planes[] = { real, imaginary };

		split(DFT_image, planes);
		Mat mag_image;
		magnitude(planes[0], planes[1], mag_image);

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
		cv::Mat inverseTransform, complexI;
		cv::dft(complexI, inverseTransform, cv::DFT_INVERSE | cv::DFT_REAL_OUTPUT);
		normalize(inverseTransform, inverseTransform, 0, 1, NORM_MINMAX);
		imshow("Reconstructed", inverseTransform);
		waitKey(0);
	
	return 0;
}*/
