#include <iostream>
#include <string>

int main() {
	int spice = 0;
	std::string numPeppersStr;
	std::cin >> numPeppersStr;
	int numPeppers = stoi(numPeppersStr);
	for (int i = 0; i < numPeppers; i++) {
		std::string pepperName;
		std::cin >> pepperName;
		if (pepperName == "Poblano") {
			spice += 1500;
		}
		else if (pepperName == "Mirasol") {
			spice += 6000;
		}
		else if (pepperName == "Serrano") {
			spice += 15500;
		}
		else if (pepperName == "Cayenne") {
			spice += 40000;
		}
		else if (pepperName == "Thai") {
			spice += 75000;
		}
		else {
			spice += 125000;
		}
	}
	std::cout << spice << std::endl;
}