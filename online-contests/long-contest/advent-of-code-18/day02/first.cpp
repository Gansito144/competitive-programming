#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
  string s;
  int twos = 0, threes = 0;
  while (cin >> s) {
    vector <int> freq(26, 0);
    for (const char &c: s) ++freq[c-'a'];
    twos += find(freq.begin(), freq.end(), 2) != freq.end();
    threes += find(freq.begin(), freq.end(), 3) != freq.end();
  }
  cout << twos * threes << endl;
  return 0;
}

