#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main() {
  int ties = 0, wins = 0, losses = 0;


  while(1){
    printf("\e[1;1H\e[2J");
    for(int i = 0; i < 3; i++){
    printf("Starting in %d\n",3-i);
    sleep(1);
  }

  

  srand(time(NULL));
  int upper_bound = 2;
  int lower_bound = 0;
  printf("\e[1;1H\e[2J");
 

    if(T == 0 && W == 0 && L ==0){
      printf("Welcome to Rock Paper Scissors\n");
    }else{
      printf("Wins: %d Losses: %d Draws: %d\n",W,L,T);}

  printf("Enter your choice: 0 for rock, 1 for paper, 2 for scissors \n");

  int userChoice;

  scanf("%d",&userChoice);

  while(userChoice < 0 || userChoice > 2){
    printf("\e[1;1H\e[2J");
    printf("Invalid choice\n");
    printf("Enter your choice: 0 for rock, 1 for paper, 2 for scissors \n");
    scanf("%d",&userChoice);
      
  }
  
  int compChoice = rand() % (upper_bound - lower_bound + 1) + lower_bound;
  char choices[3][9] = {"rock","paper","scissors"};

  printf("User choice: %s\n",choices[userChoice]);
  printf("Comp choice: %s\n",choices[compChoice]);

  if(strcmp(choices[userChoice],choices[compChoice]) == 0){
    printf("It's a draw\n");
      T++;
  }

  if(strcmp(choices[userChoice],choices[compChoice]) != 0){
    if(userChoice == 0){
      if(compChoice == 1){
      printf("Comp wins\n");
          L++;
      }else{
      printf("User wins\n");
      W++;
      }
    }else if(userChoice == 1){
      if(compChoice == 2){
      printf("Comp wins\n");
          L++;
      }else{
      printf("User wins\n");
          W++;
      }
    }else{
      if(compChoice == 0){
      printf("Comp wins\n");
          L++;
      }else{
      printf("User wins\n");
          W++;
      }
    }
  }for(int i = 0;i < 3; i++){
      sleep(3);
    }

  }
  return 0;
  
}
