// Author:  Jonah Teal
// Date:    11/12/2024
// Purpose: To make the wires of our DLD sim work
#include <iostream>

// The following pattern prevents multiple inclusion of class definitions
#define 

using namespace std;

struct  Node;
typedef Node* NodePtr;

// The key value HEAD_OF_LIST is used as a "sentinal" value
const int HEAD_OF_LIST = -1;

class Wire {
public:
    // constructors
    Wire(int wireID, bool binary);
    // destructor
    ~Wire();
    bool isZero(int wireNum);
private:
    // helper functions
    void                  insert(int key);
    void                  remove(int key);

    // NOTE: see also the non-member function createNode() associated .cpp file

    // the data member for this class is a single item similar to the example
    // in ZyBook 12.21
    NodePtr head;
};

#endif //LLSPOSINT_H

