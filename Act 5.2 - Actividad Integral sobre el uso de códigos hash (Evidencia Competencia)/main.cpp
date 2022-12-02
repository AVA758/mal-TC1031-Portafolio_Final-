// =================================================================
//
// File: main.cpp
// Author: Ricardo Navarro Gómez - A01708825
//		   Alain Vicencio Arizabalo - A01620758
//		   Fernando Josue Matute Soto - A00833375
// Date:
//
// =================================================================
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
  int m, n, value; 
  string word, p;
  map<string, int>dictionary; 
  
  
  cin >> m; 
  cin >> n; 

  // Dictionary creation.
  for(int i  = 0; i < m; i++) {
    cin >> word; 
    cin >> value;
    dictionary.insert(pair<string, int>(word, value));  
  }

  // Word reading and salary calculation. 
  for(int i = 0; i < n; i++) {
    int salary = 0;
    while(true) {
      cin >> p; 
      if (p == ".") {
        break;
      }
      salary += dictionary[p]; 
    } cout << salary << endl;
	}
	return 0;
}
