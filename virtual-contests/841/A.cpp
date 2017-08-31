#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  int n, k;
  string s;
  map<char, int> f;
  cin >> n >> k >> s;
  for(char &c: s) ++f[c];
  bool ans = true;
  for(auto &it : f) {
    if(it.second > k) {
      ans = false;
      break;
    }
  }
  cout << (ans?"YES":"NO") << endl;
  return 0;
}

