//Program to check if entered substring is found in string 

#include<stdio.h> 
#include<string.h> 
#include <stdbool.h>

void main() {
    char inputString[50], searchString[20]; 
    bool isSubstring=false; 
    
    printf("Enter input string: "); 
    fgets(inputString, sizeof inputString, stdin); 
    
    printf("Enter search string: ");
    fgets(searchString, sizeof searchString, stdin); 
    
    int totalInputCount=0, totalSubStringCount=0; 
    
    while(inputString[totalInputCount] != '\0') {
        totalInputCount++; 
    }
    totalInputCount--; 
    
    while(searchString[totalSubStringCount] != '\0') {
        totalSubStringCount++; 
    }
    totalSubStringCount--; 
    
    for(int i=0; i<=totalInputCount-totalSubStringCount; i++)
	{ 
		for(int j=i; j<i+totalSubStringCount; j++)
		{
			isSubstring = true;
			if (inputString[j] != searchString[j-i])
			{
				isSubstring = false;
			    break;
			}
		}
		if (isSubstring == true)
			break;
	} 
	
	if (isSubstring == true) {
		printf("Entered substring is found in the string"); 
	}
	else {
		printf("Entered substring is not found in the string"); 
	}
}