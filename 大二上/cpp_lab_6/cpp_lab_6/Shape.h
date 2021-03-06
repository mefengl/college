#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <vector>
using namespace std;
namespace Graphics {
    class Point {
    public:
        int x, y;
    public:
        Point() :x(0), y(0) {}
        Point(int _x, int _y) :x(_x), y(_y) {}
        double DistanceTo(const Point p);
        Point& operator=(const Point& p) {
            if (this != &p) {
                x = p.x;
                y = p.y;
            }
            return *this;
        };
    };

    class Color {
    public:
        unsigned char r, g, b;
        static Color red, green, blue, white, black, brickRed,
            seaGreen, sandYellow;
    public:
        Color() :r(255), g(255), b(255) {}
        Color(unsigned char _r, unsigned char _g, unsigned char _b) :
            r(_r), g(_g), b(_b) {}
        Color(const Color& clr){
            r = clr.r;
            g = clr.g;
            b = clr.b;
        };
        friend bool operator==(const Color& c1, const Color& c2);
    };


    class Shape {
    private:
        Color lineColor;
    public:
        Shape() :lineColor(Color::black) {}
        Shape(const Color _lineColor) : lineColor(_lineColor) {}
        Shape(const Shape& s) :lineColor(s.lineColor) {}
        Shape& operator=(const Shape& shape);
        void setLineColor(const Color _lineColor) { lineColor = _lineColor; };
        Color getLineColor() const { return lineColor; }
        virtual void GetEdgePointList(vector<Point>& ptList) = 0;
        virtual Shape* Clone() const = 0;
        virtual ~Shape() {};
    };
}
#endif
