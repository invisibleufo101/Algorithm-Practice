#include <bits/stdc++.h>
using namespace std;
int x;
int ret = 1;

string convert(int n){
    string bin = bitset<8>(n).to_string();
    return bin;
}

int main(){
    // 23 = 0b10111

    cin >> x;
    while (x != 1){
        
        if (x & 1) ret++;

        x /= 2;
    }

    cout << ret << "\n";

    cout << convert(23) << "\n";
    cout << convert(11) << "\n";
    cout << convert(5) << "\n";

    return 0;
}