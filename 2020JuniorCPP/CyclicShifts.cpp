#include <iostream>
#include <cstring>
#include <string>

static std::string ShiftCharactersToEnd(std::string *textPtr, int startIndex) {
	std::string textCopy(*textPtr);
	for (int i = 0; i < startIndex; i++) {
		textCopy += textCopy[i]; // Add current char to end
	}
	textCopy = std::string(textCopy.begin() + startIndex, textCopy.end()); // Strip the characters moved to the end from the start
	return textCopy;
}

static bool StrContains(std::string text, std::string substr) {
	return text.find(substr) != std::string::npos;
}

int main() {
	std::string originalText;
	std::string inputStr;
	std::cin >> originalText;
	std::cin >> inputStr;
	if (originalText == inputStr) {
		std::cout << "yes" << std::endl;
		exit(0);
	}
	for (int i = 1; i < originalText.size(); i++) {
		if (StrContains(originalText, ShiftCharactersToEnd(&inputStr, i))) {
			std::cout << "yes" << std::endl;
			exit(0);
		}
	}
	std::cout << "no" << std::endl;
	exit(0);
}