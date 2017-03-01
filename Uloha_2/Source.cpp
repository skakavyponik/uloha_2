#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;


int main() {
	Mat image = imread("D:/Stiahnute/2.jpg");
	int R[257] = { };
	int G[257] = { };
	int B[257] = { };
	int sum=0;

	for (int i = 0; i < image.rows; i++)
		for (int j = 0; j < image.cols; j++)
		{
			Vec3b intensity = image.at<Vec3b>(Point(j, i));
			int Red = intensity.val[0];
			int Green = intensity.val[1];
			int Blue = intensity.val[2];
			R[Red] = R[Red] + 1;
			G[Green] = G[Green] + 1;
			B[Blue] = B[Blue] + 1;
		}
	Mat HistPlotR(750, 256, CV_8UC3, Scalar(0, 0, 0));
	Mat HistPlotG(750, 256, CV_8UC3, Scalar(0, 0, 0));
	Mat HistPlotB(750, 256, CV_8UC3, Scalar(0, 0, 0));
	cout << "rozl " << image.cols*image.rows;

	for (int i = 0; i < 256; i = i + 2)
	{
		sum += R[i];
		line(HistPlotR, Point(i, 750), Point(i, 750-R[i]/2), Scalar(0, 0, 255), 1, 8, 0);
		line(HistPlotG, Point(i, 750), Point(i, 750-G[i]/2), Scalar(0, 255, 0), 1, 8, 0);
		line(HistPlotB, Point(i, 750), Point(i, 750-B[i]/2), Scalar(255, 0, 0), 1, 8, 0);
	}

	cout << "sum " << sum;
	namedWindow("Red Histogram");
	namedWindow("Green Histogram");
	namedWindow("Blue Histogram");
	imshow("Red Histogram", HistPlotR);
	imshow("Green Histogram", HistPlotG);
	imshow("Blue Histogram", HistPlotB);
	waitKey(0);
	return 0;
}