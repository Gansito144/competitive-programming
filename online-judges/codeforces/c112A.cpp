#include <iostream>
#include <algorithm>
#include <string.h>
#include <ctype.h>

using namespace std;

inline int sign(int x) {
  return (x>0)-(x<0);
}

int main() {
  string A, B;
  cin >> A >> B;
  transform(A.begin(), A.end(), A.begin(), ::tolower);
  transform(B.begin(), B.end(), B.begin(), ::tolower);
  cout << sign(strcmp(A.c_str(), B.c_str())) << endl;
  return 0;
}

