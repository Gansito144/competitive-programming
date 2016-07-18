/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Find the largest increasing
 * segment in an array.
 * Solution: Keep previous value, and count
 * lenght of each segment.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, pre = -1, now, cnt, mx = -1;

	scanf("%d",&n);
	while(n--) {
		scanf("%d",&now);
		cnt = (now<pre) ? 1 : cnt+1;
		mx = max(mx, cnt);
		pre = now;
	}
	printf("%d\n",mx);

	return 0;
}