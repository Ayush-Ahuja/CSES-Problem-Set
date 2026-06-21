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
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> summ(n+1, vector<ll>(n+1));
    LOOP(1, n+1){
        LOOP_(1, n+1, j){
            char c;
            cin >> c;
            if (c == '*') summ[i][j]++;
            summ[i][j] += summ[i-1][j] + summ[i][j-1] - summ[i-1][j-1];
        }
    }
    while(q--){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << summ[x2][y2] - summ[x2][y1-1] - summ[x1-1][y2] + summ[x1-1][y1-1] << "\n";
    }
    return 0;
}