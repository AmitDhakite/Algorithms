// Problem Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/segment-tree/max-in-a-interval-range-query-point-update-official/ojquestion

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
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

ll findMax(ll ind, ll low, ll high, ll l, ll r)
{
    if(low >= l && high <= r)
        return seg[ind];
        
    if(high < l || low > r)
        return LLONG_MIN;
        
    ll mid = low + (high - low) / 2;
    ll left = findMax(2 * ind + 1, low, mid, l, r);
    ll right = findMax(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}

void update(ll ind, ll low, ll high, ll index, ll newVal)
{
    if(low == high)
    {
        seg[ind] = newVal;
        return;
    }
    
    ll mid = low + (high - low) / 2;
    if(index >= low && index <= mid)
        update(2 * ind + 1, low, mid, index, newVal);
    else
        update(2 * ind + 2, mid + 1, high, index, newVal);
        
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int main()
{
    ll n; cin>>n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++)
        cin>>v[i];
        
    seg.resize(4 * n + 1);
    buildTree(0, 0, n-1, v);
        
    ll q; cin>>q;
    for(ll i = 0; i < q; i++)
    {
        ll type, l, r; cin>>type>>l>>r;
        if(!type)
        {
            update(0, 0, n-1, l, r);
            v[l] = r;
        }
        else
        {
            cout<<findMax(0, 0, n-1, l, r)<<endl;
        }
    }
    return 0;
}