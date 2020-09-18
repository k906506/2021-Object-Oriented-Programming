#include <iostream>
class SetValue {
private:
	int x, y;
public:
	int getX() {	// getter
		return x;
	}
	int getY() {	// getter
		return y;
	}
	void setX(int elementX) {	// setter
		x = elementX;
	}
	void setY(int elementY) {	// setter
		y = elementY;
	}
};

int main() {
	SetValue obj;
	obj.setX(33);
	obj.setY(44);
	std::cout << "X= " << obj.getX() << ", Y= " << obj.getY() << std::endl;
	system("pause");
	return 0;
}