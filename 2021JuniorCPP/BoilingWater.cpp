#include <iostream>
#include <string>

int main() {
	std::string boilingTempStr;
	std::cin >> boilingTempStr;
	int boilingTemp = stoi(boilingTempStr);
	int atmPressure = 5 * boilingTemp - 400;
	std::cout << atmPressure << std::endl;
	if (atmPressure < 100) {
		std::cout << "1" << std::endl;
	}
	else if (atmPressure == 100) {
		std::cout << "0" << std::endl;
	}
	else {
		std::cout << "-1" << std::endl;
	}
	return 0;
}