#include <iostream>
#include <algorithm>

using namespace std;

bool validate (int x, int y) {
  return (x <= y && (x<<1) >= y);
}

int main () {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  A <<= 1;
  B <<= 1;
  int CC = min(C,D) << 1;
  if(validate(D, CC) && !(validate(D, B)) && validate(C, CC))
    cout <<A<<endl<<B<<endl<<CC<<endl;
  else
    cout << "-1" << endl;

  return 0;
}

