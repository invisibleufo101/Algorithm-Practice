#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    int i = 666;
    int cnt = 0;
    while (true){
        string s = to_string(i);
        if (s.find("666") != string::npos){
            cnt++;
            if (cnt == n){
                cout << s << "\n";
                break;
            }
        }
        i++;
    }
    return 0;
}