#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string numPeopleStr;
	std::cin >> numPeopleStr;
	int numPeople = stoi(numPeopleStr);
	std::vector<std::string> schedules(numPeople);
	for (int i = 0; i < numPeople; i++) {
		std::string schedule;
		std::cin >> schedule;
		schedules[i] = schedule;
	}
	// iterate over cols
	std::vector<int> numAvailablePpl(schedules[0].size());
	for (int i = 0; i < schedules[0].size(); i++) {
		int numAvailable = 0;
		for (int j = 0; j < schedules.size(); j++) {
			if (schedules[j][i] == 'Y') {
				numAvailable++;
			}
		}
		numAvailablePpl[i] = numAvailable;
	}
	int max = 0;
	for (int numPpl : numAvailablePpl) {
		if (numPpl > max) {
			max = numPpl;
		}
	}
	std::vector<int> maxDays;
	for (int i = 0; i < numAvailablePpl.size(); i++) {
		if (numAvailablePpl[i] == max) {
			maxDays.push_back(i);
		}
	}
	for (int i = 0; i < maxDays.size(); i++) {
		if (i + 1 != maxDays.size()) {
			std::cout << i << ",";
		}
		else {
			std::cout << i << std::endl;
		}
	}
}