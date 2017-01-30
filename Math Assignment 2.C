#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main() {

	int Val1, Val2, Val3;
	int Val4, Val5, Val6;
	Val1 = 0;
	Val2 = 0;
	Val3 = 0;
	Val4 = 0;
	Val5 = 0;
	Val6 = 0;

	printf("\nEnter first Value: ");
	scanf("%d", &Val1);
	printf("\nEnter second Value: ");
	scanf("%d", &Val2);
	printf("The numbers entered are %d and %d.", Val1, Val2);

	Val3 = Val1 / Val2;

	printf("\n%d / %d = %d", Val1, Val2, Val3);

	Val4 = Val1 + Val2 + Val3;

	printf("\n%d + %d + %d = %d", Val1, Val2, Val3, Val4);

	Val5 = Val1 * Val1 * Val1;

	printf("\n%d cubed is %d", Val1, Val5);

	Val6 = Val3 + Val1 + Val2 * 2;

	printf("\n%d + %d + %d * 2 = %d\n\n", Val3, Val1, Val2, Val6);
	system("pause");
	return 0;


}