#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat srcMat = imread("G:\\picture\\3.jpg",0);
	Mat result,result1;
	threshold(srcMat, result, 100, 255, THRESH_OTSU);	//大津法
	Mat stt = getStructuringElement(MORPH_RECT, Size(20,20), Point(-1, -1));
	morphologyEx(result, result1, 3, stt, Point(-1, -1), 1, BORDER_CONSTANT, morphologyDefaultBorderValue());	//函数默认白色为前景，所以应用闭运算
	imshow("result", result1);
	bitwise_not(result1, result1);	//前背景调换
	Mat labels, stats, centroids;
	int n = connectedComponentsWithStats(result1, labels, stats, centroids, 8, CV_32S);
	cout << "原点个数：" << n - 1 << endl;
	waitKey(0);
	return 0;
}