#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>& left, vector<int>& right)
{
    int n = left.size(), m = right.size(), i = 0, j = 0;
    vector<int> res;
    while(i < n || j < m)
    {
        if(i < n && j < m)
        {
            if(left[i] <= right[j])
                res.push_back(left[i++]);
            else
                res.push_back(right[j++]);
        }
        else if(i < n)
            res.push_back(left[i++]);
        else
            res.push_back(right[j++]);
    }
    
    return res;
}

vector<int> mergeSort(vector<int>& v)
{
    int n = v.size();
    if(n == 1)
        return v;
    
    vector<int> left, right;
    for(int i = 0; i < n/2; i++)
    {
        left.push_back(v[i]);
    }
    for(int i = n/2; i < n; i++)
    {
        right.push_back(v[i]);
    }
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    return merge(left, right);
}

int main()
{
    int n; 
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    v = mergeSort(v);
    for(auto &it: v)
        cout<<it<<" ";

    return 0;
}