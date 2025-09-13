#include<stdio.h>
#include<stdlib.h>
#include<string.h>
float balance=1000.0;
char pin[5]="1234";
int checkPIN()
{
    char input[5];
    printf("Enter your pin: ");
    scanf("%s",input);
    return strcmp(input, pin) == 0;
}
void viewBalance()
{
    printf("Your current balance is Rs. %.2f/-\n",balance);
}
void depositMoney()
{
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f",&amount);
    if (amount > 0)
    {
        balance += amount;
        printf("Rs. %.2f/- Deposited successfully.",amount);
    }
    else
    {
        printf("Invalid amount.\n");
    }
}
void withdrawMoney()
{
    float amount;
    printf("Enter amount to withdraw: Rs. ");
    scanf("%f",&amount);
    if (amount <= balance && amount > 0)
    {
        balance -= amount;
        printf("Rs. %.2f/- Withdrawed successfully.\n",amount);
    }
    else
    {
        printf("Insufficient balance or Invalid amount.\n");
    }
}
void changePIN()
{
    char oldPIN[5], newPIN[5];
    printf("Enter current pin: ");
    scanf("%s",oldPIN);
    if (strcmp(oldPIN, pin) == 0)
    {
        printf("Enter new pin: ");
        scanf("%s",newPIN);
        strcpy(pin, newPIN);
        printf("PIN changed successfully.\n");
    }
    else
    {
        printf("Wrong current PIN!\n");
    }
}
int main()
{
    int choice;
    if (!checkPIN())
    {
        printf("Incorrect PIN. Access Denied.\n");
        return 0;
    }
    do 
    {
        printf("\n=====ATM Menu=====\n");
        printf("1. View Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                viewBalance();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                changePIN();
                break;
            case 5:
                printf("Thanks for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    }while (choice != 5);
    return 0;
}