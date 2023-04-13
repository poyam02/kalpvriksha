#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool SearchElementInTree(node* tnode, int target) {
    if (tnode == NULL) {
        return false;
    }

    if (tnode->value == target) {
        return true;
    } else if (tnode->value > target) {
        return SearchElementInTree(tnode->left, target);
    } else {
        return SearchElementInTree(tnode->right, target);
    }
}

int main() {
    int i, num, target, value;
    bool isFound;
    node* root = NULL;

    printf("Enter size : ");
    scanf("%d", &num);

    printf("Enter elements : ");
    for (i = 0; i < num; i++) {
        scanf("%d", &value);
        root = InsertElementInTree(value, root);
    }

    printf("Enter element to be searched : ");
    scanf("%d", &target);
    isFound = SearchElementInTree(root, target);
    if (isFound == true) {
        printf("The target value is found in the binary tree ");
    } else {
        printf("The target value is not found in the binary tree");
    }
    return 0;
}