//#include <stddef.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

struct TreeNode {
    int key;
    struct TreeNode *parent;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode NODE;

//tree = pointer pointing to root node
//NODE* is type of tree
void addNode(int key, NODE **address_of_tree) {
    NODE* tree;
    tree = *address_of_tree; //represents pointer to root node
    
    
    if (tree == NULL) {
        NODE *newnode;
        newnode = malloc(sizeof(NODE));
        newnode->key = key;
        newnode->parent=NULL;
        newnode->left=NULL;
        newnode->right=NULL;
        
        *address_of_tree = newnode;
        //tree = newnode;
        return;
    }
    
    if (key < tree->key) {
        

        addNode(key, &(tree->left));
        tree->left->parent = tree;
    
        
    }
    else{

        addNode(key, &(tree->right));
        tree->right->parent = tree;
    }
    
    
}

void removeNode(int key, NODE** address_of_tree) {
    NODE* tree = *address_of_tree;
    
    if(tree == NULL) return;
    
    if (key == tree-> key) {
        if (tree->left == NULL && tree->right == NULL) {
            // free mem allocation of root node
            
            free(tree);
            
            *address_of_tree = NULL;
            return;
        }
        if (tree->left != NULL) {
            NODE* right_most = tree->left;
            while(right_most->right !=NULL)
                right_most = right_most->right;
            
            
            tree->key = right_most->key;
            
            NODE* left = right_most->left;
            NODE* parent = right_most->parent;
            
            parent->right = left; //replace number 10 with whole subtree
            
            free(right_most);
            return;
            
            //right_most->parent->right = NULL;
        }
        // do similar for case right tree is not empty
        
        
    }
    

    
    else{
        if (key < tree->key)
            removeNode(key, &(tree->left));
        else
            removeNode(key, &(tree->right));
    }
}

void printBST(struct TreeNode *root)
{
    if (root != NULL)
    {
        printBST(root->left);
        printf("Node: %d, ", root->key);
        if (root->parent == NULL){
            printf("Parent: NULL\n");
        }
        else{
            printf("Parent: %d\n", root->parent->key);
        }
        
        printBST(root->right);
    }
 }

int main(){
    //int a, b, c, d;
    //scanf("%i %i %i %i", &a, &b, &c, &d);
    
    struct TreeNode *tree = NULL;
    char *word;
    char * in;
    in = malloc(sizeof(char)*10000);
    char* limit = in;
    char delimit[]=" \t\r\n\v\f";
    fgets(in, 10000, stdin);
    
    while ((word = strtok_r(limit, delimit, &limit))){
        int number = atoi(word);
        addNode(number, &tree);
    }
    
    printBST(tree);
    
}
