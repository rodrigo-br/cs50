#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int count(string text, int *sentence, int *letters)
{
    int index = 0;
    int words = 1;

    if (!text)
    {
        return (0);
    }
    while (text[index])
    {
        if (isspace(text[index]))
        {
            words++;
        }
        else if (text[index] == '.' || text[index] == '!' || text[index] == '?')
        {
            (*sentence)++;
        }
        else if (isalpha(text[index]))
        {
            (*letters)++;
        }
        index++;
    }
    return (words);
}

double  average(int x, int y)
{
    return ((double)x * 100 / (double)y);
}

int main(void)
{
    string  text;
    int     words = 0;
    int     sentences = 0;
    int     letters = 0;
    double  cl_index;
    double  l;
    double  s;

    text = get_string("Text: ");
    words = count(text, &sentences, &letters);
    l = average(letters, words);
    s = average(sentences, words);
    cl_index = 0.0588 * l - 0.296 * s - 15.8;
    if (cl_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (cl_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)round(cl_index));
    }
    return (0);
}
