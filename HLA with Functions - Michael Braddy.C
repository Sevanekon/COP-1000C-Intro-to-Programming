//////////////////////////////////////////////////////////////
//	Written by: Michael Braddy								//
//	Written on: 3/27/16										//
//	Written for: COP 1000									//
//	HLA with Functions 2: The Reckoning						//
//////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("pause")
#define CLS system("cls")
#define FLUSH fflush(stdin)

#include <stdlib.h>
#include <stdio.h>

//	Prototype functions here
void mainMenu();
int enterNumber();
void doAverage(int, int);
int doHighest(int, int,	int);
int doLowest(int, int, int);
//	Prototype functions end

main() { // BEGIN MAIN

	mainMenu();

}	//	END MAIN

void doAverage(int sumNum, int numCount){	//	Begin Average Display

	int avgTotal = 0;

	if (numCount == 0){
		printf("\nYou haven't entered any numbers to average yet, dummy.\n");
	}
	else{
		avgTotal = sumNum / numCount;
		printf("\nThe average of the entered numbers is: %i.\n", avgTotal);
	}

}	//	End Average Display

int doHighest(int enteredNum, int numCount, int recNumHigh){	//	Begin Highest

	if (numCount == 1) {	// If statement to determine new record number
		recNumHigh = enteredNum;
	}

	else if (recNumHigh < enteredNum){
		recNumHigh = enteredNum;
	}

	return recNumHigh;

}	//	End Highest Num

int doLowest(int enteredNum, int numCount, int recNumLow){	//	Begin Lowest

	if (numCount == 1) {	// If statement to determine new record number
		recNumLow = enteredNum;
	}

	else if (recNumLow > enteredNum){
		recNumLow = enteredNum;
	}

	return recNumLow;

}	//	End Lowest Num

int enterNumber(){

	int addNumber = 0;

	printf("\n Enter an interger: ");
	scanf("%f", &addNumber); FLUSH;

	return addNumber;
}

void mainMenu(){

	int menuChoice;
	int numCount = 0;
	int enteredNum = 0;
	int sumTotal = 0;
	int rHigh = 0;
	int rLow = 0;

	do {

		CLS;
		printf(" Please make a selection from the following menu: \n");
		printf("\n 1. Enter an number.");
		printf("\n 2. Display the Highest of Numbers entered.");
		printf("\n 3. Display the Lowest of Numbers entered.");
		printf("\n 4. Display the Average of Numbers entered.");
		printf("\n 5. Quit Program");

		menuChoice = 0;

		printf("\n Enter Selection: ");
		scanf("%i", &menuChoice); FLUSH;

		switch (menuChoice) { // Begin switch

		case 1:
			enteredNum = enterNumber();
			numCount++;
			sumTotal += enteredNum;
			rHigh = doHighest(enteredNum, numCount, rHigh);
			rLow = doLowest(enteredNum, numCount, rLow);
			break;

		case 2:

			if (numCount == 0){
				printf("\nYou haven't entered any numbers to average yet, dummy.\n");
			}
			else{				
				printf("The Highest number entered so far is %i. \n", rHigh);
			}
			break;

		case 3:

			if (numCount == 0){
				printf("\nYou haven't entered any numbers to average yet, dummy.\n");
			}
			else{
				printf("\nThe Lowest of the entered numbers is: %i. \n", rLow);
			}
			break;

		case 4:
			doAverage(sumTotal, numCount);
			break;

		case 5:
			printf("Exiting Program.\n");
			break;

		default:

			printf("\nPlease enter a valid menu option.\n");

		} // End switch

		PAUSE;
	} while (menuChoice != 5);

}
