#include <iostream>
#include <string>

int main()
{
	std::string numSmallTreatsStr;
	std::string numMediumTreatsStr;
	std::string numLargeTreatsStr;
	std::cin >> numSmallTreatsStr;
	std::cin >> numMediumTreatsStr;
	std::cin >> numLargeTreatsStr;
	int numSmallTreats = stoi(numSmallTreatsStr);
	int numMediumTreats = stoi(numMediumTreatsStr);
	int numLargeTreats = stoi(numLargeTreatsStr);
	int happiness = 1 * numSmallTreats + 2 * numMediumTreats + 3 * numLargeTreats;
	if (happiness >= 10) {
		std::cout << "happy" << std::endl;
	}
	else {
		std::cout << "sad" << std::endl;
	}
	return 0;
}
