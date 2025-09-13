#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void playRound(int *player_count,int *comp_count,int *draw)
{
    int player,i;
    for(i=1;i<=10;i++)
    {
        while(1)
        {
            printf("Choose 1.rock 2.paper 3.scissors  ");
            scanf("%d",&player);
            if (player >= 1 && player <= 3)
            {
                break;
            }
            else
            {
                printf("Invalid input! Please enter 1, 2, or 3 only.\n");
            }
        }
        int comp=(rand()%3)+1;
        switch(player)
        {
            case 1:
                switch(comp)
                {
                    case 1:
                    printf("It's a draw!\n");
                    (*draw)++;
                    break;
                    case 2:
                    printf("+1 for computer.\n");
                    (*comp_count)++;
                    break;
                    case 3:
                    printf("+1 for you.\n");
                    (*player_count)++;
                    break;
                }
                break;
            case 2:
                switch(comp)
                {
                    case 1:
                    printf("+1 for you.\n");
                    *player_count++;
                    break;
                    case 2:
                    printf("It's a draw!\n");
                    (*draw)++;
                    break;
                    case 3:
                    printf("+1 for computer.\n");
                    (*comp_count)++;
                    break;
                }
                break;
            case 3:
                switch(comp)
                {
                    case 1:
                    printf("+1 for computer.\n");
                    (*comp_count)++;
                    break;
                    case 2:
                    printf("+1 for you.\n");
                    (*player_count)++;
                    break;
                    case 3:
                    printf("It's a draw!\n");
                    (*draw)++;
                    break;
                }
                break;
        }
    }
}
int main()
{
    int player_count=0,comp_count=0,draw=0;
    char choice;
    srand(time(0));
    while(1)
    {
        playRound(&player_count, &comp_count, &draw);
        while(1)
        {
            printf("Total points are:\n");
            printf("You: %d\n",player_count);
            printf("Computer: %d\n",comp_count);
            printf("Total draws: %d\n",draw);
            if (player_count > comp_count)
            {
                printf("Congratulations! You have won.\n");
            }
            else if (player_count < comp_count)
            {
                printf("Sorry, you lost!\n");
                printf("Better luck next time!");
            }
            else
            {
                printf("It's a draw!\n");
                printf("Better luck next time!");
            }
            printf("\nDo you want to play again? (y/n): ");
            scanf(" %c",&choice);
            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
            {
                break;
            }
            else
            {
                printf("Invalid input! Please enter 1, 2, or 3 only.\n");
            }
        }
        if (choice == 'y' || choice == 'Y')
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