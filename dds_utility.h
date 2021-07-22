#ifndef DDS_UTILITY_H_INCLUDED
#define DDS_UTILITY_H_INCLUDED

#include <dlib/geometry/rectangle.h>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

/**
 *  Calculate eye aspect ratio.
 *  Calculate euclidean distance based eye aspect ratio for one eye and return
 *  the value.
 *  @param eye (Parameter) Point vector argument for left or right eye (x,y) points
 *  @param ear (Return) Eye aspect ratio of respective eye argument.
 */
void calculate_ear(vector<Point>& eye, double* ear);

/**
 *  Convert rectanle variables.
 *  Convert CV rect variable to DLIB rect variable.
 *  @param cv_rect (Parameter) CV library supported rectangle vector.
 *  @param dlib_rect (Return) DLIB library supported rectangle vector.
 *  @param pos (Parameter) CV rect index to be converted to DLIB rect.
 */
void convert_rect_CV2DLIB(vector<Rect>& cv_rect, vector<dlib::rectangle>& dlib_rect, int pos);

#endif // !DDS_UTILITY_H_INCLUDED