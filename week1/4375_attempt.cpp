#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n;

/**
 * This solution DOES work by its implementation.
 * So, the idea is that since all of the numbers in the solution need to be 1,
 * we just have to convert the cnt to string, then add "1" at the end and convert
 * that back to long long integer. 
 * 
 * However, the problem is that some outputs are going to be very very big.
 * Even the biggest number type, unsigned long long, can't cover that much.
 * And by putting a 1sec delay in the nested while loop, I can clearly see from the
 * output that when the decimal place goes over 20, the number goes to the max integer value.
 * Therefore, this method seems like a good idea at first, but techanically doesn't work.
*/

int main(){

    while (!cin.eof()){
        cin >> n;

        ull cnt=1;

        while (true){
            // Put a 1 sec delay to see what the decimal place limit is
            std::chrono::seconds dura(1);
            __libcpp_thread_sleep_for(dura);

            if (cnt % n == 0){
                cout << to_string(cnt).length() << "\n";    
                break;
            }

            // Converts to String type and adds "1" at the end
            string str_cnt = to_string(cnt) += "1";
            cout << "String ver of cnt: " << str_cnt << endl;
            // Converts the var back to integer for math calculations
            cnt = atoll(str_cnt.c_str());
            cout << "LL conversion : " << cnt << "\n";
            cout << "Decimal length : " << to_string(cnt).length() << "\n\n";
        }
    }
    
    return 0;
}

// 3 7 9901
// Small decimals
// 39 Result : 6 
// 9 Result : 9

// 47 Result : 46 
// 67 Result : 33 
// 89 Result : 44

// int cnt = 1;
// int i = 0;
// while (i < 6)
// {
//     cout << "String ver: (" << to_string(cnt) << ")\n";

//     cout << "Math stuff: " << cnt + 1 << "\n";

//     // string str_cnt = to_string(cnt);
//     // str_cnt += "1";

//     string str_cnt = to_string(cnt) += "1";

//     cnt = atoi(str_cnt.c_str());
//     i++;
// }

// cout << to_string(cnt).length() << "\n";