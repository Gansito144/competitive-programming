/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Solution: Uses modulus to calculate
 * how many cakes are needed. 
 * tricky case when n divides m
*/

#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if( m % n ) cout << (n-(m%n)) << endl;
	else cout << 0 << endl;
	return 0;
}
