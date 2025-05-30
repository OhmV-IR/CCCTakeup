#include <iostream>
#include <string>

int main() {
	std::string numBidsStr;
	std::cin >> numBidsStr;
	int numBids = stoi(numBidsStr);
	std::string highestBidder;
	int highestBid = 0;
	for (int i = 0; i < numBids; i++) {
		std::string nameBidder;
		std::string bidAmountStr;
		std::cin >> nameBidder;
		std::cin >> bidAmountStr;
		int bidAmount = stoi(bidAmountStr);
		if (bidAmount > highestBid) {
			highestBidder = nameBidder;
			highestBid = bidAmount;
		}
	}
	std::cout << highestBidder << std::endl;
}