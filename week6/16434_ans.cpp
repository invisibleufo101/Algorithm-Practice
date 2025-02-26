#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,atk,t,a,h,ret=-1;
struct room{
    ll type, attack, health;
};
vector<room>rooms;

bool check(ll maxHP){
    ll curHP = maxHP;
    ll curATK = atk;

    for(auto r : rooms){
        if (r.type == 1){
            ll damageTurns = r.health / curATK + bool(r.health % curATK) - 1;
            curHP -= damageTurns * r.attack;
        }   
        if (r.type == 2){
            curHP = min(curHP + r.health, maxHP);
            curATK += r.attack;
        }
        if (curHP <= 0) return 0;
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

    ll lo = 0, hi = 1e18+4;
    while (lo <= hi){
        ll mid = (lo + hi) / 2;
        if (check(mid)){
            ret = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ret << "\n";

    return 0;
}