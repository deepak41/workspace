#include<stdio.h>

int main()
{
    float cost, rate, amount;
    rate=15.0/100.0;
    
    printf("Enter amount in grams");
    scanf("%f", &amount);
    
    cost = rate*amount;
    
    printf("Cost = Rs %.2f", cost);
    
    getch();
    return 0;
    
    
}
