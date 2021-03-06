#include "Triangle.h"
Triangle::Triangle(const Point p1, const Point p2, const Point p3) {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
}
Triangle::Triangle(const Color _lineColor, const Point p1, const Point p2, const Point p3):Shape(_lineColor) {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
}
Triangle::Triangle(const Triangle& t) :Shape(t) {
    p[0] = t.p[0];
    p[1] = t.p[1];
    p[2] = t.p[2];
};


Triangle& Triangle::operator=(const Triangle& t) {
    if (this != &t) {
        this->Shape::operator=(t);
        //setLineColor(t.getLineColor());
        p[0] = t.p[0];
        p[1] = t.p[1];
        p[2] = t.p[2];
    }
    return *this;
}
Shape* Triangle::Clone() const {
    return new Triangle(*this);
}

void Triangle::GetEdgePointList(vector<Point>& ptList) {
    ptList.clear();
    int j, l, r;
    for (int i = 0; i < 3; i++)
    {
        j = (i + 1) % 3;
        
        if (p[i].x == p[j].x) {
            l = min(p[i].y, p[j].y);
            r = max(p[i].y, p[j].y);
            for (int k = l; k < r; k++)
            {
                ptList.push_back(Point(p[i].x, k));
            }
        }
        else {
            l = min(p[i].x, p[j].x);
            r = max(p[i].x, p[j].x);
            for (int k = l; k < r; k++)
            {
                double slope = 1.0*(p[i].y-p[j].y) / (p[i].x-p[j].x);
                int y = static_cast<int>(p[j].y + slope * (k - p[j].x));
                ptList.push_back(Point(k, y));
            }
            
        }
    }
}