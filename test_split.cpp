/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <cstddef>

int main(int argc, char* argv[])
{

    Node* Node_4 = new Node(9, NULL);
    Node* Node_3 = new Node(7, Node_4);
    Node* Node_2 = new Node(3, Node_3);
    Node* Node_1 = new Node(2, Node_2);
    Node* start = new Node(1, Node_1);
    Node* odd = NULL;
    Node* even = NULL;
    split(start, odd, even);
    Node * current = even;
    current = even;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    // Delete nodes in the odd list
    current = odd;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    

}