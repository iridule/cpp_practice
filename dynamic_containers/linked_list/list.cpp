//
//  list cpp
// 

//
#include "list.h"

// node struct
struct List::Node {
    std::string data;
    Node *next;
    Node *prev;
};
