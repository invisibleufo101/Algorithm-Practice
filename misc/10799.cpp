#include <bits/stdc++.h>
using namespace std;
string s;
stack<char>stck;
int arr[100002];
int laserPoints[100002];
int stickEnds[100002];
int stickCnt = 0;
int cnt = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    for (int i=0; i<s.length(); i++){

        if (i < s.length()-1){
            if (s[i] == '(' && s[i+1] == ')'){
                cnt += stickCnt;
                i += 1;
                continue;
            }
        }

        if (s[i] == '('){
            stickCnt++;
            stck.push(s[i]);
        }

        if (stck.size() && stck.top() == '(' && s[i] == ')'){
            stickCnt--;
            cnt++;

            stck.pop();
        }
    }

    cout << cnt << "\n";
    

    return 0;
}