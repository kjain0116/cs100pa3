#include "HCTree.h"
#include <queue>
#include <vector>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

HCTree::~HCTree() {
 deleteAll(root);
}

void HCTree::build(const vector<int>& freqs) {
  // make a priority queue forest of single node trees, want the priority queue to be a min heap
  priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> forest;

  for(int i = 0; i < freqs.size(); i++) {
    if(freqs.at(i)!=0) {
      HCNode* node = new HCNode(freqs.at(i), (char)i); // call node constructor with given info
      node->isLeaf = true;
      forest.push(node); // add the new node to the forest of trees
      this->leaves.at(i) = node;
    }
  }
  while(forest.size() > 1) { // While there is more than 1 tree in the forest:
    // Remove the two trees (T1 and T2) from the forest that have the lowest count contained in their roots
    HCNode* left = forest.top(); // return lowest value node in priority queue, put in right
    forest.pop(); // remove that lowest value from forest;
    HCNode* right = forest.top(); // return second lowest value in priority queue
    forest.pop(); // remove that value

    // Create a new node that will be the root of a new tree.
    int totalCount = left->count + right->count;
    HCNode* rootNode = new HCNode(totalCount, left->symbol); // new node with combined frequencies

    // This does it in insert:
    // Create a new node that will be the root of a new tree.
    // This new tree will have T1 and T2 as left and right subtrees.
    // Label the edge from this new root to T1 as "1" and label the edge from this new root to T2 as "0"
    rootNode->c0 = left;
    left->p = rootNode;
    left->isZero = true;

    rootNode->c1 = right;
    right->p = rootNode;
    right->isOne = true;

    // Insert this new tree in the forest
    // go back to the While statement
    forest.push(rootNode);
  }
  // make tree
  this->root = forest.top();
}


void HCTree::encode(byte symbol, BitOutputStream& out) const {
  // string encVal = ""; // this will be the encoded thing
  stack<unsigned int> encode; // initializes empty stack
  HCNode* curr = nullptr;
  // maybe need to do error checking to see if in bounds
  if(this->leaves.at(symbol)) {
    curr = this->leaves.at(symbol);
  }
  while(curr) { // while the current node has a parent
    if(curr->isZero) {
      encode.push(0);
    }
    else if(curr->isOne) {
      encode.push(1);
    }
    curr = curr->p;
  }

  // now read off from stack the encoded value
  unsigned int bit = 0;
  while(!encode.empty()) {
    // bit to write = this;
    bit = encode.top();
    //cout << "printing bit" << bit << endl; 
    out.writeBit(bit);
    encode.pop();
  }
}

void HCTree::decode(ifstream& ifin, BitInputStream& in, unsigned int numBits, ofstream & out) const {
  // decode: take each ASCII character
  // convert the ASCII to its number
  // use bitwise operations to extract the bits

unsigned int nextBit = in.readBit();

  // TODO: put this in the uncompress code
  string code;
 // for(int i = 0; i < 258; i++) {
  //  getline(ifin, code);
    //nextBit = in.readBit();
  //}

  // TODO: do something if no bits to be read
  if(numBits < 1) {
    return;
  }



  HCNode* curr = this->root;

  // for number of bits as defined in the header file
  // not sure loop bounds FIXME since started with readBit
  for(int j = 0; j < numBits; j++) {
    while(curr->isLeaf == false) {
      //cout << "next bit" << nextBit << endl;
      if(nextBit == 0) {
        curr = curr->c0;
        nextBit = in.readBit();
        
      }
      else if(nextBit == 1) {
        curr = curr->c1;
        nextBit = in.readBit();
        
      }
    }
    // isLeaf == true;
    out << curr -> symbol;
    curr = this -> root;
  }

}

void HCTree::deleteAll(HCNode* n)
{
  // TODO
  // HINT: Copy code from your BSTInt class.
  if(n == NULL) {
    return;
  }
  deleteAll(n->c0);
  deleteAll(n->c1);
  delete(n);
}
