#include "Canvas.h"
#include "BmpIO.h"
#include <queue>
using namespace Graphics;

Canvas::Canvas() :bgColor(Color::white), width(640), height(480), pixels(nullptr) {
    if (nullptr != pixels) delete[]pixels;
    pixels = nullptr;
    int numPixels = width * height;
    if (numPixels < 1) return;
    pixels = new unsigned char[numPixels * 3];
    for (int j = 0; j < numPixels; j++) {
        pixels[3 * j + 0] = bgColor.r;
        pixels[3 * j + 1] = bgColor.g;
        pixels[3 * j + 2] = bgColor.b;
    }
}
Canvas::Canvas(int _width, int _height, Color _bgColor) :
    width(_width), height(_height), bgColor(_bgColor) {
    if (nullptr != pixels) delete[]pixels;
    pixels = nullptr;
    int numPixels = width * height;
    if (numPixels < 1) return;
    pixels = new unsigned char[numPixels * 3];
    for (int j = 0; j < numPixels; j++) {
        pixels[3 * j + 0] = bgColor.r;
        pixels[3 * j + 1] = bgColor.g;
        pixels[3 * j + 2] = bgColor.b;
    }
}

Canvas::Canvas(const Canvas& c) :
    width(c.width), height(c.height), bgColor(c.bgColor) {
        if (nullptr != pixels) delete[]pixels;
        pixels = nullptr;
        int numPixels = width * height;
        if (numPixels < 1) return;
        pixels = new unsigned char[numPixels * 3];
        for (int j = 0; j < numPixels; j++) {
            pixels[3 * j + 0] = bgColor.r;
            pixels[3 * j + 1] = bgColor.g;
            pixels[3 * j + 2] = bgColor.b;
        }
}

Canvas& Canvas::operator=(const Canvas& c) {
    if (this != &c) {
        width = c.width;
        height = c.height;
        bgColor = c.bgColor;
        if (nullptr != pixels) delete[]pixels;
        pixels = nullptr;
        int numPixels = width * height;
        pixels = new unsigned char[numPixels * 3];
        for (int j = 0; j < numPixels; j++) {
            pixels[3 * j + 0] = c.pixels[3 * j + 0];
            pixels[3 * j + 1] = c.pixels[3 * j + 1];
            pixels[3 * j + 2] = c.pixels[3 * j + 2];
        }
    }
    return *this;
}

void Canvas::RemoveAllShapes() {
    for (auto x : allShapes)delete x;
    allShapes.clear();
}

void Canvas::Draw() {
    vector<Point> ptList;
    for (auto x : allShapes) {
        x->GetEdgePointList(ptList);
        Color c = x->getLineColor();
        for (auto p : ptList) {
            if (p.x >= 0 && p.x < width && p.y>0 && p.y < height) {
                int index = (p.x + p.y * width) * 3;
                pixels[index + 0] = c.r;
                pixels[index + 1] = c.g;
                pixels[index + 2] = c.b;
            }
        }
    }
}

void Canvas::SaveToBitmap(const char* filename) {
    WriteBitmap(pixels, width, height, filename);
}

bool Canvas::checkPixelColor(int x, int y, const Color& color) {
    int index = (x + y * width) * 3;
    return (pixels[index + 0] == color.r) && (pixels[index + 1] == color.g) && (pixels[index + 2] == color.b);
}

bool Canvas::check(Point p, const Color& preColor, const Color& newColor) {
    // Base cases
    if (p.x <= 0 || p.x >= width || p.y <= 0 || p.y >= height) {
        return false;
    }
    else if (!checkPixelColor(p.x, p.y, preColor)) {
        return false;
    }
    else if (checkPixelColor(p.x, p.y, newColor)) {
        return false;
    }
    return true;
}


// BFS
void Canvas::floodFillUtil(int x, int y, const Color& preColor, const Color& newColor)
{
    int to[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
    Point p, t, v;
    p.x = x;
    p.y = y;
    queue<Point> q;
    q.push(p);
    while (!q.empty()) {
        t = q.front();
        for (int i = 0; i < 8; ++i) {
            v = t;
            v.x += to[i][0];
            v.y += to[i][1];
            if (check(v, preColor, newColor)) {
                int index = (v.x + v.y * width) * 3;
                pixels[index + 0] = newColor.r;
                pixels[index + 1] = newColor.g;
                pixels[index + 2] = newColor.b;
                q.push(v);
            }
        }
        q.pop();
    }
}

void Canvas::floodFill(int x, int y, Color newColor){
    int index = (x + y * width) * 3;
    Color preColor;
    preColor.r = pixels[index + 0];
    preColor.g = pixels[index + 1];
    preColor.b = pixels[index + 2];
    floodFillUtil(x, y, preColor, newColor);
}