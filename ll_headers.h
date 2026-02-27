// file: ll_headers.h
// Do NOT change this file at all!

struct LinkNode {
    string name;
    int number;
    LinkNode *link;
};

typedef LinkNode* LinkNodePtr;

void h_insert(LinkNodePtr& head, string nom, int num);
void printLL(LinkNodePtr h);
void createLL(LinkNodePtr& h);
void findMax(LinkNodePtr h);
void findMin(LinkNodePtr h);
void insertNodeAfter(LinkNodePtr& h);
