#include <stdio.h>
#include <string.h>
 
void swap(char* firstChar, char* secondChar) {
    char temp;
    temp = *firstChar;
    *firstChar = *secondChar;
    *secondChar = temp;
}

void FindPermute(char* string, int start, int end) {
    int i;
    if (start == end)
        printf("%s\n", string);
    else {
        for (i = start; i <= end; i++) {
            swap((string + start), (string + i));
            FindPermute(string, start + 1, end);
            swap((string + start), (string + i)); 
        }
    }
}

void main() {
    char inputString[20];
    printf("Enter a string : ");
    scanf("%s", inputString);
    int lengthOfString = strlen(inputString);
    FindPermute(inputString, 0, lengthOfString - 1);
}