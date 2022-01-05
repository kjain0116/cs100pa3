#include "HCNode.h"
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

bool HCNode::operator<(const HCNode& other) const {
  // if counts are different, just compare counts
  if(count != other.count) return count > other.count;

  // counts are equal. use symbol value to break tie.
  // for this to work, internal HCNodes must have symbol set
  return symbol < other.symbol;
}
