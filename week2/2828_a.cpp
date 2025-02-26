#include <bits/stdc++.h>
using namespace std;
int n, bucket_size;
int apple_num;
int apple_pos;
int cnt;
int l_pos, r_pos;
int main(){
    cin >> n >> bucket_size;
    cin >> apple_num;

    l_pos = 0;
    r_pos = l_pos + bucket_size - 1;
    cnt = 0;

    while (apple_num--){
        cin >> apple_pos;

        apple_pos = apple_pos - 1;

        // If apple is in bucket size range
        if (apple_pos >= l_pos && apple_pos <= r_pos){    
            continue;
        }

        // If bucket has to go forward
        if (r_pos < apple_pos){

            cnt += (apple_pos - r_pos);
            r_pos = apple_pos;
            l_pos = r_pos - bucket_size + 1;

        // If the bucket has to go backwards;
        } else if (apple_pos < l_pos){

            l_pos = apple_pos;
            r_pos = l_pos + bucket_size - 1;
            cnt += (r_pos - l_pos);
        }
    }
    cout << cnt << "\n";

    return 0;
}