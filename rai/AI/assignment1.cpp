//jai bajrang bali
#include <bits/stdc++.h>
using namespace std;

#define Sachin_3059 ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long
const int N = 1e5;

vector<int>adj[N];
vector<bool>vis(N);

void dfs(int node){
    cout << node << " ";
    vis[node] = 1;

    for(auto nbr: adj[node]){
        if(!vis[nbr]){
            dfs(nbr);
        }
    }
}


void bfs(){
    queue<int>q;
    q.push(0);
    vis[0] = 1;

    while(!q.empty()){
        int node = q.front(); q.pop();
        cout << node << " ";
        for(auto nbr: adj[node]){
            if(!vis[nbr]){
                q.push(nbr);
                vis[nbr] = 1;
            }
        }
    }
    cout << endl;
}


void solve() {
    int n, m; cin >> n >> m;
    // assume vertex 0 - n;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "dfs traversal: " ;
    dfs(0);
    cout << endl;
    
    fill(vis.begin(), vis.end(), 0);
    cout << "bfs traversal: "; 
    bfs();
}

signed main() {
    Sachin_3059
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}