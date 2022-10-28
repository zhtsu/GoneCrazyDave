#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

class MyBrush {
	public:
		MyBrush();
		MyBrush(int originX, int originY);

	public:
		//设置光标起始位置
		void setOriginPosition(int originX, int originY);
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
		//返回此时坐标的值
		int getNowX();
		int getNowY(); 

	private:
		HANDLE hOut_;//新建句柄 hOut
		COORD pos_;//存储坐标结构体
};
