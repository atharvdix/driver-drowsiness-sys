// ECE612_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "drowsiness_detection_sys.h"

int main(int, char**)
{
    drowsiness_detection detect;
    detect.dds_loop();
    return 0;
}