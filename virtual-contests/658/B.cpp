#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int best[10];
int arr[212345];

int main () 
{
  int n, k, q, id, op;

  scanf("%d %d %d",&n,&k,&q);
  for (int i=0; i<n; ++i) {
    scanf("%d",&arr[i]);
  }

  memset(best, -1, sizeof best);

  while (q--) 
  {
    scanf("%d %d",&op,&id);
    --id;
    if(op == 1)
    {
      for(int i=0; i<k; ++i)
        if(-1==best[i] || arr[id] > arr[best[i]])
          swap(id, best[i]);
    }
    else
    {
      bool ans = false;
      for(int i=0; i<k; ++i)
        if(best[i] == id)
        {
          ans = true;
          break;
        }
      puts(ans?"YES":"NO");
    }
  }

  return 0;
}

