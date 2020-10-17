#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat srcMat = imread("G:/picture/1.jpg",0);
	Mat result, labels, stats, centroids;
	Rect rect;
	threshold(srcMat, result, 100, 255, THRESH_BINARY);
	int n = connectedComponentsWithStats(result, labels, stats, centroids, 8, CV_32S);
	for (int i = 1; i < stats.rows; i++)
	{
		rect.x = stats.at<int>(i, CC_STAT_LEFT);
		rect.y = stats.at<int>(i, CC_STAT_TOP);
		rect.width = stats.at<int>(i, CC_STAT_WIDTH);
		rect.height = stats.at<int>(i, CC_STAT_HEIGHT);
		rectangle(result, rect, CV_RGB(255, 255, 255), 1, 8, 0);
	}
	cout <<"硬币个数："<< n - 1 << endl;
	imshow("连通域", result);
	waitKey(0);
	return 0;
}