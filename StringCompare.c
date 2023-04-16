#include <stdio.h>

int main() {
    char firstString[50], secondString[50];
    int flag;

    printf("Enter the first string : ");
    gets(firstString);
    printf("Enter the second string : ");
    gets(secondString);

    flag = CompareStrings(firstString, secondString);

    if (flag == 0) {
        printf("Given strings are similar");
    } else {
        printf("Given strings are not similar");
    }

    return 0;
}

int CompareStrings(char firstString[50], char secondstring[50]) {
    int index, lengthOfFirstString = 0, lengthOfSecondString = 0, flag = 0;
    for (index = 0; firstString[index] != '\0'; index++) {
        lengthOfFirstString++;
    }
    for (index = 0; secondstring[index] != '\0'; index++) {
        lengthOfSecondString++;
    }

    if (lengthOfFirstString != lengthOfSecondString) {
        return (1);
    } else {
        for (index = 0; index < lengthOfFirstString; index++) {
            if (firstString[index] != secondstring[index]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            return (0);
        } else {
            return (1);
        }
    }
}