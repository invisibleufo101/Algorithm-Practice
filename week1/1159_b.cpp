#include<bits/stdc++.h>
using namespace std;
int n, cnt[26];
string plyer, ans;

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> plyer;
        cnt[plyer[0] - 'a']++;
    }

    for (int i=0; i<sizeof(cnt)/sizeof(int); i++){
        if (cnt[i] >= 5){
            ans += i + 'a';
        }
    }

    if (ans.size()) cout << ans << " ";
    else cout << "PREDAJA" << " ";

    return 0;
}
