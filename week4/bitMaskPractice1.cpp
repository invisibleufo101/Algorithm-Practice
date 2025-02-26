#include <bits/stdc++.h>
using namespace std;
const int n = 4;
string arr[4] = {"Apple", "Blueberries", "Grapes", "Pear"};

int main(){
    for (int i=0; i< (1 << n); i++){
        vector<string>ret;
        for (int j=0; j < n; j++){
            if (i & (1 << j)){
                ret.push_back(arr[j]);
            }
        }

        // Print
        for (auto i : ret) cout << i << ", ";
        cout << "\n";

    }
    cout << (1 << 1) << "\n";
    return 0;
}