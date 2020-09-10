#pragma once

#include "pch.h"

class FilterConvolute
{
public:
	FilterConvolute(Mat imgtc);
	~FilterConvolute();

	Mat ImgToConv;
	Mat ImgResult;

	void SobelFilter();

private:

	void Convolute(const Mat& src, Mat& rst);

};

