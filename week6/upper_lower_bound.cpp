#include <bits/stdc++.h>
using namespace std;
string s;

int main(){
    while (cin >> s && s != "END"){
        int val = stoi(s);
        vector<int>v = {1,5,9};

        cout << "Lower Bound:\n";
        cout << lower_bound(v.begin(), v.end(), val) - v.begin() << "\n";
        cout << "Upper Bound:\n";
        cout << upper_bound(v.begin(), v.end(), val) - v.begin() << "\n";
    }

    return 0;
}