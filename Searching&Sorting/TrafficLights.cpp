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
    ll x, n;
    cin >> x >> n;
    multiset<ll> ms;
    ms.insert(x);
    set<ll> s;
    s.insert(0);
    s.insert(x);
    LOOP(0, n){
        ll pt;
        cin >> pt;
        auto it = s.upper_bound(pt);
        auto itt = it;
        itt--;
        ll siz = *it - *itt;
        ms.erase(ms.find(siz));
        s.insert(pt);
        ms.insert(*it - pt);
        ms.insert(pt - *itt);
        auto ans = ms.end();
        ans--;
        cout << *ans << " ";
    }
    cout << "\n";
  }    
  return 0;
}