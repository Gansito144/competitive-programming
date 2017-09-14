#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

class LuckyNumbers
{
  private:
    std::vector <int> numbers;
  public:
    explicit LuckyNumbers (int maxLucky = 1e9)
      : numbers ()
    {
      int current = 0;
      numbers.push_back(0);
      while(true)
      {
        if(maxLucky / 10 < numbers[current]) break;
        int newFour  = numbers[current] * 10 + 4;
        int newSeven = numbers[current] * 10 + 7;
        numbers.push_back(newFour);
        numbers.push_back(newSeven); 
        ++current;
      }
    }

    // Get index of lucky number
    int getIndex(int lucky) 
    {
      return (int)(std::lower_bound(numbers.begin(), numbers.end(), lucky)
        - numbers.begin());
    }
};

int main()
{
  LuckyNumbers LN;
  int lucky;
  std::cin >> lucky;
  std::cout << LN.getIndex(lucky) << std::endl;
  return 0;
}

