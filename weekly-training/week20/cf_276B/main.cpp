#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  vector <int> fr(26, 0);
  cin >> s;
  for(char &c: s) {
    ++fr[c-'a'];
  }
  int odds = 0;
  for(int &x : fr) {
    odds += (x&1);
  }
  if(odds <= 1) puts("First");
  else {
    puts((odds&1) ? "First" : "Second");
  }
  return 0;
}

