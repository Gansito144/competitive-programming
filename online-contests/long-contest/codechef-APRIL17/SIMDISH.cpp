#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int tests;

  scanf("%d",&tests);
  while(tests--) {
    int same = 0;
    string s;
    vector <string> vs;
    for(int i=0; i<4; ++i) {
      cin >> s;
      vs.push_back(s);
    }
    for(int i=0; i<4; ++i) {
      cin >> s;
      for(int j=0; j<4; ++j) {
        if(vs[j] == s) same++;
      }
    }
    puts(same>1?"similar":"dissimilar");
  }
  return 0;
}

