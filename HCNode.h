#ifndef HCNODE_H
#define HCNODE_H

#include <iostream>

typedef unsigned char byte;

using namespace std;

/** A class, instances of which are nodes in an HCTree.
 */
class HCNode {

public:
    int count;
    byte symbol; // byte in the file we're keeping track of
    HCNode* c0;  // pointer to '0' child, left child
    HCNode* c1;  // pointer to '1' child, right child
    HCNode* p;   // pointer to parent
    bool isZero;
    bool isOne;
    bool isLeaf; // FIXME

    HCNode(int count,
      byte symbol,
      HCNode* c0 = 0,
      HCNode* c1 = 0,
      HCNode* p = 0,
      bool isZero = false,
      bool isOne = false,
      bool isLeaf = false)
        : count(count), symbol(symbol), c0(c0), c1(c1), p(p), isZero(isZero), isOne(isOne), isLeaf(isLeaf) { }


    /** Less-than comparison, so HCNodes will work in std::priority_queue
     *  We want small counts to have high priority.
     *  And we want to break ties deterministically.
     */
    bool operator<(const HCNode& other) const;
};

/** For printing an HCNode to an ostream
 *  Possibly useful for debugging.
 */
ostream& operator<<(ostream&, const HCNode&) __attribute__((weak)); // shut the linker up
ostream& operator<<(ostream& stm, const HCNode& n) {
    stm << "[" << n.count << "," << (int) (n.symbol) << "]";
    return stm;
}


#endif // HCNODE_H
