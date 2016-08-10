/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Solution: Simply maintain the 
 * property of none side is greater 
 * than the sum of all other sides
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, a[55], sum = 0, cnt = 0;
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	for(int i=0; i<n; ++i) {
		if(a[i] >= (sum-a[i])) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
