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
const long long MOD = 1e9 + 7;

long long modpow(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  while (b > 0) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

long long modinv(long long q) {
  return modpow(q, MOD - 2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  // cin >> t;
  t = 1;
  while(t--){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> apl(n);
    vector<ll> apt(m);
    LOOP(0, n){
        cin >> apl[i];
    }
    LOOP(0, m){
        cin >> apt[i];
    }
    sort(all(apl));
    sort(all(apt));
    ll ans = 0;
    auto it = apt.begin();
    LOOP(0, n){
        it = lower_bound(it, apt.end(), apl[i] - k);
        if (it != apt.end()){
            ll siz = *it;
            if (siz <= apl[i] + k){
                ans++;
                it++;
            }
        }
        else break;
    }
    cout << ans << "\n";
  }    
  return 0;
}