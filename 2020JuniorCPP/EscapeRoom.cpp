#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class Factor {
public:
	Factor() : f1(0), f2(0) {};
	Factor(int f1, int f2) : f1(f1), f2(f2) {};
	constexpr bool operator==(const Factor& other) const {
		return f1 + f2 == other.f1 + other.f2;
	}
	int f1;
	int f2;
};

static std::vector<Factor> GetFactorPairs(int num) {
	std::vector<Factor> factors(2);
	// Add the 1 x num factor that's always present
	factors[0] = Factor(1, num);
	factors[1] = Factor(num, 1);
	// Loop excludes 1 and num, see ^
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			factors.push_back(Factor(i, num / i));
		}
	}
	return factors;
}

static bool ExplorePaths(std::vector<std::vector<int>> *grid, int row, int col, int nRows, int nCols) {
	if (row == nRows - 1 && col == nCols - 1) {
		return true;
	}
	std::vector<Factor> factors = GetFactorPairs((*grid)[row][col]);
	for (Factor factor : factors) {
		if (factor.f1 - 1 < nRows && factor.f2 - 1< nCols) {
			if (ExplorePaths(grid, factor.f1 - 1, factor.f2 - 1, nRows, nCols)) {
				return true;
			}
		}
	}
	return false;
}

// TESTED: 
// - Grid initialization works
int main() {
	std::string numRowsStr;
	std::string numColsStr;
	std::cin >> numRowsStr;
	std::cin >> numColsStr;
	int numRows = stoi(numRowsStr);
	int numCols = stoi(numColsStr);
	// grid[row][col]
	std::vector<std::vector<int>> grid;
	for (int i = 0; i < numRows; i++) {
		std::vector<int> row(numCols);
		for (int j = 0; j < numCols; j++) {
			std::string numStr;
			// cin has a funny feature that's actually useful here.
			// it breaks strings at spaces. eg when I type 1 2 3 4 and then enter in console,
			// cin will actually have 4 seperate inputs in its buffer, "1", "2", "3", and "4".
			// we can use this to just directly convert the string to a number without having to worry about processing.
			std::cin >> numStr;
			row[j] = stoi(numStr);
		}
		grid.push_back(row);
	}
	if (ExplorePaths(&grid, 0, 0, numRows, numCols)) {
		std::cout << "yes" << std::endl;
		exit(0);
	}
	std::cout << "no" << std::endl;
}