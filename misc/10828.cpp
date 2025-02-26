#include <bits/stdc++.h>
using namespace std;
int n;
string instr;
int op;
stack<int>stck;

void execute(string instr, int op){
    if (instr == "push"){
        stck.push(op);
    } else if (instr == "pop"){
        if (stck.size()) {
            cout << stck.top() << "\n";
            stck.pop();
        }
        else cout << -1 << "\n";
    } else if (instr == "size"){
        cout << stck.size() << "\n";
    } else if (instr == "empty"){
        if (stck.empty()) cout << 1 << "\n";
        else cout << 0 << "\n";
    } else if (instr == "top"){
        if (stck.size()) cout << stck.top() << "\n";
        else cout << -1 << "\n";
    } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> instr;
        if (instr == "push"){
            cin >> op;
        } else {
            op = 0;
        }

        execute(instr, op);
    }

    return 0;
}