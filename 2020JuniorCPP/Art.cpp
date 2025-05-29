#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class Point2d {
public:
	Point2d() : x(0), y(0) {};
	Point2d(int x, int y) : x(x), y(y) {};
	int x;
	int y;
};

Point2d GetCoordsFromStr(const std::string& string) {
	std::stringstream sstream;
	int x;
	int y;
	for (char character : string) {
		if (character == ',') {
			sstream >> x;
			sstream = std::stringstream();
			continue;
		}
		sstream << character;
	}
	sstream >> y;
	return Point2d(x, y);
}

int main() {
	std::string numDropsPaintStr;
	std::cin >> numDropsPaintStr;
	int numDropsPaint = stoi(numDropsPaintStr);
	// Allocs enough size in vector for all the drops
	// It's faster than doing .add every time which has to resize the vector, which is an increasingly expensive op
	std::vector<Point2d> paintDrops(numDropsPaint);
	for (int i = 0; i < numDropsPaint; i++) {
		std::string curCoordinatesStr;
		std::cin >> curCoordinatesStr;
		paintDrops[i] = GetCoordsFromStr(curCoordinatesStr);
	}
	// Sorts by a predicate(a lambda func that returnst true or false)
	std::sort(paintDrops.begin(), paintDrops.end(), [](const Point2d &a, const Point2d &b) {
		return a.x < b.x;
		});
	int lowx = paintDrops[0].x;
	int highx = paintDrops[paintDrops.size() - 1].x;
	std::sort(paintDrops.begin(), paintDrops.end(), [](const Point2d &a, const Point2d &b) {
		return a.y < b.y;
		});
	int lowy = paintDrops[0].y;
	int highy = paintDrops[paintDrops.size() - 1].y;
	std::cout << lowx - 1 << "," << lowy - 1<< std::endl;
	std::cout << highx + 1 << "," << highy + 1 << std::endl;
	return 0;
}