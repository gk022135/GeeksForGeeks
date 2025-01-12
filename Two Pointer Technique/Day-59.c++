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
    int maxWatercnt(vector<int> &arr){
        int n = arr.size();

        //make left max on left side
        vector<int>LmaxArr(n,0);
        LmaxArr[0] = arr[0];
        for(int i =1; i<n; i++){
            int temp = max(LmaxArr[i-1],arr[i]);
            LmaxArr[i] = temp;
        }

        //make right max on right 
        vector<int>RmaxArr(n,0);
        RmaxArr[n-1] = arr[n-1];
        for(int i = n-2; i>=0; i--){
          int  temp = max(arr[i],RmaxArr[i+1]);
          RmaxArr[i] = temp;
        }

        int watercnt = 0;

        for(int i = 1;i<n-1;i++){
           int netHeight = min(RmaxArr[i],LmaxArr[i]);
           watercnt = watercnt + abs(netHeight-arr[i]);
        }
        return watercnt;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {3, 0, 1, 0, 4, 0 ,2};

    cout<<"max Water: "<<obj.maxWatertrap(arr)<<endl;
    cout<<"water count in O(n): "<<obj.maxWatercnt(arr);
    cout<<endl;
    return 0;
}