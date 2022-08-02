// Problem Link: https://leetcode.com/problems/range-sum-query-mutable/

#include<bits/stdc++.h>
using namespace std;
#define ll long long


class NumArray {
public:
    vector<ll> seg;
    vector<ll> v;
    ll n;
    
    void buildTree(ll ind, ll l, ll r)
    {        
        if(l == r)
        {
            seg[ind] = v[l];
            return;
        }
        
        ll mid = l + (r - l) / 2;
        buildTree(2 * ind + 1, l, mid);
        buildTree(2 * ind + 2, mid + 1, r);
        
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    
    NumArray(vector<ll>& a) 
    {
        for(auto &it: a)
            v.push_back(it);
        n = v.size();
        seg.resize(4 * n + 1);
        buildTree(0, 0, n-1);
    }
    
    void set(ll ind, ll index, ll l, ll r, ll dif)
    {
        if(l == r)
        {
            seg[ind] += dif;
            return;
        }
        
        ll mid = l + (r - l) / 2;
        if(index <= mid)
            set(2 * ind + 1, index, l, mid, dif);
        else
            set(2 * ind + 2, index, mid + 1, r, dif);
        seg[ind] += dif;
    }
    
    void update(ll index, ll val) 
    {
        ll dif = - v[index] + val;
        v[index] = val;
        set(0, index, 0, n-1, dif);
    }
    
    ll query(ll ind, ll low, ll high, ll l, ll r)
    {
        if(low >= l && high <= r)
            return seg[ind];
        
        if(high < l || low > r)
            return 0;
        
        ll mid = low + (high - low) / 2;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);
        
        return left + right;
    }
    
    ll sumRange(ll left, ll right) 
    {
        return query(0, 0, n-1, left, right);
    }
};
