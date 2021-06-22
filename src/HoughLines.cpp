#include "opencv2/opencv.hpp"
#include <iostream>
#include "hough.hpp"

void on_mouse(int event, int x, int y, int flags, void* param);
std::vector<cv::Point2i> pointLine_a;
std::vector<cv::Point2i> pointLine_b;
std::vector<double> alpha;
std::vector<double> beta;
int f;
fixindex fix;

int main()
{
	cv::Mat img = cv::imread("apple.jpg");
	
	cv::resize(img, img, cv::Size(500, 500));
	cv::Mat img_gray;
	cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

	cv::Mat img_canny;
	Canny(img_gray, img_canny, 100, 700);
	// ����°, �׹�° ���� : low �Ӱ谪, high �Ӱ谪
	// low �Ӱ谪���� �۰�, high �Ӱ谪 ���� Ŭ �� edge�� �ν���.
	// high �Ӱ谪�� Ŭ����(������) ������ ����ϰ� ����Ǵ� �� ����.

	std::vector<cv::Vec2f> lines;
	
	cv::HoughLines(img_canny, lines, 1, CV_PI / 180, 150);
	// ���� ������ ����(150) : ������ ����
	// �������� �� ���� ���� ����
	cv::Mat img_hough;
	img.copyTo(img_hough);
	cv::Mat img_lane;
	cv::threshold(img_canny, img_lane, 100, 700, cv::THRESH_MASK);
	cv::namedWindow("img_canny");
	cv::setMouseCallback("img_canny", on_mouse, &img_hough);
	while (1) {
		cv::imshow("img_canny", img_hough);
		cv::imshow("img_lane", img_lane);

		
		for (size_t i = 0; i < lines.size(); i++)
		{
			float rho = lines[i][0], theta = lines[i][1];
			cv::Point pt1, pt2;
			double a = cos(theta), b = sin(theta);
			double x0 = a * rho, y0 = b * rho;
			pt1.x = cvRound(x0 + 700 * (-b));
			pt1.y = cvRound(y0 + 700 * (a));
			pt2.x = cvRound(x0 - 700 * (-b));
			pt2.y = cvRound(y0 - 700 * (a));
			cv::line(img_hough, pt1, pt2, cv::Scalar(0, 0, 255), 2, 8);
			cv::line(img_lane, pt1, pt2, cv::Scalar::all(255), 1, 8);
			
			pointLine_a.push_back(pt1);
			pointLine_b.push_back(pt2);

			double alp = (double)(pointLine_b[i].y - pointLine_a[i].y) / (double)(pointLine_b[i].x - pointLine_a[i].x); // ����, ����ĳ�����������
			double bet = pointLine_a[i].y - alp * pointLine_a[i].x;

			alpha.push_back(alp);
			beta.push_back(bet);
			
			std::cout << "a " << pointLine_a[i] << std::endl;
			std::cout << "b " << pointLine_b[i] << std::endl;
			std::cout << "alpha " << alpha[i] << std::endl;
			std::cout << "beta " << beta[i] << std::endl;
		}
		cv::imshow("img_canny", img_hough);
		cv::imshow("img_lane", img_lane);
		cv::waitKey();
		
		
		//std::cout << pointLine[1] << std::endl;
		//cv::line(img_lane, pointLine[0].x, pointLine.y, cv::Scalar(255, 0, 0), 2, 8);
		

		
	}
	
	return 0;
}

void on_mouse(int event, int x, int y, int flags, void* param)
{
	cv::Mat img;
	img = *(cv::Mat*)param;

	cv::Point point;
	point = cv::Point(x, y);
	
	if (event == cv::EVENT_LBUTTONDOWN)
		std::cout << "LBUTTUON DOWN : " << point.x << " " << point.y << std::endl;
	if (event == cv::EVENT_LBUTTONUP)
	{
		std::cout << "LBUTTON UP : " << point.x << " " << point.y << std::endl;
		cv::Point click = point;
		std::cout << "click : " << click.x << " " << click.y << std::endl;
		for (int i = 0; i < pointLine_a.size(); i++) {
			cv::line(img, pointLine_a[i], pointLine_b[i], cv::Scalar(0, 0, 255), 2, 8);
		}
		
		fix.idxpoint(click);
		fix.indexing(alpha, beta);
		fix.pointline(&img, pointLine_a, pointLine_b);
		
	}

	
	
}