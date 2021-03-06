#include"Canvas.h"
#include"Rect.h"
#include"Circle.h"
#include "Triangle.h"
using namespace Graphics;
int main() {
	// 创建画布
	Canvas canvas(420, 300);
	// 创建圆，太阳
	Point point(320, 40);
	Circle circle(Color::red, point, 80);
	// 创建长方形，房体
	Point pointRect(100, 150);
	Rect rect(pointRect, 100, 100);
	// 创建长方形，烟囱
	Point pointChimney(100, 110);
	Rect rectChimney(pointChimney, 15, 30);
	// 创建三角形，屋顶
	Point p1(75, 150), p2(225, 150), p3(150, 100);
	Triangle triangle(Color::brickRed, p1, p2, p3);
	// 将上述形状画上画布
	canvas.Attach(rect);
	canvas.Attach(rectChimney);
	canvas.Attach(circle);
	canvas.Attach(triangle);
	canvas.Draw();
	// 填色
	canvas.floodFill(320, 40, Color::red);
	canvas.floodFill(150, 125, Color::brickRed);
	canvas.floodFill(101, 111, Color::seaGreen);
	canvas.floodFill(101, 139, Color::seaGreen);
	canvas.floodFill(101, 151, Color::sandYellow);
	canvas.floodFill(10, 10, Color::green);
	// 转换为bmp图
	canvas.SaveToBitmap("bg.bmp");
}