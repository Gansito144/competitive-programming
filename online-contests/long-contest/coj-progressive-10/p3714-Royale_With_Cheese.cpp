/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Ad-hoc lets use 
 * an array an hash every letter
 * in the string
*/

#include <cstdio>
#include <cstring>

using namespace std;

int code[26]={ 1,  5,  3,  4,  2,  9,  7,  8,  6, 10,
              11, 15, 13, 14, 12, 19, 17, 18, 16, 50,
              51, 55, 53, 54, 52, 59}, id[26];

int main() {
	char s[123456];
	while(gets(s)) {
		memset(id, -1, sizeof id);
		int i = -1, h; // None has appeared, hash
		int l = strlen(s);
		for( int k=0; k<l; ++k) {
			h = s[k]-'a';
			if(id[h] == -1) {
				id[h] = ++i;
			}
			printf("%d",code[id[h]]);
		}
		putchar('\n');
	} 
	return 0;
}