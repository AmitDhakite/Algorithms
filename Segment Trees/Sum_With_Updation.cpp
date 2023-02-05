// Problem Link: https://leetcode.com/problems/range-sum-query-mutable/
// CSES: https://cses.fi/problemset/task/1648/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll, ll>
#define vb vector<bool>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vpl vector<pair<ll, ll>>
#define gpl greater<pair<ll, ll>>
#define in(v,n) for(ll i = 0; i < n; i++) cin>>v[i]
#define out(v) for(ll i = 0; i < v.size(); i++) {char c = ' '; cout<<v[i]<<c; if(i==n-1) cout<<endl;}
#define mid(l,r) l+(r-l)/2
#define fo(i,n) for(ll i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007 
#define INF 1000000000000000000
 
class SGTree {
    vl seg;
  public:    
    SGTree(vl& v)
    {
        ll n = v.size();
        seg.resize(4*n + 1);
        buildTree(0, 0, n-1, v);
    }
    void show()
    {
        for(auto &it: seg)
            cout<<it<<" ";
        cout<<endl;
    }
    void buildTree(ll ind, ll l, ll r, vl& v)
    {
        if(l == r)
        {
            seg[ind] = v[l];
            return;
        }
        ll mid = l + (r - l) / 2;
        buildTree(2 * ind + 1, l, mid, v);
        buildTree(2 * ind + 2, mid + 1, r, v);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    ll getSum(ll ind, ll l, ll r, ll low, ll high)
    {
        if(l >= low && r <= high)
            return seg[ind];

        if(r < low || l > high)
            return 0;

        ll mid = l + (r - l) / 2;
        ll left = getSum(2 * ind + 1, l , mid, low, high);
        ll right = getSum(2 * ind + 2, mid + 1 , r, low, high);
        return left + right;
    }
    void updateSum(ll ind, ll l, ll r, ll i, ll dif)
    {
        if(i < l || i > r)
            return;                

        if(l == r)
        {
            seg[ind] += dif;
            return;
        }


        ll mid = l + (r - l) / 2;
        updateSum(2 * ind + 1, l, mid, i, dif);
        updateSum(2 * ind + 2, mid + 1, r, i, dif);
        seg[ind] += dif;
    }
};

void solve()
{
    ll n, q; cin>>n>>q;
    vl v(n); in(v,n);
    SGTree obj(v);
    while(q--)
    {
        ll type; cin>>type;
        if(type == 1)
        {
            ll i, val;
            cin>>i>>val;
            ll dif = val - v[i-1];
            v[i-1] = val;
            obj.updateSum(0, 0, n-1, i-1, dif);
        }
        else
        {
            ll l, r; cin>>l>>r;
            cout<<obj.getSum(0, 0, n-1, l-1, r-1)<<endl;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t = 1; 
    while(t--)
        solve();
    return 0;
}
