//File name: main.cpp
//Name: Jasmine Angel Fortez
//Date: November 5, 2021
//Compiler name: replit.com
//Purpose: To count the number of times blockchain is repeated (not case-sensitive)

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main() {
  //count blockchain (case-sensitive)
  string aLineFromFile = " ";
  ifstream input ("blockchains.txt");
  int blockChainsCount = 0;

  if(input.is_open()){

    cout << "File opened successfully for processing..." <<endl;

    while (!input.eof()){
    
      getline(input, aLineFromFile);

      stringstream ss (aLineFromFile);
      string word = "";
      
      while (!ss.eof()){
        ss >> word;

        while (word.find("blockchain") != -1 || word.find("Blockchain") != -1 ){
          if(word.find("Blockchain") != -1){
            blockChainsCount ++;
            word = word.replace((word.find("Blockchain")), 10, "x");
           }
          else if (word.find("blockchain") != -1){
            blockChainsCount ++;
            word = word.replace((word.find("blockchain")), 10, "x");
          }
        }
      
      }
    }
    cout << "The word 'blockchain' occur "  << blockChainsCount << " times." <<endl;
   
  }
  return 0;
} 