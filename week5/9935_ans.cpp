#include <bits/stdc++.h>
using namespace std;
string s,r,ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s >> r;
    // Add char one by one
    // If the end of the string ret is equal to the target string,
    // Delete it
    // If ret is an empty string, print FULA
    // Else, print what's left

    for (char c : s){
        ret += c;

        if (ret.size() >= r.size() && ret.substr(ret.size() - r.size(), r.size()) == r){
            int delSize = r.size();
            ret.erase(ret.size() - r.size(), delSize);
        }
    }

    if (ret.size()) cout << ret << "\n";
    else cout << "FRULA\n";
}