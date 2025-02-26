#include <bits/stdc++.h>
using namespace std;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    sort(s.begin(), s.end(), greater<int>());
    cout << s << "\n";
    
    return 0;
}