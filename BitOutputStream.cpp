#include "BitOutputStream.h"
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

// send the bitwise buffer to the output stream, and clear the bitwise buffer
void BitOutputStream::flush() {
  //cout << "printing buf" << buf << endl; // printing buf
  out.put(buf); // write the bitwise buffer to the ostream
  // flush the ostream (optional, slower to do it here)
  buf = 0;      // clear the bitwise buffer
  nbits = 0;    // bitwise buffer is cleared, so there are 0 bits in it
}

// write bit to the bitwise buffer
void BitOutputStream::writeBit(unsigned int bit) {
  // flush the bitwise buffer if it is full
  if(nbits == 8) {
    flush(); // or is it buf.flush?
  }

  // write the given bit to the buffer at proper location
  int loc = 8 - nbits - 1;
  buf = (buf | (bit << loc));


  // increment the number of bits in our bitwise buffer
  nbits++;
  
}
