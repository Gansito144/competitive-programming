/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Use a greedy approach to 
 * charge the device with less energy
 * Solution: Simulation + Greedy
*/

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int cnt = 0, a, b, down = 2, up = 1;
	cin >> a >> b;
	while( (a>0 && b>0) && (a>1||b>1) ) {
		if(a > b) swap(a,b);
		++a;
		b -= down;
		++cnt;
	}
	cout << cnt << endl;
	return 0;
}