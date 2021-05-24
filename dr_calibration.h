#pragma once

#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/utils/filesystem.hpp>

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

class DR_Calibration
{
public:
	enum { DETECTION, CAPTURING, CALIBRATED };

	enum Pattern 
	{ 
		CHESSBOARD,					//CHESSBOARD ∆Â≈Ã∏Ò
		CIRCLES_GRID,				//CIRCLES_GRID	∂‘≥∆‘≤
		ASYMMETRIC_CIRCLES_GRID 	//ASYMMETRIC_CIRCLES_GRID ∑«∂‘≥∆‘≤
	};

	DR_Calibration(const std::string& imgsDir,
		const std::string& outputFilename,
		Size boardSize,
		double squareSize,
		Pattern pattern
	) :_imgsDir(imgsDir), _outputFilename(outputFilename), _boardSize(boardSize), _squareSize(squareSize), _pattern(pattern){}

	static double computeReprojectionErrors(
		const vector<vector<Point3f> >& objectPoints,
		const vector<vector<Point2f> >& imagePoints,
		const vector<Mat>& rvecs, const vector<Mat>& tvecs,
		const Mat& cameraMatrix, const Mat& distCoeffs,
		vector<float>& perViewErrors);

	static void calcChessboardCorners(Size boardSize, float squareSize,
		vector<Point3f>& corners, Pattern patternType = CHESSBOARD);

	bool doCalibration();

	cv::Mat getCameraMatrix() const;
	cv::Mat getDistCoeffsMatrix() const;
	cv::Mat getExtrinsicsBigMat() const;
	vector<int> getFoundCheeseBoardVec() const;

	void createCalibBoard(string fileDir);


protected:
	void saveCameraParams(const string& filename,
		Size imageSize, Size boardSize,
		float squareSize, float aspectRatio, int flags,
		const Mat& cameraMatrix, const Mat& distCoeffs,
		const vector<Mat>& rvecs, const vector<Mat>& tvecs,
		const vector<float>& reprojErrs,
		const vector<vector<Point2f> >& imagePoints,
		double totalAvgErr);

	bool runCalibration(vector<vector<Point2f> > imagePoints,
		Size imageSize, Size boardSize, Pattern patternType,
		float squareSize, float aspectRatio,
		int flags, Mat& cameraMatrix, Mat& distCoeffs,
		vector<Mat>& rvecs, vector<Mat>& tvecs,
		vector<float>& reprojErrs,
		double& totalAvgErr);

	bool runAndSave(const string& outputFilename,
		const vector<vector<Point2f> >& imagePoints,
		Size imageSize, Size boardSize, Pattern patternType, float squareSize,
		float aspectRatio, int flags, Mat& cameraMatrix,
		Mat& distCoeffs, bool writeExtrinsics, bool writePoints);

	bool readCameraParameters(
		const std::string& filename,
		cv::Mat & camMatrix, cv::Mat & distCoefs);



private:
	Size _boardSize;
	double _squareSize;
	float _aspectRatio = 1;	//ÕºœÒ≥ﬂ¥Á1:1

	bool undistortImage = false;
	int flags = 2;
	bool flipVertical = false;
	bool showUndistorted = false;

	clock_t prevTimestamp = 0;

	string _imgsDir;
	string _outputFilename;

	bool writeExtrinsics = true;
	bool writePoints = true;

	Pattern _pattern;
	int _mode = CALIBRATED;

	vector<vector<Point2f> > imagePoints;
	Mat cameraMatrix, distCoeffs;
	Size imageSize;

	vector<int> foundCheeseBoardVec;
	Mat extrinsicsBigMat;

	bool _saveResImg = false;
};

