#include <bits/stdc++.h>
using namespace std;
int n,m,a[500004],b[500004];
vector<int>ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    sort(a, a+n); sort(b, b+m);

    for (int i=0; i<n; i++){
        if (!binary_search(b, b+m, a[i])) ret.push_back(a[i]);
    }

    if (ret.empty()) cout << 0;
    else {
        cout << ret.size() << "\n";
        for (int i : ret) cout << i << " ";
    }

    return 0;
}