/* linkedlists.cpp
 * For use in CS16, (c) 2024, Matni
 *
 * Do not change any code in this file.
 */
#include <iostream>
#include <string>
using namespace std;

#include "ll_headers.h"        // Do not change
#include "ll_functions.cpp"    // Needs completion

int main() {
    // Define the node and its pointer type
    // Actual node structure defined in ll_headers.h
    LinkNode node;
    LinkNodePtr head = NULL;
    
    //1. Create a linked list of variable length
    //2. Print the linked list
    cout << "CREATING A LINKED LIST\n";
    createLL(head);
    printLL(head);

    //3. Insert a node inside this linked list, based on a position number
    //4. Print the linked list
    cout << "\nINSERT NODE\n";
    insertNodeAfter(head);
    printLL(head);

    //5. Find and print the largest number in the linked list data
    //6. Find and print the largest number in the linked list data
    cout << "\nFIND MAX/MIN\n";
    findMax(head);
    findMin(head);

    return 0;
}
