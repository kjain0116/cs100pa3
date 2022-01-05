// NOTE: add this to the HCTree.cpp file and make corresponding method in header file 

void HCTree::makeHeader(HCNode* node, ofstream& out) {

  if(!node) {
    return;
  }
  // while(curr) {

  if(node->isLeaf) {
    out << '1' << node->symbol;
  }
  else {
    out << '0'; 
  }
    // if(node->c0) {
    //   if(node->c0->isLeaf) { // if it is a leaf
    //     out << '1' << node->c0->symbol; // output 1 and its symbol
    //   }
    //   else {
    //     out << '0';
    //   }
    // }
    // if(node->c1) {
    //   if(node->c1->isLeaf) { // if it is a leaf
    //     out << '1' << node->c1->symbol; // output 1 and its symbol
    //   }
    //   else {
    //     out << '0';
    //   }
    // }
  //}
  makeHeader(node->c0, out); // node -> left
  makeHeader(node->c1, out);
}