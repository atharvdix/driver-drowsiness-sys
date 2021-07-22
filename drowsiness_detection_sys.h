#ifndef DROWSINESS_DETECTION_SYS_H_INCLUDED
#define DROWSINESS_DETECTION_SYS_H_INCLUDED

#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include <dlib/image_processing.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/opencv/cv_image.h>

#include "dds_utility.h"

using namespace std;
using namespace cv;

/**
 *   Drowsiness detection class. Class defined to process camera image and detect event by calculating eye aspect ratio.
 */
class drowsiness_detection
{
private:
    Mat frame, frame_clone;
    VideoCapture camera;        /**< CV camera object*/

    const double EAR_TH = 0.24; /**< Eye aspect ratio threshold value.*/
    const int COUNT_TH = 10;   /**< Event trigger threshold for counter.*/
    int counter = 0;
    int eventcount = 0;
    double earL, earR, ear;
    bool face_not_detected;     /**< Fail safe check if face not detected*/

    dlib::point temp_xy_dlib;   /**< Temporary DLIB variable to store (x,y) point.*/
    Point temp_xy_cv;           /**< Temporary CV variable to store (x,y) point.*/

    CascadeClassifier face_detect;  /**< Face detection object.*/
    dlib::shape_predictor face_landmarks; /**< Face landmark object.*/
public:
    /**
     *  Constructor.
     *  Initialize the camera object, face detection object and face landmark object respectively.
     */
    drowsiness_detection(void);

    /**
     *  Read frame.
     *  Read a single image frame per function call, generate a clone frame and a gray image.
     */
    void cam_read_frame(void);

    /**
     *  System loop.
     *  Main system loop which combines all member functions.
     */
    void dds_loop(void);

    /**
     *  Event trigger.
     *  Trigger an event when drowsiness detected and increment event count.
     */
    void detect_event(void);

    /**
     *  Image processing.
     *  Perform face detection on gray image then create face landmark map
     *  followed by calcuation of average eye aspect ratio of left and right eye.
     */
    void process_image(void);
};

#endif // !DROWSINESS_DETECTION_SYS