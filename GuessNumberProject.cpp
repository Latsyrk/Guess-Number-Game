#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//made by Dierta Pasific

void guess (); 
void choose(int A);
void stop(int A);

int main(){

	int pilihan;
	
	printf("Hello! Welcome to Latsyrk's Game!\nPlease enter a range of number (lower-higher): "); //welcoming sentence for user
			
	guess();
	
	//after playing 1 time using guess function(line 30), user can choose whether they want to play again or to stop using choose function(line 90)
	for(int i=0; i<10000;i++){
		printf("\nDo you want to play again?(enter number)\n1 Yes\n2 No\n"); // Give the user choice whether they want to play again or not
		scanf("%d", &pilihan);
		choose(pilihan); // use choose function(line 90) 
	}

	return 0;
	
}
void guess (){
	
	int targetNum;
	int guessNum;
	int lower,upper;
	
	scanf("%d-%d", &lower, &upper); //input range using lower-upper format
	printf("Nice! Now guess a number beetwen the range.\n");
	
	srand(time(NULL)); //time returns the time since 00:00:00 UTC, January 1, 1970 (in seconds), srand--> producing random integers
	targetNum = (rand() % (upper-lower+1))+lower; // to maintain that targetNum is bigger than lower and smaller than upper
	
	for(int i = 1 ; ; i++){
		scanf("%d", &guessNum); //input guess number from user
		
		if( guessNum <= upper && guessNum >= lower) { 
			if(targetNum == guessNum){ //if input is the same with targer number
				puts("You did it!");
			}else if(i%5 == 0){ //after 5 times guessing, user will have to choose whether user want to continue or not
				puts("Do you still want to continue?\n1 Yes\n2 No");
				int choices;
				scanf("%d", &choices);
				while(choices != 1 && choices != 2){
					puts("Please enter number between 1 and 2");
					scanf("%d", &choices);
				}
					if(choices == 2){
						printf("Thank You for Participating in this game!\nSee You next time!\n");
						exit(1);
					} else if (choices == 1){
						printf("Your guess is: ");
						continue;
					}
			}
			 else if(targetNum > guessNum){ //if the input is smaller than the target mumber
				puts("Your guess is lower than the target number.");
			} else if(targetNum < guessNum){ //if the input is bigger than the target mumber
				puts("Your guess is higher than the target number.");
			} 
		} 
		else {
			puts("Stay in the range."); // this occurs when input is outside range the user already input before
		}	
	
		if(guessNum==targetNum){
			break; //if the guess number is alrady correct (same with target number) the loop will be stopped using break
		}
	}	
	
	
}

void choose(int choice){
	
	if( choice==1 ){ //if on line 21 user choose "Yes", guess function(line 30 will occurs again)
		printf("Please enter a range of number (lower-higher): ");
		guess();
	} else if (choice==2){
		printf("Thank You for Participating in this game!\nSee You next time!\n");
		exit(1); //if on line 21 user choose"No", the program will stop.
	} else {
		printf("Please enter number between 1 and 2\n"); //this occurs when user input number that is not 1 or 2
	} 
}



