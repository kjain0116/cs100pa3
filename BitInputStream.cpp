#include "BitInputStream.h"
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>


using namespace std;


// fill the bitwise buffer by reading one byte from the input stream
void BitInputStream::fill() {
  buf = in.get(); // read one byte from istream to bitwise buffer
  nbits = 0;      // no bits have been read from bitwise buffer
}

// read bit from the bitwise buffer
// return 1 if next bit is 1; 0 if next bit is 0
unsigned int BitInputStream::readBit() {
  // fill bitwise buffer if there are no more unread bits
  if(nbits == 8) {
    fill();
  }

  // get the next unread bit from the bitwise buffer (how?)
  unsigned int nextBit = 0;
  int loc = 8 - nbits - 1;
  unsigned char copybuf = buf;
  nextBit = (copybuf >> loc) & 1;

  // increment the number of bits we have read from the bitwise buffer
  nbits++;

  // return the bit we just read
  return nextBit;
}
