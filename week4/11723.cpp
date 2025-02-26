#include <bits/stdc++.h>
using namespace std;
int n;
string instr;
int op;
int base = 0;

void execute(string s, int o){

    // Add
    if (s == "add"){
        base |= (1 << o);
    } else if (s == "remove"){
        base &= ~(1 << o);
    } else if (s == "check"){
        if (base & (1 << o)) cout << 1 << "\n";
        else cout << 0 << "\n";
    } else if (s == "toggle"){
        base ^= (1 << o);
    } else if (s == "all"){
        base = (1 << 21) - 1;
    } else if (s == "empty"){
        base = 0;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<pair<string,int>>v;
    cin >> n;
    for (int i=0; i<n; i++){

        cin >> instr;
        if (instr == "all" || instr == "empty"){
            op = 0;
        } else {
            cin >> op;
        }

        execute(instr, op);   
    }

    return 0;
}

