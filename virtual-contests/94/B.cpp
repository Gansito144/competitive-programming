#include <iostream>
#include <string>

using namespace std;

int G[6][6];

int main ()
{
  int m, a, b;

  cin >> m;
  while (m--)
  {
    cin >> a >> b;
    G[a][b] = G[b][a] = 1;
  }
  int ts = 0;
  for (int x=1; x<=5; ++x)
    for (int y=1; y<=5; ++y)
      for (int z=1; z<=5; ++z)
      {
        if (x==y || x==z || y==z)
          continue;
        int cnt = G[x][y] + G[x][z] + G[y][z];
        ts += cnt==0 || cnt == 3;
      }
        
  cout << ( ts>0 ? "WIN" : "FAIL") << endl;
  return 0;
}

