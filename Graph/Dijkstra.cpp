// Single source shortest path algo
// Will not work on graph with negative weight loop

#include<bits/stdc++.h>
using namespace std;
#define ll long long


vector<ll> dijkstra(ll src, ll n, vector<vector<ll>> a[])
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.emplace(0, src);
    vector<bool> vis(n+1, false);
    vector<ll> dist(n+1, 1e18);
    dist[src] = 0;
    while(q.size())
    {
        ll node = q.top().second;
        ll d = q.top().first;
        q.pop();
        if(d > dist[node] || vis[node])
            continue;
        
        vis[node] = true;
        for(auto &it: a[node])
        {
            if(vis[it[0]])
                continue;
            if(dist[it[0]] > dist[node] + it[1])
            {
                dist[it[0]] = dist[node] + it[1];
                q.emplace(dist[it[0]], it[0]);
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m; cin>>n>>m;
    vector<vector<ll>> adj[n+1];
    while(m--)
    {
        ll x, y, z;
        cin>>x>>y>>z;
        adj[x].push_back({y, z});
    }
    dijkstra(0, n, adj);
    return 0;
}