#include<bits/stdc++.h>
using namespace std;

int partition_randomized(int l, int r, vector<int>& v)
{
    srand(time(NULL));
    int ran = rand() % (r - l) + l;
    swap(v[ran], v[r-1]);
    return partition(l, r, v);
}
int partition(int l, int r, vector<int>& v)
{
    int pivotIndex = l;
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
    swap(v[pivotIndex], v[j]);
    return j;
}
void quickSort(int l, int r, vector<int>& v)
{
    if(l >= r)
        return;
    
    int pivot = partition_randomized(l, r, v);
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