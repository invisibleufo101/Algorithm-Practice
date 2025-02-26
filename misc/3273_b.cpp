#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int n, x;
map<int,int>mp;
int cnt = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cin >> x;

	for (int i = 0; i < n; i++){

        if (mp.find(x - arr[i]) != mp.end()){
            cnt++;
        } else {
            mp[arr[i]] = 1;
        }
	}

	cout << cnt << "\n";

	return 0;
}