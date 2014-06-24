/* ------------------------------------------------
* MiniMasterMind
* Class: CS 141, Spring 2014. Thurs 12pm lab.
* System: Windows 8, written in Codewriter, 
		  compiled with Visual Studio
* Author: Allison Channic
* -------------------------------------------------
*/

//Include necessary C libraries
#include <stdlib.h>
#include <time.h>

/* Main method
* The game operates by first choosing a random number consisting of three 
* digits. The player then tries to guess the number by typing in three
* digits. If any digit is in the correct place, the number of digits in the
* correct place are indicated under the "in place" column. If the user guesses
* any correct digits but they do not correspond to the digit placement of the 
* hidden number, the number is considered to be "out of place." The game 
* indicates the number of digits "out of place" in the "out of place" column. 
* The user has ten tries to guess the number. If the user correctly guesses the
* number and all three digits within 10 turns, the user has won.
*/
int main(int argc, const char* argv[]) {
	//Set up the random number function in C
	srand((int) time(0));
	
	//Initialize and declare the digits to be guessed by the user.
	//Each digit is chosen randomly from 0 - 9.
	//HundredsDigit corresponds to the "first" digit, based on the digits
	//of ordinary decimal numbers, and so forth.
	int onesDigit = rand() % 10;
	int tensDigit = rand() % 10;
	int hundredsDigit = rand() % 10;
	
	//Check to see that none of the digits are equal to each other
	//If they are, change the value of each until all digits are different
	while ((onesDigit == tensDigit) || (onesDigit == hundredsDigit) || 
		   (tensDigit == hundredsDigit)){
		onesDigit = rand() % 10;
		tensDigit = rand() % 10;
		hundredsDigit = rand() % 10;
	}
	
	//Convert chars to integer values
	if(argc > 1) {
        hundredsDigit = argv[1][0] - '0';
        tensDigit = argv[1][1] - '0';
        onesDigit = argv[1][2] - '0';
	}
	
	//Prints project header with name, lab time, and project name
	printf("\nAuthor: Allison Channic\n");
	printf("Lab: Thursday 12:00pm\n");
	printf("Program #2: MiniMasterMind\n\n");
	
	//Prints game instructions to the user
	printf("Welcome to MiniMastermind.\n");
	printf("The program selects 3 distinct random digits 0..9.\n"); 
	printf("On each turn you guess 3 digits.\n");
	printf("Program indicates how many digits are correct.\n"); 
	printf("You have 10 moves to guess the number. Good luck!\n\n");
	
	/*Prints the column headers for number digits that are "in place" and 
	"out of place"
	*/
	printf("\t \t \t \t\tIn Place \t Out of Place\n");
	printf("\t \t \t \t\t--------- \t ------------\n");
	
	/*Initialize variables for the number of digits in the correct place,
	  number of digits out of place, the three digit number the user
	  guesses, and the ones, tens and hundreds digit of that number.
	*/
	int numDigitsCorrect = 0;
	int numDigitsOutOfPlace = 0;
	int userGuess;
	int userGuessHundreds;
	int userGuessTens;
	int userGuessOnes;
	
	/*For loop to iterate gameplay for ten turns, where numGuesses indicates 
	  what turn the user is on. Loop works by prompting the user to guess a 
	  three digit number. The number is then separated into digits (ones, tens
	  and hundreds). The program then checks to see if each digit is equal to 
	  the digits of the number the user is trying to guess. If the digit is in 
	  the correct place, the variable "numDigitsCorrected" is increased by 1.
	  If a digit is correct but not in the correct place, the variable 
	  "numDigitsOutOfPlace" is. Process is repeated for each of the 10 turns.
	*/
	
	//Initialize loop variable representing the number of turns
	int numGuesses;
	
	//Begin loop;
	for (numGuesses = 1; numGuesses <= 10; numGuesses++) {
		
		/*Prompts the user to guess a number and tells them
		  what turn they are on. Guess is scanned into the
		  variable "userGuess"
	    */
		printf("%d.) Your guess: ", numGuesses);
		scanf("%d", &userGuess);
		
		//Parse the user's guess into three separate digits
		userGuessOnes = userGuess % 10;
		userGuessTens = (userGuess/10) % 10;
		userGuessHundreds = userGuess/100;
		
		/*Checks to see if each digit is the same as the digits of 
		  the hidden number. If it is, numDigitsCorrect increases by 1.
		  If a digit is correct but out of place, numDigitsOutOfPlace
		  is increased by 1. If the user guesses no digits correct,
		  both variables remain at 0.
		*/
		if (userGuessHundreds == hundredsDigit)
			numDigitsCorrect++;
		else if ((userGuessHundreds == onesDigit) || 
				(userGuessHundreds == tensDigit))
			numDigitsOutOfPlace++;
			
		if (userGuessTens == tensDigit)
			numDigitsCorrect++;
		else if ((userGuessTens == onesDigit) || 
				(userGuessTens == hundredsDigit))
			numDigitsOutOfPlace++;
			
		if (userGuessOnes == onesDigit)
			numDigitsCorrect++;
		else if ((userGuessOnes == tensDigit) || 
				(userGuessOnes == hundredsDigit))
			numDigitsOutOfPlace++;
			
		//Tells the user what number they entered and tells them how many 
		//digits are in place and how many are out of place	
		printf("\t\tYou entered: %d%d%d \t   %d\t\t\t%d\n", userGuessHundreds, 
				userGuessTens, userGuessOnes, numDigitsCorrect, 
				numDigitsOutOfPlace);
		
		/*If the user enters all three digits correctly, the user has won and
		  the loop stops.
		  If not, both numDigitsCorrect and numDigitsOutOfPlace are reset to 0.
		*/
		if (numDigitsCorrect == 3) {
			printf("\n*** Congratulations! You guessed the number. ***\n\n");
			break;
		}
		else {
			numDigitsCorrect = 0;
			numDigitsOutOfPlace = 0;
		}
		
		//If the user still has not guessed all three digits by the 10th turn,
		//the user has lost and the hidden number is revealed.
		if ((numGuesses == 10) && (numDigitsCorrect != 3)){
			printf("\nBetter luck next time. The number was %d%d%d. \n\n", 
					hundredsDigit, tensDigit, onesDigit);
		}
	}
	
	//Thanks the user for playing and exits the program.
	printf("Thank you for playing. Now exiting.");
}