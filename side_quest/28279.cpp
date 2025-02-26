#include <bits/stdc++.h>
using namespace std;
int n, ins, num; 
deque<int>dq;

void execute(int instr, int num){
    switch(instr){

        case 1:
            dq.push_front(num);
            break;

        case 2:
            dq.push_back(num);
            break;

        case 3:
            if(!dq.empty()){
                cout << dq.front() << "\n";
                dq.pop_front();   
            } else {
                cout << "-1" << "\n";
            }
            break;

        case 4:
            if(!dq.empty()){
                cout << dq.back() << "\n";
                dq.pop_back();
            } else {
                cout << "-1" << "\n";
            }
            break;

        case 5:
            cout << dq.size() << "\n";
            break;

        case 6:
            if (dq.empty()){
                cout << "1" << "\n";
            } else {
                cout << "0" << "\n";
            }
            break;

        case 7:
            if (!dq.empty()){
                cout << dq.front() << "\n";
            } else {
                cout << -1 << "\n";
            }
            break;

        case 8:
            if (!dq.empty()){
                cout << dq.back() << "\n";
            } else {
                cout << -1 << "\n";
            }
            break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> ins;
        if (ins == 1 || ins == 2){
            cin >> num;
            execute(ins, num);
        } else {
            num = 0;
            execute(ins, num);
        }
    }

    return 0;
}