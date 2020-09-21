#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char string[100] = "";	// 100자(\n포함 101자)
	printf("문자를 입력하세요(100자 이내).\n");
	scanf("%[^\n]", string);	// 공백을 제외한 입력
	printf("입력된 문자는 %s 입니다.\n", string);
	return 0;
}