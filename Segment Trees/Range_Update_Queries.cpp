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
 
class ST
{
    vl seg, lazy;
  public:
    ST(vl& v)
    {
        ll n = v.size();
        seg.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(0, 0, n-1, v);
    }
    void build(ll ind, ll l, ll r, vl& v)
    {
        if(l == r)
        {
            seg[ind] = v[l];
            return;
        }
        ll mid = l + (r - l) / 2;
        build(2 * ind + 1, l, mid, v);
        build(2 * ind + 2, mid + 1, r, v);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    void propogate(ll ind, ll l, ll r)
    {
        if(lazy[ind] != 0)
        {
            seg[ind] += (r - l + 1) * lazy[ind];

            if(l != r)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            
            lazy[ind] = 0;
        }
    }
    void update(ll ind, ll l, ll r, ll low, ll high, ll val)
    {
        // If there is something to propogate, then do it first
        propogate(ind, l, r);        

        // NO OVERLAP
        if(r < low || l > high)
            return;

        // FULL OVERLAP
        if(l >= low && r <= high)
        {
            seg[ind] += (r - l + 1) * val;

            if(l != r)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;            
        }

        // PARTIAL OVERLAP
        ll mid = l + (r - l) / 2;
        update(2 * ind + 1, l, mid, low, high, val);
        update(2 * ind + 2, mid + 1, r, low, high, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    ll get(ll ind, ll l, ll r, ll low, ll high)
    {
        // If there is something to propogate, then do it first 
        propogate(ind, l, r);

        // NO OVERLAP
        if(r < low || l > high)
            return 0;

        // FULL OVERLAP
        if(l >= low && r <= high)
        {
            return seg[ind];
        }

        // PARTIAL OVERLAP
        ll mid = l + (r - l) / 2;
        ll left = get(2 * ind + 1, l, mid, low, high);
        ll right = get(2 * ind + 2, mid + 1, r, low, high);
        return left + right;
    }
};

void solve()
{
    ll n, q; cin>>n>>q;
    vl v(n); in(v,n);
    ST obj(v);
    while(q--)
    {
        ll type; cin>>type;
        if(type == 1)
        {
            ll l, r, val; cin>>l>>r>>val;
            obj.update(0, 0, n-1, l-1, r-1, val);
        }
        else
        {
            ll i; cin>>i;
            cout<<obj.get(0, 0, n-1, i-1, i-1)<<endl;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t = 1; 
    // cin>>t;
    while(t--)
        solve();
    return 0;
}