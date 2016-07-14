/*
 * Author: Ulises Mendez Martinez
 * Mail: ulisesmdzmtz@gmail.com
 * Description: Use two streams to check wheter each 2 
 * lines have the same number of words with the same initial 
 * letters.  
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
   string line_a, line_b, str_a ,str_b;
   while(getline(cin, line_a)){
      getline(cin, line_b);
      bool ok = true;
      istringstream in_a(line_a);
      istringstream in_b(line_b);
      while(ok) {
	 in_a >> str_a;
         in_b >> str_b;
         if( (str_a.size() > 0) ^ (str_b.size() > 0) ){
            ok = false;
            break;
         }
         if(str_a.size() > 0) {
	   ok = str_a[0] == str_b[0];
         } else break;
         // cout << "a: " << str_a << " ,b: " << str_b << endl;
         str_a = str_b = ""; 
      }
      cout << (ok?"yes":"no") << endl;
   }
   return 0; 
}

