#include <stdio.h>

void GetStringCopy(char secondString[50], char firstString[50]) {
    int index;
    for (index = 0; firstString[index] != '\0'; index++) {
        secondString[index] = firstString[index];
    }
    secondString[index] = '\0';
}

int main() {
    char firstString[50], secondString[50];
    int i;
    printf("Enter the string you want to copy : ");
    gets(firstString);
    GetStringCopy(secondString, firstString);
    printf("The copied string is : %s", secondString);

    return 0;
}