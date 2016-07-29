/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Find the numbers of pairs which 
 * sum is a power of two
 * Solution: Complete search using map
*/

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
	map <int, int> cnt;
	int n, aj, ai;
	long long int ans = 0LL;

	scanf("%d",&n);
	while(n--) {
		scanf("%d",&aj);
		for(int k=1; k<31; ++k) {
			ai = (1<<k) - aj;
			if( cnt.count(ai) > 0 ) {
				ans += cnt[ai];
			}
		}
		cnt[aj]++;
	}
	cout << ans << endl;

	return 0;
}