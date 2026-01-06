#include <bits/stdc++.h>
#include <array>

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
const ll LOG_MAX = ceil(log2(1e9));
vector<ll> a;
ll n;
vector<array<ll, 31>> table;

void fill_table(){
  LOOP(1, n+1){
    table[i][0] = a[i];
  }
  LOOP(1, table[0].size()){
    LOOP_(1, n+1, j){
      table[j][i] = table[table[j][i-1]][i-1];
    }
  }
}

ll answer_query(ll u, ll k){
  LOOP(0, 31){
    if (1&k){
      u = table[u][i];
    }
    k >>= 1;
    if (k == 0){
      break;
    }
  }
  return u;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll q;
  cin >> n >> q;
  a.resize(n+1);
  LOOP(1, n+1){
    cin >> a[i];
  }
  table.resize(n+1);
  for (int i = 0; i <= n; ++i) {
    table[i].fill(0);
  }
  fill_table();
  while(q--){
    ll x, k;
    cin >> x >> k;
    cout << answer_query(x, k) << "\n";
  }
  return 0;
}