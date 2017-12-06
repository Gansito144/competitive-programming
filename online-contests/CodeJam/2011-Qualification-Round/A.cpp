#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
  int cases;
  cin >> cases;
  for (int tc=1; tc<= cases; ++tc)
  {
    int steps=0, pO=1, pB=1, queries, pos, sO=0, sB=0;
    string robot;
    cin >> queries;
    while (queries--)
    {
      cin >> robot >> pos;
      if (robot == "O")
      {
        if (abs(pos-pO) > sB)
        {
          steps += abs(pos-pO) - sB;
          sO    += abs(pos-pO) - sB;
        }
        sB = 0; ++sO;
        pO = pos;
      }
      else
      {
        if (abs(pos-pB) > sO)
        {
          steps += abs(pos-pB) - sO;
          sB    += abs(pos-pB) - sO;
        }
        sO = 0; ++sB;
        pB = pos; 
      }
      ++steps;
    }
    cout<< "Case #"<< tc<< ": "<< steps<< endl;
  }
  return 0;
}

