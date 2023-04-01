/*
 * File: linked_List.c
 * Author: Thong Truong
 * Date: 26/3/2023
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

} node;

/*
 * Function: push_Back
 * Description: Function is designed to add node to linked list
 * Input:
 *   **arr - use pointer to pointer to be able to create multiple lists
 *   data - value to add to the link
 */
static void pushBack(node **arr, uint8_t data)
{

    /* Dynamically allocate 1 new address */
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    /* Initial node initialization condition */
    if (*arr == NULL)
        *arr = newNode;

    else
    {

        node *p = *arr;
        while (p->next != NULL)
            p = p->next;

        /* Link to newNode */
        p->next = newNode;
    }
}

/*
 * Function: assign
 * Description: Function is designed to change the value at the specified location
 * Input:
 *   *arr - use pointer to pointer to be able to replace the value of multiple lists
 *   data - Pass in the value to be replaced
 *   index - location to be replaced
 */
static void assign(node **arr, uint8_t index, uint8_t data)
{

    printf("Replace the value at position %d = %d:\n", index, data);
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    /* Create counter variable to determine index */
    uint8_t i = 0;

    /* Create a pointer to save first node */
    node *p = *arr;

    while (p->next != NULL)
    {

        i++;
        if (i == index)
        {

            /* Create pointer to save the replaced node address */
            node *p2 = p->next;

            /* Assign newNode address to the replaced node address */
            p->next = newNode;

            /* link newNode to next node */
            newNode->next = p2->next;

            /* Delete replaced node address */
            free(p2);
            return;
        }
        p = p->next;
    }
}

/*
 * Function: erase
 * Description: Function is designed to delete the specified node
 * Input:
 *   **arr - use pointer to pointer to be able to delete designated node
 *   index - designated location
 */
static void erase(node **arr, uint8_t index)
{

    printf("Delete data at location %d:\n", index);

    uint8_t i = 0;
    node *p = *arr;

    while (p->next != NULL)
    {

        i++;
        if (i == index)
        {

            /* Create a pointer to save the node address to delete */
            node *p2 = p->next;

            /* Assign the address of the next node to the node to delete */
            p->next = p->next->next;

            /* Delete node to delete */
            free(p2);
            return;
        }
        p = p->next;
    }
}

/*
 * Function: pop_Back
 * Description: Function is designed to delete the last node of the list
 * Input:
 *   **arr
 */
static void popBack(node **arr)
{

    printf("Delete the last data of the list:\n");
    node *p = *arr;
    while (p->next != NULL)
    {

        if (p->next->next == NULL)
        {

            /* Đelete the last node of the list */
            free(p->next);
            p->next = NULL;
            return;
        }
        p = p->next;
    }
}

/*
 * Function: clear
 * Description: Function is designed to delete all nodes
 *   **arr
 */
static void clear(node **arr)
{

    printf("Delete all data ...\n");
    while ((*arr)->next != NULL)
    {

        /* Mark node position 1 */
        node *p = (*arr)->next;

        /* Assign the address of the next node to the node to delete */
        (*arr)->next = (*arr)->next->next;
        free(p);
    }
}

/*
 * Function: get_Data
 * Description: Function is designed to get the specified
 * Input:
 *   **arr
 *   index - designated location
 * Output:
 *   Data
 */
static void getData(node **arr, uint8_t index)
{

    printf("Data at location %d: ", index);
    node *p = *arr;
    uint8_t temp = 0;

    while (p != NULL)
    {

        /* Find the disignated location to print data */
        if (index == temp)
        {
            printf("%d\n", p->data);
            break;
        }

        p = p->next;
        temp++;
    }
}

/*
 * Function: printLish
 * Description: Function is designed to print data in list
 * Input:
 *   *arr
 */
static void printLish(node *arr)
{

    printf("%d\n", arr->data);
    for (node *p = arr->next; p != NULL; p = p->next)
    {
        printf("%d\n", p->data);
    }
}

/* Description: Create struct to initialize the functions pointer, as a vector */
typedef struct
{

    void (*pushBackInit)(node **, uint8_t);
    void (*assignInit)(node **, uint8_t, uint8_t);
    void (*eraseInit)(node **, uint8_t);
    void (*popBackInit)(node **);
    void (*clearInit)(node **);
    void (*getDataInit)(node **, uint8_t);
    void (*printLishInit)(node *);
    node *nodeInit;

} vector;

/*
 * Description: use vector assignment of functions pointer
 * initialized in struct with corresponding functions
 */
void vectorInit(vector *value)
{

    value->nodeInit = NULL;
    value->pushBackInit = &pushBack;
    value->assignInit = &assign;
    value->eraseInit = &erase;
    value->popBackInit = &popBack;
    value->clearInit = &clear;
    value->getDataInit = &getData;
    value->printLishInit = &printLish;
}

/*
 * Function: main
 * Description: Operations for creating and editing data in a list
 */
int main()
{

    /* Initialize the lists */
    vector array1, array2;

    /* Operation with lish 1 */
    vectorInit(&array1);
    printf("Linked list 1:\n");
    array1.pushBackInit(&array1.nodeInit, 1);
    array1.pushBackInit(&array1.nodeInit, 2);
    array1.pushBackInit(&array1.nodeInit, 3);
    array1.pushBackInit(&array1.nodeInit, 4);
    array1.pushBackInit(&array1.nodeInit, 5);
    array1.printLishInit(array1.nodeInit);

    array1.assignInit(&array1.nodeInit, 1, 4);
    array1.printLishInit(array1.nodeInit);

    array1.eraseInit(&array1.nodeInit, 1);
    array1.printLishInit(array1.nodeInit);

    array1.popBackInit(&array1.nodeInit);
    array1.printLishInit(array1.nodeInit);

    array1.getDataInit(&array1.nodeInit, 2);

    array1.clearInit(&array1.nodeInit);
    array1.printLishInit(array1.nodeInit);

    /* Operation with lish 1 */
    vectorInit(&array2);
    printf("\n\nLinked list 2:\n");
    array2.pushBackInit(&array2.nodeInit, 6);
    array2.pushBackInit(&array2.nodeInit, 7);
    array2.pushBackInit(&array2.nodeInit, 8);
    array2.pushBackInit(&array2.nodeInit, 9);
    array2.pushBackInit(&array2.nodeInit, 10);
    array2.printLishInit(array2.nodeInit);

    array2.assignInit(&array2.nodeInit, 3, 4);
    array2.printLishInit(array2.nodeInit);

    array2.eraseInit(&array2.nodeInit, 2);
    array2.printLishInit(array2.nodeInit);

    array2.popBackInit(&array2.nodeInit);
    array2.printLishInit(array2.nodeInit);

    array2.getDataInit(&array2.nodeInit, 2);

    array2.clearInit(&array2.nodeInit);
    array2.printLishInit(array2.nodeInit);

    return 0;
}