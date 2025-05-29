#include <iostream>
#include <string>
#include <math.h>

int main() {
	std::string thresholdInfectedStr;
	std::string initialInfectedStr;
	std::string growthFactorStr;
	std::cin >> thresholdInfectedStr;
	std::cin >> initialInfectedStr;
	std::cin >> growthFactorStr;
	int thresholdInfected = stoi(thresholdInfectedStr);
	int initialInfected = stoi(initialInfectedStr);
	int growthFactor = stoi(growthFactorStr);
	int day = 1;
	int totalInfected = initialInfected;
	while (totalInfected <= thresholdInfected) {
		totalInfected += initialInfected * pow(growthFactor, day);
		day++;
	}
	std::cout << day - 1 << std::endl;
	return 0;
}