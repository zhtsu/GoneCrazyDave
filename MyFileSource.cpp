#include <fstream>
#include <iostream>
#include <string.h>
#include <Windows.h>

#include "MyFileHead.h" 

using namespace std;

MyFile::MyFile() {}//无参构造函数

MyFile::MyFile(char *FileAddress) {
	//有参构造函数，将用户指定的文件地址赋值给文件指针
	pFileAddress_ = FileAddress;
}

void MyFile::setFileAddress(char *pFile) {
	//无参构造情况下设置需要打开的文件的路径
	pFileAddress_ = pFile;
}

void MyFile::showError() {
	//打开文件错误处理
	MessageBox(NULL, "文件打开失败！", "提示", MB_ICONEXCLAMATION);
	throw false;
}

void MyFile::addUserData(const string msg) {
	//向文件写入字符串 string 类型数据
	ofstream File(this->pFileAddress_, ios::app);

	if (! File.is_open()) {
		showError();

	} else {
		File << msg << endl;
	}

	File.close();
}

void MyFile::addUserData(const double msg) {
	//向文件写入双精度 double 类型数据
	ofstream File(this->pFileAddress_, ios::app);

	if (! File.is_open()) {
		showError();

	} else {
		File << msg << endl;
	}

	File.close();
}

int MyFile::getFileData() {
	//从文件读取一个 int 型数据
	int myData;

	ifstream File(this->pFileAddress_, ios::in);

	if (! File.is_open()) {
		showError();

	} else {
		File >> myData;
	} 

	File.close();
	
	return myData;
} 

void MyFile::displayFileData(void) {
	//展示文件中所有数据
	string myString;

	ifstream File(this->pFileAddress_, ios::in);

	if (! File.is_open()) {
		showError();

	} else {
		while (File >> myString) {
			cout << myString << endl;
		}
	} 

	File.close();
}

void MyFile::deleteFileData(void) {
	//清空文件内的数据
	fstream File(this->pFileAddress_, ios::out);
	File.close();
}

