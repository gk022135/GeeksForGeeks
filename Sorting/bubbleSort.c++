// bubble sort is sorting algo that compares two adjacent elements and swaps them until thy are in the intended order

#include<iostream>
#include<vector>


using namespace std;

class Solution{
    public:
    void bubbleSort(vector<int> &arr){
        int n = arr.size();

        for(int i =0;i<n;i++){
            for(int j =0;j<n-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }

    }
};

int main(){
    vector<int>arr = {1,234,23,4,14,5,13,23,623};
    Solution obj;
    obj.bubbleSort(arr);
    for(auto i : arr){
        cout<<i<<", ";
    }
    return 0;
}