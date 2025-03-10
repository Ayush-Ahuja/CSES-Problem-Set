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
ll inf = 1e9 + 7;
ll N = 3e5+7;
// int dp[1000007];
const int mod = 1e9 + 7;

// int solve(int n, vector<int>& coins){
//     if(n<0) return 0;
//     if(n==0) return 1;
//     if(dp[n] != -1) return dp[n];
//     int sum = 0;
//     LOOP(0, coins.size()){
//         sum = (sum + solve(n - coins[i], coins)) % mod;
//     }
//     dp[n] = sum%mod;
//     return dp[n];
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    LOOP(0,n){
        cin >> a[i];
    }
    vector<int> dp(x + 1, 0);
    dp[0] = 1; // Base case: One way to make sum 0 (use no coins)

    // Iterative DP
    for(int j = 1; j <= x; j++){
      int sum = 0;
      LOOP(0,n){
        if((j - a[i])>=0){
          sum = (sum + dp[(j - a[i])])% mod; 
        }
        dp[j] = sum;        
      }
    }
    cout << dp[x] << "\n";
}