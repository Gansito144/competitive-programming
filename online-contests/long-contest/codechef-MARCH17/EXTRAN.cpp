#include <stdio.h>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
  int no_cases;

  scanf("%d",&no_cases);
  while(no_cases--)
  {
    int no_numbers, bad_number;
    scanf("%d",&no_numbers);
    deque <int> numbers(no_numbers);
    for(int i=0; i<no_numbers; ++i) {
      scanf("%d",&numbers[i]);
    }
    sort(numbers.begin(), numbers.end());
    if(numbers[1]-1 > numbers[0])
    {
      bad_number = numbers[0];
    } else if(numbers[no_numbers-1] - 1 > numbers[no_numbers-2]) 
    {
      bad_number = numbers[no_numbers-1];
    }
    else
    {  for(int i=1; i<no_numbers; ++i)
      {
        if(numbers[i] == numbers[i-1])
        {
          bad_number = numbers[i];
          break;
        }
      }
    }
    printf("%d\n",bad_number);
  }

  return 0;
}

