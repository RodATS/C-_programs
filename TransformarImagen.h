#pragma once
#include <complex>
using namespace cv;
using namespace std;

//typedef std::complex<double> Complex;
const double PI = 3.14159265358979323846;
void ProcesarImagen(string path);
void ProcesarImagen2(string path);
void calculateDFT(Mat& scr, Mat& dst);
void FF1D(Mat& input, bool inverse = false);
void fftshift(const Mat& input_img, Mat& output_img);
//-------------------------------------------------------------------------------------------------------------------------
void ProcesarImagen(string path)
{
	string image_path = path;

	Mat img = imread(image_path, 0);
	img.convertTo(img, CV_32F);

	// expand input image to optimal size
	Mat padded, img3, freq, dst;
	int m = getOptimalDFTSize(img.rows);
	int n = getOptimalDFTSize(img.cols);
	copyMakeBorder(img, padded, 0, m - img.rows, 0, n - img.cols, BORDER_CONSTANT, Scalar::all(0));

	/*
	//Transformada de coseno discreta (Discrete cosine transform)
	img3 = Mat(padded.rows, padded.cols, CV_64F);
	padded.convertTo(img3, CV_64F); // Let's do the DCT now: image => frequencies
	dct(img3, freq); // Visualiza los coeficientes de la DCT
	imshow("FDCT", freq); waitKey(0);

	idct(freq, dst);
	normalize(dst, dst, 0, 1, NORM_MINMAX);
	imshow("FIDCT", dst);	waitKey(0);
	*/ //por si funciona lo otro sacamos puntitos aqui es una derivada del DFT



	// calculate DFT
	Mat DFT_image;
	calculateDFT(padded, DFT_image);


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

	cv::normalize(shifted_DFT, shifted_DFT, 0, 1, NORM_MINMAX);//si aumentas ese 1 a 2 para adelante aumenta el brillo de la imagen

	cv::imshow("DFT", shifted_DFT);
	cv::waitKey(0);


	//calculating the idft 
	//sera??
	cv::Mat inverseTransform;
	idft(shifted_DFT, inverseTransform, DFT_REAL_OUTPUT);
	//normalize(inverseTransform, inverseTransform, 0, 1, NORM_MINMAX);
	cv::imshow("Reconstructed", inverseTransform);
	cv::waitKey(0);

	////////////////////////////////////////////////////////
	cv::Mat finalImage;
	cv::dft(DFT_image, finalImage, cv::DFT_INVERSE | cv::DFT_REAL_OUTPUT);
	cv::normalize(finalImage, finalImage, 0, 1, NORM_MINMAX);
	cv::imshow("IDFT", finalImage);
	cv::waitKey(0);

}
//-------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------
void fft(vector<complex<float>>& v)
{
	int N = v.size();
	if (N <= 1) return;

	// divide
	vector<complex<float>> impar;
	vector<complex<float>> par;
	for (int i = 0; i < N - 1; i += 2) {
		par.push_back(v[i]);
		impar.push_back(v[i + 1]);
	}

	// conquer
	fft(par);
	fft(impar);

	// combine
	for (int k = 0; k < N / 2; ++k)
	{
		complex<float> aux(std::polar(1.0, -2 * PI * k / N).real(),std::polar(1.0, -2 * PI * k / N).imag());
		complex<float> t = aux * impar[k];
		v[k] = par[k] + t;
		v[k + N / 2] = par[k] - t;
	}
}

void ifft(vector<complex<float>>& v)
{
	for (auto& x : v)
		x = conj(x);
	fft(v);
	complex<float> s(v.size(), 0);
	for (auto& x : v)
		x = conj(x) / s;

}

