#include <bits/stdc++.h>
using namespace std;

int ret = INT_MAX;
int cnt = 0;
int n,aa,bb,cc;

int solve(int a, int b, int c)
{
	if (a <= 0 && b <= 0 && c <= 0) {
		ret = ret < cnt ? ret : cnt;
		return;
	}

	solve(a - 9, b - 3, c - 1);
	solve(a - 9, b - 1, c - 3);
	solve(a - 3, b - 9, c - 1);
	solve(a - 3, b - 1, c - 9);
	solve(a - 1, b - 3, c - 9);
	solve(a - 1, b - 9, c - 3);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

	cout << solve(arr[0], arr[1], arr[2]);
	
    return 0;
}