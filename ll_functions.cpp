// file: ll_functions.cpp

// Pre-conditions:
//     head is either nullptr (empty list) or points to the first node of a linked list
//     nom is the name to store in the new node
//     num is the number to store in the new node
// Post-conditions:
//     A new node containing (nom, num) is appended to the end of the linked list
//     OR head is made to point to the start of a new linked list
void h_insert(LinkNodePtr& head, string nom, int num) {

    // Creates and fills in the data if a new node
    LinkNodePtr tmp_ptr;
    tmp_ptr = new LinkNode; 
    tmp_ptr->name = nom;
    tmp_ptr->number = num;
    tmp_ptr->link = nullptr;

    // If the list is empty, the new node becomes the head
    if (head == nullptr){
        head = tmp_ptr;
    }
    // If the list is not empty, traverse to the last node and attach the new node
    else{
        LinkNodePtr tempHead = head;
        while (tempHead->link != nullptr){
            tempHead = tempHead->link;
        }
        tempHead->link = tmp_ptr;
    }
}

// Pre-conditions:
//     h is a reference to the head pointer of a linked list and may be point to nothing
// Post-conditions:
//     Repeatedly reads (name, number) pairs from the user and appends them to the list
//     Stops when user enters name = "0" AND number = 0
void createLL(LinkNodePtr& h) {
    //declare name and number variables
    string nom = "";
    int num;

    // Repeatedly prompt the user, and add a new node to the linked list with that data, up until they enter "0 0" 
    while (true){
        cout << "Enter name, then a number. To quit, enter 0 for the name AND 0 for the number:\n";
        cin >> nom >> num;
        if ( (nom == "0") && (num == 0) ){
            return;
        }
        h_insert(h, nom, num);
    }
}

// Pre-conditions:
//     h is either nullptr or points to a linked list
// Post-conditions:
//     Prints each node's index (starting at 0), name, and number to cout
//     Prints a message if the list is empty
void printLL(LinkNodePtr h) {

    // Check if the list is empty, print a message saying so, then quit the function
    if (h == nullptr){
        cout << "This list is empty.\n";
        return;
    }

    // If the linked list is not empty, then go through the list, printing each node
    cout << "Printing the list:\n";
    int nodeCount = 0; // The nodes are numbered starting from zero
    while (h != nullptr){
        cout << "Node #" << nodeCount << ": " << h->name << ", " << h->number << endl;
        h = h->link;
        nodeCount++;
    }
    cout << "--------\n";
}

// Pre-conditions:
//     h is a reference to the head pointer of a linked list and may be pointing to nothing
// Post-conditions:
//     If the list is non-empty and the user provides a valid position,
//     inserts a new node AFTER the node at that position.
//     If the list is empty, prints an error and performs no insertion.
//     If the user enters a negative position, exits without changes.
void insertNodeAfter(LinkNodePtr &h) {
    //
    if (h == nullptr){
        cout << "Cannot insert in a non-existing link.\n";
        return;
    }

    
    LinkNodePtr temph = h;
    /*int listLength = 0;
    while (temph != nullptr){
        listLength++;
        temph = temph->link;
    }
    temph = h;
*/
     
        int position;
        cout << "Enter node position to insert new node after (enter negative number to exit): ";
        cin >> position;
        if (position < 0){
            return;
        }
        /*else if (position >= listLength){
            cout << "Position entered is illegal. Nothing inserted.\n";
            return;
        }*/
        else{
            for (int i = 0; i < position; i++){
                temph = temph->link;
                if (temph == nullptr){
                    cout << "Position entered is illegal. Nothing inserted.\n";
                    return;
                }
            }

            string nombre;
            int num;
            cout << "Enter data (name, then number): ";
            cin >> nombre >> num;
            
            LinkNodePtr tempPtr;
            tempPtr = new LinkNode;
            tempPtr->name = nombre;
            tempPtr->number = num;
            tempPtr->link = temph->link;

            temph->link = tempPtr;
        }
    
}

void findMax(LinkNodePtr h) {
    // Incomplete function - student must complete
    if (h == nullptr){
        cout << "This list is empty.\n";
        return;
    }
    
    int max = h->number;
    while (h != nullptr){
        if (h->number > max){
            max = h->number;
        }
        h = h->link;
    }
    cout << "Largest number in the list is: " << max << endl;
}

void findMin(LinkNodePtr h) {
    // Incomplete function - student must complete
    if (h == nullptr){
        cout << "This list is empty.\n";
        return;
    }

    int min = h->number;
    while (h != nullptr){
        if (h->number < min){
            min = h->number;
        }
        h = h->link;
    }

    cout << "Smallest number in the list is: " << min << endl;
}

