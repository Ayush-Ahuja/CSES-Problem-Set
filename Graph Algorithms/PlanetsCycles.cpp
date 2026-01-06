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

ll n;
vector<ll> tel;
vector<bool> visited;
vector<ll> ans;

void fill_value(ll u){
    ll a = tel[u];
    ll b = tel[tel[u]];
    ll f = 0;
    ll temp = 1;
    while(a != b){
        if (visited[a]){
            f = 1;
            break;
        }
        a = tel[a];
        b = tel[tel[b]];
        temp++;
    }
    if (f){
        ll val = ans[a] + temp;
        ll x = u;
        while(x != a){
            ans[x] = val;
            val--;
            visited[x] = true;
            x = tel[x];
        }
        return;
    }
    a = u;
    while(a != b){
        a = tel[a];
        b = tel[b];
    }
    ll len = 1;
    a = tel[a];
    while(a != b){
        a = tel[a];
        len++;
    }
    visited[b] = true;
    ans[b] = len;
    a = tel[a];
    while(a != b){
        visited[a] = true;
        ans[a] = len;
        a = tel[a];
    }
    ll x = u;
    ll dist = 0;
    while(x != b){
        x = tel[x];
        dist++;
    }
    dist += len;
    while(u != b){
        visited[u] = true;
        ans[u] = dist;
        u = tel[u];
        dist--;
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  tel.resize(n+1);
  ans.resize(n+1);
  visited.resize(n+1, false);
  LOOP(1, n+1){
    cin >> tel[i];
  }
  LOOP(1, n+1){
    if (!visited[i]){
        fill_value(i);
    }
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}