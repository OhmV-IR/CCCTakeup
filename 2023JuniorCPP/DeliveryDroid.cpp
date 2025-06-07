#include <iostream>
#include <string>

int main() {
	std::string numPackagesDeliveredStr;
	std::string numCollisionsStr;
	std::cin >> numPackagesDeliveredStr;
	std::cin >> numCollisionsStr;
	int numPackagesDelivered = stoi(numPackagesDeliveredStr);
	int numCollisions = stoi(numCollisionsStr);
	int score = 50 * numPackagesDelivered - 10 * numCollisions;
	if (numPackagesDelivered > numCollisions) {
		score += 500;
	}
	std::cout << score << std::endl;
}