#include <bits/stdc++.h>
using namespace std;
string arr[5] = { "apple", "banana", "crocs", "deer", "elephant"};
map<char, int> mp;
string ans;

int main(){
    for (int i=0; i<sizeof(arr)/sizeof(string); i++){
        char first_letter = arr[i][0];

        if (mp[first_letter]){
            mp[first_letter] += 1;
        } else {
            mp[first_letter] = 1;
        }
    }

    for (auto i: mp){
        if (i.second >= 1){
            ans += i.first;
        }
    }

    if (ans.size()) cout << ans << "\n";
    else cout << "NONE" << "\n";

    return 0;
}