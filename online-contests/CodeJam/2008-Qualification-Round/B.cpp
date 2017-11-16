#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main () 
{
  const int TOTAL_MINUTES = 60*24;
  int cases;

  scanf("%d",&cases);
  for(int test_case=1; test_case<=cases; ++test_case)
  {
    int need_A=0, need_B=0;

    vector <int> timeA(TOTAL_MINUTES+1, 0), timeB(TOTAL_MINUTES+1, 0);
    int trainsA, trainsB, hr, mn, ttime, delta;

    scanf("%d",&delta);
    // Read for A
    scanf("%d %d",&trainsA,&trainsB);
    while(trainsA--)
    {
      scanf("%d:%d",&hr,&mn);
      ttime = hr*60 + mn + 1;
      --timeA[ttime];
      scanf("%d:%d",&hr,&mn);
      ttime = hr*60 + mn + delta + 1;
      if(ttime <= TOTAL_MINUTES)
        ++timeB[ttime];

    }
    while(trainsB--)
    {
      scanf("%d:%d",&hr,&mn); 
      ttime = hr*60 + mn + 1;
      --timeB[ttime]; 
      scanf("%d:%d",&hr,&mn);
      ttime = hr*60 + mn  + delta + 1;
      if(ttime <= TOTAL_MINUTES)
        ++timeA[ttime];
    }
    for(int i=1; i<=TOTAL_MINUTES; ++i)
    {
      timeA[i] += timeA[i-1];
      timeB[i] += timeB[i-1];
      if(timeA[i] < 0)
      {
        need_A += -timeA[i];
        timeA[i] = 0;
      }
      if(timeB[i] < 0)
      {
        need_B += -timeB[i];
        timeB[i] = 0;
      }
    }
    printf("Case #%d: %d %d\n", test_case, need_A, need_B);
  }
  return 0;
}

