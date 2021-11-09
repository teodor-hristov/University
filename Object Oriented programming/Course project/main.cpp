#include <iostream>
#include <fstream>
#include <bitset>
#include "Image/Image.h"
#include "PbmImage/PbmImage.h"

using namespace std;

int main() {
    ofstream out("/home/tedo3637/Desktop/uq1.pbm", ios::trunc | ios::binary | ios::ate);

    char temp[100][150];

    PbmImage pbm(150, 150);

    out << pbm.getImageIdentifier() << "\n" << pbm.getWidth() << " " << pbm.getHeight() << "\n";

    for (int i = 0; i < 150; ++i) {
        for (int j = 0; j < 150; ++j) {
            if (i > 50) {
                pbm.setAt(i, j, '1');
            } else {
                pbm.setAt(i, j, '0');
            }
        }
    }
    char c;
    for (int i = 0; i < 150; ++i) {
        for (int j = 0; j < 150; ++j) {
            c = pbm.getAt(i, j);
            out.write(&c, 1);
        }
    }

    out.close();
    return 0;
}
