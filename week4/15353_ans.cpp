#include <bits/stdc++.h>
using namespace std;;
string a,b;

string solve(string a, string b){
    int sum = 0;
    string ret = "";
    while (a.size() || b.size() || sum){
        if (a.size()){
            sum += int(a.back() - '0');
            a.pop_back();
        } 
        
        if (b.size()){
            sum += int(b.back() - '0');
            b.pop_back();
        }

        ret += char((sum % 10) + '0');
        sum /= 10; // Carryover (either 1 or 0)

        cout << ret << "\n";
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;

    cout << solve(a,b) << "\n";

    return 0;
}