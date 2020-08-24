#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
/*
A Linked List program with various functions.
*/

typedef struct Node {
    uint32_t data;
    struct Node* next;
} List_t;

List_t* List()
{
    return NULL;
}

static List_t* NewNode(uint32_t data)
{
    List_t* tmpNode = (List_t*)malloc(sizeof(List_t));
    if (!tmpNode) return NULL;
    tmpNode->data = data;
    tmpNode->next = NULL;
    return tmpNode;
}

void ListPush(List_t** list, uint32_t data)
{
    //Check if empty
    if (!(*list)) {
        *list = NewNode(data);
        return;
    }

    //Create new node at front, set head to new->next and new to head
    List_t* newNode = NewNode(data);
    newNode->next = *list;
    *list = newNode;

}

void ListAppend(List_t** list, uint8_t data) 
{
    //Check if empty
    if (!(*list))
    {
        *list = NewNode(data);
        return;
    }

    List_t* currentNode = *list;
    while (1) {
        //If there's a next node, switch to it
        if (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        //If this is the last node, create a new one and add data to it, set next of it to NULL
        else {
            currentNode->next = NewNode(data);
            return;
        }
    }
}

void ListPrint(List_t* list) 
{
    List_t* currentNode = list;
    if (list != NULL) {
        while (1) {
            if (currentNode->next != NULL) {
                printf("Data: %d\n", currentNode->data);
                currentNode = currentNode->next;
            }
            else {
                printf("Data: %d\n", currentNode->data);
                break;
            }
        }

    }
    else {
        printf("List empty...");
    }
    printf("\n");
}

uint32_t ListPop(List_t** list)
{
    if (!(*list))
    {
        printf("List empty.\n");
        return 0;
    }
    List_t* currentNode = *list;
    uint32_t data = currentNode->data;

    List_t* tmpNode = currentNode->next;
    free(*list);
    *list = tmpNode;

    return data;
}

uint32_t ListLength(List_t* list)
{
    List_t* currentNode = list;
    uint32_t length=0;

    if (list != NULL) {
        while (1) {
            if (currentNode->next) {
                ++length;
                currentNode = currentNode->next;
            }
            else {
                ++length;
                break;
            }
        }
    }
    return length;
}

void ListSort(List_t** list)
{
    uint32_t len = 0, pass, element, tmpData = 0;
    len = ListLength(*list);

    List_t* firstElement = *list;
    List_t* secondElement = NULL;

    for (pass = len - 1; pass > 0; pass--)
    {
        firstElement = *list;
        for (element = 0; element < pass; element++)
        {
            secondElement = firstElement->next;
            if ((firstElement->data - secondElement->data) > 0)
            {
                tmpData = firstElement->data;
                firstElement->data = secondElement->data;
                secondElement->data = tmpData;
            }
            //Move to another pair
            firstElement = firstElement->next; 
        }
    }
}

List_t* ListCopy(List_t* list)
{
    List_t* head = NULL;
    List_t** pHead = &head;

    while(list)
    {
        *pHead = NewNode(list->data);

        list = list->next;
        pHead = &((*pHead)->next);
    }
    return head;
}

void ListReverse(List_t** list)
{
    List_t* firstNode = *list;
    List_t* secondNode = *list;
    int tempData = 0, len = 0, count = 0, i = 0;

    len = ListLength(*list);

    for (i = 0; i < len / 2; i++)
    {
        secondNode = *list;
        for (count = 0; count < len - (i + 1); count++)
            secondNode = secondNode->next;

        tempData = firstNode->data;
        firstNode->data = secondNode->data;
        secondNode->data = tempData;

        firstNode = firstNode->next;
    }
}

void ListDelete(List_t* list)
{
    while(list)
    {
        List_t* tmpNode = list->next;
        free(list);
        list = tmpNode;
    }
}

int main() 
{
    List_t* MyList = List();

    ListPush(&MyList, 1);
    ListPush(&MyList, 2);
    ListPush(&MyList, 3);
    ListPush(&MyList, 4);
    ListPush(&MyList, 5);
    ListPush(&MyList, 6);
    ListPrint(MyList);

    ListAppend(&MyList, 33);
    ListAppend(&MyList, 44);
    ListAppend(&MyList, 55);
    ListPrint(MyList);

    printf("Element popped: %d\n", ListPop(&MyList));
    printf("Element popped: %d\n", ListPop(&MyList));
    printf("\n");

    ListPrint(MyList);

    printf("List length: %d\n\n", ListLength(MyList));

    ListSort(&MyList);
    ListPrint(MyList);

    List_t* CopiedList = ListCopy(MyList);

    ListReverse(&CopiedList);

    printf("List:\n");
    ListPrint(MyList);
    printf("Reversed:\n");
    ListPrint(CopiedList);

    ListDelete(MyList);
    MyList = NULL;
    ListDelete(CopiedList);
    CopiedList = NULL;

    return 0;
}
