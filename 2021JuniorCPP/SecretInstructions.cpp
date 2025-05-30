#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string lastDirection;
	std::vector<std::string> inputLines;
	while (true) {
		std::string curLine;
		std::cin >> curLine;
		if (curLine == "99999") {
			break;
		}
		inputLines.push_back(curLine);
	}
	for (std::string curLine : inputLines) {
		int digit1 = stoi(std::string(curLine.begin(), curLine.begin() + 1));
		int digit2 = stoi(std::string(curLine.begin() + 1, curLine.begin() + 2));
		int sum = digit1 + digit2;
		if (sum % 2 != 0) {
			std::cout << "left ";
			lastDirection = "left ";
		}
		else if (sum % 2 == 0 && sum != 0) {
			std::cout << "right ";
			lastDirection = "right ";
		}
		else {
			std::cout << lastDirection;
		}
		std::cout << std::string(curLine.begin() + 2, curLine.end()) << std::endl;
	}
}