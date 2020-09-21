#include <iostream>

void swap(int &first, int &second) {    // 래퍼런스를 사용하여 주소값을 불러온다
    int temp = first;   
    first = second;
    second = temp;  // 최종적으로 first에는 second가, second에는 first가 저장된다
}
int main() {
    int a = 2, b = 3;
    swap(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}
