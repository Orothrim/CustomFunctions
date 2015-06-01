#ifndef _excludecolour_included_h_
#define _excludecolour_included_h_
#define WHITE 255
#define BLUE 0
#define GREEN 1
#define RED 2

#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include "ExcludeColour.c"

void excludeColour(Mat image, Mat maskImage, int colour, int display = 0, int position = 1);

#endif
