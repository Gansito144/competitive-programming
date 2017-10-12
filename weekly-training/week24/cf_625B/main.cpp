#include <iostream>

using namespace std;

int main()
{
  string src, tgt;

  cin >> src;
  cin >> tgt;

  int N = (int)src.size();
  int M = (int)tgt.size();

  int ans = 0;
  for(int i=0; i+M<=N; ++i)
  {
    bool match = true;
    for(int j=0; j<M; ++j)
    {
      if(src[i+j] != tgt[j])
      {
        match = false;
        break;
      }
    }
    if(match)
    {
      i += M-1; 
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}


