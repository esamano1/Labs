// file: ll_functions.cpp
#include "ll_headers.h"

// Used in the function createLL()
// This function is started for you correctly - you have to complete it.
//   Use the comments to help you figure out what to do.
void h_insert(LinkNodePtr& head, string nom, int num) {
    LinkNodePtr tmp_ptr;
    tmp_ptr = new LinkNode;

    tmp_ptr->name = nom;
    tmp_ptr->number = num;
    tmp_ptr->link = nullptr; 

// If the list is empty, the new node becomes the head



// If the list is not empty, traverse to the last node

    

// Change the pointer of the last node to the new node


}

void createLL(LinkNodePtr& h) {
    // Incomplete function - student must complete
    string nom = "";
    int num;  
    while(0) // THIS IS A STUB
    {
        cout << "Enter name, then a number. To quit, enter 0 for the name AND 0 for the number:\n";
        cin >> nom >> num;
        // Incomplete code here...
        // At some point, you call:    h_insert(h, nom, num);
    }
}

void printLL(LinkNodePtr h) {
    // Incomplete function - student must complete
    cout << "printLL\n"; // THIS IS A STUB
}

void insertNodeAfter(LinkNodePtr h) {
    // Incomplete function - student must complete
    cout << "insertNodeAfter\n"; // THIS IS A STUB
}

void findMax(LinkNodePtr h) {
    // Incomplete function - student must complete
    int max(0);
    cout << "Largest number in the list is: " << max << endl;
}

void findMin(LinkNodePtr h) {
    // Incomplete function - student must complete
    int min(0);
    cout << "Smallest number in the list is: " << min << endl;
}

