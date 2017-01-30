//== == == == == == == == == == == == == == == == == == == == == == == == == ==
//Name...................:Krystal Myers		
//Date...................:3/3/2016
//Purpose................:Guess the Number
//== == == == == == == == == == == == == == == == == == == == == == == == == ==
#define PAUSE system("pause") // short cut for pause//PAUSE;
#define _CRT_SECURE_NO_WARNINGS //  for no _s
#include <stdio.h>
#include <stdlib.h>
#define CLS system("cls")
#include <time.h>
#define SIZE 10


int count_occur(int a[], char map[], int num_elements, int start);
void print_array(int a[], int num_elements);

int main(void)
{
	int lotto[SIZE];
	char map[SIZE] = { 0 };
	int num_occ, i,temp,swapped;
	int count = 0;

	
	
	srand(time(NULL));

	for (i = 0; i < SIZE; i++){

		lotto[i] = (rand() % 53) + 1;

	}// end for

	printf("orig list\n");
	for (i = 0; i < SIZE; i++){
		count++;
		printf("%i . %d\n", count, lotto[i]);

	}//end for

	while (1){
		swapped = 0;
		for (i = 0; i < SIZE - 1; i++){
			if (lotto[i]>lotto[i + 1]){
				int temp = lotto[i];
				lotto[i] = lotto[i + 1];
				lotto[i + 1] = temp;
				swapped = 1;

			}//end if 


		}// end for
		if (swapped == 0){
			break;
		}//end if swapped

	}//end while 
	
	
	
	
	
	
	
	
	
	printf("\nSorted numbers:\n");
	print_array(lotto, SIZE);

	for (i = 0; i < SIZE; i++)
	{
		if (map[i] == 0) {
			num_occ = count_occur(lotto, map, SIZE, i);
			printf("The value %d was found %d times.\n", lotto[i], num_occ);
		}
	}
	PAUSE;

}

int count_occur(int lotto[], char map[], int num_elements, int start)
/* checks array a for number of occurrances of value */
{
	int i, count = 0, value = lotto[start];

	for (i = start; i < num_elements; i++)
	{
		if (lotto[i] == value)
		{
			map[i] = 1;
			++count; /* it was found */
		}
	}
	return (count);
}

void print_array(int lotto[], int num_elements)
{
	int i;
	for (i = 0; i< num_elements; i++)
	{
		printf("%d \t", lotto[i]);
	}
	printf("\n");
}