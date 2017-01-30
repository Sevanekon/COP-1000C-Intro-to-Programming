///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Written by Michael Braddy
//	Written on 1/31/16
//	Assignment 05: Shipping Homework
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("Pause")

#include <stdio.h>
#include <stdlib.h>

main() { //BEGIN MAIN

	///////////////////////////////////////////////////
	// Shipping formula is:
	// w <= 15lbs, then $15
	// w > 15 lbs, then $15 + 0.5(each extra pound)
	// Then add $10 for every 500 miles
	///////////////////////////////////////////////////

	//VARIABLE DECLARATION START
	float miles = 0;
	float weight = 0;
	float weightPrice = 0;
	float milesPrice = 0;
	float totalPrice = 0;
	int milesInc = 0;
	//VARIABLE DECLARATION END

	printf("\nThis program will calculate your shipping cost for you.\nEnter the distance in miles you'd like to ship the package: ");
	scanf("%f", &miles);
	//MILEAGE QUERY

	printf("\nYou entered: %.2f miles.\nEnter the weight of the package in pounds: ", miles);
	scanf("%f", &weight);
	//WEIGHT QUERY

	printf("\nYou entered: %.2f pounds.\n", weight);

	//WEIGHT PRICE CALCULATION BEGIN
	if (weight <= 15){
		weightPrice = 15;
	}
	else{
		weightPrice = (weight - 15) * 0.5 + 15;
	}//WEIGHT PRICE CALCULATION END

	//MILEAGE PRICE START
	milesInc = miles / 500 + 0.5; //Establishing mileage increment

	if (miles <= 500){
		milesPrice = 10;
	}

	else {
		milesPrice = milesInc * 10;
	}//MILEAGE PRICE END

	totalPrice = milesPrice + weightPrice;
	printf("\nThe total to ship your %.2f pound package %.2f miles is : %.2f\n", weight, miles, totalPrice);

	PAUSE;

} // END MAIN