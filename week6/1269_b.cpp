#include <bits/stdc++.h>
using namespace std;
int a,b,aSet[200004],bSet[200004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;
    for (int i=0; i<a; i++) cin >> aSet[i];
    for (int i=0; i<b; i++) cin >> bSet[i];
    sort(aSet, aSet+a); sort(bSet, bSet+b);

    int cnt = 0;
    for (int i=0; i<a; i++) if (!binary_search(bSet, bSet+b, aSet[i])) cnt++;
    for (int i=0; i<b; i++) if (!binary_search(aSet, aSet+a, bSet[i])) cnt++;

    cout << cnt;
    return 0;
}