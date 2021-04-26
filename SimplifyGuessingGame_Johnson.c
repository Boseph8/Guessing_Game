#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

   srand(time(0));
   int x = rand() % 101;
   int y,z,count;
   int flag = 0;

   printf("Welcome to guessing digit game - simplify version\n");
   printf("Please input how many times you want to guess: ");
   scanf("%d", &y);

   for (count=1; count<=y; count++){
       printf("Please guess a number from 0 - 100:\n");
       scanf("%d", &z);
       if (z == x){
           printf("Congratulations! You guessed correctly.\n");
           count = y + 1;
           flag = 1;
       }
       else if (z < x){
           printf("Your guess is lower than the correct number.");
       }
       else if (z > x){
           printf("Your guess is higher than the correct number.");
       }
   }
   if (flag == 0){
       printf("The correct number is : %d\n", x);
       printf("Too bad! Better luck next time!");
   }

   return(0);
}