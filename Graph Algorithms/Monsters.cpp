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

ll n, m;
vector<vector<char>> grid;
vector<vector<ll>> dist;
vector<vector<char>> par;
vector<vector<bool>> visited;

bool is_valid(pair<ll, ll> p){
    if((p.first>=0) && (p.first< n) && (p.second >=0) && (p.second < m)){
        return true;
    }
    return false;
}

void bfs(pair<ll, ll> start){
    queue<pair<ll ,ll>> q;
    par[start.first][start.second] = '0';
    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 0;
    q.push(start);
    while(!q.empty()){
        pair<ll, ll> temp = q.front();
        q.pop();
        pair<ll, ll> left = {temp.first, temp.second-1};
        pair<ll, ll> right = {temp.first, temp.second+1};
        pair<ll, ll> down = {temp.first+1, temp.second};
        pair<ll, ll> up = {temp.first-1, temp.second};
        if(is_valid(left)){
            if(grid[left.first][left.second] == '.' && !visited[left.first][left.second]){
                visited[left.first][left.second] = true;
                par[left.first][left.second] = 'L';
                dist[left.first][left.second] = 1 + dist[temp.first][temp.second];
                q.push(left);
            }
        }
        if(is_valid(right)){
            if(grid[right.first][right.second] == '.' && !visited[right.first][right.second]){
                visited[right.first][right.second] = true;
                par[right.first][right.second] = 'R';
                dist[right.first][right.second] = 1 + dist[temp.first][temp.second];
                q.push(right);
            }
        }
        if(is_valid(up)){
            if(grid[up.first][up.second] == '.' && !visited[up.first][up.second]){
                visited[up.first][up.second] = true;
                par[up.first][up.second] = 'U';
                dist[up.first][up.second] = 1 + dist[temp.first][temp.second];
                q.push(up);
            }
        }
        if(is_valid(down)){
            if(grid[down.first][down.second] == '.' && !visited[down.first][down.second]){
                visited[down.first][down.second] = true;
                par[down.first][down.second] = 'D';
                dist[down.first][down.second] = 1 + dist[temp.first][temp.second];
                q.push(down);
            }
        }
    }
}

ll N = 3e5+7;
ll mod = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    dist.resize(n, vector<ll>(m, -1));
    par.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    vector<pair<ll, ll>> monsters; 
    pair<ll, ll> start;
    LOOP(0, n){
        LOOP_(0, m, j){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                start = {i, j};
                grid[i][j] = '.';
            }
            if(grid[i][j] == 'M'){
                monsters.push_back({i, j});
                grid[i][j] = '.';
            }
        }
    }    
    pair<ll, ll> p = {0, 0};
    while(1){
        if (grid[p.first][p.second] == '.'){
            bfs(p);
            ll mindis = LLONG_MAX;
            LOOP(0, monsters.size()){
                if (dist[monsters[i].first][monsters[i].second] != -1)
                mindis = min(dist[monsters[i].first][monsters[i].second], mindis);
            }
            if ((mindis > dist[start.first][start.second]) && (dist[start.first][start.second] != -1)){
                cout << "YES\n";
                cout << dist[start.first][start.second] << "\n";
                vector<char> tempp;
                pair<ll, ll> temp = start;
                for(auto c = par[start.first][start.second]; c!= '0'; ){
                    if(c == 'L'){
                        temp = {temp.first, temp.second+1};
                        tempp.push_back('R');
                    }
                    else if(c == 'R'){
                        temp = {temp.first, temp.second-1};
                        tempp.push_back('L');
                    }
                    else if(c == 'D'){
                        temp = {temp.first-1, temp.second};
                        tempp.push_back('U');
                    }
                    else if(c == 'U'){
                        temp = {temp.first+1, temp.second};
                        tempp.push_back('D');
                    }           
                    c = par[temp.first][temp.second];
                }
                LOOP(0, tempp.size()){
                    cout << tempp[i];
                }
                cout << "\n";
                return 0;
            }
        } 
        if (p.first == 0){
            if(p.second == (m-1)){
                p.first += 1;
            }
            else{
                p.second += 1;
            }
        } 
        else if (p.second == (m-1)){
            if(p.first == (n-1)){
                p.second -= 1;
            }
            else{
                p.first+= 1;
            }
        }
        else if (p.first == (n-1)){
            if(p.second == 0){
                p.first -= 1;
            }
            else{
                p.second -= 1;
            }
        }
        else if (p.second == 0){
            if(p.first == 0){
                p.second += 1;
            }
            else{
                p.first -= 1;
            }
        }         
        LOOP(0,n){
            LOOP_(0, m, j){
                dist[i][j] = -1;
                visited[i][j] = false;
            }
        }
        if ((((p.first)==0) && (p.second == 0)) || !is_valid(p)){
            break;
        } 
    }
    cout << "NO\n";
    return 0;
}