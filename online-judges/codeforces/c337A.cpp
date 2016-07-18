/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Use Two pointers 
 * to keep distance between numbers 
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int f[12345];

int main() {
	int n, m, mx = 1234567;

	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++) {
		scanf("%d",&f[i]);
	}
	sort(f,f+m);
	--n;
	for(int i=n; i<m; i++) {
		mx = min(mx, f[i]-f[i-n]);
	}
	printf("%d\n",mx);
	return 0;
}