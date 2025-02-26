#include <bits/stdc++.h>
using namespace std;
int n, num;
stack<int>stck;
int mx = 0;
vector<char>v;
bool isPossible = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> num;

        if (stck.size() && stck.top() > num){
            isPossible = 0;
            continue;
        }

        if (num > mx){

            for (int j=mx+1; j<=num; j++){
                v.push_back('+');

                stck.push(j);
            }

            v.push_back('-');
            stck.pop();

            mx = num;
        } else if (num < mx){

            while (stck.top() != num){
                v.push_back('-');
                stck.pop();
            }
            
            v.push_back('-');
            stck.pop();
        }
    }

    if (isPossible){
        for (char c : v) cout << c << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}