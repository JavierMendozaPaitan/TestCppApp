#include "pch.h"
#include "FilterConvolute.h"

FilterConvolute::FilterConvolute(Mat imgtc)
{
	try
	{
		ImgToConv = imgtc;
	}
	catch (const std::exception&)
	{
		throw;
	}
}

FilterConvolute::~FilterConvolute()
{
	ImgResult.release();
}

void FilterConvolute::SobelFilter()
{
	try
	{
		CV_Assert(ImgToConv.depth() == CV_8U);
		Convolute(ImgToConv, ImgResult);
		ImgResult.row(0).setTo(Scalar(0));
		ImgResult.row(ImgResult.rows - 1).setTo(Scalar(0));
		ImgResult.col(0).setTo(Scalar(0));
		ImgResult.col(ImgResult.cols - 1).setTo(Scalar(0));
	}
	catch (const std::exception&)
	{
		throw;
	}
}

void FilterConvolute::Convolute(const Mat& src, Mat& rst)
{
	try
	{
		const int nchnn = src.channels();
		rst.create(src.size(), src.type());
#pragma omp parallel for
		for (int j = 1; j < src.rows - 1; ++j)
		{
			const uchar* prv = src.ptr<uchar>(j - 1);
			const uchar* cur = src.ptr<uchar>(j);
			const uchar* nxt = src.ptr<uchar>(j + 1);
			uchar* out = rst.ptr<uchar>(j);
			for (int i = nchnn; i < nchnn*(src.cols - 1); ++i)
			{
				uchar gx = saturate_cast<uchar>(prv[i - nchnn] + 2 * cur[i + nchnn] + nxt[i + nchnn] - prv[i - nchnn] - 2 * cur[i - nchnn] - nxt[i - nchnn]);
				uchar gy = saturate_cast<uchar>(nxt[i - nchnn] + 2 * nxt[i] + nxt[i + nchnn] - prv[i - nchnn] - 2 * prv[i] - prv[i + nchnn]);
				*out++ = saturate_cast<uchar>(sqrt(gx * gx + gy * gy));				
			}
		}
	}
	catch (const std::exception&)
	{
		throw;
	}
}
