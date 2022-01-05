#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include "HCTree.h"
// #include "BitOutputStream.h"
// #include "BitInputStream.h"

using namespace std;


//Open file
int main( int argc, char * argv[]){
  vector<int> freq (256, 0);
  int symbol = 0;
  char s;
  ifstream in;
  BitInputStream bin(in);


  in.open(argv[1]); // open the input file

  while(1){
    if(in.eof()) break;
      symbol = (int)in.get(); // get next char of input text
      if(symbol < 0 || symbol > 255){
        break;
    }

    freq.at(symbol) = freq.at(symbol) + 1; // updates freq vector
  }
int sum = 0;
int chars = 0;
for(int k = 0; k < 256; k++){
 sum = sum + freq.at(k);
 if(freq.at(k)!=0) {
   chars ++;
 }
}

//empty edge case
 if(sum == 0){
  ofstream o;
  o.open(argv[2]);
  o.close();
  return 0;
 }

in.close(); // close input file
HCTree tree; // initialize a tree
tree.build(freq); // build the tree

ofstream out; // initialize output stream
BitOutputStream bout(out); // initialize BitOutputStream
out.open(argv[2]); // open output file (the one we will write encoding to)

// make header
out << chars << endl; // count unique chars
for(int i = 0; i < 256; i++){ // go through freq vector and put non zero chars in second line
  if(freq.at(i)!=0) {
    out << (char) i;
  }
}
out << endl;

// go through and put freq vector
for(int j = 0; j < 256; j++){ // go through freq vector and put non zero chars in second line
  if(freq.at(j)!=0) {
    out << freq.at(j) << endl;
  }
}

out << sum << endl; // count bits


in.open(argv[1]); // open input file again

while(1){
 s= (int)in.get(); // read each char in input file
 if(in.eof()) break;
 tree.encode(s, bout); // encode each char based on the tree we made
}

bout.flush();
in.close();
out.close();

  //Read bytes from the file. Count the number of occurrences of each byte value.
  // Close the file.
}
