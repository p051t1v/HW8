
// Author:  Jonah Teal
// Date:    10/8/24
// Purpose: To implement a simple, sorted linked-list of positive integers

#include "LLSortedPosInt.h"

// The linked-list is constructed of Node elements
struct Node {
    int   key;
    Wire* next;
};

// the following function is not a member function, it is a convenience
// function which exists to make the implementation of the LLSortedPosInt
// class more concise
void MakeWire(int key) {
    n->key = key;
    // return the new Node to the caller
    return n;
}

// Student implementation of LLSortedPosInt begins here

// Constructors
LLSortedPosInt::LLSortedPosInt() {
    head = createNode(HEAD_OF_LIST, nullptr);
    // create the sentinal node at the head of this list
}

LLSortedPosInt::LLSortedPosInt(int key) {
    // create the sentinal Node at the head of the list
    head = createNode(HEAD_OF_LIST, nullptr);

    //add the single element key, as long as it is positive
    if (key > 0) {
        insert(key);
    }
}

LLSortedPosInt::LLSortedPosInt(int* keys, int n) {
    // create the sentinal node at the head of the list
    head = createNode(HEAD_OF_LIST, nullptr);
    for (int i = 0; i < n; i++) {
        if (keys[i] > 0) {
            insert(keys[i]);
        }
    }
    // add new Nodes for each positive value in keys

}

LLSortedPosInt::LLSortedPosInt(const LLSortedPosInt& l) {
    head = createNode(HEAD_OF_LIST, nullptr);
    NodePtr curr = l.head->next;
    while (curr) {
        insert(curr->key);
        curr = curr->next;
    }
}

// Destructor
LLSortedPosInt::~LLSortedPosInt() {
    NodePtr curr = head;
    while (curr) {
        NodePtr temp = curr;
        curr = curr->next;
        delete temp;
    }
    // free the Nodes in *this, including the sentinal
}

// Assignment Operator
LLSortedPosInt& LLSortedPosInt::operator=
(const LLSortedPosInt& l) {
    // handle self assignment
    if (this == &l) {
        return *this;
    }

    // free old elements of the list before the new elements from l are assigned
    NodePtr curr = head->next;
    while (curr) {
        NodePtr temp = curr;
        curr = curr->next;
        delete temp;
    }
    // if necessary, rebuild the sentinal
    head->next = nullptr;
    // build the list as a deep copy of l
    NodePtr rcCurr = l.head->next;
    while (rcCurr) {
        insert(rcCurr->key);
        rcCurr = rcCurr->next;
    }
    // return *this
    return *this;
}

// Print Operator (a non-member function)
ostream& operator<<  (ostream& out, const LLSortedPosInt& l) {
    out << "<";
    NodePtr curr = l.head->next;
    if (curr) {
        out << curr->key;
        curr = curr->next;
    }
    while (curr) {
        out << ", " << curr->key;
        curr = curr->next;

    }
    out << ">";

    return out;
}

// Boolean Functions
bool LLSortedPosInt::isEmpty() const {
    return head->next == nullptr;
}

bool LLSortedPosInt::containsElement(int key) const {
    NodePtr curr = head->next;
    while (curr) {
        if (curr->key == key) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// Other Operator Member Functions
bool LLSortedPosInt::operator==(const LLSortedPosInt& l) const {
    NodePtr curr1 = this->head->next;
    NodePtr curr2 = l.head->next;
    while (curr1 && curr2) {
        if (curr1->key != curr2->key) {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return(curr1 == nullptr && curr2 == nullptr);
}

bool LLSortedPosInt::operator!=(const LLSortedPosInt& l) const {
    // do the opposite of operator==
    return !(*this == l);
}

// Other Operator Functions (non-member functions)
LLSortedPosInt  operator+ (const LLSortedPosInt& l1,
    const LLSortedPosInt& l2) {
    LLSortedPosInt sum;
    NodePtr curr = l1.head->next;
    while (curr) {
        sum.insert(curr->key);
        curr = curr->next;
    }
    curr = l2.head->next;
    while (curr) {
        sum.insert(curr->key);
        curr = curr->next;
    }
    // create a copy of l1 and add each element of l2 to it in 
    // the correct (sorted ascending) order, allow duplicates
    return sum;
}

LLSortedPosInt  operator- (const LLSortedPosInt& l1,
    const LLSortedPosInt& l2) {
    LLSortedPosInt result;
    // copy l1 and remove all of l2 from l1, taking care to 
    NodePtr curr = l1.head->next;
    while (curr) {
        if (!l2.containsElement(curr->key)) {
            result.insert(curr->key);
        }
        curr = curr->next;
    }


    return result;
}

// The following helper functions are provide to assist you in
// building the class--these helper functions are useful in
// several places among the functions you will write--take time
// to learn what they do

// insert() inserts an element in the linked list in sorted order
void LLSortedPosInt::insert(int key) {

    // setup pointers to walk the list
    NodePtr npp = head;
    NodePtr npc = head->next;

    // walk the list, searching until the given key value is exceeded
    while (npc != NULL && npc->key <= key) {
        npp = npc;
        npc = npc->next;
    }

    // insert the new value into the list
    npp->next = createNode(key, npc);
}

// remove() removes an element from the list (if it is present)
void LLSortedPosInt::remove(int key) {

    // negative values should not be stored in the list
    if (key <= 0) {
        return;
    }

    // setup pointers to walk the list
    NodePtr npp = head;
    NodePtr npc = head->next;

    // search the list until the end (if necessary)
    while (npc != NULL) {

        // if the key value is found, then splice this Node from the list and
        // reclaim its storage
        if (npc->key == key) {
            npp->next = npc->next;
            delete npc;
            break;
        }

        // walk the pointers to the next Node
        npp = npc;
        npc = npc->next;
    }
}
