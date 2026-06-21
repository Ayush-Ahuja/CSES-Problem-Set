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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll maxx = 0;
    ll summ = 0;
    LOOP(0, n){
        cin >> a[i];
        maxx = max(a[i], maxx);
        summ += a[i];
    }
    ll ans;
    if (summ - maxx < maxx) ans = 2*maxx;
    else ans = summ;
    cout << ans << "\n";
    return 0;
}