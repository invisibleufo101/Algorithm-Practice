#include <bits/stdc++.h>
using namespace std;
int n, k, words[51];
string s; 
int ret = 0;

int count(int mask) {
    int cnt = 0;
    for (int i=0; i<n; i++) { 
        if((words[i] & mask) == words[i]) cnt++; 
    }
    return cnt;
}

bool isDefaultLetter(int idx){
    char cIdx = idx + 'a';

    if (cIdx == 'a' || cIdx == 'c' || cIdx == 'i' || cIdx == 'n' || cIdx == 't'){
        return true;
    }
    return false;
}

// Actual answer
int go(int index, int cnt, int mask) {
    if (cnt > k) return 0;

    if (index == 26) return count(mask); 

    int ret = go(index+1, cnt+1, mask | (1 << index)); 

    if (index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a') {
        ret = max(ret, go(index+1, cnt, mask)); 
    }

    return ret;
}


// My version
void solve(int idx, int val, int cnt){
    if (cnt > k){
        return;
    } else if (idx == 26){
        ret = max(ret, count(val));
        return;
    }

    solve(idx+1, val | (1 << idx), cnt+1);

    if (!isDefaultLetter(idx)){
        solve(idx+1, val, cnt);
    }
}



int main() { 
    cin >> n >> k; 
    for (int i=0; i<n; i++) { 
        cin >> s;
        for (char str : s) {
            words[i] |= (1 << (str - 'a'));
        }
    }

    // cout << go(0, 0, 0) << '\n';

    solve(0, 0, 0);
    cout << ret << "\n";

    return 0;
}