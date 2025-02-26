#include <bits/stdc++.h>
using namespace std;
int x,y,w,h;

int main(){
    cin >> x >> y >> w >> h;

    vector<int>v = {w - x, x, h - y, y};
    cout << *min_element(v.begin(), v.end()) << "\n";

    return 0;
}
