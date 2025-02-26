#include<bits/stdc++.h>
using namespace std;

// Counting Stars - Map or Array
string word;
int cnt[26];
int x[5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> word;
    for (char i : word) cnt[i - 'a']++;
    for (int i=0; i<sizeof(cnt)/sizeof(cnt[0]); i++) cout << cnt[i] << " ";
    
    return 0;
}

/**
 * JUST REMEMBER
 * ASCII code for 
 * !! A = 65 !!
 * Z = 65 + 26 - 1 = 90
 * !! a = 97 !!
 * z = 97 + 26 - 1 = 122
*/