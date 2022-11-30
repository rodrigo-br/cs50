#include <cs50.h>
#include <stdio.h>

/*Print spaces before bricks*/
void    print_spaces(int height)
{
    while (height--)
    {
        printf(" ");
    }
}

/*Print first block of bricks, then space, then the next block*/
void    print_bricks(int bricks)
{
    int counter;

    counter = 0;
    while (counter < bricks)
    {
        printf("#");
        counter++;
    }
    printf("  ");
    counter = 0;
    while (counter < bricks)
    {
        printf("#");
        counter++;
    }
}

int main(void)
{
    int     height;
    int     n_of_bricks;

    do
    {
        height = get_int("Choose a height: ");
    }
    while (height < 1 || height > 8);
    n_of_bricks = 1;
    while(height--)
    {
        print_spaces(height);
        print_bricks(n_of_bricks);
        printf("\n");
        n_of_bricks++;
    }
}
