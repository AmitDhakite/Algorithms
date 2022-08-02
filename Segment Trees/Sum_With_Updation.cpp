class NumArray {
public:
    vector<int> seg;
    vector<int> v;
    int n;
    
    void buildTree(int ind, int l, int r)
    {        
        if(l == r)
        {
            seg[ind] = v[l];
            return;
        }
        
        int mid = l + (r - l) / 2;
        buildTree(2 * ind + 1, l, mid);
        buildTree(2 * ind + 2, mid + 1, r);
        
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    
    NumArray(vector<int>& a) 
    {
        for(auto &it: a)
            v.push_back(it);
        n = v.size();
        seg.resize(4 * n + 1);
        buildTree(0, 0, n-1);
    }
    
    void set(int ind, int index, int l, int r, int dif)
    {
        if(l == r)
        {
            seg[ind] += dif;
            return;
        }
        
        int mid = l + (r - l) / 2;
        if(index <= mid)
            set(2 * ind + 1, index, l, mid, dif);
        else
            set(2 * ind + 2, index, mid + 1, r, dif);
        seg[ind] += dif;
    }
    
    void update(int index, int val) 
    {
        int dif = - v[index] + val;
        v[index] = val;
        set(0, index, 0, n-1, dif);
    }
    
    int query(int ind, int low, int high, int l, int r)
    {
        if(low >= l && high <= r)
            return seg[ind];
        
        if(high < l || low > r)
            return 0;
        
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        
        return left + right;
    }
    
    int sumRange(int left, int right) 
    {
        return query(0, 0, n-1, left, right);
    }
};
