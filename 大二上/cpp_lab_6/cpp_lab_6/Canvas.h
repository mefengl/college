#ifndef _CANVAS_H_
#define _CANVAS_H_
#include "Shape.h"
#include <vector>

using namespace std;
namespace Graphics {

    class Canvas {
    private:
        int width, height;
        Color bgColor;
        vector<Shape*> allShapes;
        unsigned char* pixels;
    private:
        void ConvertToBitmap();
        void RemoveAllShapes();
        bool checkPixelColor(int x, int y, const Color& Color);
        bool check(Point p, const Color& preColor, const Color& newColor);
        void floodFillUtil(int x, int y, const Color& preColor, const Color& newColor);
    public:
        Canvas();
        Canvas(int x, int y, const Color& preColor, const Color& newColor);
        Canvas(int _width, int _height, Color _bgColor = Color::white);
        Canvas(const Canvas& c);
        Canvas& operator=(const Canvas& c);

        ~Canvas() {
            delete[]pixels;
            RemoveAllShapes();
        }
        void Attach(const Shape& s) {
            allShapes.push_back(s.Clone());
        }
        void Draw();
        void ReDraw() {}
        void SaveToBitmap(const char* filename);

        

        void floodFill(int x, int y, Color newColor);
    };
}
#endif
