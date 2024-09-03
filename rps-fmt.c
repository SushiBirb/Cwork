#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(void) {
  // You can condense these into a one-liner
  // Also, use descriptive variable names you have autocomplete man
  int ties = 0, wins = 0, losses = 0;

  while (1) { // for (;;) also works but this is more idomatic so it's fine
    printf("\e[1;1H\e[2J");
    for (int i = 0; i < 3; ++i) {
      printf("Starting in %d\n", 3 - i);
      sleep(1);
    }

    srand(time(NULL));
    /* int upper_bound = 2;
    int lower_bound = 0;
    printf("\e[1;1H\e[2J"); */ 

    // This nor the starting sectgion should really be in the loop but I'll keep it because it's a stylistic choice
    if (ties + wins + losses == 0) {
      printf("\e[1;1H\e[2J");
      printf("Welcome to Rock Paper Scissors\n");
    } else {
      printf("\e[1;1H\e[2J");
      printf("Wins: %d Losses: %d Draws: %d\n", wins, losses, ties);
    }

    printf("Enter your choice: 0 for rock, 1 for paper, 2 for scissors \n");

    int userChoice;

    // If you want to error handle it's smarter to take in a string and parse it yourself
    // Use fgets to get a string with defined size, then use sscanf to check that it's a valid number

    // scanf("%d", &userChoice); 
    char buf[128];
    fgets(buf, 128, stdin);
    fflush(stdin); // Clear the input buffer, fgets leaves the \n in the buffer fucking things up
    
    // Continue asking for input until the user gives a valid input
    // It's important to remember the mechanics of the && operator here
    // 
    // In the case you have a statement like the following:
    // false && (statement to evaluate)
    // The compiler will see the first false and completely ignore the second statement
    //
    // It only executes the second statement if the first one is true
    //
    // This is somewhat important because userChoice is 0 by default (as an uninitialized int)
    // This behavior would never show in this sample but it's still something to remember
    // This way the only case in which you're actually comparing userChoice requires it being defined properly
    while ((sscanf(buf, "%d", &userChoice) != 1) && (userChoice < 0 || userChoice > 2)) {
      printf("Invalid choice\n");
      printf("Enter your choice: 0 for rock, 1 for paper, 2 for scissors \n");
      fgets(buf, 128, stdin);
    }

    int compChoice = rand() % 3; // it's more succinct to just get rid of the unnecessary variables here
    char *choices[3] = { // BRO JUST USE A STRING ARRAY HERE LMAO
      "rock",
      "paper",
      "scissors"
    };

    printf("User choice: %s\n", choices[userChoice]);
    printf("Comp choice: %s\n", choices[compChoice]);

    // In cases like these switches are clunky but marginally faster (also compare indices don't strcmp if possible it's way slower)
    switch (userChoice) {
      case 0:
        if (compChoice == 0) {
          printf("It's a tie!\n");
          ties++;
        } else if (compChoice == 1) {
          printf("You lose!\n");
          losses++;
        } else {
          printf("You win!\n");
          wins++;
        }
        break;
      case 1:
        if (compChoice == 0) {
          printf("You win!\n");
          wins++;
        } else if (compChoice == 1) {
          printf("It's a tie!\n");
          ties++;
        } else {
          printf("You lose!\n");
          losses++;
        }
        break;
      case 2:
        if (compChoice == 0) {
          printf("You lose!\n");
          losses++;
        } else if (compChoice == 1) {
          printf("You win!\n");
          wins++;
        } else {
          printf("It's a tie!\n");
          ties++;
        }
        break;
    }
    for(int i = 0; i < 3; i++) {
      sleep(1);
    }
  }
  return 0;

}
