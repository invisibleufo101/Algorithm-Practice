#include <bits/stdc++.h>
using namespace std;
int t;
string s;
char arr[1000001];
vector<char>v (1000001);
string ret="";

// - => Backspace
// < => arrow left key
// > => arrow right key

int main(){
    cin >> t;
    while (t--){
        cin >> s; 
        v.clear();
        int i = 0;
        int cur_cursor = 0;
        int prev_cursor = 0;
        while (true){
            if (s[i] == '<' && cur_cursor >= 0) {
                cur_cursor--;
            } else if (s[i] == '>' && v.size()) {
                cur_cursor++;
            } else if (s[i] == '-') {
                cur_cursor--;
                v.erase(v.end() - cur_cursor);
            } else {
                v.push_back(s[cur_cursor]);
                cur_cursor++;
            }

            if (i >= s.length()) break;

            prev_cursor = cur_cursor;

            i++;
        }
    }
    return 0;
}