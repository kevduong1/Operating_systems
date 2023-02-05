#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#include "../include/sstring.h"

// Verifies if the passed character array is null terminated or not.
// \param str the character array that may be null terminated
// \param length to prevent buffer overflow while checking
// \return true if the character array is a string
bool string_valid(const char *str, const size_t length)
{
    if (str == NULL)
        return false;

    for (size_t i = 0; i < length; i++)
    {
        if (str[i] == '\0')
        {
            return true;
        }
    }
    return false;
}

// Copy the contents of the passed string upto the given length
// \param str is the string that will be copied into heap allocated string
// \param length the number of characters to copy
// \return an allocated pointer to new string, else NULL
char *string_duplicate(const char *str, const size_t length)
{
    if (str == NULL || length == 0)
        return NULL;

    char *duplicate_str = (char *)malloc((length + 1) * sizeof(char));

    for (size_t i = 0; i < length; i++)
    {
        duplicate_str[i] = str[i];
    }

    duplicate_str[length] = '\0';
    return duplicate_str;
}

// Checks to see if both strings contain the same characters
// \param str_a the string that will be compared against
// \param str_b the string that will be compared with str_a
// \param length the number of characters to be compared
bool string_equal(const char *str_a, const char *str_b, const size_t length)
{
    if (str_a == NULL || str_b == NULL || length == 0)
        return false;

    for (size_t i = 0; i < length; i++)
    {
        if (str_a[i] != str_b[i])
            return false;
    }
    return true;
}

// Finds the number of characters in the string, not including the null terminator
// \param str the string to count the number of characters in the string
// \param length the max possible string length for the application
// \return the length of the string or -1 for invalid string
int string_length(const char *str, const size_t length)
{
    if (str == NULL || length == 0)
        return -1;

    int count = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (str[i] == '\0')
            break;
        else
            count++;
    }

    return count;
}
// Split the incoming string to tokens that are stored in a passed allocated tokens string array
// \param str the string that will be used for tokenization
// \param delims the delimiters that will be used for splitting the str into segments
// \param str_length the lengt of the str
// \param tokens the string array that is pre-allocated and will contain the parsed tokens
// \param max_token_length the max length of a token string in the tokens string array with null terminator
// \param requested_tokens the number of possible strings that tokens string array can contain
// \return returns the number of actual parsed tokens, 0 for incorrect params, and -1 for incorrect token allocation
int string_tokenize(const char *str, const char *delims, const size_t str_length, char **tokens, const size_t max_token_length, const size_t requested_tokens)
{
    if (str == NULL || delims == NULL || tokens == NULL || max_token_length == 0 || requested_tokens == 0 || str_length == 0)
        return 0;

    int token_count = 0;
    int token_start = 0;

    for (size_t i = 0; i < str_length; i++)
    {
        if (str[i] == delims[0] || str[i] == '\0')
        {
            int index = 0;
            for (size_t k = token_start; k < i; k++)
            {
                if (tokens[token_count] == NULL)
                    return -1;
                tokens[token_count][index] = str[k];
                index++;
            }
            token_start = i + 1;
            token_count = token_count + 1;
        }
    }

    return token_count;
}

// Converts the passed string into a integer
// \param str The string that contains numbers
// \param converted_value the value converted from the passed string str
// \return true for a successful conversion, else false
bool string_to_int(const char *str, int *converted_value)
{
    if (str == NULL || converted_value == NULL)
        return false;
    int res = 0;
    int old_res = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            break;
        }
        res = res * 10 + str[i] - '0';
        if (res < old_res)
            return false;
        old_res = res;
    }

    *converted_value = res;
    return true;
}
