#pragma once
#include <opencv2/opencv.hpp>
#include <Windows.h>
#include <winuser.h>

using namespace cv;

struct StateTraining {
    bool screenshotTaken;
    StateTraining() {
        this->screenshotTaken = false;
    }

    BITMAPINFOHEADER createBitmapHeader(int width, int height) {
        BITMAPINFOHEADER bi;
        bi.biSize = sizeof(BITMAPINFOHEADER);
        bi.biWidth = width;
        bi.biHeight = -height;  //this is the line that makes it draw upside down or not
        bi.biPlanes = 1;
        bi.biBitCount = 32;
        bi.biCompression = BI_RGB;
        bi.biSizeImage = 0;
        bi.biXPelsPerMeter = 0;
        bi.biYPelsPerMeter = 0;
        bi.biClrUsed = 0;
        bi.biClrImportant = 0;
        return bi;
    }

    Mat takeScreenshot(HWND hwnd) {
        Mat src;

        // get handles to a device context (DC)
        HDC hwindowDC = GetDC(hwnd);
        HDC hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);
        SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);

        // define scale, height and width
        int scale = 1;
        int screenx = GetSystemMetrics(SM_XVIRTUALSCREEN);
        int screeny = GetSystemMetrics(SM_YVIRTUALSCREEN);
        int width = GetSystemMetrics(SM_CXVIRTUALSCREEN);
        int height = GetSystemMetrics(SM_CYVIRTUALSCREEN);

        // create mat object
        src.create(height, width, CV_8UC4);

        // create a bitmap
        HBITMAP hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
        BITMAPINFOHEADER bi = createBitmapHeader(width, height);

        // use the previously created device context with the bitmap
        SelectObject(hwindowCompatibleDC, hbwindow);

        // copy from the window device context to the bitmap device context
        StretchBlt(hwindowCompatibleDC, 0, 0, width, height, hwindowDC, screenx, screeny, width, height, SRCCOPY);  //change SRCCOPY to NOTSRCCOPY for wacky colors !
        GetDIBits(hwindowCompatibleDC, hbwindow, 0, height, src.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);            //copy from hwindowCompatibleDC to hbwindow

        // avoid memory leak
        DeleteObject(hbwindow);
        DeleteDC(hwindowCompatibleDC);
        ReleaseDC(hwnd, hwindowDC);

        return src;
    }

    void saveImage(Mat src, std::string filename) {
        std::vector<uchar> buf;
        imencode(".png", src, buf);
        imwrite(filename, src);
        buf.clear();
    }


};

