#include <bits/stdc++.h>
using namespace std;
int k;
int sum = 0;
int curNum;
stack<int>stck;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> k;
    for (int i=0; i<k; i++){
        cin >> curNum;

        if (curNum == 0){
            stck.pop();
        } else {
            stck.push(curNum);
        }
    }

    while (stck.size()){
        sum += stck.top();
        stck.pop();
    }

    cout << sum << "\n";

    return 0;
}