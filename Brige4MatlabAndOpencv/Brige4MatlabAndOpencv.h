// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 BRIGE4MATLABANDOPENCV_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// BRIGE4MATLABANDOPENCV_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef BRIGE4MATLABANDOPENCV_EXPORTS
#define BRIGE4MATLABANDOPENCV_API __declspec(dllexport)
#else
#define BRIGE4MATLABANDOPENCV_API __declspec(dllimport)
#endif
#include "dataConverter.h"
#include "mexFunctionCollector.h"
// 此类是从 Brige4MatlabAndOpencv.dll 导出的
class BRIGE4MATLABANDOPENCV_API CBrige4MatlabAndOpencv {
public:
	CBrige4MatlabAndOpencv(void);
	// TODO:  在此添加您的方法。
};


extern BRIGE4MATLABANDOPENCV_API int nBrige4MatlabAndOpencv;

BRIGE4MATLABANDOPENCV_API int fnBrige4MatlabAndOpencv(void);
