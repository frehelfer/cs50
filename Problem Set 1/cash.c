#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

//Function for getting data
int get_cents()
{
    int c = 0;
    do
    {
        c = get_int("Number of Cents: ");
    }
    while (c < 0);
    return c;
}

//Function for quarters
int calculate_quarters(int cents)
{
    if (cents >= 25)
    {
        return cents / 25;
    }
    else
    {
        return 0;
    }
}

//Function for dimes
int calculate_dimes(int cents)
{
    if (cents >= 10)
    {
        return cents / 10;
    }
    else
    {
        return 0;
    }
}

//Function for nickels
int calculate_nickels(int cents)
{
    if (cents >= 5)
    {
        return cents / 5;
    }
    else
    {
        return 0;
    }
}

//Function for pennies
int calculate_pennies(int cents)
{
    if (cents >= 1)
    {
        return cents;
    }
    else
    {
        return 0;
    }
}
