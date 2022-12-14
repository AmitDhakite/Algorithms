#include<bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int>& v) 
{
    int n = v.size();
    for(int i = 1; i < n; i++)
    {
        int pivot = v[i], j = i-1;
        while(j >= 0 && v[j] > pivot)
        {
            v[j+1] = v[j];
            j--;
        }
        
        v[j+1] = pivot;
    }
    return v;
}

int main()
{
    int n; 
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    insertionSort(v);
    for(auto &it: v)
        cout<<it<<" ";

    return 0;
}