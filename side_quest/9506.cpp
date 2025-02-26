#include <bits/stdc++.h>
using namespace std;
int n;

int main(){

    while (cin >> n && n != -1){
        vector<int>v;
        int sum = 0;
        for (int i=1; i<n; i++){
            if (n % i == 0){
                sum += i;
                v.push_back(i);
            }
        }

        if (sum == n){
            cout << n << " = ";
            for (int i=0; i<v.size(); i++){
                if (i == v.size()-1){
                    cout << v[i] << "\n";
                } else {
                    cout << v[i] << " + ";
                }
            }
        } else {
            cout << n << " is NOT perfect.\n";
        }
    }
    return 0;
}