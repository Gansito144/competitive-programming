#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

inline double abso(double X)
{
  return X < 0.0 ? -X : X;
} 

int main ()
{
  double n, a;
  
  cin >> n >> a;
  double ang = ((180.0f) * (n-2.0f)) / n;
  double del = ang / (n-2.0f);
  int best = 3;
  double best_diff = abso(ang - a);
  for(int k = 4; k <= n; ++k)
  {
    double new_ang = ang - del;
    if(abso(new_ang - a) < best_diff)
    {
      best_diff = abso(new_ang - a);
      best = k;
    }
    ang = new_ang;
  }
  cout << "1 2 " << best << endl;
  return 0;
}

