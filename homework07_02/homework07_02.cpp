#include <iostream>
#include <stdexcept>

bool funcA() {
	int c;
	std::cin >> c;
	if (c < 10) {	//Let's assume this is exception
		throw std::out_of_range("Invalid Input!!");
	}
	return true;
}

int main() {
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
	return 0;
}