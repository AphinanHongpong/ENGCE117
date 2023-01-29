//Aphinan HongPong 65543206087-0 Sec3
//https://youtu.be/IAadXGVH9uE
#include <stdio.h>
#include <string.h>

struct carNode
{
    char Product[30];
    int Price;
    struct carNode *next;
};

struct carNode *AddNode(struct carNode **walk, char pro[], int pri);
void UpdateNode(struct carNode *walk, char proO[], char proN[], int pri);
void SwapNode(struct carNode **walk, char proO[], char proN[]);
void ShowAll(struct carNode *walk);
void ShowBack(struct carNode **walk);

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
void ShowAll(struct carNode *walk)
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
void UpdateNode(struct carNode *walk, char proO[], char proN[], int pri)
{
    while (strcmp(walk->Product, proO) != 0)
    {
        walk = walk->next;
    }
    strcpy(walk->Product, proN);
    walk->Price = pri;
}//close UpdateNode
//-------------------------------------------------------------------------
void SwapNode(struct carNode **walk, char proO[], char proN[])
{
    struct carNode *prevProO = NULL, *currProO = *walk;
    while (strcmp(currProO->Product, proO) != 0)
    {
        prevProO = currProO;
        currProO = currProO->next;
    }
    struct carNode *prevProN = NULL, *currProN = *walk;
    while (strcmp(currProN->Product, proN) != 0)
    {
        prevProN = currProN;
        currProN = currProN->next;
    }

    if (prevProO != NULL)
        prevProO->next = currProN;
    else
        *walk = currProN;

    if (prevProN != NULL)
        prevProN->next = currProO;
    else
        *walk = currProO;

    struct carNode *temp = currProN->next;
    currProN->next = currProO->next;
    currProO->next = temp;
}//close SwapNode
//-------------------------------------------------------------------------
void ShowBack(struct carNode **walk)
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

