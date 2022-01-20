#include <new>
#include <iostream>
#include "Image.h"

void deleteMatrix(char **matr, size_t height) {
    for (int i = 0; i < height; ++i) {
        delete matr[i];
    }
    delete[] matr;
}

Image::Image(char *imageIdentifier, size_t width, size_t height) : width(width), height(height) {

    setIimageIdentifier(imageIdentifier);

    try {
        this->imageMatrix = new char *[height];

        for (int i = 0; i < height; ++i) {
            this->imageMatrix[i] = new char[width]();
        }
    } catch (const std::bad_alloc &ba) {
        std::cerr << "Allocation of matrix failed!" << std::endl;
        throw ba;
    }

}

Image::Image(char *imageIdentifier, size_t width, size_t height, char **imageMatrix) : Image(imageIdentifier, width,
                                                                                             height) {
    setImageMatrix(imageMatrix, width, height);
}

Image::Image(const Image &other) : Image(other.imageIdentifier, other.width, other.height, other.imageMatrix) {
}

Image &Image::operator=(const Image &other) {
    if (this == &other) {
        return *this;
    }

    try {
        setImageMatrix(other.imageMatrix, other.width, other.height);
    } catch (const std::bad_alloc &ba) {
        std::cerr << ba.what() << std::endl;
        return *this;
    }

    //assign new values
    this->height = other.height;
    this->width = other.width;

    setIimageIdentifier(other.imageIdentifier);

    return *this;
}

Image::~Image() {
    deleteMatrix(this->imageMatrix, this->height);
}

void Image::setIimageIdentifier(char *imageIdentifier) {
    //todo validate
    if (!imageIdentifier) {
        throw std::invalid_argument("Image identifier can't be nullptr!");
    }

    this->imageIdentifier = imageIdentifier;
}

void Image::setImageMatrix(char **imageMatrix, size_t width, size_t height) {
    if (!imageMatrix) {
        throw std::invalid_argument("Image matrix can't be nullptr!");
    }

    if (width == this->width && height == this->height) {
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                this->imageMatrix[i][j] = imageMatrix[i][j];
            }
        }
    } else {
        char **temp;

        temp = new char *[height];
        for (int i = 0; i < height; ++i) {
            temp[i] = new char[width];
        }

        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                temp[i][j] = imageMatrix[i][j];
            }
        }

        deleteMatrix(this->imageMatrix, this->height);

        this->imageMatrix = temp;
    }

}

char *Image::getImageIdentifier() const {
    return this->imageIdentifier;
}

size_t Image::getWidth() const {
    return width;
}

size_t Image::getHeight() const {
    return height;
}

void Image::setAt(size_t x, size_t y, char value) {
    if (x >= this->width || y >= this->height) {
        throw std::invalid_argument("Coordinates are out of bonds");
    }

    this->imageMatrix[y][x] = value;
}

const char Image::getAt(size_t x, size_t y) const {
    if (x >= this->width || y >= this->height) {
        throw std::invalid_argument("Coordinates are out of bonds");
    }

    return this->imageMatrix[y][x];
}