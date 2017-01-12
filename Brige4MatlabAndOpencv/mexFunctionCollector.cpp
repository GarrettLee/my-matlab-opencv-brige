#include "stdafx.h"

#include "mexFunctionCollector.h"
mexFunctionCollector::numericArray::numericArray()
{
}

mexFunctionCollector::numericArray::numericArray(size_t ndim, const size_t * idims, mxClassID classid, mxComplexity flag)
{
	array = createNumericArray( ndim, idims,  classid,  flag);
	dims = this->calDims();
	
}

cv::vector<int> mexFunctionCollector::numericArray::getDims()
{
	return this->dims;
}

mexFunctionCollector::realDoubleArray::realDoubleArray(size_t ndim, const size_t * dims, mxClassID classid, mxComplexity flag) : doubleArray( ndim,   dims,  classid,  flag)
{
}

cv::Mat mexFunctionCollector::realDoubleArray::tocv(int cvType)
{
	return this->converter.mx2cv(this->array, cvType);
}

cv::vector<int> mexFunctionCollector::numericArray::calDims()
{
	cv::vector<int> dims;
	const size_t * dim = mxGetDimensions(array);
	const size_t num = mxGetNumberOfDimensions(array);
	for (int i = 0; i < num; i++){
		dims.push_back(dim[i]);
	}
	return dims;
}

mxArray * mexFunctionCollector::numericArray::createNumericArray(size_t ndim, const size_t * dims, mxClassID classid, mxComplexity flag)
{
	return mxCreateNumericArray( ndim,   dims,  classid,  flag);
}

const size_t * mexFunctionCollector::numericArray::getDims(const mxArray * pa)
{
	return mxGetDimensions(pa);
}

const size_t mexFunctionCollector::numericArray::getDimNums(const mxArray * pa)
{
	return mxGetNumberOfDimensions(pa);
}

mexFunctionCollector::doubleArray::doubleArray(size_t ndim, const size_t * dims, mxClassID classid, mxComplexity flag):numericArray( ndim,  dims,  classid,  flag)
{
}
