#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat srcMat = imread("G:/picture/1.jpg", 0);
	Mat result,result1,result2,result3,result4;
	Mat stt = getStructuringElement( MORPH_RECT, Size(3, 3), Point(-1, -1));
	threshold(srcMat, result, 100, 255, THRESH_BINARY);
	erode(result, result1, stt,Point(-1, -1), 1, BORDER_CONSTANT,morphologyDefaultBorderValue());
	dilate(result, result2, stt,Point(-1, -1), 1, BORDER_CONSTANT,morphologyDefaultBorderValue());
	morphologyEx(result, result3,2,stt,Point(-1, -1), 1, BORDER_CONSTANT,morphologyDefaultBorderValue());
	morphologyEx(result, result4, 3, stt,Point(-1, -1), 1, BORDER_CONSTANT,morphologyDefaultBorderValue());
	imshow("result", result);
	imshow("result1", result1);
	imshow("result2", result2);
	imshow("result3", result3);
	imshow("result4", result4);
	waitKey(0);
}