#include "pch.h"
#include "FileManager.h"

FileManager::FileManager(string name)
{
	try
	{
		Filename = name;
		SrcImage = imread(Filename, IMREAD_COLOR);
	}
	catch (const std::exception&)
	{
		throw;
	}
}

FileManager::~FileManager()
{
	SrcImage.release();
}

void FileManager::ShowSrcImage()
{
	try
	{
		namedWindow("Showing Source Image", WINDOW_AUTOSIZE);
		imshow("Showing Source Image", SrcImage);
	}
	catch (const std::exception&)
	{
		throw;
	}
}

void FileManager::ShowDstImage()
{
	try
	{
		namedWindow("Showing Source Image", WINDOW_AUTOSIZE);
		imshow("Showing Source Image", DstImage);
		delete Filter;
	}
	catch (const std::exception&)
	{
		throw;
	}
}

void FileManager::ApplySobel()
{
	try
	{
		Filter = new FilterConvolute(SrcImage);
		Filter->SobelFilter();
		DstImage = Filter->ImgResult;
	}
	catch (const std::exception&)
	{
		throw;
	}
}
