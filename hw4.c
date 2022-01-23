
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IntNode {
    char *word;
    struct IntNode *next;
    struct IntNode *prev;
    struct IntNode *first;
    struct IntNode *last;
    
};

typedef struct IntNode INTNODE;
typedef struct IntNode* INTNODE_PTR;

void removeNode(int n, INTNODE_PTR *head_address){
    //remove a node at position n
    INTNODE_PTR head = *head_address;
    
    INTNODE_PTR node = head;
    INTNODE_PTR prev = NULL;
    
    int i=1;
    for (i=1; i<n; i++) {
        if (node == NULL) return;
        prev = node;
        node = node->next;
    }
    
    if (prev == NULL) {
        //first node is the culprit
        //simply bypass the first node
        *head_address = node->next;
    }
    else {
        if (node->next == NULL) {
            //last node is the match
            prev->next = NULL;
        }
        else{
            //match is strictly inside list
            prev->next = node->next;
        }
    }
    
    free(node->word);
    free(node);
    
    
    
}

/*
void addNewNodeToPosition(char *new_word, int n, INTNODE_PTR *head_address ){
    //add a node right before position n
    //assume head node is at position 0
    INTNODE_PTR head = *head_address;
    
    INTNODE_PTR node = head;
    INTNODE_PTR prev = NULL;
    
    int i=0;
    for (i=0; i<n; i++) {
        if (node == NULL) return;
        prev = node;
        node = node->next;
    }
    
    INTNODE_PTR new_node;
    new_node = malloc(sizeof(INTNODE));
    new_node->word= malloc(sizeof(strlen(new_word)+1));
    strcpy(new_node->word, new_word);
    new_node->next = NULL;
    
    if (prev == NULL){
        // node is first node
        new_node->next = node;
        *head_address = new_node;
    }
    else {
        prev->next = new_node;
        new_node->next = node;
    }
    
} */

/*
void removeWordFromList(char *new_word, INTNODE_PTR *head_address){
    // remove the first occurrence of the word from list
    
    INTNODE_PTR head = *head_address;
    
    INTNODE_PTR node = head;
    INTNODE_PTR prev = NULL;
    while(node!=NULL && strcmp(node->word, new_word)!=0) {
        prev = node;
        node = node->next;
        
        //match not found
    }
    if (node == NULL) {
        //no word is found
        return;
    }
    
    else{
        //see match
        if (prev == NULL) {
            //first node is the match
            //simply bypass the first node
            *head_address = node->next;
        }
        else {
            if (node->next == NULL) {
                //last node is the match
                prev->next = NULL;
            }
            else{
                //match is strictly inside list
                prev->next = node->next;
            }
        }
        
        free(node->word);
        free(node);
        
        
        
    }
    
    //A->next = B;
    //free(W);
} */

/*
void addNewNodeToTheBeginning(char *new_word, INTNODE_PTR *head_address) {
    INTNODE_PTR new_node; //is a pointer to IntNode struct
    INTNODE_PTR head;
    head = *head_address;
    
    new_node = malloc(sizeof(INTNODE));
    new_node->word= malloc(sizeof(strlen(new_word)+1));
    strcpy(new_node->word, new_word);
    new_node->next = NULL;
    
    if (head ==NULL) {
        //head = &new_node; //is local variable it does nothing to head address
        *head_address = new_node; *head_address is the list we are talking about
    }
    
    else {
        //add new_node to beginning of list
        new_node->next = head;
        *head_address = new_node;
    }
    
} */
//struct IntNode *head;
//struct IntNode ** address_of_variable_head//represent address of variable head

void addNewNodeToTheEnd(char *new_word, INTNODE_PTR *head_address) {//need to pass in the address of the value of the list
    //head address is the address of the pointer "head" that represents first node of list
    //add a new node to store new_value and add it to the end of the list
    INTNODE_PTR new_node; //is a pointer to IntNode struct
    INTNODE_PTR head;
    head = *head_address; //get the first node of the list (i.e. the value at address)
    
    
    new_node = malloc(sizeof(INTNODE));
    //struct IntNode *first_node = list; //remember the first node of list
    new_node->word= malloc(sizeof(strlen(new_word)+1));
    strcpy(new_node->word, new_word);
    new_node->next = NULL;
    
    if (head ==NULL) {
        //head = &new_node; //is local variable it does nothing to head address
        *head_address = new_node; //*head_address is the list we are talking about
    }
    else{
        //have to go to the last node of list, then add new node
        struct IntNode *last_node = head;
        while (1){
            if (last_node-> next == NULL){
                //this is the last node
                break;
            }
            
            else{
                last_node = last_node->next;
            }
        }
        
        last_node->next = new_node;
        //head = &node; //will point to last null in list
        
    }
}


void printList(INTNODE_PTR head){
    
    if(head == NULL) printf("");
    
    struct IntNode *pt;
    pt = head;
    
    //int position = 0;
    
    while(pt!=NULL){
        if(pt->next!=NULL)
            printf("%s,",pt->word);
        else
            printf("%s",pt->word);
        pt=pt->next;
    }
    
    
    /*while(pt!=NULL){
        
        position++;
        printf("elem at position %d: value=%s, address of next node = %ld\n", position, pt-> word, (long int) pt->next);
        pt = pt->next;
    } */
}



int main(){
    struct IntNode *list=NULL;
    char *words;
    char * in;
    in = malloc(sizeof(char)*10000);
    char* limit = in;
    char delimit[]=" \t\r\n\v\f";
    fgets(in, 10000, stdin);
    while ((words = strtok_r(limit, delimit, &limit)))
    {
        //printf("word is: %s and of length: %ld\n",words, strlen(words));
        if (list == NULL){
            if (strlen(words)> 100){
                //printf("word is %s", words);
                char otherString[101];
                strncpy(otherString, words, 100);
                otherString[100] = '\0';
                
                addNewNodeToTheEnd(otherString, &list);
                //printf("1st word is %s", words);
            }
            else {
                addNewNodeToTheEnd(words, &list);
                //printf("1st word is %s", words);
            }
        }
        
        int wordCheck =1;
        struct IntNode* wordCheckNode = list;
        while(wordCheckNode!=NULL)//check to see if word is already present or not
        {
            if(strcmp(wordCheckNode->word,words)==0)
            {
                wordCheck =0;
                break;
            }
            wordCheckNode=wordCheckNode->next;
                
        }
            
        if(wordCheck==1) //word is not present after having iterated through all list
        {
            if (strlen(words)> 100){
                char otherString[101];
                strncpy(otherString, words, 100);
                otherString[100] = '\0';
                    
                addNewNodeToTheEnd(otherString, &list);
                //printf("Addeddd word is %s", words);
            }
            else {
                addNewNodeToTheEnd(words, &list);
                //printf("Added word is %s", words);
            }
        }
        else //word is present in list (i.e. entered strcmp body)
        {
            continue;
        }
    }

    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);
    removeNode(a, &list);
    b = b -1;
    removeNode(b, &list);
    c = c -2;
    removeNode(c, &list);

    printList(list);
    
    return 0;
}
