#include <bits/stdc++.h>
using namespace std;
int n,student, cnt=1;
stack<int>stck;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> student;

        if (student == cnt) cnt++;
        else stck.push(student);

        while(stck.size() && stck.top() == cnt){
            cnt++;
            stck.pop();
        }
    }

    if(stck.size()) cout << "Sad\n";
    else cout << "Nice\n";

    return 0;
}