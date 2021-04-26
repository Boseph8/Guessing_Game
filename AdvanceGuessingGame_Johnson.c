#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x,y,z,i,j;
    int count;
    int guess;
    int flag = 0;
    int star = 0;
    int plus = 0;

    printf("Welcome to guessing digit game - advanced version\n");
    printf("Please input how many times you want to guess: ");
    scanf("%d",&guess);

    srand(time(0));
    int code[4] = {rand() % 9 + 1, rand() % 9 + 1, rand() % 9 + 1, rand() % 9 + 1};
    int history[guess][4];
    for (i=0; i<guess; i++){
        for (j=0; j<4; j++){
            history[i][j] = 0;
        }
    }

    for (count=0; count<guess; count++){
        star = 0;
        plus = 0;
        printf("\nTurn #%d ",count + 1);
        printf("Please guess 4 digits.\n");
        printf("Please type using this format: X-X-X-X \n");
        scanf("%d-%d-%d-%d",&history[count][0],&history[count][1],&history[count][2],&history[count][3]);
        for (y=0; y<4; y++){
            if (history[count][y] == code[y]){
                star++;
            }
            for (z=0; z<4; z++){
                if (history[count][y] == code[z]){
                    plus++;
                }
            }
            if (star == 4){
                count = count + guess;
                flag = 1;
                printf("Congratulations, you guessed correctly!");
            }
        }
        printf("Your guess has: %d* and %d+\n",star,plus);
        for (i=0; i<guess; i++){
            for (j=0; j<4; j++){
                printf("%d", history[i][j]);
                if (j == 3){
                    printf("\n");
                }
            }
        }
    }
    if (flag == 0){
        printf("\n\nThe correct number is: %d-%d-%d-%d\n", code[0],code[1],code[2],code[3]);
        printf("Too bad! Better luck next time!");
    }

    return 0;
}