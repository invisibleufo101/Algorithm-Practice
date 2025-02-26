#include <bits/stdc++.h>
using namespace std;
int t, n;
string p,x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){

        // String of commands
        // Number of elements
        // Array represented as string
        cin >> p >> n >> x;

        int tmp = 0;
        deque<int>dq;
        for (char c : x){
            if (c == '[' || c == ']') continue;
            else if (c >= '0' && c <= '9'){
                tmp = tmp * 10 + int(c - '0');
            } else if (c == ','){
                if (tmp > 0) dq.push_back(tmp);
                tmp = 0;
            }   
        }

        if (tmp > 0) dq.push_back(tmp);

        bool hasError = 0, isReversed = 0;
        for (char instruction : p){
            if (instruction == 'R') isReversed = !isReversed;
            else if (instruction == 'D'){
                if (dq.empty()){
                    hasError = 1;
                    break;
                }

                if (isReversed)  dq.pop_back();
                else dq.pop_front();
            }
        }

        if (hasError){
            cout << "error\n";
        } else {
            cout << "[";
            if (isReversed) reverse(dq.begin(), dq.end());
            while (dq.size()){
                if (dq.size() == 1) cout << dq.front();
                else cout << dq.front() << ",";
                dq.pop_front();
            }
            cout << "]\n";
        }

    }

    return 0;
}