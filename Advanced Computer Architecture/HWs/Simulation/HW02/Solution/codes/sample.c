//           ******************************************************
//          **   course         : Advanced Computer Architecture  **
//         ***   HomeWork       : 03                              ***
//        ****   Topic          : Simulation on gem5              ****
//        ****   AUTHOR         : Reza Adinepour                  ****
//         ***   Student ID:    : 402131055                       ***
//          **   Github         : github.com/rezaAdinepour/       **
//           ******************************************************


#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int label;
    struct Node* next;
};


struct Node* createNode(int label) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->label = label;
    newNode->next = NULL;
    return newNode;
};


struct Node* reverse(struct Node* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return head;
    } else 
    {
        struct Node* new_head = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
}


int main() 
{

    struct Node* head = NULL;
    struct Node* current = NULL;

    for (int i = 1; i <= 10000; i++) 
    {
        if (head == NULL) 
        {
            head = createNode(i);
            current = head;
        } else 
        {
            current->next = createNode(i);
            current = current->next;
        }
    }

    reverse(head);

    return 0;
}
