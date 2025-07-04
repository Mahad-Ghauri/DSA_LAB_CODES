#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int x)
    {
        data = x;
        next = NULL;
    }

    void setNext(Node *other)
    {
        next = other;
    }

    void setData(int x)
    {
        data = x;
    }

    Node *getNext()
    {
        return next;
    }

    int getData()
    {
        return data;
    }
};

#endif