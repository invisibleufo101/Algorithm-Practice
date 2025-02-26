#include <bits/stdc++.h>
using namespace std;
string s;
int b;
map<char,int>mp;
long long sum = 0;

void setup(){
    for (int i=0; i<26; i++){
        char c = i + 'A';
        mp[c] = i+10;
    }
    return;
}

int main(){
    cin >> s >> b;

    setup();
    reverse(s.begin(), s.end());

    for (int i=0; i<s.size(); i++){
        if (isupper(s[i])){
            int buffer = mp[s[i]] * pow(b, i);
            sum += buffer;
        } else if (!isupper(s[i])){
            int buffer = (s[i] - '0') * pow(b, i);
            sum += buffer;
        }
    }

    cout << sum << "\n";

    return 0;
}