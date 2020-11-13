#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::min;
using std::abs;

int main()
{
	double aX, aY, bX, bY, cX, cY,
			a1X, a1Y, b1X, b1Y, c1X, c1Y,
			firstHeight, firstWidth, secondHeight, secondWidth,
			intersectionWidth, intersectionHeight, intersectionArea;

	cin >> aX >> aY >> firstWidth >> firstHeight;
	cin >> a1X >> a1Y >> secondWidth >> secondHeight;

	//points from first rectangle

	bX = aX + firstWidth;
	bY = aY;
	cX = aX + firstWidth;
	cY = aY + firstHeight;

	//points from second rectangle

	b1X = a1X + secondWidth;
	b1Y = a1Y;
	c1X = a1X + secondWidth;
	c1Y = a1Y + secondHeight;

	intersectionWidth = (min(bX, b1X) - max(aX, a1X));
	intersectionHeight = (max(bY, b1Y) - min(cY, c1Y));

	intersectionArea = abs(intersectionHeight * intersectionWidth);
	
	cout << intersectionArea << endl;

	return 0;
}

