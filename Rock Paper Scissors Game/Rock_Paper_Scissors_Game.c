#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void playRound()
{
    int player,comp=(rand()%3)+1;
    while(1)
    {
        printf("Choose 1.rock 2.paper 3.scissors  ");
        scanf("%d",&player);
        if (player>=1 && player<=3)
        {
            break;
        }
        else
        {
            printf("Invalid input! Please enter 1, 2, or 3 only.\n");
        }
    }
    switch(player)
    {
        case 1:
            switch(comp)
            {
                case 1:
                printf("It's a draw!\n");
                break;
                case 2:
                printf("Sorry, you lost!\n");
                break;
                case 3:
                printf("Congratulations! You have won.\n");
                break;
            }
            break;
        case 2:
            switch(comp)
            {
                case 1:
                printf("Congratulations! You have won.\n");
                break;
                case 2:
                printf("It's a draw!\n");
                break;
                case 3:
                printf("Sorry, you lost!\n");
                break;
            }
            break;
        case 3:
            switch(comp)
            {
                case 1:
                printf("Sorry, you lost!\n");
                break;
                case 2:
                printf("Congratulations! You have won.\n");
                break;
                case 3:
            printf("It's a draw!\n");
                break;
            }
            break;
    }
}
int main()
{
    char choice;
    srand(time(0));
    while(1)
    {
        playRound();
        while(1)
        {
            printf("\nDo you want to play again? (y/n): ");
            scanf(" %c",&choice);
            if (choice=='y' || choice=='Y' || choice=='n' || choice=='N')
            {
                break;
            }
            else
            {
                printf("Invalid input! Please enter 1, 2, or 3 only.\n");
            }
        }
        if (choice=='y' || choice=='Y')
        {
            continue;
        }
        else
        {
            break; 
        }
    }
    return 0;
}