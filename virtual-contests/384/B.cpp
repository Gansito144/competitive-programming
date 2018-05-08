#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
using ii = pair <int, int>;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int R, C, k;

  cin >> R >> C >> k;
  vector <vector<int>> A(R, vector<int> (C));
  vector <ii> ans;

  for (vector<int> & ai : A)
    for (int & aij: ai)
      cin >> aij;

  for (int i=0; i<C; ++i)
    for (int j=i+1; j<C; ++j)
    {
      bool change = false;
      for (int r=0; r<R; ++r)
      {
        if (k == 0 && A[r][i] > A[r][j])
        {
          change = true;
          swap(A[r][i], A[r][j]);
        }
        if (k == 1 && A[r][i] < A[r][j])
        {
          change = true;
          swap(A[r][i], A[r][j]);
        }
      }
      if (change)
      {
        if (k == 0) ans.push_back({i+1, j+1});
        else ans.push_back({j+1, i+1});
      }
    }

  cout << ans.size() << endl;

  for (const auto & ai : ans)
    cout << ai.first << " " << ai.second << endl;
 

  return 0;
}


