//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace cv;
//using namespace std;
//int main()
//{
//	Mat srcMat = imread("G:\\picture\\2.jpg", 0);
//	Mat result, result1, result2;
//	threshold(srcMat, result, 100, 255, THRESH_OTSU);       //���
//	Mat stt = getStructuringElement(MORPH_RECT, Size(5, 5), Point(-1, -1));
//	morphologyEx(result, result1, 2, stt, Point(-1, -1), 1, BORDER_CONSTANT, morphologyDefaultBorderValue());     //������
//	imshow("result", result1);
//	bitwise_not(result1, result1);         //ǰ��������
//	Mat labels, stats, centroids;
//	int n = connectedComponentsWithStats(result1, labels, stats, centroids, 8, CV_32S);
//	for (int i = 1; i < stats.rows; i++)
//	{
//		if (stats.at<int>(i, CC_STAT_AREA) <4500 )
//			n--;
//	}		//�ȶ����ȥ������
//	cout << "�����������" << n - 1 << endl;
//	waitKey(0);
//	return 0;
//}