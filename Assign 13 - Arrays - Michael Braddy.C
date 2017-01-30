//////////////////////////////////////////////////
//	Written by: Michael Braddy					//
//	Written on: 4/10/16							//
//	Written for: Assignment 13 - Arrays			//
//////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#define CLS system("cls")
#define PAUSE system("pause")
#define SIZE 100000
#define FLUSH fflush(stdin)

#include <stdio.h>
#include <stdlib.h>

//	Prototype Functions Here
void enterNumber(int assignment[], int counter);
void mainMenu(int assignment[]);
void showArray(int assignment[], int counter);
void showAverage(int assignment[], int counter);
void showSum(int assignment[], int counter);
//	Prototype End

main(){

	int assignment[] = { 0 };

	mainMenu(assignment);

}	//	End Main

void mainMenu(int assignment[]){

	int counter = 0;
	int mSelection = 0;

	do {	// Begin Menu Loop

		CLS;

		printf("Please make a selection from the following menu: \n");
		printf("\n 1. Enter a number.");
		printf("\n 2. Display sum of all numbers entered.");
		printf("\n 3. Display average of all numbers entered.");
		printf("\n 4. Display all numbers entered.");
		printf("\n 5. Quit");

		mSelection = 0;

		printf("\n Enter Selection: ");
		scanf("%i", &mSelection); FLUSH;

		switch (mSelection) { // Begin switch

		case 1:
			CLS;
			enterNumber(assignment, counter);
			counter++;
			break;

		case 2:
			if (counter == 0){	//	Error Check
				printf("\nYou haven't entered any numbers yet, dummy.\n");
				break;
			}
			else{
				showSum(assignment, counter);
			}	//	End If Else
			break;

		case 3:
			if (counter == 0){	//	Error Check
				printf("\nYou haven't entered any numbers yet, dummy.\n");
				break;
			}
			else{
				showAverage(assignment, counter);
			}
			break;

		case 4:
			if (counter == 0){	//	Error Check
				printf("\nYou haven't entered any numbers yet, dummy.\n");
				break;
			}
			else{
				showArray(assignment, counter);
			}
			break;

		case 5:
			printf("\nExitting Program.\n");
			break;

		default:
			printf("\nPlease enter a valid menu option.\n");
		} // End switch

		PAUSE;
	} while (mSelection != 5);	//	End Menu Loop

}	//	End mainMenu

void enterNumber(int assignment[], int counter){	//	Begin Enter Score
	int newEntry = 0;

	if (counter > SIZE){ // Begin If
		printf("\nYou have reached the limit of this program.\n");
	}	//	End If

	else{
		printf("Enter an exam score: ");
		scanf("%i", &newEntry); FLUSH;
		assignment[counter] = newEntry;
		printf("\n");
	}	//	End Else
}	//	End Enter Score

void showArray(int assignment[], int counter){

	int i;
	for (i = 0; i < counter; i++)
	{
		printf("%d \n", assignment[i]);
	}
	printf("\n");

}	//	End showArray

void showAverage(int assignment[], int counter){

	int sumTotal = 0, i = 0, avgNum = 0;

	for (i = 0; i < counter; i++){
		sumTotal += assignment[i];
	}	//	End sum loop

	avgNum = sumTotal / counter;

	printf("\nThe average of the entered numbers is: %i.\n", avgNum);

}	//	End Show Sum

void showSum(int assignment[], int counter){

	int sumTotal = 0, i = 0;

	for (i = 0; i < counter; i++){
		sumTotal += assignment[i];
	}	//	End sum loop

	printf("\nThe sum of the entered numbers is: %i.\n", sumTotal);

}	//	End Show Sum