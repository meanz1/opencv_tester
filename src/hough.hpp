#pragma once
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core/core.hpp"

class fixindex {
public :
	cv::Point p1;
	int fixidx;

	void idxpoint(cv::Point p) {
		p1.x = p.x;
		p1.y = p.y;
		std::cout << "idxpoint" << std::endl;
	}
	
	int indexing(std::vector<double> a, std::vector<double> b) {

		std::vector<double> temp;
		double _min = 10000000;
		std::cout << "what" << std::endl;
		for (int i = 0; i < a.size(); i++) {

			double min = a[i] * p1.x + b[i] - p1.y;
			double square = min * min;
			temp.push_back(square);
			std::cout << "min : " << min << std::endl;
			std::cout << "tmp : " << square << std::endl;
			if (temp[i] < _min) {
				_min = temp[i];
			}

		}
		fixidx = std::find(temp.begin(), temp.end(), _min) - temp.begin();
		std::cout << "fixed index is " << fixidx << std::endl;
		return fixidx;
	}
	void pointline(void* param, std::vector<cv::Point2i> a, std::vector<cv::Point2i> b) {
		cv::Mat img;
		img = *(cv::Mat*)param;
		for (int i = 0; i < a.size(); i++) {
			if (i == fixidx) {
				cv::line(img, a[fixidx], b[fixidx], cv::Scalar(0, 255, 0), 2, 8);
			}
			
		}
		
		cv::imshow("img_canny", img);
	}
};
