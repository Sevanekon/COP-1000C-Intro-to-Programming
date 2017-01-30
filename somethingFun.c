//== == == == == == == == == == == == == == == == == == == == == == == == == ==
//Name...................:Krystal Myers 
//Date...................:03/17/16
//Purpose................:Functions
//== == == == == == == == == == == == == == == == == == == == == == == == == ==
#define PAUSE system("pause") // short cut for pause//PAUSE;
#define _CRT_SECURE_NO_WARNINGS //  for no _s
#define CLS system("cls")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// prototype FUN


char name();
int age();
void choosePet();
int difAge();



main(){
	char userChoice;
	do{
		printf("Welcome to the function menu, but you may call me the FUN menu.\n");
		printf("Please choose one of the following.\n");
		printf("A.Enter your name.\n");
		printf("B.Enter some ages.\n");
		printf("C.Surprise me!\n");
		printf("Q.QUIT\n");
		scanf("%s", &userChoice);
		CLS;
	
	
	switch (userChoice)
	{// end of do

	case 'a':{
		char nameFst[50], nameLast[50], memory;
		
		printf("What is your first name?\n");
		scanf("%s", &nameFst);
		printf("What is your last name?\n");
		scanf("%s", &nameLast);
	    name(nameFst, nameLast);
		
		PAUSE;
		CLS;
		break;
}//end of case a
	case 'b':{
		int userAge, momAge, becameMom, dadAge, yearsApart;
		printf("What is your age?\n");
		scanf("%i", &userAge);
		printf("What is your mothers curent age?\n");
		scanf("%i", &momAge);
		printf("What is your fathers curent age?\n");
		scanf("%i", &dadAge);
		becameMom = age(userAge, momAge);
		printf("So your mom had you when she was %i years old.Cool\n", becameMom);

		yearsApart = difAge(dadAge, momAge);
		printf("Your parents are only %i years apart. I bet you have never thought about that.\n", yearsApart);


		
		PAUSE;
		CLS;
		break;
}// end of case b 

	case 'c':{
		
		char petChoice;
		printf("What do you like more?\n C.Cats\n D.Dogs\n");
		scanf("%s", &petChoice);
		choosePet(petChoice);
	
		PAUSE;
		CLS;
		break;

	}// end of c

	case 'q'://QUIT
		printf("You have quit the program.\n");
		PAUSE;
		break;

	default://Error message
		printf("Invalid choice or enter lower case letters Try again.\n");

		PAUSE;
		CLS;
		break;




		PAUSE;

	}//end of switch

} while (userChoice != 'q');




}// end of main

char name(char nameFst[], char nameLast[]){

	
	
	printf("%s What a nice name!\n",nameFst);
	printf("%s WOW! What a STRONG last name! I see lots of history in %s.\n", nameLast,nameLast);
	
	if (strcmp("Dennis", nameFst) == 0)
	printf("I know a great professor named %s!\n",nameFst);
	return 0;

	if (strcmp("Hunchuck", nameLast) == 0)
		printf("I know a professor named Professor  %s!....Are you two related? \n", nameLast);
	return 0;

}// end of name

int age(int age,int momAge){
	int becameMom ;
	if (age <= 10)
		printf("%i ? Did you ask your parents if you can play this game?\n", age);
	else if (age >= 11 && age <= 20)
		printf("%i, You should be doing homework. Not playing with me.\n", age);
	else if (age ==21 )
		printf("%i! Wow great time to be alive! Be safe though.\n", age);
	else if (age >= 22 && age <= 80)
		printf("%i, How is life so far? I hope it is nice.\n", age);
	else if (age>=81)
		printf("%i? According to PEW research you are apart of the 37 precent of adults  that can use a computer at your age! GOOD JOB. \n", age);
	becameMom = momAge - age;
	return becameMom;
	
	


}// end of age




int difAge( int dadAge,  int momAge){
	int ageDif;
	if (dadAge >= momAge)
		ageDif = dadAge - momAge;
	else
		ageDif = momAge - dadAge;
	return ageDif;

}// end of age diffrence


