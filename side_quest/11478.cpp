#include <bits/stdc++.h>
using namespace std;
string s;
set<string>st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    for (int i=0; i<s.size(); i++){
        for (int j=1; j<=s.size()-i; j++){
            st.insert({s.substr(i,j)});
        }
    }

    cout << st.size() << "\n";
    
    return 0;
}