#ifndef HW5_POINT_H
#define HW5_POINT_H
class Point
{
public:
	Point() : x(0), y(0) {

	}
	Point(double _x, double _y) : x(_x), y(_y) {

	}
	
private:
	double x;
	double y;
};
#endif
