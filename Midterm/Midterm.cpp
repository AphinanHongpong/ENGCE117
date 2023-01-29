#include <stdio.h>
#include <string.h>

struct carNode
{
    char Product[30];
    int Price;
    struct carNode *next;
};

struct carNode *AddNode(struct carNode **walk, char pro[], int pri);
void UpdatecarNode(struct carNode *walk, char mod1[], char modZ[], int pri);
void SwapcarNode(struct carNode **walk, char mod1[], char modZ[]);
void ShowcarAll(struct carNode *walk);
void ShowcarBack(struct carNode **walk);

int main()
{
    struct carNode *start;
    start = NULL;

    printf("Add Node\n");
    AddNode(&start, "Tesla Model S", 100000);
    AddNode(&start, "BMW i8", 140000);
    AddNode(&start, "Mercedes-Benz S-Class", 110000);
    AddNode(&start, "Audi A8", 90000);
    ShowAll(start);

    printf("Update Node\n");
    UpdateNode(start, "BMW i8", "BMW i3", 60000);
    ShowAll(start);
    UpdateNode(start, "Audi A8", "Audi Q8", 80000);
    ShowAll(start);

    printf("Swap Node \n");
    SwapNode(&start, "Tesla Model S", "Audi Q8");
    ShowAll(start);
    SwapNode(&start, "Mercedes-Benz S-Class", "BMW i3");
    ShowAll(start);

    printf("Show Back\n");
    ShowBack(&start);
    return 0;
}//close main

//-------------------------------------------------------------------------

struct carNode *AddNode(struct carNode **walk, char pro[], int pri)
{
    while (*walk != NULL)
    {
        walk = &(*walk)->next;
    }
    *walk = new struct carNode;
    strcpy((*walk)->Product, pro);
    (*walk)->Price = pri;
    (*walk)->next = NULL;
    return *walk;
}//close carNode

//-------------------------------------------------------------------------

void UpdatecarNode(struct carNode *walk, char mod1[], char modZ[], int pri)
{
    while (strcmp(walk->Product, proO) != 0)
    {
        walk = walk->next;
    }
    strcpy(walk->Product, proN);
    walk->Price = pri;
}//close UpdateNode

//-------------------------------------------------------------------------

void SwapcarNode(struct carNode **walk, char mod1[], char modZ[])
{
    struct carNode *prevmod1 = NULL, *currmod1 = *walk;
    while (strcmp(currmod1->Product, mod1) != 0)
    {
        prevmod1 = currmod1;
        currmod1 = currmod1->next;
    }
    struct carNode *prevmodZ = NULL, *currmodZ = *walk;
    while (strcmp(currmodZ->Product, modZ) != 0)
    {
        prevmodZ = currmodZ;
        currmodZ = currmodZ->next;
    }

    if (prevmod1!= NULL)
        prevmod1->next = currmodZ;
    else
        *walk = currmodZ;

    if (prevmodZ != NULL)
        prevmodZ->next = currmod1;
    else
        *walk = currmod1;

    struct carNode *temp = currmodZ->next;
    currmodZ->next = currmod1->next;
    currmod1->next = temp;
}//close SwapNode

//-------------------------------------------------------------------------

void ShowcarAll(struct carNode *walk)
{
    while (walk != NULL)
    {
        printf("[%s ", walk->Product);
        printf("%d] ", walk->Price);
        walk = walk->next;
    }
    printf("\n");
}//close ShowAll

//-------------------------------------------------------------------------

void ShowcarBack(struct carNode **walk)
{
    struct carNode *prevNode = NULL;
    struct carNode *currentNode = *walk;
    struct carNode *nextNode = NULL;
    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    *walk = prevNode;
    while ((*walk) != NULL)
    {
        printf("[%s ", (*walk)->Product);
        printf("%d] ", (*walk)->Price);
        (*walk) = (*walk)->next;
    }
}//close ShowBack
