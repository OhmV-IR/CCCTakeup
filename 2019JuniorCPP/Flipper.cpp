#include <iostream>

class Grid {
public:
	Grid() : topLeft(1), topRight(2), botLeft(3), botRight(4) {};
	void HorizontalFlip() {
		int buf = topLeft;
		topLeft = topRight;
		topRight = buf;
		buf = botLeft;
		botLeft = botRight;
		botRight = buf;
	}
	void VerticalFlip() {
		int buf = topLeft;
		topLeft = botLeft;
		botLeft = buf;
		buf = topRight;
		topRight = botRight;
		botRight = buf;
	}
	int topLeft = 1;
	int topRight = 2;
	int botLeft = 3;
	int botRight = 4;
	
};

int main() {
	std::string input;
	std::cin >> input;
	Grid grid;
	for (char character : input) {
		if (character == 'V') {
			grid.VerticalFlip();
		}
		else {
			grid.HorizontalFlip();
		}
	}
	std::cout << grid.topLeft << " " << grid.topRight << std::endl;
	std::cout << grid.botLeft << " " << grid.botRight << std::endl;
}