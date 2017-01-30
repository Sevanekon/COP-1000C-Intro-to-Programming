//////////////////////////////////////////////////
//	Written by: Michael Braddy					//
//	Written on: 4/3/16							//
//	Written for: Week 11 HW assignment			//
//////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#define CLS system("cls")
#define FLUSH fflush(stdin)
#define PAUSE system("pause")

#include <stdio.h>
#include <stdlib.h>

//	Prototype Functions Here
float adjustMileage(float);
float adjustMPG(float);
float adjustPPG(float);
void displayCurrents(float, float, float, float);
void mainMenu(float, float, float);
float takeATrip(float, float, float);
//	Prototype Functions End

main(){	//	Begin Main
	
	// Variables Start
	float currentMileage = 0, pricePG = 0, milesPG = 0;
	
	// Variables End

	printf("This Program will calculate the cost for a trip and show you your mileage upon completion.\nYou will need to know the Miles per gallon of your vehicle, the Price per gallon of gas, and your starting mileage.\n\n");
	PAUSE;
	CLS;
	milesPG = adjustMPG(milesPG);
	pricePG = adjustPPG(pricePG);
	currentMileage = adjustMileage(currentMileage);	
	
	mainMenu(currentMileage, milesPG, pricePG);


	printf("Have a Good Trip!\n");
	PAUSE;

}	//	End Main

float adjustMileage(float mileage){	//	adjustMileage begin

	CLS;
	printf("Please enter the current mileage of your Vehicle: ");
	scanf("%f", &mileage);

	return mileage;

	CLS;
}	//	End adjustMileage

float adjustMPG(float mPG){	//	adjustMPG begin
	
	CLS;
	printf("Please enter the Miles Per Gallon of your Vehicle: ");
	scanf("%f", &mPG);

	return mPG;

	CLS;
}	//	End adjustMPG

float adjustPPG(float pPG){	//	adjustPPG begin

	CLS;
	printf("Please enter the current Price Per Gallon of Gas: ");
	scanf("%f", &pPG);

	return pPG;

	CLS;
}	//	End adjustPPG

void displayCurrents(float curMileage, float curPPG, float curMPG, float totalCost){	//	displayCurrents begin
	printf("Current Mileage: %.2f\n", curMileage);
	printf("Current PPG: %.2f\n", curPPG);
	printf("Current MPG: %.2f\n", curMPG);
	printf("Total Trip Cost: %.2f\n", totalCost);

}	//	End displayCurrents

void mainMenu(float mileage, float mPG, float pPG){	//	Begin mainMenu

	int mSelection = 0;
	float totalCost = 0;
	float tripMileage = 0;

	do{	//	Begin Do While
		mSelection = 0;
		tripMileage = 0;
		CLS;
		displayCurrents(mileage, pPG, mPG, totalCost);
		printf("Please choose from the following options: \n");
		printf("1.\tTake a trip!\n");
		printf("2.\tAdjust Miles Per Gallon\n");
		printf("3.\tAdjust Price Per Gallon\n");
		printf("4.\tAdjust Current Mileage\n");
		printf("5.\tExit Program\n\n");
		printf("Enter Selection: ");
		scanf("%i", &mSelection);

		switch (mSelection){	//	Begin Switch
		case 1:
			tripMileage = takeATrip(mileage, pPG, mPG);
			mileage += tripMileage;
			totalCost += (tripMileage / mPG) * pPG;
			break;
		case 2:
			printf("***Note: This Only Effects Prices Going Forward. Previously Traveled Distances Aren't Altered.***\n\n");
			mPG = adjustMPG(mPG);
			break;
		case 3:
			printf("***Note: This Only Effects Prices Going Forward. Previously Traveled Distances Aren't Altered.***\n\n");
			pPG = adjustPPG(pPG);
			break;
		case 4:
			mileage = adjustMileage(mileage);
			break;
		case 5:
			break;

		default:
			printf("Please Enter a Valid Option.");
			break;
		}	//	End Switch
	} while (mSelection != 5);	//	End Do While

}	//	End mainMenu

float takeATrip(float mileage, float pPG, float mPG){	//	takeATrip begin	
	float tripMileage = 0;
	float tripCost = 0;

	CLS;
	printf("Please enter the distance of your next trip: ");
	scanf("%f", &tripMileage);
	mileage += tripMileage;
	tripCost += (tripMileage / mPG) * pPG;

	printf("This trip will cost %.2f and raise your mileage to %.2f\n", tripCost, mileage);
	PAUSE;
	return tripMileage;

}	//	End takeATrip