#include <iostream>
#include <set>

using namespace std;

typedef long long int i64;

int main() {
    int T;
    i64 n;
    set<i64> s;
    set<i64> ::iterator it;
    s.insert(1); s.insert(2); s.insert(3);
    s.insert(5); s.insert(6); s.insert(9);
    s.insert(10); s.insert(13); s.insert(17);
    cin >> T;
    while(T--) {
        cin >> n;
        puts((s.find(n)!=s.end())?"No":"Yes");
    }
    return 0;
}

