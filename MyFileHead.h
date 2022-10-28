#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

class MyFile {
	public:
		MyFile();
		MyFile(char *pFile);//构造函数

	public:
		void setFileAddress(char *pFile);//设置需要打开的文件路径 
		void addUserData(const string msg);
		void addUserData(const double msg);
		int getFileData();         //从文件读取一个 int 型数据
		void displayFileData(void);//展示文件中所有数据
		void deleteFileData(void); //删除文件内的数据

	private:
		void showError();//文件打开错误处理

	private:
		char *pFileAddress_;//用户传入的文件地址
};
