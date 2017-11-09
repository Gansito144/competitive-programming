#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using i64 = long long int;

const int MaxN = 502;

int people[MaxN];

int main ()
{
  i64 k, wins = 0, n;
  int mx = -1;
  queue <int> line;

  cin >> n >> k;
  for(int i=0; i<(int)(n); ++i)
  {
    cin >> people[i];
    mx = max(mx, people[i]);
    line.push(people[i]);
  }
  if(k > n) cout << mx << endl;
  else
  {
     mx = line.front(); line.pop();
     while(true)
     {
       int next = line.front(); line.pop();
       if(mx > next)
       {
          ++wins;
       } else 
       {
         wins = 1;
         swap(next, mx);
       }
       if(wins == k) 
         break;
       line.push(next);
     }
     cout << mx << endl;
  }
  return 0;
}