void choosePet(char petChoice){
	
	
	if (petChoice == 'c') {
	printf("\n\n\n");
	printf(" ____________________________________$$$$\n__________________________________$$____$\n_________________________________$_______$\n");
	printf("___$$$$_________________________$_________$\n__$____$$______________________$____$_____$\n_$_______$$___________________$____$$$____$\n");
	printf("_$_________$$_____$$$$_$$$___$____$$$$$___$\n$____________$_$$$__$$$__$$_$____$$$$$$___$\n$____$$_______$_$$__$$$__$$$____$$$$$$$___$\n");
	printf("$___$$$$_______$$$$_$$$___$$_____$$$$$$___$\n$___$$$$$$_____$$$$_$$$$__$$$______$$$$$__$\n$___$$$$$$$____$$$$_$$$$__$$$________$$$__$\n");
	printf("$___$$$$$______$$$$_$$$$__$$$$____________$\n$___$$$$_______$$$$_$$$$__$$$$____________$\n$___$$$________$$$$_$$$$__$$$$____________$\n");
	printf("$___$$_________$$$$__$$$__$$$$____________$\n$______________$$$___$$$___$$$____________$\n$_______________$_____$_____$_____________$\n");
	printf("_$_________________________________________$\n\$________________________________$$$$_______$\n$_______________________________$__$$$______$\n");
	printf("$__________$$$$________________$$__$$$$_____$\n$_________$$$__$_______________$$$$$$$$_____$\n$________$$$$__$_______________$$$$$$$$_____$\n");
	printf("$________$$$$$$$$______________$$$$$$$$_____$\n$________$$$$$$$$_______________$$$$$$______$\n$________$$$$$$$$_______$___$____$$$$_______$\n");
	printf("$_________$$$$$$_____$__$$_$________________$\n$__________$$$$_______$$__$________________$\n_$_____________________$__$_______________$\n");
	printf("__$_____________________$$_______________$\n___$______________________________$$$___$\n____$$___________________________$___$_$\n");
	printf("______$$$_______________________$_____$\n_________$$$$_____________$$$$$$______$\n___$$________$$$$$$$$$$$$$____________$\n");
	printf("__$__$________$___$_________________$$\n__$___$_______$____$_____________$$$\n__$___$________$____$___________$$\n");
	printf("__$$$$$$_______$____$__________$__$\n___$___$$_______$___$_________$____$\n___$$$$$$$___$$$_$$$_________$_____$\n");
	printf("____$___$$$$$__$_____$_______$_____$\n_____$__$______$_____$_______$_____$\n______$$$$$$$$$$_____$_______$____$\n");
	printf("______$$$$$$$$$$_____$_______$____$\n________________$$$$$_________$$$$\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$$$$$$$$$$$--SURPRISE--$$$$$$$$$$$\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n");
}// end if
	else
	{

	
	
	
	printf("______________________$$$$$$$$\n_______________$$$$$$$________$$$$$$$$$\n_____________$$________________________$$$$\n");
	printf("____________$$_____________________________$$\n___________$__________________________________$$\n___________$$___________________________________$$\n");
	printf("__________$$__$$______________________$$__________$$\n________$$__$$___$$$$_________$$$$____$$__________$$$$\n______$$___$$__$$$$__$$_____$$$$__$$_$$_____________$$$\n");
	printf("______$$___$$____$$$$_________$$$$___$$_______________$$\n______$$___$$________________________$$_______________$$\n______$$____$$_______________________$$_____________$$\n");
	printf("________$$__$$____$$$$$$_____________$$___________$$$\n________$$__$$__$$______$$___________$$_________$$\n________$$__$$__$$______$$___________$$_______$$\n");
	printf("__________$$$$____$$$$$$_____________$$$$____$$$$\n__________$$$$_____________________$$__$$____$$$\n___________$$_$$$$$$$$$$$$_____$$$$______$$$$_$$\n");
	printf("_____________$$___$$______$$$$$_______________$$\n_____________$$_____$$$$$$$____________________$$\n_____________$$________________________________$$\n");
	printf("____________$$_________________________________$$\n____________$$_________________________________$$\n____________$$___________________________________$\n");
	printf("____________$$___________________________________$$\n__________$$_________________________$$___________$\n__________$$__________$$___________$$_____________$$\n");
	printf("________$$__$$________$$_________$$_______________$$\n______$$____$$__________$$_______$$_______________$$\n______$$____$$____________$$___$$_________________$$\n");
	printf("____$$______$$_____________$$_$$_______$$_________$$\n____$$______$$________$$____$$$________$$_________$$\n____$$______$$________$$____$$$_______$$__________$$\n");
	printf("____$$______$$________$$_______________$$__________$$\n____$$______$$________$$_______________$$____________$\n_$$$$_______$$________$$_______________$$____________$$\n");
	printf("$___$$______$$________$$$$___________$$$$____________$$\n$___$$______$$________$$__$$_______$$__$$____________$$\n_$$$$$______$$________$$____$$___$$_____$$___________$$\n");
	printf("____$$______$$________$$______$$_______$$___________$$\n____$$______$$________$$_____$$________$$___________$$\n__$$________$$________$$$$$$$$___$$$$$$__$$_________$$\n");
	printf("__$$________$$________$$______$$$______$$$$_________$$\n$$________$$__________$$_________$$$$$$__$$__________$\n$$______$$__________$$$$$$$$$$$$$$$______$$__________$\n");
	printf("$$_$$_$$$__________$$_____________$$$$$$$__$$_________$\n_$$$$$$$___________$$______________________$$________$$\n_____$$__$$__$$__$$_$_____--SURPRISE--_____$$__________$$\n");
	printf("______$$$$__$___$__$$______________________$$____________$\n_______$$___$___$__$________________________$$_$__$$__$$__$\n_________$$$$$$$$$$__________________________$$_$_$$$$$$$$\n");

}// end else
}// end of pet