#include <bits/stdc++.h>
using namespace std;
int n;
string op;
int num;
int start = 0;

void execute(string inst, int x){
    // Switch case is not available for strings RIP

    if (inst == "add"){
        
    } else if (inst == "remove"){
        
    } else if (inst == "check"){

    } else if (inst == "toggle"){

    } else if (inst == "all"){

    } else if (inst == "empty"){

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> op >> num;
        execute(op, num);
    }

    return 0;
}