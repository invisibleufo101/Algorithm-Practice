#include <bits/stdc++.h>
using namespace std;
int n, num;
string instr;
deque<int>dq;

void execute(string instr, int num){
    if (instr == "push"){
        dq.push_back(num);
    } else if (instr == "pop"){
        if (dq.size()){
            cout << dq.front() << "\n";
            dq.pop_front();
        } else {
            cout << -1 << "\n";
        }
    } else if (instr == "size"){
        cout << dq.size() << "\n";
    } else if (instr == "empty"){
        if (dq.empty()) cout << 1 << "\n";
        else cout << 0 << "\n";
    } else if (instr == "front"){
        if (dq.size()) cout << dq.front() << "\n";
        else cout << -1 << "\n";
    } else if (instr == "back"){
        if (dq.size()) cout << dq.back() << "\n";
        else cout << -1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> instr;
        if (instr == "push") cin >> num;
        else num = 0;

        execute(instr, num);
    }

    return 0;
}