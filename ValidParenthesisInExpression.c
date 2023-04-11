// Check if parenthesis in an expression are valid or not
#include<stdio.h>  

int main() {  
    char expression[100]; 
    int count=0, index=0;  
    printf("\nEnter an expression");  
    scanf("%s", expression);      
    while(expression[index]!= '\0') {   
        if(expression[index]=='(') {  
            count++;   
        } else if(expression[index]==')') {  
            count--;   
            if(count<0)  
                break;  
        }  
    index++;     
    }  

    if(count==0) {  
        printf("The parenthesis in the entered expression is valid");  
    } else {  
        printf("The parenthesis in the entered expression is not valid");  
    }  
    return 0;  
} 