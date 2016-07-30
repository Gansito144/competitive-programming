#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char s[123456];

int main() {
	int len;
	
	scanf("%s",s);
	len = strlen(s);
	int fab = len, lab = -1, fba = len, lba = -1;
	for(int i=0; i<len ; ++i) {
		if('A'==s[i] && 'B'==s[i+1]) {
			fab = min(fab,i);
			lab = max(lab,i);
		}
		if('B'==s[i] && 'A'==s[i+1]) {
			fba = min(fba,i);
			lba = max(lba,i);
		}
	}
	if(((fab+1)<lba)||((fba+1)<lab)) {
		puts("YES");
	} else puts("NO");
	return 0;
}