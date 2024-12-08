// bubble sort is sorting algo that compares two adjacent elements and swaps them until thy are in the intended order

#include<iostream>
#include<vector>


using namespace std;

class Solution{
    public:
    bool isSorted(vector<int>&arr){
        
    }
    void bubbleSort(vector<int> &arr){
        int n = arr.size();

        for(int i =0;i<n;i++){
            for(int j =0;j<n-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    if(isSorted(arr)) break;
                }
            }
        }

    }
};
