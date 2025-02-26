#include <bits/stdc++.h>
using namespace std;
int a;
string b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;

    int ret3 = a * (b.back() - '0');
    int ret4 = a * (b[1] - '0');
    int ret5 = a * (b[0] - '0');

    cout << ret3 << "\n" << ret4 << "\n" << ret5 << "\n";
    cout << a * atoi(b.c_str()) << "\n";

    return 0;
}