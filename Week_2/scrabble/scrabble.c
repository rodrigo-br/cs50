#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return (0);
}

void    to_upper_str(string *word)
{
    int i = -1;
    while ((*word)[++i])
    {
        if ((*word)[i] >= 'a' && (*word)[i] <= 'z')
        {
            (*word)[i] = (*word)[i] - 32;
        }
    }
}

int     ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z'));
}

int     compute_score(string word)
{
    int points = 0;
    int i = 0;

    to_upper_str(&word);
    while (word[i])
    {
        if (ft_isalpha(word[i]))
        {
            points += POINTS[word[i] - 65];
        }
        i++;
    }
    return (points);
}
