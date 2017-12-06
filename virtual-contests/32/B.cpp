#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool ans;

void back(string &s, int a[], int k, int &n)
{
  if (k == int(s.size()))
  {
    ans = true;
  }
  else
  {
    ++n;
    if (s[k] == '.')
    {
      a[n-1] = 0;
      back(s, a, k+1, n);
    }
    if(!ans && k<int(s.size()-1))
    {
      if (s[k] == '-')
      {
        if (s[k+1] == '.')
        {
          a[n-1] = 1;
          back(s, a, k+2, n);
        }
        else
        {
          a[n-1] = 2;
          back(s, a, k+2, n);
        }
      }
    }
  }
}


int main ()
{
  string code;
  int n = 0, sol[202];
  cin >> code;
  back(code, sol, 0, n);
  for(int i=0; i<n; ++i)
  {
    cout << sol[i];
  }
  cout << endl;
  return 0;
}

