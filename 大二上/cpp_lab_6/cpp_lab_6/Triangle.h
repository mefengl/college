#include"Shape.h"
using namespace Graphics;

class Triangle :public Shape {
private:
    Point p[3];
public:
    Triangle() = default;
    Triangle(const Point p1, const Point p2, const Point p3);
    Triangle(const Color _lineColor, const Point p1, const Point p2, const Point p3);
    Triangle(const Triangle& t);
    ~Triangle() = default;
    Triangle& operator=(const Triangle& t);
    Shape* Clone() const;
    void GetEdgePointList(vector<Point>& ptList);
};