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
ll inv2_mod2 = 500000004;

vector<ll> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll target = (n*(n+1))/2;
    if (target%2 == 1) {
        cout << "0\n";
    }
    else{
        target /= 2;
        dp.resize(target+1);
        vector<ll> mark(target+1, 0);
        dp[0] = 1;
        LOOP(1, n+1){
            for(int j = target + 1; j>=0; j--){
                if ((j+i) <= target){
                    dp[j+i] = (dp[j+i] + dp[j])%mod2;
                }
            }
        }
        cout << (dp[target]*inv2_mod2)%mod2 << "\n";
    }
    return 0;
}