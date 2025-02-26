#include <bits/stdc++.h>
using namespace std;
string s;

int main(){
    while (getline(cin, s) && s != "END"){

        reverse(s.begin(), s.end());
        cout << s << "\n";
    }

    return 0;
}