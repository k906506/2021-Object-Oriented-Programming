#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char string[100] = "";	// 100��(\n���� 101��)
	printf("���ڸ� �Է��ϼ���(100�� �̳�).\n");
	scanf("%[^\n]", string);	// ������ ������ �Է�
	printf("�Էµ� ���ڴ� %s �Դϴ�.\n", string);
	return 0;
}