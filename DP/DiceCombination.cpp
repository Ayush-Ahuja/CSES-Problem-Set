#include <bits/stdc++.h>

using namespace std;

#define LOOP(p, q) for(int i = (p); i < (q); i++)
#define LOOP_(p,q,i) for(int i = (p); i < (q); i++)
#define ll long long
long long GCD(long long a,long long b){
  if(b==0LL) return a;
  else return GCD(b,a%b);
}
long long LCM(long long a,long long b){
  return (a*b)/GCD(a,b);
}
ll N = 3e5+7;
ll dp[1000007];
ll mod = 1e9 + 7;

ll solve(ll n){
    if(n<=0) return 0;
    if(n==1) return dp[n] = 1;
    if(dp[n] != 0) return dp[n];
    ll sum = 0;
    LOOP(1, 7){
        sum += (solve(n-i))%mod;
    }
    if(n>=2 && n<=6){
        sum++;
    } 
    dp[n] = sum%mod;
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    solve(n);
    cout << dp[n] << "\n";
}