#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
  int n;
  cin >> n;
  vector <int> A(n);
  for (int &ai : A) cin >> ai;
  sort(A.begin(), A.end());
  cout << A[(n-1) >> 1] << endl;
  return 0;
}

