#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  int tcs, A, B, N;
  string answer;

  cin >> tcs;
  while (tcs--)
  {
    cin >> A >> B >> N;
    ++A;
    int AA = A, BB = B, NN = N;
    while (A <= B)
    {
      int C = A + (B-A) / 2;
      cout << C << endl;
      cin >> answer;
      if (answer!="TOO_BIG" && answer!="TOO_SMALL")
      {
        if (answer == "CORRECT")
          break;
        cerr << answer << " " << AA << " " << BB << " " << NN << endl;
        return 0;
      }
      if (answer == "TOO_BIG")
        B = C - 1;
      else
        A = C + 1;
    }
  }

  return 0;
}
