#include <bits/stdc++.h>
using namespace std;

// Function to find the sum of weights of the Minimum Spanning Tree
// int spanningTree(int V, vector<vector<int>> adj[])
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     // priority_queue<pair<int,int>,vector
//     vector<int> vis(V, 0);
//     pq.push({0, 0}); // {weight, node}
//     int sum = 0;

//     while (!pq.empty())
//     {
//         auto it = pq.top();
//         pq.pop();
//         int node = it.second;
//         int wt = it.first;

//         if (vis[node] == 1)
//             continue;

//         vis[node] = 1;
//         sum += wt;

//         for (auto it : adj[node])
//         {
//             int adjNode = it[0];
//             int edW = it[1];
//             if (!vis[adjNode])
//             {
//                 pq.push({edW, adjNode});
//             }
//         }
//     }
//     return sum;
// }


int spanningTree(int V, vector<pair<int,int>>adj[]){

    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;

    pq.push({0,0});

    vector<int>vis(V,0);
    int ans=0;

    while(!pq.empty()){
        auto it =pq.top();
        pq.pop();

        int node=it.second;
        int wt=it.first;

        if(vis[node]==1) continue;
        vis[node]=1;
        ans+=wt;

        for(auto it :adj[node]){
            int adjnode=it[0];
            int edgw=it[1];

            if(!vis[adjnode]){
                pq.push({edgw,adjnode})
            }
        }
    }

    return ans;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj[V];

    cout << "Enter each edge in the format: u v weight" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int sum = spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << sum << endl;

    return 0;
}
