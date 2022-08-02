// Problem Link: https://cses.fi/problemset/task/1651

#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> seg;
void buildTree(ll ind, ll low, ll high, vector<ll>& v)
{
    if(low == high)
    {
        seg[ind] = v[low];
        return;
    }
    ll mid = low + (high - low) / 2;
    buildTree(2 * ind + 1, low, mid, v);
    buildTree(2 * ind + 2, mid + 1, high, v);
    seg[ind] = 0;
}

void update(ll ind, ll low, ll high, ll l, ll r, ll val)
{
    if(low >= l && high <= r)
    {
        seg[ind] += val;
        return;
    }
    if(high < l || low > r)
        return;
    
    ll mid = low + (high - low) / 2;
    update(2 * ind + 1, low, mid, l, r, val);
    update(2 * ind + 2, mid + 1, high, l, r, val);
}

void propogate(ll ind)
{
    seg[2 * ind + 1] += seg[ind];
    seg[2 * ind + 2] += seg[ind];
    seg[ind] = 0;
}

ll query(ll ind, ll low, ll high, ll pos)
{
    if(low == high)
    {
        return seg[ind];
    }
    propogate(ind);
    
    ll mid = low + (high - low) / 2;
    if(pos >= low && pos <= mid)
        return query(2 * ind + 1, low, mid, pos);
        
    return query(2 * ind + 2, mid + 1, high, pos);
}

int main()
{
    ll n, q; cin>>n>>q;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    seg.resize(4 * n + 1, 0);
    buildTree(0, 0, n-1, v);
    for(ll i = 0; i < q; i++)
    {
        ll type; cin>>type;
        if(type == 1)
        {
            ll l, r, val; cin>>l>>r>>val;
            update(0, 0, n-1, l-1, r-1, val);
        }
        else
        {
            ll ind; cin>>ind;
            cout<<query(0, 0, n-1, ind-1)<<endl;
        }
    }
    
    return 0;
}