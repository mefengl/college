#include "Rect.h"
Rect& Rect::operator=(const Rect& r) {
    if (this != &r) {
        this->Shape::operator=(r);
        //setLineColor(r.getLineColor());
        p = r.p;
        width = r.width;
        height = r.height;
    }
    return *this;
}
Shape* Rect::Clone() const {
    return new Rect(*this);
}
void Rect::GetEdgePointList(vector<Point>& ptList) {
    ptList.clear();
    for (int i = p.x; i < p.x + width; ++i) {
        ptList.push_back(Point(i, p.y));
        ptList.push_back(Point(i, p.y + height));
    }
    for (int j = p.y; j < p.y + height; ++j) {
        ptList.push_back(Point(p.x, j));
        ptList.push_back(Point(p.x + width, j));
    }
}