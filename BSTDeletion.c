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

node* DeleteElementFromTree(struct node* root, int value) {
    if(root == NULL) {
        return root; 
    } 

    if(root -> value > value) {
        root -> left = DeleteElementFromTree(root -> left, value); 
    } 

    if(root -> value < value) {
        root -> right = DeleteElementFromTree(root -> right, value); 
    } else {
        if(root -> left == NULL) {
            struct node* tempNode = root -> right; 
            free(root); 
            return tempNode; 
        } else if(root -> right == NULL) {
            struct node* tempNode = root -> left; 
            free(root); 
            return tempNode; 
        } 
        
        struct node* tempNodeFirst = root -> right; 
        struct node* tempNodeSecond = tempNodeFirst; 
        while(tempNodeSecond && (tempNodeSecond -> left != NULL)) {
            tempNodeSecond = tempNodeSecond -> left; 
        } 
        
        root -> value = tempNodeFirst -> value; 
        root -> right = DeleteElementFromTree(root -> right, tempNodeFirst -> value); 
    } 
    return root; 
} 

void PrintInorder(struct node *root) {  
    if(root == NULL)  
        return;  
   
    PrintInorder(root->left);  
    printf("%d ",root->value);  
    PrintInorder(root->right);  
} 

int main() {
    int i, numberOfElements, target, value;
    node* root = NULL;
    printf("Enter number of elements : ");
    scanf("%d", &numberOfElements);
    printf("Enter elements to be inserted in tree : ");
    for (i = 0; i < numberOfElements; i++) {
        scanf("%d", &value);
        root = InsertElementInTree(value, root);
    }
    
    printf("Enter element that you want to delete : ");
    scanf("%d", &target);
    root = DeleteElementFromTree(root, target);
    PrintInorder(root);
    return 0;
}