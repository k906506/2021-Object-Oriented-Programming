#include <iostream>
using namespace std;

int i;

class A {
public:
	~A() {	// �Ҹ���
		i = 10;
	}
};
int foo() {
	i = 3;
	if (i == 3) {	
		A ob;	// A�� ��ü ob�� �Ҹ�� �� i = 10�� ����
	}
	return i;
}
int main() {
	cout << foo() << endl;
	return 0;
}