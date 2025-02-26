#include <bits/stdc++.h>
using namespace std;
int n, ins, num;
stack<int>stck;

void execute(int instr, int n){
    switch(instr){
        case 1:
            stck.push(n);
            break;

        case 2:
            if (stck.size()){
                cout << stck.top() << "\n";
                stck.pop();
            } else if (stck.empty()){
                cout << -1 << "\n";
            }
            break;

        case 3:
            cout << stck.size() << "\n";
            break;

        case 4:
            if (stck.empty()) cout << 1 << "\n";
            else if (stck.size()) cout << 0 << "\n";
            break;

        case 5:
            if (stck.size()) cout << stck.top() << "\n";
            else cout << -1 << "\n";
            break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> ins;
        if (ins == 1) cin >> num;
        else num = 0;

        execute(ins, num);
    }

    return 0;
}