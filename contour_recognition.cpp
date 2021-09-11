#include<opencv2/opencv.hpp>
#include<iostream>
#include <fstream>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/highgui/highgui_c.h>
#include<math.h>

using namespace cv;
using namespace std;

Mat src, dst,dst2,gray_src, edge_output, blur_out, binary_out;
int t1_value = 30;
int t2_value = 20;

int main(int argc, char** argv)
{
	//����ԭʼͼ
	/*src = imread("D:/vcprojects/ʩ���ֳ�ͼ.jpg");
	if (!src.data)
	{
		printf("can not load\n");
		exit(-1);
	}
	char INPUT_TITLE[] = "Input Image";
	char OUTPUT_TITLE[] = "Output Image";

	//��������
	namedWindow("INPUT_TITLE", CV_WINDOW_NORMAL);
	namedWindow("OUTPUT_TITLE", CV_WINDOW_NORMAL);
	//��ʾԭʼͼ
	imshow("INPUT_TITLE", src);

	//ͼƬ�ҶȻ�
	cvtColor(src, gray_src, CV_BGR2GRAY);
	//ͼƬ����
	blur(gray_src, blur_out, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);

	threshold(blur_out, binary_out, 55, 255, CV_THRESH_BINARY);

	Canny(binary_out,dst , t1_value, t2_value, 3, false);

	imshow("OUTPUT_TITLE", dst);*/

	//imshow("OUTPUT_TITLE",dst);

	/*Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(18,18));
	morphologyEx(dst, dst2, MORPH_CLOSE, kernel);

	//Canny(dst2, dst2, t1_value, t2_value, 3, false);

	imshow("OUTPUT_TITLE", dst2);*/

	//threshold(dst,edge_output, 55, 255, CV_THRESH_BINARY);
	//ͼƬ��ֵ��
	/*threshold(blur_out, binary_out, 55, 255, CV_THRESH_BINARY);
	//��̬ѧ����
	Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(30, 30), Point(-1, -1));
	morphologyEx(binary_out, dst, MORPH_OPEN, kernel);
	//��Ե���
	Canny(dst, edge_output, t1_value, t2_value, 3, false);*/

	//imshow("OUTPUT_TITLE", edge_output);

	//������ͼ��bmp��ʽд��Ӳ��
	//imwrite("D:/vcprojects/chulihou.bmp", dst2);
	//����bmp��ʽ����ͼ
	Mat M = imread("D:/vcprojects/chulihou.bmp", 0);

	//���������Ͳ�νṹ
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(M, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);
	
	//Mat conImage = Mat::zeros(M.rows, M.cols, CV_8UC3);
	//������ȡ��д���ı��ĵ�
	for (size_t t= 0; t < contours.size(); t++)
	{
		Rect rect = boundingRect(contours[t]);
		if (rect.width < M.cols /5)continue;
		if (rect.width > (M.cols - 20))continue;
		//drawContours(conImage, contours, static_cast<int>(t), Scalar(0, 0, 255), 1, 8, hierarchy);
		for (int j = 0; j < contours[t].size(); j++)
		{
			cout << contours[t][j].x << "	" << contours[t][j].y << endl;
			ofstream f;
			f.open("D:/vcprojects/����������.txt", ios::out | ios::app);
			f << contours[t][j].x << "	" << contours[t][j].y << endl;
		}
	}
	//imshow("result", conImage);
	

	waitKey(0);

	return 0;
}
