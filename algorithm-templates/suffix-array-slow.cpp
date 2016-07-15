/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: O(N^2 Log N) Implementation for suffix array
 * computation. Expected output:
 * sa[0] = 4
 * sa[1] = 2
 * sa[2] = 0
 * sa[3] = 5
 * sa[4] = 3
 * sa[5] = 1
 * sa[6] = 6
*/

#include <cstdio>
#include <algorithm>
 
using namespace std;
 
char *str = "ababaac";
 
bool cmp(int a, int b) {
	return strcmp(str+a, str+b) < 1; 
}
 
void build_suffix( ) {
	int n = strlen(str);
	int sa[n];
	for(int i=0; i<n; i++) sa[i] = i;
	sort(sa,sa+n, cmp);
	for(int i=0; i<n; i++){
		printf("sa[%d] = %d\n",i,sa[i]);
	}
}
 
int main() {
	build_suffix();
	return 0;
}