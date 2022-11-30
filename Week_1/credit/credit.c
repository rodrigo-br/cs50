#include <cs50.h>
#include <stdio.h>

int invalid(void)
{
    printf("INVALID\n");
    return (0);
}

int check_size(long n)
{
    int size;

    size = 0;
    while (n > 0)
    {
        n /= 10;
        size++;
    }
    return (size);
}


/*For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:

4003600000000014

Okay, let’s multiply each of the underlined digits by 2:

1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

That gives us:

2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

Now let’s add those products’ digits (i.e., not the products themselves) together:

2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13*/
int first_underline_mult_2(long n, int size)
{
    int limit;
    int counter;
    int result;
    int aux;

    result = 0;
    counter = 0;
    limit = size / 2;
    if (size % 2 != 0)
    {
        limit++;
    }
    n /= 10;
    while (counter < limit)
    {
        aux = (n % 10) * 2;
        if (aux > 9)
        {
            result += aux / 10;
            result += aux % 10;
        }
        else
        {
            result += aux;
        }
        counter++;
        n /= 100;
    }
    return (result);
}

int sum_rest(long n, int size)
{
    int limit;
    int counter;
    int result;

    limit = size / 2;
    if (size % 2 != 0)
    {
        limit++;
    }
    counter = 0;
    result = 0;
    while (counter < limit && n > 0)
    {
        result += (n % 10);
        n /= 100;
    }
    return (result);
}

void find_first_n_second_digit(int *first_digit, int *second_digit, long n, int size)
{
    int counter;

    counter = 0;
    while (counter < size - 2)
    {
        n /= 10;
        counter ++;
    }
    *second_digit = n % 10;
    *first_digit = n / 10;
}

int main(void)
{
    long    card_number;
    int     produt_digit;
    int     first_digit;
    int     second_digit;
    int     size;

    do
    {
        card_number = get_long("Inform the credit card number ");
    }
    while (!card_number);
    size = check_size(card_number);
    if (size < 13 || size > 16 || size == 14)
    {
        return (invalid());
    }
    produt_digit = first_underline_mult_2(card_number, size);
    produt_digit += sum_rest(card_number, size);
    find_first_n_second_digit(&first_digit, &second_digit, card_number, size);
    printf("%d %d %d %d\n", produt_digit, first_digit, second_digit, size);
    if (produt_digit % 10 != 0)
    {
        invalid();
    }
    else if (first_digit == 4 && (size == 13 || size == 16))
    {
        printf("VISA\n");
    }
    else if (first_digit == 3 && (second_digit == 7 || second_digit == 4) && size == 15)
    {
        printf("AMEX\n");
    }
    else if (first_digit == 5 && (second_digit > 0 && second_digit < 6) && size == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        invalid();
    }
    return (0);
}