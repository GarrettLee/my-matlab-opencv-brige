#pragma once
#pragma once

#ifdef BRIGE4MATLABANDOPENCV_EXPORTS
#define BRIGE4MATLABANDOPENCV_API __declspec(dllexport)
#else
#define BRIGE4MATLABANDOPENCV_API __declspec(dllimport)
#endif


#include "opencv2/opencv.hpp"
#include "mex.h"
#include "dataConverter.h"

namespace mexFunctionCollector {		
	//可能为复数！！！
	class BRIGE4MATLABANDOPENCV_API numericArray {	
	public:
		numericArray();
		numericArray(size_t ndim, const size_t *dims, mxClassID classid, mxComplexity flag);
		cv::vector<int> getDims();
		virtual cv::Mat tocv(int cvType) = 0;
	protected:
		mxArray *  createNumericArray(size_t ndim, const size_t *dims, mxClassID classid, mxComplexity flag);
		const size_t * getDims(const mxArray *pa);
		const size_t getDimNums(const mxArray *pa);
		cv::vector<int> calDims();
		cv::vector<int> dims;
		mxArray * array;
	};

	//double
	class BRIGE4MATLABANDOPENCV_API doubleArray : public numericArray {
	public:
		doubleArray(size_t ndim, const size_t *dims, mxClassID classid, mxComplexity flag);
		virtual cv::Mat tocv(int cvType) = 0;

	};

	//实double
	class BRIGE4MATLABANDOPENCV_API realDoubleArray : public doubleArray {
	public:
		realDoubleArray(size_t ndim, const size_t *dims, mxClassID classid, mxComplexity flag);
		virtual cv::Mat tocv(int cvType);
	private:
		garrettWorkspace::numericConverter converter;
	};
}