#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>

#define P first 
#define X first
#define Y second

using namespace std;
using ii = pair<int, int>;
using iii = pair<ii, int>;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, x, y;

  cin >> n;
  vector <iii> A(n);

  for (int i=0; i<n; ++i)
  {
    cin >> A[i].P.X >> A[i].P.Y;
    A[i].Y = i;
  }
  
  sort(A.begin(), A.end(), [=] (const iii&a, const iii&b)
      -> bool {
        if (a.P.Y != b.P.Y)
          return a.P.Y < b.P.Y;
        return a.P.X > b.P.X;
      });
  int L = 0, i = -1, j = -1;
  multiset <int> E;
  for (i=0; i<n; ++i)
  {
    //cout << A[i].Y << " " << A[i].P.X << " " << A[i].P.Y << endl; //
    while ( (L<i) && (A[L].P.Y < A[i].P.X) )
    {
      E.erase(E.find(A[L].P.X));
      ++L;
    }
    // Match
    if (E.lower_bound(A[i].P.X) != E.end())
    {
      //cout << "Found: " << *E.lower_bound(A[i].P.X) << endl; //
      while (L < i)
      {
        //cout<<L<<": "<<A[L].P.X<< ","<<A[L].P.Y<<" "<<A[L].Y<<endl; //
        if (A[L].P.X >= A[i].P.X)
        {
          j = A[i].Y + 1;
          i = A[L].Y + 1;
          break;
        }
        ++L;
      }
      break;
    }
    E.insert(A[i].P.X);
  }
  if (j == -1) i = -1;
  cout << i << " " << j << endl;
  return 0;
}

