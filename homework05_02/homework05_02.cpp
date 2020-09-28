#include <iostream>
using namespace std;

int i;

class A {
public:
	~A() {	// 소멸자
		i = 10;
	}
};
int foo() {
	i = 3;
	if (i == 3) {	
		A ob;	// A의 객체 ob가 소멸될 때 i = 10이 저장
	}
	return i;
}
int main() {
	cout << foo() << endl;
	return 0;
}