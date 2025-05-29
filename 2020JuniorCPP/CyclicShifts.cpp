#include <iostream>
#include <cstring>
#include <string>

std::string ShiftCharactersToEnd(std::string text, int startIndex) {
	for (int i = 0; i < startIndex; i++) {
		text += text[i]; // Add current char to end
	}
	text = std::string(text.begin() + startIndex, text.end()); // Strip the characters moved to the end from the start
	return text;
}

bool StrContains(std::string text, std::string substr) {
	return text.find(substr) != std::string::npos;
}

int main() {
	std::string searchText;
	std::string inputStr;
	std::cin >> searchText;
	std::cin >> inputStr;
	if (StrContains(searchText, inputStr)) {
		std::cout << "yes" << std::endl;
		exit(0);
	}
	for (int i = 1; i < inputStr.size(); i++) {
		if (StrContains(searchText, ShiftCharactersToEnd(&inputStr, i))) {
			std::cout << "yes" << std::endl;
			exit(0);
		}
	}
	std::cout << "no" << std::endl;
}