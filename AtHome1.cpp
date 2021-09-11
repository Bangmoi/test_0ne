#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;
 
int main()
{
	Mat img = imread("D:\\OpenCV346\\girl.jpg", CV_LOAD_IMAGE_COLOR);
	imshow("TestAtHome", img);
	Mat picture = imread("D:\\OpenCV346\\hinh.jpg", CV_LOAD_IMAGE_COLOR);
	imshow("TestAtHome", picture);
	Mat kenh[3],img1;
	split(img,kenh);
	imshow("BLUE", kenh[0]);
	imshow("GREEN", kenh[1]);
	imshow("RED", kenh[2]);
	
	cout << "Ten ban vua nhap la: " << img.rows<< endl;

	/*kenh[0] = Mat::zeros(img.rows, img.cols, CV_8UC1);
	kenh[1] = kenh[0];
	imshow("red_zezos", kenh[2]);
	merge(kenh,3,img1);
	imshow("0_0_red", img1);

	kenh[0] = Mat::zeros(img.rows, img.cols, CV_8UC1);
	kenh[2] = kenh[0];
	imshow("GREEN_Zezos", kenh[1]);
	merge(kenh,3, img1);
	imshow("0_GREEN_0", img1);*/

	kenh[1] = Mat::zeros(img.rows, img.cols, CV_8UC1);
	kenh[2] = kenh[1];
	imshow("BLUE_Zezos", kenh[0]);
	merge(kenh, 3, img1);
	imshow("BLUE_0_0", img1);

	Mat imgRGB, imgHSV;
	cvtColor(img, imgHSV, COLOR_RGB2HSV);
	imshow("RGB->HSV", imgHSV);
	cvtColor(imgHSV, imgRGB, COLOR_HSV2RGB);
	imshow("HSV->RGB", imgRGB);
	////viet file save trong O F I F E;
	//imwrite("ok.png", imgHSV);

	for (int i = 0;i < img.rows;i++)
	{
		for (int j = 0;j < img.cols;j++)
		{
				img.at<Vec3b>(i, j)[0] = 0;
				img.at<Vec3b>(i, j)[2] = 0;
		}
	}
	imshow("0_0_0", img);

	for (int x = 0;x <picture.rows;x++)
	{
		for (int y = 0;y < picture.cols;y++)
		{
			picture.at<Vec3b>(x, y)[0] += 200;
			if (picture.at<Vec3b>(x, y)[0] += 200 > 255)
			{
				picture.at<Vec3b>(x, y)[0] = 255;
			}
			picture.at<Vec3b>(x, y)[1] += 200;
			if (picture.at<Vec3b>(x, y)[1] += 200 > 255)
			{
				picture.at<Vec3b>(x, y)[1] = 255;
			}	
		}
	}
	imshow("IMG+100", picture);

	waitKey();
	return 0;
}
