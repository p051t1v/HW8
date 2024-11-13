// Author:  Jonah Teal
// Date:    11/12/2024
// Purpose: To make the wires of our DLD sim work
#include <iostream>

// The following pattern prevents multiple inclusion of class definitions
#define 

using namespace std;

struct  Wire;
typedef Wire* WirePtr;

// The key value HEAD_OF_LIST is used as a "sentinal" value
const int HEAD_OF_LIST = -1;

class Wire {
public:
    // constructors
    Wire(int key, bool binary);
    // destructor
    ~Wire();
    bool isZero(int key);
private:
    // helper functions
    void MakeWire(int key);
    void MakeGate(int key);

    // NOTE: see also the non-member function createNode() associated .cpp file

    // the data member for this class is a single item similar to the example
    // in ZyBook 12.21
    WirePtr head;
};

#endif //LLSPOSINT_H

