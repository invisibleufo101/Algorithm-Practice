#include <bits/stdc++.h>
using namespace std;
int n,x,y;
int max_x = -10001, max_y = -10001;
int min_x = 10001, min_y = 10001;

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x >> y;

        max_x = max(max_x, x);
        max_y = max(max_y, y);
        
        min_x = min(min_x, x);
        min_y = min(min_y, y);
    }

    int area = (max_x - min_x) * (max_y - min_y);
    cout << area << "\n";
    
    return 0;
}