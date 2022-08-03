#include<bits/stdc++.h>
using namespace std;

int partition(int l, int r, vector<int>& v)
{
    int pivot = v[l];
    int i = l, j = r;
    while(i <= j)
    {
        do{
            i++;
        } while(i < r && v[i] <= pivot);
        
        do{
            j--;
        } while(j > 0 && v[j] > pivot);
        
        if(i < j)
            swap(v[i], v[j]);
    }
    swap(v[l], v[j]);
    return j;
}

void quickSort(int l, int r, vector<int>& v)
{
    if(l >= r)
        return;
    
    int pivot = partition(l, r, v);
    quickSort(l, pivot, v);
    quickSort(pivot + 1, r, v);
}

int main()
{
    int n; 
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    quickSort(0, n, v);
    for(auto &it: v)
        cout<<it<<" ";

    return 0;
}