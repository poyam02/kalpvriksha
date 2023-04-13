#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left; 
    struct node* right;
}
node;

node* InsertElementInTree(int value, node* tnode) {
    if (tnode == NULL) {
        tnode = (node*)malloc(sizeof(node));
        tnode->value = value;
        tnode->left = NULL;
        tnode->right = NULL;
    } else if (value < tnode->value)
        tnode->left = InsertElementInTree(value, tnode->left);
    else
        tnode->right = InsertElementInTree(value, tnode->right);

    return tnode;
}

void PrintInorder(struct node *root) {  
    if(root == NULL)  
        return;  
   
    PrintInorder(root->left);  
    printf("%d ",root->value);  
    PrintInorder(root->right);  
}  

void PrintPreorder(struct node *root) {  
    if(root == NULL)  
        return;  
    
    printf("%d ",root->value);   
    PrintPreorder(root->left);   
    PrintPreorder(root->right);  
} 

void PrintPostorder(struct node *root) {  
    if(root == NULL)  
        return;  
  
    PrintPostorder(root->left);  
    PrintPostorder(root->right);  
    printf("%d ",root->value);  
} 

int main() {
    int i, numberOfElements, chooseOperation, value;
    node* root = NULL;
    printf("Enter number of elements : ");
    scanf("%d", &numberOfElements);
    printf("Enter elements to be inserted in tree : ");
    for (i = 0; i < numberOfElements; i++) {
        scanf("%d", &value);
        root = InsertElementInTree(value, root);
    }
    printf("Press 1 for In-order traversal, 2 for Pre-order, 3 for Post-order \n");
    scanf("%d", &chooseOperation);
    switch(chooseOperation) {
        case 1 :
            PrintInorder(root);
            break;
        
        case 2 :
            PrintPreorder(root);
            break;
            
        case 3 :
            PrintPostorder(root);
            break;
        default :
            printf("Invalid choice");
            break;
    }
    return 0;
}