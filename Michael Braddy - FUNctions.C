//////////////////////////////////////////
//	Written By: Michael Braddy			//
//	Written On: 3/20/16					//
//	Written for: Function Assignment	//
//////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#define CLS system("cls")
#define FLUSH fflush(stdin)
#define PAUSE system("pause")

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//	PROTOTYPE FUNCTIONS HERE
int chalRatingAdjust(int, int);
void determineEvent(int, int);
void mainMenu(int, int);
//	PROTOTYPE FUNCTIONS END

main(){
	
	//	Variable Declarations
	int chalRating = 0;
	int numPlayer = 0;
	//	End Variable Declarations

	printf("This program will randomly generate encounters and suggest a proper Challenge Rating for said encounters.\n");
	printf("To start with, please enter the number of players: ");
	scanf("%i", &numPlayer);
	printf("Now Enter the average party level: ");
	scanf("%i", &chalRating);

	mainMenu(chalRating, numPlayer);

}	//	End Main


int chalRatingAdjust(int rating, int playNum){	//	Difficulty Adjustment for Number of Players

	if (playNum <= 3){
		rating--;
	}
	else if (playNum >= 6){
		rating++;
	}
	return rating;
}	//	End Rating Adjustment


void determineEvent(int roll, int aRate){	//	Event determination for roll
	if (roll == 1){
		printf("The Party should encounter a Negative Magic Influence, such as a Cursed Item, Powerful Debuff Aura, or Powerful Enchantments.\n This is a BAD event.\n");
	}
	else if (roll > 1 && roll <= 30){
		printf("Nothing Interesting Happens.\n");
	}
	else if (roll > 30 && roll <= 39){
		printf("Easy Encounter: The Party should enter combat with a challenge rating of %i.\n", aRate - 1);
	}
	else if (roll > 39 && roll <= 54){
		printf("Normal Encounter: The Party should enter combat with a challenge rating of %i.\n", aRate);
	}
	else if (roll > 54 && roll <= 63){
		printf("Challenging Encounter: The Party should enter combat with a challenge rating of %i.\n", aRate + 1);
	}
	else if (roll > 63 && roll <= 68){
		printf("Hard Encounter: The Party should enter combat with a challenge rating of %i.\nThis is a difficult encounter and caution should be advised.\n", aRate + 2);
	}
	else if (roll > 68 && roll <= 71){
		printf("Epic Encounter: The Party should enter combat with a challenge rating of %i.\nThis is a VERY difficult encounter and the party should be wary.\n", aRate + 3);
	}
	else if (roll == 72){
		printf("Improbable Encounter: The Party should enter combat with a challenge rating of %i.\nThis is an unlikely matchup and the party should be expected to lose, though still possible.\n", aRate + 4);
	}
	else if (roll == 73){
		printf("Unlucky Encounter: The Party should enter combat with a challenge rating of %i.\nThe Party SHOULD NOT FIGHT. This encounter may be represented as a horde or an extremely powerful monster.\nDeath is CERTAIN.\nFLY you FOOLS.\n", aRate + 8);
	}
	else if (roll > 73 && roll <= 80){
		printf("Shop Encounter: The Party should encounter a shop or marketplace.\nA place to restock and offload loot.\n");
	}
	else if (roll > 80 && roll <= 86){
		printf("Fortunate Encounter: The Party should meet with other heroes or npcs who may aid them on their journey.\n");
	}
	else if (roll > 86 && roll <= 88){
		printf("Treasure Encounter: The Party should encounter an oppurtunity to attain vast treasure.\nThis is a challenge, though not necessarily life threatening.\n");
	}
	else if (roll > 88 && roll <= 90){
		printf("Trap Encounter: The Party should encounter a trapped encounter.\nThis may take the form of a false treasure, or a trapped passageway for example.\n");
	}
	else if (roll > 90 && roll <= 93){
		printf("Puzzle Encounter: The Party should encounter a puzzle.\nDifficulty of the puzzle is subject to DM discretion.\nSuggested Puzzles: A Labyrinth, Hidden Objects, Object Placement\n");
	}
	else if (roll > 93 && roll <= 97){
		printf("Natural Adjustment: The environment the player is within should take on a change.\nThis can be in the form of weather, terrain, or climate.\n");
	}
	else if (roll > 97 && roll <= 99){
		printf("Natural Disaster Challenge: The Party should be challenged with a natural disaster that they must overcome.\nThis can be in many forms, but should need to be overcame through a skill check.\nSuggested Events: Flood, Heatwave, Sandstorm, Blizzard, Tornado\n");
	}
	else if (roll == 100){
		printf("Positive Magic Influence: The Party should encounter a beneficial magical event.\nThis can range from finding a magical item to receiving a magical boon or aura.\nSubject to DM Discretion, but should be influential. This is a RARE event.");
	}

}	//	End Roll Determination


void mainMenu(int rate, int play){	//	Menu Function

	int mSelection = 0;
	int adjustedCR = 0; //  This is the Adjusted Challenge Rating
	int randomRoll = 0; //	This is the random event roll

	srand((unsigned)time(NULL)); // Seed Random

	do {	// Begin Menu Loop

		adjustedCR = chalRatingAdjust(rate, play);

		CLS;

		printf("Average Party Level: %i.\nNumber of Party Members: %i.\n\n", rate, play);
		printf("Please make a selection from the following menu: \n");
		printf("\n 1. Roll A Random Event.");
		printf("\n 2. Adjust Average Party Level");
		printf("\n 3. Adjust Number of Players");
		printf("\n 4. Exit Program");

		mSelection = 0;

		printf("\n Enter Selection: ");
		scanf("%i", &mSelection); FLUSH;

		switch (mSelection) { // Begin switch

		case 1:
			randomRoll = 1 + rand() % (100 - 1 + 1);
				
			determineEvent(randomRoll, adjustedCR);

			break;

		case 2:

			printf("\nPlease enter the new Average Party Level: ");
			scanf("%i", &rate);
			break;

		case 3:
			printf("\nPlease enter the new count of players in the party: ");
			scanf("%i", &play);
			break;

		case 4:
			printf("Exitting Program. See you next time, adventurer.\n");
			break;

		default:
			printf("\nPlease enter a valid menu option.\n");
		} // End switch

		PAUSE;
	} while (mSelection != 4);	//	End Menu Loop

}	//	End Menu Function