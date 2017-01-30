//////////////////////////////////////////////////////////////////////
//	Written by: Michael Braddy,	Do Han, Krystal Myers, James Tarr	//
//	Written on:	3/21/16	- 4/9/16									//
//	Written for: Exam 3												//
//////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("pause")
#define CLS	system("cls")
#define FLUSH fflush(stdin)
#define SIZE 10000

#include <stdio.h>
#include <stdlib.h>

//	PROTOTYPE FUNCTIONS HERE
void adjustmentMenu(int examScores[], int examCounter);
void adjustScoreLower(int examScores[], int examCounter);
void adjustScoreRaise(int examScores[], int examCounter);
int countOccur(int examScores[], char map[], int examCounter, int start);
char doTheSwitch(int examScores[], int index);
void enterScore(int examScores[], int examCounter);
void examHighLow(int examScores[], int examCounter);
void examAverageCalculation(int examScores[], int examCounter);
void howMany(int examScores[], int examCounter);
void programMenu(int examScores[]);
void printSortedArray(int examScores[], int examCounter);
//	PROTOTYPE FUNCTIONS END

main(){
	int examScores[SIZE] = { 0 };

	programMenu(examScores);	//	Call to the Main Menu

}	//	END MAIN

void adjustmentMenu(int examScores[], int examCounter){

	int mSelection = 0;

	do {	// Begin Menu Loop

		CLS;

		printf("What would you like to do? \n");
		printf("\n 1. Raise the Exam Scores.");
		printf("\n 2. Lower the Exam Scores.");
		printf("\n 3. Return to Main Menu.");

		printf("\n Enter Selection: ");
		scanf("%i", &mSelection); FLUSH;

		switch (mSelection) { // Begin switch

		case 1:
			if (examCounter == 0){	//	Error Check
				printf("\nYou haven't entered any scores yet, dummy.\n");
				PAUSE;
				break;
			}
			else{
				adjustScoreRaise(examScores, examCounter);
				printf("\nAll entered scores have been raised by 2 to a maximum of 100.\n");
				PAUSE;
				break;
			}
		case 2:
			if (examCounter == 0){	//	Error Check
				printf("\nYou haven't entered any scores yet, dummy.\n");
				PAUSE;
				break;
			}
			else{
				adjustScoreLower(examScores, examCounter);
				printf("\nAll entered scores have been lowered by 5 to a minimum of 0");
				PAUSE;
				break;
			}
		case 3:
			break;

		default:
			printf("\nPlease enter a valid menu option.\n");

		} // End switch
	} while (mSelection != 3);	//	End Menu Loop

}	//	END ADJUSTMENT MENU

void adjustScoreLower(int examScores[], int examCounter){

	int i = 0;

	for (i = 0; i < examCounter; i++){	//	Begin For
		examScores[i] -= 5;

		if (examScores[i] < 0){	//	Minimum Zero Limit
			examScores[i] = 0;
		}

	}	//	Linear adjustment End
}	//	End Adjustment Lower

void adjustScoreRaise(int examScores[], int examCounter){

	int i = 0;

	for (i = 0; i < examCounter; i++){
		examScores[i] += 2;

		if (examScores[i] > 100){	//	Maximum 100 limit
			examScores[i] = 100;
		}

	}	//	Linear adjustment End
}	//	End Adjustment Raise

int countOccur(int examScores[], char map[], int examCounter, int j)
//checks array a for number of occurrances of value 
{
	int i, count = 0, value = examScores[j];

	for (i = j; i < examCounter; i++)
	{
		if (examScores[i] == value)
		{
			map[i] = 1;
			++count; // it was found 
		}
	}
	return (count);
}	//	End countOccur

char doTheSwitch(int examScores[], int index){
	char result = 'Y';
	int temp;
	temp = examScores[index];	// Stores sub 0
	examScores[index] = examScores[index + 1];	//	replaces sub 0 with sub 1
	examScores[index + 1] = temp;	//	replaces sub 1 with sub 0 (stored)

	return result;

}	//	End doTheSwitch

void enterScore(int examScores[], int numExams){	//	Begin Enter Score
	int newScore = 0;

	if (numExams > 10000){ // Begin If
		printf("\nThe Limit for this program is 10,000 scores.\n");
	}	//	End If

	else{
		printf("Enter an exam score: ");
		scanf("%i", &newScore);
		examScores[numExams] = newScore;
		printf("\n");
	}	//	End Else
}	//	End Enter Score

void examAverageCalculation(int examScores[], int examCounter){

	int sumTotal = 0, i = 0, examAvg = 0;

	for (i = 0; i < examCounter; i++){
		sumTotal += examScores[i];
	}	//	End rolling array sum

	examAvg = sumTotal / examCounter;

	printf("\nThe Average of the %i entered scores is: %i.\n", examCounter, examAvg);

}	//	examAverageCalculation End

void examHighLow(int examScores[], int examCounter){
	char switchMade = 'N';
	int i = 0, temp = 0;

	int bottom = examCounter - 1;
	do{
		switchMade = 'N';
		for (i = 0; i < bottom; i++){
			if (examScores[i] < examScores[i + 1]){
				switchMade = doTheSwitch(examScores, i);
			}	//	end If
		}	//	End For
		bottom--;
	} while (switchMade == 'Y');
}	//	End Exam Sorting

void howMany(int examScores[], int examCounter){

	char map[SIZE] = { 0 };
	int i, times;
	for (i = 0; i < examCounter; i++){
		if (map[i] == 0) {
			times = countOccur(examScores, map, examCounter, i);
			printf("The value %i was found %i times.\n", examScores[i], times);
		}
	}

}	//	End howMany

void printSortedArray(int examScores[], int examCounter)
{
	int i;
	for (i = 0; i < examCounter; i++)
	{
		printf("%d \n", examScores[i]);
	}
	printf("\n");
}	//	end of print from high to low

void programMenu(int examScores[]){	//	This is the menu for the program

	int examCounter = 0;
	int mSelection = 0;

	do {	// Begin Menu Loop

		CLS;

		printf("Please make a selection from the following menu: \n");
		printf("\n 1. Enter an Exam Score.");
		printf("\n 2. Adjust an Exam Score.");
		printf("\n 3. Display Entered Exam Scores in Descending Order With Number of Occurances.");
		printf("\n 4. Display the Average of Entered Exam Scores.");
		printf("\n 5. Exit Program");

		mSelection = 0;

		printf("\n Enter Selection: ");
		scanf("%i", &mSelection); FLUSH;

		switch (mSelection) { // Begin switch

		case 1:
			CLS;
			enterScore(examScores, examCounter);
			examCounter++;
			break;

		case 2:
			adjustmentMenu(examScores, examCounter);
			break;

		case 3:
			if (examCounter == 0){	//	Error Check
				printf("\nYou haven't entered any scores yet, dummy.\n");
				break;
			}
			else{
				examHighLow(examScores, examCounter);
				CLS;
				howMany(examScores, examCounter);
				printf("\nA total of %i scores have been entered so far.\n", examCounter);
			}
			break;

		case 4:
			if (examCounter == 0){	//	Error Check
				printf("\nYou haven't entered any scores yet, dummy.\n");
				break;
			}
			else{
				examAverageCalculation(examScores, examCounter);
			}

		case 5:
			printf("\nExitting Program.\n");
			break;

		default:
			printf("\nPlease enter a valid menu option.\n");
		} // End switch

		PAUSE;
	} while (mSelection != 5);	//	End Menu Loop

}	//	END PROGRAM MENU