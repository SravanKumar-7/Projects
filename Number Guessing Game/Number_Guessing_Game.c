#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int min=1,max=100,n,roll,i=1;
    srand(time(NULL));
    roll=(rand()%(max-min+1)+min);
    while(n!=roll)
    {
        printf("Enter your guess: ");
        scanf("%d",&n);
        if (n==roll)
        {
            printf("Correct guess!\n");
            printf("You guessed in %d attempts.\n",i);
            break;
        }
        else if (n<roll)
        {
            printf("Too low!\n");
            i++;
        }
        else
        {
            printf("Too high!\n");
            i++;
        }
    }
}