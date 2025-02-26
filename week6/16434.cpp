#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,atk,t,a,h;
ll ret = LLONG_MAX;
struct room {
    ll type,attack,health;
};
vector<room>rooms;

bool check(ll maxHP){
    ll curHP = maxHP;
    ll curATK = atk;
    for (int i=0; i<n; i++){
        room curRoom = rooms[i];
        if (curRoom.type == 1){
            ll monsterATK = curRoom.attack;
            ll monsterHP = curRoom.health;

            // Times the knight attacks => monsterHP / curATK + bool(monsterHP % curATK)
            // Times the knight GETS attacked => Number of times knight attacks - 1
            // we substract 1 since the knight attacks the monster FIRST
            ll timesAttacked = monsterHP / curATK + bool(monsterHP % curATK) - 1;

            // Deduct HP 
            curHP -= monsterATK * timesAttacked;
            if (curHP <= 0) return 0; // Game over
        } else if (curRoom.type == 2){
            curHP = min(curHP + curRoom.health, maxHP);
            curATK += curRoom.attack;
        }
    }
    
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> atk;
    for (int i=0; i<n; i++){
        cin >> t >> a >> h;
        rooms.push_back({t,a,h});
    }

    ll lo = 1, hi = LLONG_MAX - 1;
    // Binary Search maxHP
    while (lo <= hi){
        ll mid = (lo + hi) / 2;
        // If the current maxHP can clear the game, 
        // try to find a lower maxHP that can also clear the game
        if (check(mid)) hi = mid - 1;
        else if (!check(mid)) lo = mid + 1;
    }

    cout << lo << "\n";

    return 0;
}