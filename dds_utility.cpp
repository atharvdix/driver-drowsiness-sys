#include "dds_utility.h"

void calculate_ear(vector<Point>& eye, double* ear)
{
    double A, B, C;
    double temp_x[6], temp_y[6];

    for (int i = 0; i < 6; i++)
    {
        temp_x[i] = (double)eye[i].x;
        temp_y[i] = (double)eye[i].y;
    }

    A = (temp_x[5] - temp_x[1]) * (temp_x[5] - temp_x[1]);
    A = sqrt(A + ((temp_y[5] - temp_y[1]) * (temp_y[5] - temp_y[1])));

    B = (temp_x[4] - temp_x[2]) * (temp_x[4] - temp_x[2]);
    B = sqrt(B + ((temp_y[4] - temp_y[2]) * (temp_y[4] - temp_y[2])));

    C = (temp_x[3] - temp_x[0]) * (temp_x[3] - temp_x[0]);
    C = sqrt(C + ((temp_y[3] - temp_y[0]) * (temp_y[3] - temp_y[0])));

    *ear = (A + B) / (2 * C);
}

void convert_rect_CV2DLIB(vector<Rect>& cv_rect, vector<dlib::rectangle>& dlib_rect, int pos)
{
    Rect temp_cv;
    dlib::rectangle temp_dlib;

    temp_cv = cv_rect[pos];
    temp_dlib.set_left((long)temp_cv.x);
    temp_dlib.set_top((long)temp_cv.y);
    temp_dlib.set_right((long)(temp_cv.x + temp_cv.width));
    temp_dlib.set_bottom((long)(temp_cv.y + temp_cv.height));
    dlib_rect.push_back(temp_dlib);
}
