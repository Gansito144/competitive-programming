#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

inline int getIndex(string s, char c) {
  for(int i=0; i<s.size(); ++i) {
    if(c == s[i]) return i;
  }
  return -1;
}

int main() {
  bool hasValidConfig = false;
  vector < string > sentences;
  string line;
  while(cin >> line) sentences.push_back(line);
  string config =  "ABC";
  do {
    hasValidConfig = true;
    for(string p : sentences) {
      if(p[1] == '<' && 
          getIndex(config, p[0]) > getIndex(config, p[2])) {
        hasValidConfig = false;
        break;
      }
     if(p[1] == '>' && 
         getIndex(config, p[0]) < getIndex(config, p[2])) { 
       hasValidConfig = false;
       break;
     } 
    }
  } while (!hasValidConfig && next_permutation(config.begin(), config.end()));
  if(hasValidConfig) {
    printf("%s\n",config.c_str());
  } else {
    puts("Impossible");
  }
  return 0;
}

