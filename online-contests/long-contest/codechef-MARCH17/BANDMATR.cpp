#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int zeros, cases, grid_size, item, ans;

  scanf("%d",&cases);
  while(cases--)
  {
    scanf("%d",&grid_size);
    zeros = 0;
    for(int i=0; i<grid_size; ++i)
    {
      for(int j=0; j<grid_size; ++j)
      {
        scanf("%d",&item);
        if(0 == item) zeros++;
      }
    }
    ans = grid_size - 1;
    for(int i=1; i<grid_size; ++i)
    {
      if(zeros >= (i<<1))
      {
        zeros -= (i<<1);
        ans--;
      }
    }
    printf("%d\n",ans);
  }

  return 0;
}

