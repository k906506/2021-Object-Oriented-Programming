#include <iostream>

void swap(int &first, int &second) {    // ���۷����� ����Ͽ� �ּҰ��� �ҷ��´�
    int temp = first;   
    first = second;
    second = temp;  // ���������� first���� second��, second���� first�� ����ȴ�
}
int main() {
    int a = 2, b = 3;
    swap(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}
