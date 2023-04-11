#include<stdio.h>
#include<string.h>
#include <stdbool.h>

bool IfCharacterExists(char p, char q[], int v) {
	int i;
	for (i=0; i<v;i++) {
        if (q[i]==p) 
        return (true);
    }
	return (false);
}
void main() {
	char inputString[50], str[50];
	int lengthOfInputstring, indexOfInputStr, indexOfStr;
	printf("Enter a string: ");
	scanf("%s",inputString);

	lengthOfInputstring = strlen(inputString);
	str[0] = inputString[0];
    
	indexOfStr=1;
	for(indexOfInputStr=1; indexOfInputStr < lengthOfInputstring;  indexOfInputStr ++) {
		if(IfCharacterExists(inputString[indexOfInputStr], str, indexOfStr)) {
			printf("The firstmost repetitive character in above string is: %c ", inputString[indexOfInputStr]);
			break;
		} else {
			str[indexOfStr] = inputString[indexOfInputStr];
			indexOfStr++;
		}
	}
	if(indexOfInputStr == lengthOfInputstring)
		printf("No repetitve character found in the string entered.");
}