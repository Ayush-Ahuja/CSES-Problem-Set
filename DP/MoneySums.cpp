#include <bits/stdc++.h>

using namespace std;

#define LOOP(p, q) for(int i = (p); i < (q); i++)
#define LOOP_(p,q,i) for(int i = (p); i < (q); i++)
#define ll long long
#define all(x) x.begin(), x.end()
long long GCD(long long a,long long b){
  if(b==0LL) return a;
  else return GCD(b,a%b);
}
long long LCM(long long a,long long b){
  return (a*b)/GCD(a,b);
}
ll N = 3e5+7;
ll mod = 998244353;
ll mod2 = 1e9 + 7;
ll n;
vector<ll> coins;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    coins.resize(n);
    ll total = 0;
    LOOP(0, n){
        cin >> coins[i];
        total += coins[i];
    }
    vector<ll> values(total + 1, 0);
    values[0] = 2;
    LOOP(0, n){
        LOOP_(0, total + 1, j){
            if (values[j] == 2){
                if (values[j + coins[i]] == 2) continue;
                values[j + coins[i]] = 1;
            }
        }
        LOOP_(0, total + 1, j){
            if (values[j] == 1){
                values[j] = 2;
            }
        }
    }
    ll ans = 0;
    LOOP_(1, total + 1, j){
        if (values[j] == 2){
            ans++;
        }
    }
    cout << ans << "\n";
    LOOP_(1, total + 1, j){
        if (values[j] == 2){
            cout << j << " ";
        }
    }
    cout << "\n";
    return 0;
}