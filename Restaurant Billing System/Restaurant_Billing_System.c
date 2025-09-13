#include<stdio.h>
#include<string.h>
int main()
{
    const char valid_username[]="admin";
    const char valid_password[]="hi@123";
    char username[50],password[50];
    int login_attempts=0;
    printf("Welcome to Hi Restaurant.\n");
    printf("Please login to continue...... \n");
    while (login_attempts < 3)
    {
        printf("Enter username: ");
        scanf("%s",&username);
        printf("Enter password: ");
        scanf("%s",&password);
        if (strcmp(username, valid_username) == 0 && strcmp(password, valid_password) == 0)
        {
            printf("Login successful! \nAcces granted.\n");
            break;
        }
        else
        {
            printf("Invalid username or password. Try again.\n");
            login_attempts++;
        }
        if (login_attempts == 3)
        {
            printf("Too many login attempts! Exiting the program.\n");
            return 1;
        }
    }
    int meal_plan, order_no, qty, add_more;
    int total=0;
    float cgst, sgst, total_bill;

    char *breakfast_menu[]={"Idly","Dosa","Woda","Bonda","Puri","Tea/Coffee"};
    int breakfast_prices[]={50,60,70,60,70,30};

    char *lunch_menu[]={"Veg Thali","Non-Veg Thali","Chicken biryani","Mutton Biryani","Veg Biryani","Salad/Papad","Cold Drink"};
    int lunch_prices[]={280,150,230,300,250,45,90};

    char *dinner_menu[]={"Chicken Biryani","Mutton Biryani","Chicken Curry","Paneer Curry","Roti/Chapati","Soup"};
    int dinner_prices[]={230,300,300,250,20,120};

    char **menu;
    int *prices;
    int menu_size;
    int order_quantity[10]={0};
    printf("\nChoose your meal plan: \n");
    printf("1. Breakfast\n2. Lunch\n3. Dinner\n");
    if (scanf("%d", &meal_plan) != 1)
    {
        printf("Invalid input! Please enter a number.\n");
        while(getchar() != '\n');
        return 1;
    }

    switch (meal_plan)
    {
        case 1: 
            menu=breakfast_menu;
            prices=breakfast_prices;
            menu_size=sizeof(breakfast_prices)/sizeof(breakfast_prices[0]);
            break;
        case 2:
            menu=lunch_menu;
            prices=lunch_prices;
            menu_size=sizeof(lunch_prices)/sizeof(lunch_prices[0]);
            break;
        case 3:
            menu=dinner_menu;
            prices=dinner_prices;
            menu_size=sizeof(dinner_prices)/sizeof(dinner_prices[0]);
            break;
    }
    printf("\nMenu:\n");
    for (int i=0;i<menu_size;i++)
    {
        printf("%d. %s - %d/-\n",i+1,menu[i],prices[i]);
    }
    do
    {
        printf("\nEnter item no to order: ");
        if (scanf("%d", &order_no) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');
            return 1;
        }
        if (order_no < 1 || order_no > menu_size)
        {
            printf("Invalid choice! Please try again.\n");
            continue;
        }
        printf("Enter quantity: ");
        if (scanf("%d", &qty) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');
            return 1;
        }
        order_quantity[order_no-1] += qty;
        total += prices[order_no-1]*qty;
        printf("\nAdd more to your order? (1 for yes/ 0 for no): ");
        if (scanf("%d", &add_more) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');
            return 1;
        }
    }while(add_more == 1);

    printf("\nGenerating your BILL...\n\n");
    printf("BILL Generated\n");
    printf("========================================\n");
    printf("Item                Quantity   Price\n");
    printf("----------------------------------------\n");
    for (int i=0;i<menu_size;i++)
    {
        if (order_quantity[i] > 0)
        {
            printf("%-18s %3d   %5d/-\n",menu[i],order_quantity[i],prices[i] * order_quantity[i]);
        }
    }
    printf("----------------------------------------\n");
    printf("Sum total                    : %d/-\n", total);

    cgst=total*0.05;
    sgst=total*0.05;
    printf("CGST 5%%                      : %.2f/-\n", cgst);
    printf("SGST 5%%                      : %.2f/-\n", sgst);
    total_bill=total+cgst+sgst;
    printf("Total Bill                   : %.2f/-\n", total_bill);
    printf("========================================\n");
    return 0;
}