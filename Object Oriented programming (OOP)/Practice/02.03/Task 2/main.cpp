#include <iostream>
#include <cmath>

using namespace std;

struct Rectangle{
    double width;
    double height;
};

Rectangle createRectangle(double width, double height) {
    Rectangle created;
    created.height = height;
    created.width = width;

    return created;
}

void printRectangle(Rectangle rectangle){
    for(int i = 0; i < rectangle.width; i++) {
        cout << "* ";
    }
    cout << endl;
    for (int i = 0; i < rectangle.height - 2; ++i) {
        cout << "*";
        for(int j = 0; j < rectangle.width; j++) {
            cout << " ";
        }
        cout << "*";
        cout << endl;
    }
    for(int i = 0; i < rectangle.width; i++) {
        cout << "* ";
    }
    cout << endl;
}

double getCircumscribedRadius(Rectangle rect) {
    return sqrt(rect.width*rect.width + rect.height*rect.width)/2;
}

double getArea(Rectangle rect) {
    return rect.width * rect.height;
}

double getPerimeter(Rectangle rect) {
    return 2*rect.height + 2*rect.width;
}

int main() {
    Rectangle rect1;
    rect1 = createRectangle(3,5);
    printRectangle(rect1);

    cout << "Area: " << getArea(rect1) << endl;
    cout << "Perimeter: " << getPerimeter(rect1) << endl;
    cout << "Radius: " << getCircumscribedRadius(rect1) << endl;
}
