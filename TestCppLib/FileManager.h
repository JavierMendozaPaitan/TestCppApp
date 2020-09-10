#pragma once

#include "pch.h"
#include "FilterConvolute.h"

using namespace std;
using namespace cv;

class FileManager
{
public:
	FileManager(string name);
	~FileManager();

	string Filename;
	Mat SrcImage;
	Mat DstImage;

	void ShowSrcImage();
	void ShowDstImage();
	void ApplySobel();

	

private:
	FilterConvolute* Filter;

	string DstFileName();
};