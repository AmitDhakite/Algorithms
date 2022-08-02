// Problem Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/segment-tree/max-in-a-interval-range-query-point-update-official/ojquestion

#include<bits/stdc++.h>
using namespace std;

vector<int> seg;

void buildTree(int ind, int low, int high, vector<int>& v)
{
    if(low == high)
    {
        seg[ind] = v[low];
        return;
    }
    int mid = low + (high - low) / 2;
    buildTree(2 * ind + 1, low, mid, v);
    buildTree(2 * ind + 2, mid + 1, high, v);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int findMax(int ind, int low, int high, int l, int r)
{
    if(low >= l && high <= r)
        return seg[ind];
        
    if(high < l || low > r)
        return INT_MIN;
        
    int mid = low + (high - low) / 2;
    int left = findMax(2 * ind + 1, low, mid, l, r);
    int right = findMax(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}

void update(int ind, int low, int high, int index, int newVal)
{
    if(low == high)
    {
        seg[ind] = newVal;
        return;
    }
    
    int mid = low + (high - low) / 2;
    if(index >= low && index <= mid)
        update(2 * ind + 1, low, mid, index, newVal);
    else
        update(2 * ind + 2, mid + 1, high, index, newVal);
        
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
        
    seg.resize(4 * n + 1);
    buildTree(0, 0, n-1, v);
        
    int q; cin>>q;
    for(int i = 0; i < q; i++)
    {
        int type, l, r; cin>>type>>l>>r;
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