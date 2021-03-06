#include"Shape.h"
using namespace Graphics;

class Rect :public Shape {
private:
    Point p;
    int width, height;
public:
    Rect() :p(Point()), width(1), height(1) {}
    Rect(const Point& position, const int _width, const int _height) :
        p(position), width(_width), height(_height) {}
    Rect(const Color _lineColor, const Point& position,
        const int _width, const int _height) :
        Shape(_lineColor), p(position), width(_width), height(_height) {}
    Rect(const Rect& r) :Shape(r), p(r.p), width(r.width), height(r.height) {}
    Rect& operator=(const Rect& r);
    Shape* Clone() const;
    void GetEdgePointList(vector<Point>& ptList);
    ~Rect() {}
};