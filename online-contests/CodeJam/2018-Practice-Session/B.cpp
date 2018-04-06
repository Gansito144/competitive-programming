#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define VAL first
#define CHR second

using namespace std;
using IC = pair <int, char>;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tcs;
  cin >> tcs;

  for (int tc=1; tc<=tcs; ++tc)
  {
    int N, tot = 0, pi;
    cin >> N;
    priority_queue < IC > PQ; 
    for (int i=0; i<N; ++i)
    {
      cin >> pi;
      tot += pi;
      PQ.push(make_pair(pi, 'A'+i));
    }
    cout << "Case #" << tc  << ":";
    while (!PQ.empty())
    {
      IC a = PQ.top(); PQ.pop();
      IC b = PQ.top(); PQ.pop();
      if (a.VAL == 1 && b.VAL == 1 && PQ.size() == 1)
      {
        cout << " " << a.CHR;
        PQ.push(b);
        continue;
      }
      cout << " " << a.CHR << b.CHR;
      --a.VAL; --b.VAL;
      if (a.VAL) PQ.push(a);
      if (b.VAL) PQ.push(b);
    }
    cout << endl;
  }
  return 0;
}

