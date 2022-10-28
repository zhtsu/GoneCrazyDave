#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

class MyBrush {
	public:
		MyBrush();

	public:
		//在起始位置横向方向上按要求输出字符或字符串。可设置输出次数和单个字符输出的间隔时间（秒数）
		void draw_in_lateral(int originX, int originY, char needDraw, int number = 1, double gapSeconds = 0);
		void draw_in_lateral(int originX, int originY, string needDraw, int number = 1, double gapSeconds = 0);
		//垂直方向
		void draw_in_vertical(int originX, int originY, char needDraw, int number = 1, double gapSeconds = 0);
		void draw_in_vertical(int originX, int originY, string needDraw, int number = 1, double gapSeconds = 0);
		//在起始位置横向方向擦除指定数量的字符串
		void earse_in_lateral(int originX, int originY, int number = 1);
		//垂直方向
		void earse_in_vertical(int originX, int originY, int number = 1);
		//在限定范围内使用一个字符绘制矩形边框
		void drawRectangle(int left, int top, int right, int bottom, char needDraw);
		//擦除矩形边框
		void earseRectangle(int left, int top, int right, int bottom);
		//在指定位置使用一个字符绘制一个三角形
		//该三角形的锚点为以该三角形的底边为长，高为宽的矩形的左上角。 
		void drawTriangle(int anchorX, int anchorY, char needDraw, int layers);
		//擦除三角形
		void earseTriangle(int anchorX, int anchorY, int layers);

	private:
		void setOriginPosition(int originX, int originY);//设置光标起始位置

	private:
		HANDLE hOut_;//新建句柄 hOut
		COORD pos_;//存储坐标结构体
};

MyBrush::MyBrush() {
	//构造函数
	hOut_=GetStdHandle(STD_OUTPUT_HANDLE);//实例化句柄 hOut
	COORD pos_= {0,0};
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

int main() {
	system("mode con cols=75 lines=25");

	MyBrush one;
	
	one.draw_in_lateral(30, 10, "开始测试", 1, 1);
	one.earse_in_lateral(30, 10, 4);
	one.drawRectangle(0, 0, 74 , 24, '@');
	one.earseRectangle(0, 0, 74 , 24);
	one.drawTriangle(10, 10, '*', 9);
	one.earseTriangle(10, 10, 9);
	one.draw_in_lateral(30, 10, "测试完成");
	
	while (!getch()) {

	}

	return 0;
}
