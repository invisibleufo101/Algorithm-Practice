#include <bits/stdc++.h>
using namespace std;
string s;

int main(){
    getline(cin, s);
    deque<char>dq;

    for (int i=0; i<s.length(); i++){
        if (dq.size() && dq.front() == s[i]) continue;

        dq.push_front(s[i]);
    }

    while(dq.size()){
        cout << dq.back();
        dq.pop_back();
    }

    return 0;
}
