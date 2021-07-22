#include "drowsiness_detection_sys.h"

drowsiness_detection::drowsiness_detection(void)
{
    camera.open(0);
    if (!camera.isOpened())
    {
        cerr << "Error.....Unable to open camera." << endl;
        exit(0);
    }

    String face_cascade = samples::findFile("C:/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml");
    if (!face_detect.load(face_cascade))
    {
        cout << "Error loading face cascade" << endl;
        exit(0);
    };

    try
    {
        dlib::deserialize("C:/Assignment/ECE612_Project/shape_predictor_68_face_landmarks.dat/shape_predictor_68_face_landmarks.dat") >> face_landmarks;
    }
    catch (dlib::serialization_error & e)
    {
        cout << "Error loading shape predictor" << endl << e.what() << endl;
    }
    catch (exception & e)
    {
        cout << e.what() << endl;
    }

    cout << "Starting system...." << endl
        << "Press any key to terminate." << endl;
}

void drowsiness_detection::cam_read_frame(void)
{
    camera.read(frame);
    if (frame.empty())
        cerr << "Empty frame read." << endl;

    frame_clone = frame.clone();

    cvtColor(frame, frame, COLOR_RGB2GRAY);
}

void drowsiness_detection::dds_loop(void)
{
    while (true)
    {
        cam_read_frame();
        process_image();

        if (face_not_detected)
        {
            cout << "Error...Face not detected" << endl;
        }
        else
        {
            detect_event();
        }

        imshow("Camera View", frame_clone);

        if (waitKey(30) >= 0)
            break;
    }
}

void drowsiness_detection::process_image(void)
{
    vector<Rect> face_cv;
    vector<dlib::rectangle> face_dlib;
    vector<Point> left_eye;
    vector<Point> right_eye;

    dlib::cv_image<dlib::rgb_pixel> img(frame_clone);

    equalizeHist(frame, frame);                             //Equalize the image for clear face detection
    face_detect.detectMultiScale(frame, face_cv);           //Detect face in the gray frame

    /*
     *  Fail safe in case face is not detected.
     */
    if (face_cv.empty())
    {
        face_not_detected = true;
        return;
    }
    else
    {
        face_not_detected = false;
        rectangle(frame_clone, face_cv[0], (0, 255, 0));
    }

    convert_rect_CV2DLIB(face_cv, face_dlib, 0);

    dlib::full_object_detection shape = face_landmarks(img, face_dlib[0]);    //Predict the face landmarks in the detected face

    /*
     *  Loop to extract the eye landmarks (x,y) coordinates
     */
    for (unsigned long k = 36; k < 48; k++)
    {
        temp_xy_dlib = shape.part(k);
        temp_xy_cv.x = temp_xy_dlib.x();
        temp_xy_cv.y = temp_xy_dlib.y();

        if (k < 42)
        {
            right_eye.push_back(temp_xy_cv);
        }
        else
        {
            left_eye.push_back(temp_xy_cv);
        }
    }

    calculate_ear(left_eye, &earL);
    calculate_ear(right_eye, &earR);

    ear = (earL + earR) / 2;
}

void drowsiness_detection::detect_event(void)
{
    if (ear < EAR_TH)
    {
        counter++;
        if (counter > COUNT_TH)
        {
            eventcount++;
            cout << "Event triggered. Event Count : " << eventcount << endl;
        }
    }
    else
    {
        counter = 0;
    }
}