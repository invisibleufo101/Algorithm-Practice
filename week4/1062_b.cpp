#include <bits/stdc++.h>
using namespace std;
int n,k;
string s;
int words[51];
int base = 0;
int ret = 0;

bool isDefaultLetter(int idx){
    char charIdx = idx + 'a';

    if (charIdx == 'a' || charIdx == 'c' || charIdx == 'i' || charIdx == 'n' || charIdx == 't'){
        return true;
    }
    return false;
}

int count(int val){
    int cnt = 0;
    for (int i=0; i<n; i++){
        if ((words[i] & val) == words[i]) cnt++;
    }
    return cnt;
}

void solve(int idx, int val, int cnt){
    if (cnt > k-5){
        return;
    } 

    if (idx == 26){
        ret = max(ret, count(val));
        return;
    }

    // Case for not including letter
    solve(idx+1, val, cnt);

    // Case for including letter IF it's not a,c,i,n,t (because they're already included)
    if (!isDefaultLetter(idx)){

        solve(idx+1, val | (1 << idx), cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> s;
        for (char c : s){
            words[i] |= (1 << int(c - 'a'));
        }
    }

    for (char c : {'a','c','i','n','t'}){
        base |= (1 << int(c - 'a'));
    }

    solve(0, base, 0);
    cout << ret << "\n";

    return 0;
}