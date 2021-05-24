#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <iostream>

#include "dr_calibration.h"

int main()
{

	std::string imgPath = "./data/cam1/";
	std::string calibDataPath = "./data/cam1/camParam.yaml";
	DR_Calibration calib(imgPath, calibDataPath, cv::Size(11, 8), 0.045, DR_Calibration::Pattern::CHESSBOARD);

	//cv::Size size(7, 7);
	//std::string imgPath = "./data/calibImgold/";
	//std::string calibDataPath = "./data/calibImgold/camParam.yaml";
	//DR_Calibration calib(imgPath, calibDataPath, size, 0.015, DR_Calibration::Pattern::CIRCLES_GRID);

	calib.doCalibration();

	
	return 0;
}