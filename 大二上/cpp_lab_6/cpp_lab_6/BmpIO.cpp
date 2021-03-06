#include "BmpIO.h"
#include <cstdio>
//把一幅24位彩色位图图像的像素序列保存为一个bmp位图文件
//这是一个简单的未经严格测试的代码，也没有注释，凑合用一下。
//王文中
//Jan-1st-2020

void Int2Byte(BYTE& w, int v) {
    w = v & 0xff;
}
void Int2Word(WORD w, int v) {
    w[0] = v & 0xff;
    w[1] = (v >> 8) & 0xff;
}

void Int2DWord(DWORD w, int v) {
    w[0] = v & 0xff;
    w[1] = (v >> 8) & 0xff;
    w[2] = (v >> 16) & 0xff;
    w[3] = (v >> 24) & 0xff;
}
void Int2Long(LONG w, int v) {
    w[0] = v & 0xff;
    w[1] = (v >> 8) & 0xff;
    w[2] = (v >> 16) & 0xff;
    w[3] = (v >> 24) & 0xff;
}
bool WriteBitmap(unsigned char* pixels, int width, int height, const char* filename) {
    if (0 == pixels) return false;
    FILE* fp = 0;
    fopen_s(&fp, filename, "wb");
    if (0 == fp) return false;

    BITMAPINFO* pbmi = 0;
    int stride = width * 3;
    unsigned char* pbmi_data = new  unsigned char[sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD)];
    pbmi = reinterpret_cast<BITMAPINFO*>(pbmi_data);
    if (stride % 4 != 0) stride = stride + 4 - stride % 4;

    Int2Word(pbmi->bmiHeader.biBitCount, 24);
    Int2DWord(pbmi->bmiHeader.biClrImportant, 0);
    Int2DWord(pbmi->bmiHeader.biClrUsed, 0);
    Int2DWord(pbmi->bmiHeader.biCompression, 0);
    Int2DWord(pbmi->bmiHeader.biHeight, -height);
    Int2Word(pbmi->bmiHeader.biPlanes, 1);
    Int2DWord(pbmi->bmiHeader.biSize, sizeof(BITMAPINFOHEADER));
    Int2DWord(pbmi->bmiHeader.biSizeImage, height * stride);
    Int2DWord(pbmi->bmiHeader.biWidth, width);
    Int2DWord(pbmi->bmiHeader.biXPelsPerMeter, 96);
    Int2DWord(pbmi->bmiHeader.biYPelsPerMeter, 96);

    for (int i = 0; i < 256; i++)
    {
        pbmi->bmiColors[i].rgbBlue = (BYTE)i;
        pbmi->bmiColors[i].rgbGreen = (BYTE)i;
        pbmi->bmiColors[i].rgbRed = (BYTE)i;
        pbmi->bmiColors[i].rgbReserved = 0xFF;
    }

    BITMAPFILEHEADER bmfh;
    Int2Word(bmfh.bfType, 0x4D42);
    Int2Word(bmfh.bfReserved1, 0);
    Int2Word(bmfh.bfReserved2, 0);
    Int2DWord(bmfh.bfSize, sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD) + height * stride);
    Int2DWord(bmfh.bfOffBits, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD));

    fwrite(&bmfh, sizeof(bmfh), 1, fp);
    fwrite(pbmi_data, sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD), 1, fp);

    unsigned char* pdata = new unsigned char[stride];
    for (int col = 0; col < stride; ++col) pdata[col] = 0x00;
    for (int row = 0; row < height; row++)
    {
        unsigned char* prow = pixels + row * width * 3;
        for (int j = 0; j < width * 3; ++j)
            pdata[j] = prow[j];
        fwrite(pdata, stride, 1, fp);
    }

    fclose(fp);
    delete[]pbmi_data;
    return true;
}