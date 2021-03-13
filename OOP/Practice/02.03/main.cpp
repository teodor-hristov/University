#include <iostream>
#include <cmath>

using namespace std;

struct Vector{
private:
    double xAxis;
    double yAxis;
    double zAxis;
public:
    double getXAxis() {
        return this->xAxis;
    }
    double getYAxis() {
        return this->yAxis;
    }
    double getZAxis() {
        return this->zAxis;
    }
    void setXAxis(double value){
        this->xAxis = value;
    }
    void setYAxis(double value){
        this->yAxis = value;
    }
    void setZAxis(double value){
        this->zAxis = value;
    }

};

void printVector(Vector vect) {
    cout << "X:" << vect.getXAxis()<< " Y: "<< vect.getYAxis() << " Z: " << vect.getZAxis() << endl;
}

double getVectorLength(Vector &vect) {
    return sqrt(vect.getZAxis()*vect.getZAxis() +
                        vect.getYAxis()*vect.getYAxis() +
                        vect.getXAxis()*vect.getXAxis());
}

Vector vectorSum(Vector &a, Vector &b) {
    Vector result;
    result.setXAxis(a.getXAxis()+b.getXAxis());
    result.setYAxis(a.getYAxis()+b.getYAxis());
    result.setZAxis(a.getZAxis()+b.getZAxis());
    return result;
}

void multiplicationWithScalar(Vector &vect, double num) {
    vect.setXAxis(vect.getXAxis()*num);
    vect.setYAxis(vect.getYAxis()*num);
    vect.setZAxis(vect.getZAxis()*num);
}

void normalization(Vector &vect) {
    vect.setXAxis(vect.getXAxis()/getVectorLength(vect));
    vect.setYAxis(vect.getYAxis()/getVectorLength(vect));
    vect.setZAxis(vect.getZAxis()/getVectorLength(vect));
}

int main() {
    Vector e1;
    e1.setXAxis(3.4);
    e1.setYAxis(1.01);
    e1.setZAxis(5.1);

    Vector e2;
    e2.setXAxis(78.02);
    e2.setYAxis(54.1);
    e2.setZAxis(6.09);
    printVector(e1);
    cout << "Len: " << getVectorLength(e1) << endl;

    cout << "e1 + e2: " << endl;
    printVector(vectorSum(e1,e2));

    normalization(e1);
    printVector(e1);
    cout << "e1 len: " << getVectorLength(e1) << endl;

    cout << "e2: " << endl;
    printVector(e2);
    multiplicationWithScalar(e2,2);
    printVector(e2);
}
