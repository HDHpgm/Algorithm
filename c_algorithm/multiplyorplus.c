#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int n;
	char str[20];

	scanf("%s", &str);

	int result = str[0] - '0';
	for (int i = 1; i < strlen(str); i++)
	{
		int next = str[i] - '0';
		if (result <= 1 || next <= 1) result += next;
		else result *= next;
	}
	printf("%d\n", result);
}