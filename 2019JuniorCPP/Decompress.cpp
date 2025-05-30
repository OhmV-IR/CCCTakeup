#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
	std::string numLinesStr;
	std::cin >> numLinesStr;
	int numLines = stoi(numLinesStr);
	for (int i = 0; i < numLines; i++) {
		std::string numRepeatsStr;
		std::cin >> numRepeatsStr;
		int numRepeats = stoi(numRepeatsStr);
		std::string characterToRepeat;
		std::cin >> characterToRepeat;
		for (int j = 0; j < numRepeats; j++) {
			std::cout << characterToRepeat;
		}
		std::cout << std::endl;
	}
}