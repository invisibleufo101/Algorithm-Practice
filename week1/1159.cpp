#include<bits/stdc++.h>
using namespace std;
int n;
string plyer, ans;
map<char, int> mp;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> plyer;
        if (mp[plyer[0]]){
            mp[plyer[0]] += 1;
        } else {
            mp[plyer[0]] = 1;
        }
    }

    for (auto i: mp){
        if (i.second >= 5){
            ans += i.first;
        }
    }

    if (ans.size()) cout << ans << " ";
    else cout << "PREDAJA" << " ";

    return 0;
}