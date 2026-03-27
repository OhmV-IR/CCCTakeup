#include <iostream>
#include <string>

int main() {
	std::string threePtAppleStr;
	std::string twoPtAppleStr;
	std::string onePtAppleStr;
	std::string threePtBananasStr;
	std::string twoPtBananasStr;
	std::string onePtBananasStr;
	std::cin >> threePtAppleStr;
	std::cin >> twoPtAppleStr;
	std::cin >> onePtAppleStr;
	std::cin >> threePtBananasStr;
	std::cin >> twoPtBananasStr;
	std::cin >> onePtBananasStr;
	int threePtApple = stoi(threePtAppleStr);
	int twoPtApple = stoi(twoPtAppleStr);
	int onePtApple = stoi(onePtAppleStr);
	int threePtBananas = stoi(threePtBananasStr);
	int twoPtBananas = stoi(twoPtBananasStr);
	int onePtBananas = stoi(onePtBananasStr);
	int apple = 3 * threePtApple + 2 * twoPtApple + 1 * onePtApple;
	int bananas = 3 * threePtBananas + 2 * twoPtBananas + 1 * onePtBananas;
	if (apple > bananas) {
		std::cout << "A" << std::endl;
	}
	else if (apple < bananas) {
		std::cout << "B" << std::endl;
	}
	else {
		std::cout << "T" << std::endl;
	}
};