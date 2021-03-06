#include"Shape.h"
#include<cmath>
using namespace Graphics;

class Circle :public Shape {
public:
    Circle() : r(0) {}
    Circle(Point _point, double _r) : p(_point), r(_r) {}
    Circle(const Color _lineColor, Point _point, double _r) : Shape(_lineColor), p(_point), r(_r) {}
    Circle& operator=(const Circle& c);
    Shape* Clone() const;
    void GetEdgePointList(vector<Point>& ptList);
    ~Circle() = default;
private:
    Point p;
    double r;
};