#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[], int n)
{
    for(int i=0;i<n;i++){
        int j=i;
        int swap=0;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
            swap=1;
        }
        
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}