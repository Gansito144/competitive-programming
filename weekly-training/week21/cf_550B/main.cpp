#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

class Solution 
{
  int problems, minTotal, maxTotal, minDiff;
  std::deque<int> cost;
public:
  // Default constructor
  Solution ()
    : problems(0)
    , minTotal(INT_MAX)
    , maxTotal(INT_MIN)
    , minDiff (0)
    , cost    ()
  {}
  // Read parameters
  void read ()
  {
    std::cin >> problems;
    std::cin >> minTotal;
    std::cin >> maxTotal;
    std::cin >> minDiff;
    cost.assign(problems, 0);
    for(int &c : cost)
      std::cin >> c;
  }
  // Validate diff
  inline bool isValidDiff (int diff)
  {
    return diff >= minDiff;
  }
  // Validate total
  inline bool isValidTotal (int total) 
  {
    return total >= minTotal && total <= maxTotal;
  }
  // validate at least two problems
  inline bool isValidMask (int mask) 
  {
    return __builtin_popcount(mask) >= 2; 
  }
  // Get total from a mask 
  int getTotalFromMask (int mask)
  {
    int total = 0;
    for(int bit=0; bit<problems; ++bit)
    {
      if((mask>>bit)&1) total += cost[bit];
    }
    return total;
  }
  // Get a diff from mask
  int getDiffFromMask (int mask)
  {
    int minCost = INT_MAX, maxCost = INT_MIN;
    for(int bit=0; bit<problems; ++bit)
    {
      if((mask>>bit)&1)
      {
        minCost = std::min(minCost, cost[bit]);
        maxCost = std::max(maxCost, cost[bit]);
      }
    }
    return maxCost - minCost; 
  }
  // get count of Solutions
  int getCount ()
  {
    int cnt = 0;
    for(unsigned int mask=3; mask<(1<<problems); ++mask)
    {
      if( !isValidMask(mask)) continue;
      int total = getTotalFromMask(mask);
      int diff  = getDiffFromMask (mask);
      if(isValidTotal(total) && isValidDiff(diff)) ++cnt;
    }
    return cnt;
  }
};

int main()
{
  Solution solution;
  solution.read();
  std::cout << solution.getCount() << std::endl;
  return 0;
}

