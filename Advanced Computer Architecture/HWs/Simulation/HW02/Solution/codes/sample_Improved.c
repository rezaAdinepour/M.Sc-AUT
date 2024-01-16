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
    int nextIndex;
};

struct Node* createNode(int label, int nextIndex) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->label = label;
    newNode->nextIndex = nextIndex;
    return newNode;
}

int main() 
{
    const int SIZE = 10000;

    struct Node* nodes = (struct Node*)malloc(SIZE * sizeof(struct Node));

    for (int i = 0; i < SIZE; i++) 
    {
        nodes[i] = *createNode(i + 1, i + 1);
    }

    nodes[SIZE - 1].nextIndex = -1;

    int currentIndex = 0;
    int nextIndex = nodes[currentIndex].nextIndex;

    while (nextIndex != -1) 
    {
        int temp = nodes[nextIndex].nextIndex;
        nodes[nextIndex].nextIndex = currentIndex;
        currentIndex = nextIndex;
        nextIndex = temp;
    }

    return 0;
}
