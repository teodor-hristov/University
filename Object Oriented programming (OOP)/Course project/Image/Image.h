#ifndef COURSE_PROJECT_IMAGE_H
#define COURSE_PROJECT_IMAGE_H

#include <cstddef>
#include <cstdint>

class Image {
private:
    char *imageIdentifier;
    size_t width;
    size_t height;
    char **imageMatrix;

    void setIimageIdentifier(char imageIdentifier[2]);

    void setImageMatrix(char **imageMatrix, size_t width, size_t height);

public:
    Image() = delete;

    Image(char *imageIdentifier, size_t width, size_t height);

    Image(char *imageIdentifier, size_t width, size_t height, char **imageMatrix);

    Image(const Image &other);

    Image &operator=(const Image &other);

    virtual ~Image();

    char *getImageIdentifier() const;

    size_t getWidth() const;

    size_t getHeight() const;

    void setAt(size_t x, size_t y, char value);

    const char getAt(size_t x, size_t y) const;

    //virtual void resize(size_t newWidth, size_t newHeight) = 0;

    //virtual Image readImage(std::string filePath) = 0;

    //virtual void writeImage(std::string filePath) = 0;
};

#endif //COURSE_PROJECT_IMAGE_H
