#include <bits/stdc++.h>
using namespace std;

int main() {
    // int x[] = {1, 2, 3};
    int sum = 0;
    vector<int> temp {3,1,2,5,4,7};
    sort(temp.begin(), temp.end());

    do {
        for (int i=0; i<2; i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";
        sum += 1;

    } while (
        next_permutation(temp.begin(), temp.end())
    );

    cout << sum << "\n";

    return 0;
}