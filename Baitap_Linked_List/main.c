/*
 * File: linked_List.c
 * Author: Thong Truong
 * Date: 27/3/2023
 * Description: Create linked list with delete and edit function
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Description: create struct to link nodes into a list */
typedef struct node
{
    uint8_t data;
    struct node *next;
}node;

/*
 * Function: pushBack
 * Description: Function is designed to add node to linked list
 * Input:
 *   **arr - use pointer to pointer to be able to create multiple lists 
 *   data - value to add to the link
 */
void pushBack (node **arr, uint8_t data) {

    /* Dynamically allocate 1 new address */
    node *newNode = (node *)malloc(sizeof(node)); 
        newNode->data = data;
        newNode->next = NULL;

    /* Initial node initialization condition */
    if (*arr == NULL) (*arr) = newNode;

    else {

        node *p = (*arr);
        while (p->next != NULL)
            p = p->next;

        /* Link to newNode */
        p->next = newNode;

    }
}

/*
 * Function: printLish
 * Description: Function is designed to print data in list
 * Input:
 *   *arr 
 */
void printLish (node *arr) {
    
    printf("%d\n",arr->data);
    for (node *p = arr->next; p != NULL; p = p->next) {
        printf("%d\n", p->data);
    
    }
}

typedef struct vector
{
    node *NODE;
}vector;

void assignFirst (vector *arr) {
    arr->NODE = NULL;
}

/*
 * Function: main
 * Description: Operations for creating and editing data in a list
 */
int main()
{
    
    /* Initialize the lists */  
    vector arr1, arr2;

    /* Operation with lish 1 */
    printf("Linked list 1:\n");
    assignFirst(&arr1);
    pushBack(&arr1.NODE, 1);
    pushBack(&arr1.NODE, 2);
    pushBack(&arr1.NODE, 3);
    pushBack(&arr1.NODE, 4);
    printLish(arr1.NODE);

    /* Operation with lish 2 */
    assignFirst(&arr2);
    printf("Linked list 2:\n");
    pushBack(&arr2.NODE, 5);
    pushBack(&arr2.NODE, 6);
    pushBack(&arr2.NODE, 7);
    pushBack(&arr2.NODE, 8);
    printLish(arr2.NODE);

    return(0);
}