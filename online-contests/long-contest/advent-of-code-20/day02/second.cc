#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// I feel bad about this.
char token[12345];

int main() {
  string line;
  int valid = 0;
  while (getline(cin, line)) {
    char target;
    int min, max, count = 0;
    sscanf(line.c_str(),"%d-%d %c: %s", &min, &max, &target, token);
    string word(token);
    valid += (word[min - 1] == target) ^ (word[max - 1] == target);
  }
  cout << valid << endl;
  return 0;
}

