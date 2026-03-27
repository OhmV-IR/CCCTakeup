#include <iostream>
#include <string>
#include <map>

int main() {
	std::string numLinesStr;
	std::cin >> numLinesStr;
	int numLines = stoi(numLinesStr);
	for (int i = 0; i < numLines; i++) {
		std::string curLine;
		std::cin >> curLine;
		char currentCharacter = curLine[0];
		int numConsecutive = 0;
		for (char character : curLine) {
			if (character != currentCharacter) {
				std::cout << numConsecutive << " " << currentCharacter << " ";
				currentCharacter = character;
				numConsecutive = 0;
			}
			numConsecutive++;
		}
		std::cout << numConsecutive << " " << currentCharacter << std::endl;
	}
}