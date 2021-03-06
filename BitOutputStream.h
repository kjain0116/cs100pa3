#ifndef BITOUTPUTSTREAM_H
#define BITOUTPUTSTREAM_H

#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class BitOutputStream {
public: // TODO change to private
   unsigned char buf; // bitwise bufer (one byte)
   int nbits;         // number of bits that have been written to the bitwise buffer
  
   ostream & out;     // reference to the bytewise output stream (a C++ ostream)

 // public:
   // constructor: assign 'out' to 'os', 'buf' to 0, and 'nbits' to 0
   BitOutputStream(ostream & os) : out(os), buf(0), nbits(0) {}

   // send the bitwise buffer to the output stream, and clear the bitwise buffer
   void flush();

   // write bit to the bitwise buffer
   void writeBit(unsigned int bit);

   // these could technically be private
   // unsigned char clearBit(unsigned char input, unsigned int n);
   // unsigned char setBit(unsigned char input, unsigned int n);

};


#endif // BITOUTPUTSTREAM_H