//-------------------------------------------------------------------------------------------------------------------------
void ProcesarImagen2(string path) {
	string image_path = path;
	//Mat img;
	Mat img = imread(image_path, IMREAD_GRAYSCALE); //CV_LOAD_IMAGE_GRAYSCALE
	//cv::cvtColor(img_color, img, cv::COLOR_BGR2GRAY);
	img.convertTo(img, CV_32FC1, 1.0 / 255.0);
	//normalize(img, img, 0, 1, NORM_MINMAX);
	imshow("Original", img);
	cv::waitKey(0);


	// agrandar imagen al tamaño óptimo
	Mat padded, img3, freq, dst;
	int m = getOptimalDFTSize(img.rows);
	int n = getOptimalDFTSize(img.cols);
	copyMakeBorder(img, padded, 0, m - img.rows, 0, n - img.cols, BORDER_CONSTANT, Scalar::all(0));

	// Mat CompleX;
	//  Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
	// //  Mat planes[] = { padded, Mat::zeros(padded.size(), CV_32F) };
	//  merge(planes, 2, CompleX);         // Add to the expanded another plane with zeros


	//float f1 = CompleX.at<float>(m, n);

	//std::vector<float>vec(padded.begin<float>(), padded.end<float>());
	vector<float> imgVec;
	for (int i = 0; i < padded.rows; ++i) {
		imgVec.insert(imgVec.end(), padded.ptr<float>(i), padded.ptr<float>(i)+padded.cols*padded.channels());
	}
	//imgVec = (uchar*)CompleX.data;
	vector<complex<float>> complexVec;
	for (auto &i: imgVec){
		complex<float> a(imgVec[i],0);
		complexVec.push_back(a);
	}
	//vector<complex<float>> complexVec(imgVec.begin(), imgVec.end());
	// vector<complex<double>> complexVec;
	// for (int i = 0; i < padded.rows; ++i) {
    // complexVec.insert(complexVec.end(), padded.ptr<complex<double>>(i),padded.ptr<complex<double>>(i)+padded.cols*padded.channels());
  	//}


	fft(complexVec);

	Mat FFT_image(m, n, CV_32F, complexVec.data());
	// Mat LFFT;
	// calculateDFT(FFT_image,LFFT);

	// for (int n = 0; n < CompleX.cols; n++)
	// {
	// 	Mat c = CompleX.col(n);
	// 	dft(c,c);
	// }

	// for (int n = 0; n < CompleX.rows; n++)
	// {
	// 	Mat f = CompleX.row(n);
	// 	dft(f,f);
	// }
	// DFT_image=CompleX;

	//normalize(FFT_image, FFT_image, 0, 1, NORM_MINMAX);
	imshow("FFT", FFT_image);
	waitKey(0);

	// for (int n = 0; n < padded.rows; n++)
	// {
	// 	Mat f = padded.row(n);
	// 	dft(f, f, cv::DFT_INVERSE | cv::DFT_REAL_OUTPUT);
	// }

	// for (int n = 0; n < padded.cols; n++)
	// {
	// 	Mat c = padded.col(n);
	// 	dft(c, c, cv::DFT_INVERSE | cv::DFT_REAL_OUTPUT);
	// }

	ifft(complexVec);
	Mat IFT_image(m, n, CV_32F, complexVec.data());
	//idft(IFT_image, inverseTransform, DFT_REAL_OUTPUT);
	//normalize(inverseTransform, inverseTransform, 0, 1, NORM_MINMAX);
	//imshow("Reconstructed", inverseTransform);

	// Mat IFT_image,inverseTransform;
	// cv::dft(FFT_image, IFT_image, cv::DFT_INVERSE | cv::DFT_REAL_OUTPUT);
	//normalize(IFT_image, IFT_image, 0, 1, NORM_MINMAX);
	imshow("IFFT", IFT_image);
	waitKey(0);
}
//---------------------------------------------------------------------------------------------------------------------

// void FF1D(Mat &input, bool inverse){
// 	int size = input.rows;
// 	double angle;

// 	if(size <= 1)
// 		return;

// 	int channels = input.row(0).rows;
// 	Mat even;
// 	Mat odd;

// 	for(int i = 0; i < size; i+=2)
// 	{
// 		Mat tempEven;
// 		Mat tempOdd;
// 		for(int channelIterator = 0; channelIterator < channels; channelIterator++)
// 		{
// 			tempEven.push_back(input.at<complex<double>>(i,channelIterator));
// 			tempOdd.push_back(input.at<complex<double>>(i+1,channelIterator));
// 		}

// 		even.push_back(tempEven);
// 		odd.push_back(tempOdd);
// 	}

// 	FF1D(even, inverse);
// 	FF1D(odd, inverse);

// 	for(int channelIterator = 0; channelIterator < channels; channelIterator++)
// 	{
// 		for(int i = 0; i < size / 2; i++)
// 		{
// 		   if(inverse == false)
// 			   angle = -2.0 * PI * (double)i / (double)size;
// 		   else
// 			   angle = 2.0 * PI * (double)i / (double)size;

// 		   double real = cos(angle);
// 		   double imaginary = sin(angle);

// 		   complex<double> W(real,imaginary);

// 		   W = W * odd.at<complex<double>>(i,channelIterator);

// 		   input.at<complex<double>>(i,channelIterator) = even.at<complex<double>>(i,channelIterator) + W;
// 		   input.at<complex<double>>((size / 2) + i,channelIterator) = even.at<complex<double>>(i,channelIterator) - W;
// 	   }
// 	}
// }

//--------------------------------------------------------------------

void calculateDFT(Mat& scr, Mat& dst)
{
	// define mat consists of two mat, one for real values and the other for complex values
	// Mat planes[] = { scr, Mat::zeros(scr.size(), CV_32F) };
	// Mat complexImg;
	// merge(planes, 2, complexImg);
	dft(scr, scr);
	dst = scr;
}

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
