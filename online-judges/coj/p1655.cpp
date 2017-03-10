#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string source, target;
  while(cin >> source >> target) {
    bool ans = true;
    int s = 0, t = 0;
    for( ; s<source.size(); ++s) {
      for( ; t<target.size(); ++t) {
        if(source[s] == target[t]) {
          ++t;
          break;
        }
        if(t+1 == target.size()) {
          ans = false;
          break;
        }
      }
    }
    puts(ans?"Yes":"No");
  }
  return 0;
}

