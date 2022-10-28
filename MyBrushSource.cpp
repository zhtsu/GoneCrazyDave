#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "MyBrushHead.h"

using namespace std;

MyBrush::MyBrush() {
	//构造函数
	hOut_ = GetStdHandle(STD_OUTPUT_HANDLE);//实例化句柄 hOut
	COORD pos_ = {0,0};
}

MyBrush::MyBrush(int originX, int originY) {
	//构造函数设置光标起始位置
	pos_.X = originX;
	pos_.Y = originY;
	SetConsoleCursorPosition(hOut_,pos_);
}

void MyBrush::setOriginPosition(int originX, int originY) {
	//设置光标起始位置
	pos_.X = originX;
	pos_.Y = originY;
	SetConsoleCursorPosition(hOut_,pos_);
}

void MyBrush::draw_in_lateral(int originX, int originY, char needDraw, int number, double gapSeconds) {
	//从起始位置在横向方向上输出字符
	setOriginPosition(originX, originY);

	for (int i = 0; i < number; i++) {
		cout << needDraw;
		Sleep(gapSeconds * 1000);
	}
}

void MyBrush::draw_in_vertical(int originX, int originY, char needDraw, int number, double gapSeconds) {
	//垂直方向
	setOriginPosition(originX, originY);

	for (int i = 0; i < number; i++) {
		cout << needDraw;
		originY++;
		setOriginPosition(originX, originY);
		Sleep(gapSeconds * 1000);
	}
}

void MyBrush::draw_in_lateral(int originX, int originY, string needDraw, int number, double gapSeconds) {
	//从起始位置在横向方向上输出字符串
	setOriginPosition(originX, originY);

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < needDraw.length(); j++) {
			cout << *(needDraw.begin() + j);
			Sleep(gapSeconds * 1000);
		}
	}
}

void MyBrush::draw_in_vertical(int originX, int originY, string needDraw, int number, double gapSeconds) {
	//垂直方向
	setOriginPosition(originX, originY);

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < needDraw.length(); j++) {
			cout << *(needDraw.begin() + j);
			originY++;
			setOriginPosition(originX, originY);
			Sleep(gapSeconds * 1000);
		}
	}
}

void MyBrush::earse_in_lateral(int originX, int originY, int number) {
	//横向擦除
	setOriginPosition(originX, originY);

	for (int i = 0; i < number; i++) {
		cout << " ";
		originX++;
		setOriginPosition(originX, originY);
	}
}

void MyBrush::earse_in_vertical(int originX, int originY, int number) {
	//纵向擦除
	for (int i = 0; i < number; i++) {
		cout << " ";
		originY++;
		setOriginPosition(originX, originY);
	}
}

void MyBrush::drawRectangle(int left, int top, int right, int bottom, char needDraw) {
	//通过设置矩形的左上角和右下角绘制矩形边框
	draw_in_lateral(left, top, needDraw, (right - left));
	draw_in_lateral(left, bottom, needDraw, ((right - left) + 1));
	draw_in_vertical(left, top, needDraw, (bottom - top));
	draw_in_vertical(right, top, needDraw, (bottom - top));
}

void MyBrush::earseRectangle(int left, int top, int right, int bottom) {
	//擦除矩形边框
	earse_in_lateral(left, top, ((right - left) + 1));
	earse_in_lateral(left, bottom, ((right - left)));
	earse_in_vertical(left, top, ((bottom - top)));
	earse_in_vertical(right, top, ((bottom - top)));
}

void MyBrush::drawTriangle(int anchorX, int anchorY, char needDraw, int layers) {
	//通过设置位置和三角形的层数绘制三角形 
	setOriginPosition(anchorX, anchorY);
	
	for (int i = 0; i < layers+1; i++) {
		for (int j = layers - i; j > 0; j--) {
			cout << " "; 
		}
		for (int k = 0; k < i; k++) {
			cout << " " << needDraw;
		}
		anchorY++;
		setOriginPosition(anchorX, anchorY);
	}
}

void MyBrush::earseTriangle(int anchorX, int anchorY, int layers) {
	//擦除三角形
	setOriginPosition(anchorX, anchorY);
	
	for (int i = 0; i < layers+1; i++) {
		for (int j = layers - i; j > 0; j--) {
			cout << " "; 
		}
		for (int k = 0; k < i; k++) {
			cout << " " << " ";
		}
		anchorY++;
		setOriginPosition(anchorX, anchorY);
	}
}

int MyBrush::getNowX() {
	//返回当前 X 坐标 
	return pos_.X;
}

int MyBrush::getNowY() {
	//返回当前 Y 坐标 
	return pos_.Y;
}

