#include <bits/stdc++.h>
using namespace std;
int n;
string name, status;
map<string,int>mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> name >> status;
        if (status == "enter"){
            mp[name] = 1;
        } else if (status == "leave"){
            mp.erase(name);
        }
    }

    auto it = mp.end();
    it--;
    while (it != mp.begin()){
        cout << it->first << "\n";
        it--;

        if (it == mp.begin()){
            cout << it->first << "\n";
        }
    }

    return 0;
}