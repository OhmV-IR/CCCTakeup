#include <iostream>
#include <string>
#include <unordered_map>

int main() {
	std::unordered_map<std::string, std::string> matches;
	for (int i = 0; i < 3; i++) {
		std::string match;
		std::string replace;
		std::cin >> match;
		std::cin >> replace;
		matches[match] = replace;
	}
	std::string curText;
	std::string finalText;
	std::string numStepsStr;
	std::cin >> numStepsStr;
	int numStepsNeeded = stoi(numStepsStr);
	std::cin >> curText;
	std::cin >> finalText;
	int numSubs = 0;
	while (numSubs <= numStepsNeeded) {
		int i = 0;
		for (std::pair<std::string, std::string> entry : matches) {
			size_t pos = curText.find(entry.first);
			if (pos != std::string::npos) {
				curText.replace(pos, entry.first.length(), entry.second);
				std::cout << i + 1 << " " << pos + 1 << " " << curText << std::endl;
				numSubs++;
			}
			i++;
		}
	}
}