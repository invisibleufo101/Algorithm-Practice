#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,atk,t,a,h;
ll maxHP, curHP;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> atk;
    for (int i=0; i<n; i++){
        cin >> t >> a >> h;
        
        // Case when it's a monster
        if (t == 1){
            ll damageTaken = a * (h / atk + bool(h % atk) - 1);
            
            if (curHP < damageTaken){
                maxHP += (damageTaken - curHP);
                curHP = 0;
            } else if (curHP >= damageTaken){
                curHP -= damageTaken;
            }
        // Case when it's a potion
        } else if (t == 2){
            curHP = min(maxHP, curHP + h);
            atk += a;
        }
    }

    cout << maxHP + 1 << "\n";

    return 0;
}