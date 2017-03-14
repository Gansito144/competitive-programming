#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
  int task, no_cases, no_tasks;
  
  scanf("%d",&no_cases);
  while(no_cases--)
  {
    scanf("%d",&no_tasks);
    int paths[2] = {0, 0};
    for(int i=0; i<no_tasks; ++i)
    {
      scanf("%d",&task);
      paths[i&1] += task;
    }
    for(int i=1; i<=no_tasks; ++i)
    {     
      scanf("%d",&task);
      paths[i&1] += task;
    }
    printf("%d\n",min(paths[0], paths[1]));
  }
  return 0;
}

