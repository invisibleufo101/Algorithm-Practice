#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string>v;
map<string, int>mp;

bool cmp(string a, string b){
    if (a.length() == b.length()){
        return a < b;
    }
    return a.length() < b.length();
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> s;
    
        if (mp.find(s) == mp.end()){
            v.push_back(s);
            mp[s] = 1;
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (auto i : v){
        cout << i << "\n";
    }

    return 0;
}