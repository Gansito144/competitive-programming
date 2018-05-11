#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using i64 = unsigned long long int;

inline bool check (i64 A, i64 K, i64 B)
{
  if (B % K) return false;
  return B/K == A;
}

int main ()
{
  int n;
  cin >> n;
  vector <i64> a(n);
  vector <bool> seen(n, false);
  deque <i64> dq;

  for (i64 &ai : a) cin >> ai;

  dq.push_front(a[0]); seen[0] = true;
  //cout << "Adding: " << a[0] << endl; //
  while (dq.size() < n)
  {
    for (int i=1; i<n; ++i)
    {
      if (seen[i]) continue;
      // check front 
      i64 A = dq.front(), &B = a[i], C = dq.back();
      //cout << A << " , " << B << " , " << C << endl; //
      if (   (A>B && check(B, 2ULL, A))
          || (A<B && check(A, 3ULL, B)) )
      {
        dq.push_front(B);
        seen[i] = true;
        //cout << "Adding in front: " << B << endl; //
        break;
      } 
      // check back
      if (   (C>B && check(B, 3ULL, C))
          || (C<B && check(C, 2ULL, B)) )
      {
        dq.push_back(B);
        seen[i] = true;
        //cout << "Adding in back: " << B << endl; //
        break;
      }
    }
  }

  while (!dq.empty())
  {
    cout << dq.front() << " ";
    dq.pop_front();
  }
  cout << endl;
  return 0;
}



