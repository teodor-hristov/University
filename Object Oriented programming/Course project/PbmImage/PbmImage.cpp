#include "PbmImage.h"

PbmImage::PbmImage(size_t width, size_t height) : Image("P1", width, height){
}

PbmImage::PbmImage(size_t width, size_t height, char **imageMatrix) : Image("P1", width, height, imageMatrix) {
}
