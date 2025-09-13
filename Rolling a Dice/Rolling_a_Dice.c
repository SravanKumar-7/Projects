#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int rol,max=6,min=1;
    srand(time(0));   // you can use 0 ot NULL 
    rol=(rand()%(max-min+1)+min);
    printf("%d",rol);
    return 0;
}