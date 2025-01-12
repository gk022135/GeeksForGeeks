//Day 59 Trapping Rain water
/*
Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    //brute force timecomplexity = O(n2)
    int maxWatertrap(vector<int>&arr){
        int  n =arr.size();
        int waterCnt = 0;
        for(int i =1; i<n-1; i++){

            //left max
            int Lmax = arr[i];
            for(int j = 0; j<i; j++){
                Lmax = max(arr[j],Lmax);
            }
            //right max
            int Rmax = arr[i];
            for(int j = i+1; j<n;j++){
                Rmax = max(Rmax,arr[j]);
            }
            int netHeight = min(Rmax,Lmax);
            waterCnt = waterCnt + abs(netHeight - arr[i]);
        }
        return waterCnt;
    }

    //optimal approach O(n) timecomplexity
    
};

int main(){
    Solution obj;
    vector<int> arr = {3, 0, 1, 0, 4, 0 ,2};

    cout<<"max Water: "<<obj.maxWatertrap(arr);
    cout<<endl;
    return 0;
}