#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*Check for errors*/
int check_args(int argc, string argv[])
{
    int index = 0;
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return (1);
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return (1);
    }
    while (argv[1][index])
    {
        if (!isalpha(argv[1][index]) ||
            strchr(&argv[1][index + 1], argv[1][index]))
        {
            //search for duplicate and invalid characters
            printf("Usage: ./substitution key\n");
            return (1);
        }
        index++;
    }
    return (0);
}

/*put all str uppercase. Used to create the upper map*/
void    to_upper_str(string *str)
{
    int i = -1;
    while ((*str)[++i])
    {
        if ((*str)[i] >= 'a' && (*str)[i] <= 'z')
        {
            (*str)[i] = (*str)[i] - 32;
        }
    }
}

/*put all str lowercase. Used to create the lower map*/
void    to_lower_str(string *str)
{
    int i = -1;
    while ((*str)[++i])
    {
        if ((*str)[i] >= 'A' && (*str)[i] <= 'Z')
        {
            (*str)[i] = (*str)[i] + 32;
        }
    }
}

/*It uses the mappers indexes by converting the ascii
value to integer subtracting 65 (A) or 97 (a) if
Upper or lower respectively*/
void    criptograph(string *str, char *upper, char *lower)
{
    int i = -1;
    while ((*str)[++i])
    {
        if (isalpha((*str)[i]))
        {
            if ((*str)[i] >= 'A' && (*str)[i] <= 'Z')
            {
                (*str)[i] = upper[(*str)[i] - 65];
            }
            else if ((*str)[i] >= 'a' && (*str)[i] <= 'z')
            {
                (*str)[i] = lower[(*str)[i] - 97];
            }
        }
    }
}

/*Couldn't include strdup, don't know why, so i created one*/
char    *ft_strdup(const char *s)
{
    char    *new_str;
    int     index;

    index = 0;
    new_str = malloc(strlen(s) * sizeof(char) + 1);
    if (!new_str)
    {
        return (new_str);
    }
    while (s[index])
    {
        new_str[index] = s[index];
        index++;
    }
    new_str[index] = '\0';
    return (new_str);
}

/*use of strdup to duplicate 2 maps for upper and lower values*/
int main(int argc, string argv[])
{
    char    *map_upper;
    char    *map_lower;
    string  new_str;

    if (check_args(argc, argv))
    {
        return (1);
    }
    map_upper = ft_strdup(argv[1]);
    map_lower = ft_strdup(argv[1]);
    new_str = get_string("plaintext: ");
    to_upper_str(&map_upper);
    to_lower_str(&map_lower);
    criptograph(&new_str, map_upper, map_lower);
    free(map_upper);
    free(map_lower);
    printf("ciphertext: %s\n", new_str);
    return (0);
}