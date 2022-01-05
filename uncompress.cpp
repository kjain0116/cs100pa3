
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
#include<fstream>
#include <stdio.h>
#include <vector>
#include "HCTree.h"

using namespace std;


//NOTE: infile.txt is the infile to open

//Open file
int main( int argc, char * argv[]){
vector<int> temp;
vector<int> freq (256, 0);
int symbol = 0;
string s;
ifstream in;
BitInputStream bin(in);

in.open(argv[1]);

if(in.peek() == EOF){
  ofstream o;
  o.open(argv[2]);
  o.close();
 return 0;
}

int chars = 0;

getline(in, s); // this is the first line
chars = stoi(s); // number of unique chars


vector<unsigned char> characters;
char c;
for(int m = 0; m < chars; m++) {
  c = in.get();
  characters.push_back(c);

}
getline(in, s);
for(int n = 0; n < chars + 1; n++) {
  // c = in.get();
  

  getline(in, s);
  symbol = stoi(s);
  temp.push_back(symbol);
}

// make real frequency vector
int index = 0;
for(int p = 0; p < chars; p++) {
  index = characters.at(p); // should convert symbol to int
  freq.at(index) = temp.at(p);
}


// char c;
// for(int i = 0; i < 256; i++){
//
//  getline(in, s);
//  c = s[0];
//  if(s.length() == 0) {
//    symbol = 0;
//  }
//  else {
//    symbol = stoi(s);
//  }
//
//  freq.at(i) = symbol;
// }
//
// getline(in, s);
// symbol = stoi(s);


HCTree tree;
tree.build(freq);

/*for(int k = 0; k < 256; k++){
  if(freq.at(k) != 0){
    cout << freq.at(k) << endl;
    cout << k << endl;
  }
}*/

ofstream out;
out.open(argv[2]);

tree.decode(in, bin, symbol, out);

in.close();
out.close();

  //Read bytes from the file. Count the number of occurrences of each byte value.
  // Close the file.
}
