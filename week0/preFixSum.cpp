#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100004], b, c, psum[100004], n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=1; i<=8; i++){
        cout << "Input for element number" << i << "\n";
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];

    }

    for (int i=0; i < 3; i++){
        cin >> b >> c;
        cout << psum[c] - psum[b-1] << "\n";
        
    }
    return 0;
}