#include "Circle.h"

Circle& Circle::operator=(const Circle& c) {
    if (this != &c) {
        this->Shape::operator=(c);
        //setLineColor(c.getLineColor());
        p = c.p;
        r = c.r;
    }
    return *this;
}
Shape* Circle::Clone() const { return new Circle(*this); }
void Circle::GetEdgePointList(vector<Point>& ptList) {
    ptList.clear();
    if (r <= 0)return;
    double delta = std::fmax(1 / r, 1e-5);
    static const double two_pi = 3.1415926 * 2;
    for (double t = 0; t < two_pi; t += delta) {
        int x = static_cast<int>(r * cos(t) + p.x);
        int y = static_cast<int>(r * sin(t) + p.y);
        ptList.push_back(Point(x, y));
    }
}