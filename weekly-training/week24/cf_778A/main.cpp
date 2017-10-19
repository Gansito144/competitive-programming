#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int kM = 212345;
char src[kM], tgt[kM];
int dead[kM];
int N, M;

int check (int ti) 
{
  if(ti >= N) return true;
  int p = 0;
  for(int i=0; i<N; ++i)
  {
    if(dead[i] <= ti) continue;
    if(src[i] == tgt[p])
    {
      ++p;
      if(p == M)
        return false;
    }
  }
  return true;
}

int main ()
{
  scanf("%s",src);
  scanf("%s",tgt);
  N = (int) strlen(src);
  M = (int) strlen(tgt);
  for (int i=0; i<N; ++i) 
  {
    int nxt;
    scanf("%d",&nxt);
    dead[nxt-1] = i+1;
  }
  int ans = (1<<21) - 1;
  for(int k=20; k>=0; --k)
  {
    int bit = 1<<k;
    int ret = check(ans ^ bit);
    //cout << (ans^bit) << " - " << ret << endl;
    ans ^= ret << k;
  }
  cout << ans-1 << endl;
  return 0;
}

