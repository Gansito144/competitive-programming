#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  int n, k, score[51];

  scanf("%d %d",&n,&k);
  for(int i=0; i<n; ++i)
    scanf("%d",&score[i]);
  for( ; k<n && score[k] == score[k-1]; ++k);
  for(k=k-1; k>=0 && !score[k]; k--);
  printf("%d\n",k+1);
  return 0;
}

