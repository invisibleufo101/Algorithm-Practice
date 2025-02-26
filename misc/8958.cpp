#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int main(){
    cin >> n;
    while (n--){
        cin >> s;
        int cnt = 0;
        int bonus = 1;
        for (int i=0; i<s.length(); i++){
            if (s[i] == 'O'){
                cnt += bonus;
                bonus++;
            } else {
                bonus = 1;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}