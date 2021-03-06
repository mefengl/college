#include "Shape.h"
using namespace Graphics;

Color Color::blue(255, 0, 0);
Color Color::green(0, 255, 0);
Color Color::red(0, 0, 255);
Color Color::white(255, 255, 255);
Color Color::black(0, 0, 0); 
Color Color::brickRed(31, 102, 156);
Color Color::seaGreen(140, 240, 250);
Color Color::sandYellow(150, 150, 150);

bool operator==(const Color& c1, const Color& c2) {
    return (c1.r == c2.r) && (c1.g == c2.g) && (c1.b == c2.b);
}

Shape& Shape::operator=(const Shape& shape) {
	if (this != &shape)
	{
		lineColor = shape.lineColor;
	}
	return *this;
};

double Point::DistanceTo(const Point p) {
    return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
}

