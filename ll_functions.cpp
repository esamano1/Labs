// file: ll_functions.cpp

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

    if (head == nullptr){
        head = tmp_ptr;
    }
    else{
        LinkNodePtr tempHead = head;
        while (tempHead->link != nullptr){
            tempHead = tempHead->link;
        }
        tempHead->link = tmp_ptr;
    }
}

void createLL(LinkNodePtr& h) {
    // Incomplete function - student must complete
    string nom = "";
    int num;  
    while(true) // THIS IS A STUB
    {
        cout << "Enter name, then a number. To quit, enter 0 for the name AND 0 for the number:\n";
        cin >> nom >> num;
        if ( (nom == "0") && (num == 0) ){
            return;
        }
        h_insert(h, nom, num);
        // Incomplete code here...
        // At some point, you call:    h_insert(h, nom, num);
    }
}

void printLL(LinkNodePtr h) {
    // Incomplete function - student must complete
    int nodeCount = 0;
    if (h == nullptr){
        cout << "This list is empty.\n";
        return;
    }
    cout << "Printing the list:\n";
    while (h != nullptr){
        cout << "Node #" << nodeCount << ": " << h->name << ", " << h->number << endl;
        h = h->link;
        nodeCount++;
    }
    cout << "--------\n";
}

void insertNodeAfter(LinkNodePtr &h) {
    //
    LinkNodePtr temph = h;
    int listLength = 0;
    while (temph != nullptr){
        listLength++;
        temph = temph->link;
    }
    temph = h;

    if (listLength == 0){
        cout << "Cannot insert in a non-existing link.\n";
    }
    else{
        int position;
        cout << "Enter node position to insert new node after (enter negative number to exit): ";
        cin >> position;
        if (position < 0){
            return;
        }
        else if (position >= listLength){
            cout << "Position entered is illegal. Nothing inserted.\n";
            return;
        }
        else{
            string nombre;
            int num;
            cout << "Enter data (name, then number): ";
            cin >> nombre >> num;
            for (int i = 0; i < position; i++){
                temph = temph->link;
            }

            LinkNodePtr tempPtr;
            tempPtr = new LinkNode;
            tempPtr->name = nombre;
            tempPtr->number = num;
            tempPtr->link = temph->link;

            temph->link = tempPtr;
        }
    }
    
}

void findMax(LinkNodePtr h) {
    // Incomplete function - student must complete
    int max(0), listLength(0);
    while (h != nullptr){
        listLength++;
        if (h->number > max){
            max = h->number;
        }
        h = h->link;
    }
    if (listLength == 0){
        cout << "This list is empty.\n";
        return;
    }
    cout << "Largest number in the list is: " << max << endl;
}

void findMin(LinkNodePtr h) {
    // Incomplete function - student must complete
    int min(0), listLength(0);
    while (h != nullptr){
        listLength++;
        if (h->number < min){
            min = h->number;
        }
        h = h->link;
    }
    if (listLength == 0){
        cout << "This list is empty.\n";
        return;
    }
    cout << "Smallest number in the list is: " << min << endl;
}

