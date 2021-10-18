#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

//made by Dierta Pasific

void guess (); 
void choose(int A);
void stop(int A); void clearScreen();


int main(){

	clearScreen();
	printf("Hello! Welcome to Latsyrk's Guess Number Game!\nPlease enter a range of number (lower - higher): "); //welcoming sentence for user	
	guess();

	return 0;
	
}


void guess (){
	
	int targetNum;
	char guessNumchar[100];
	int guessNum;
	char lowerchar[100];
	char upperchar[100];
	int lower,upper;
	int pilihan;

	scanf("%s - %s", lowerchar, upperchar); //input range using lower-upper format in form of string

	lower = atoi(lowerchar);
	upper = atoi(upperchar);

	if( lowerchar[0] >= 'A' || upperchar[0] >= 'A'){
		clearScreen();
		printf("\nRange can only be a integer number (lower - higher): "); //id users input is an alphabet, program will go to guess() function
		guess();
	}

	srand(time(NULL)); //time returns the time since 00:00:00 UTC, January 1, 1970 (in seconds), srand--> producing random integers
	targetNum = (rand() % (upper-lower+1))+lower; // to maintain that targetNum is bigger than lower and smaller than upper
	
	for(int i = 1 ; ; i++){
		
		printf("Now enter your guess number: ");

		scanf("%s", &guessNumchar); //input guess number in form of character from user

		guessNum = atoi(guessNumchar); //convert the input from character to integer

		if( guessNum <= upper && guessNum >= lower && guessNumchar[0]<'A') { 
			if(targetNum == guessNum){ //if input is the same with target number
				puts("You did it!");
				for(int i=0; i<10000;i++){
					printf("\nDo you want to play again?(enter number)\n1 Yes\n2 No\n"); // Give the user choice whether they want to play again or not
					scanf("%d", &pilihan);
					choose(pilihan); // use choose function(line 99) 
				}

			}else if(i%5 == 0){ //after 5 times guessing, user will have to choose whether user want to continue or not
				puts("Do you still want to continue?\n1 Yes\n2 No");
				int choices;
				scanf("%d", &choices);
				while(choices != 1 && choices != 2){
					puts("Please enter number between 1 and 2");
					scanf("%d", &choices);
				}
					if(choices == 2){
						clearScreen();
						printf("\n\tThank You for Participating in this game!\n\t          See You next time!\n");
						exit(1);
					} else if (choices == 1){
						printf("Your guess is: ");
						continue;
					}
			}
			 else if(targetNum > guessNum){ //if the input is smaller than the target mumber
				puts("\nYour guess is lower than the target number.");
			} else if(targetNum < guessNum){ //if the input is bigger than the target mumber
				puts("\nYour guess is higher than the target number.");
			} 
		} else if (guessNumchar[0] >= 'A') {//using ascii index, if input is an alphabet, program will print line 88
			puts("\nYou need to enter a number."); 
		} else if (guessNum==targetNum){
			break; //if the guess number is alrady correct (same with target number) the loop will be stopped using break
		} else{
			puts("Stay in the range.");// this occurs when input is outside range the user already input before
		}
	}	
	
	
}

void choose(int choice){
	
	if( choice==1 ){ //if on line 60 user choose "Yes", guess function(line 24 will occurs again)
		clearScreen();
		printf("Please enter a range of number (lower-higher): ");
		guess();
	} else if (choice==2){
		clearScreen();
		printf("\n\tThank You for Participating in this game!\n\t          See You next time!\n");
		exit(1); //if on line 60 user choose"No", the program will stop.
	} else {
		printf("Please enter number between 1 and 2\n"); //this occurs when user input number that is not 1 or 2
	} 
}

void clearScreen(){
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}




