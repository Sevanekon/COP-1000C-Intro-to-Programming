/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Written by: Michael Braddy
//	Written on: 2/7/16
//	Assignment 06: Payroll
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("pause")

#include <stdlib.h>
#include <stdio.h>

main() { //BEGIN MAIN

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//	Input Needs: Hourly Rate, Hours Worked														//
	//	Output Needs: Regular Pay, OT Pay, Gross Pay, Fed Tax (27%), Med Insurance (14%), Net Pay	//
	//	Rate = Input 1, Hours = Input 2																//
	//	Regpay: If =< 40, Input 1 * Input 2 and OT = 0, Otherwise Input 1 * 40 then calculate OT	//
	//	OTpay: Input 1 * (Input 2 - 40) * 1.5														//
	//	Gross Pay: Reg + OT pay																		//
	//	Fed Taxes: Gross - (Gross * .27) = GrossLeft												//
	//	Med Ins: GrossLeft - (Gross * .14) = Netpay													//
	//////////////////////////////////////////////////////////////////////////////////////////////////

	// Input Variable Declaration, Start

	float hRate = 0;
	float hWork = 0;

	// Input Variable Declaration, End

	printf("This program will determine your weekly paycheck information and present a paystub.\nPlease enter your hourly rate:");
	scanf("%f", &hRate); // hRate Query

	printf("Next, please enter how many hours you worked this week:");
	scanf("%f", &hWork); // hWork Query

	// Calculations Begin

	float rPay = 0;
	float oTPay = 0;
	float gPay = 0;
	float gLeft = 0;
	float nPay = 0;
	float fTaxes = 0;
	float mIns = 0;

	if (hWork <= 40){ // Begin IF/ELSE statement
		rPay = hRate * hWork;
		oTPay = 0;
	}
	else {
		rPay = hRate * 40;
		oTPay = (hWork - 40) * hRate * 1.5;
	}  //End IF/ELSE statement

	gPay = rPay + oTPay;	// Gross Pay

	gLeft = gPay - (gPay * .27); // Federal Taxes 27%
	fTaxes = gPay * .27;

	nPay = gLeft - (gPay * .14); // Medical Insurance 14%
	mIns = gPay *.14;

	//	Calculations End

	//	Display to User
	
	printf("\nFor working %.1f hours at your hourly rate of %.2f, Your pay for the week is as follows:\n", hWork, hRate);

	printf("Regular Pay: %.2f\nOT Pay: %.2f\nGross Pay: %.2f\nFederal Tax (27%%): %.2f\nMedical Insurance (14%%): %.2f\nNet Pay: %.2f\n", rPay, oTPay, gPay, fTaxes, mIns, nPay);


	PAUSE;

} // END MAIN