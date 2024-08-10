// 23. Write a program that reads and compare two strings with the help of pointers only.

#include <stdio.h>
#include <string.h>

int compareStrings(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return 0;
        }
        str1++;
        str2++;
    }

    return (*str1 == '\0' && *str2 == '\0');
}

int main()
{
    char str1[100], str2[100];

    printf("Enter strings to check if they are the same or not\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    if (compareStrings(str1, str2))
    {
        printf("Both strings are equal\n");
    }
    else
    {
        printf("Both strings are different\n");
    }

    return 0;
}
