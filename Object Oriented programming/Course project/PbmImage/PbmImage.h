#ifndef COURSE_PROJECT_PBMIMAGE_H
#define COURSE_PROJECT_PBMIMAGE_H
#pragma once
#include "../Image/Image.h"

class PbmImage : public Image{
public:
    PbmImage(size_t width, size_t height);

    PbmImage(size_t width, size_t height, char** imageMatrix);
};

#endif //COURSE_PROJECT_PBMIMAGE_H
