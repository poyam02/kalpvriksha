//Program to get string input upto particular length
#include<stdio.h> 

int main() {
   char inputString[6];
	printf("Enter a string (Maximum 6 characters only) : ");
	scanf("%6s", inputString);
	printf("You entered: %s\n", inputString);
   return 0;
} 