#include <stdio.h>
#include <string.h>
 
int main() {
  	char string[50];
  	int startIndex, endIndex;
 
  	printf("Enter a String : ");
  	gets(string);
  	endIndex = strlen(string) - 1;
  	
  	printf("String after reversing words :\n"); 	   	
  	for(int i = strlen(string) - 1; i >= 0; i--) {
		if(string[i] == ' ' || i == 0) {
			if(i == 0) {
				startIndex = 0;
			} else {
				startIndex = i + 1;
			}
			for(int j = startIndex; j <= endIndex; j++) {
				printf("%c", string[j]);
			}
			endIndex = i - 1;
			printf(" ");				
		} 
	}
  	return 0;
}