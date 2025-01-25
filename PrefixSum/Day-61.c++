//find euilibrium  point  in given array

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    //approach -02

    //approch-03
    int equiPoint(vector<int>&arr){

        int totalSum = 0;
        int PrefixSum = 0;

        for(int i: arr){
            totalSum += arr[i];
        }

        for(int i =0; i<arr.size(); i++){
            int suffixSum = totalSum-PrefixSum-arr[i];

            if(suffixSum == PrefixSum){
                return i;
            }
            PrefixSum += arr[i];
        }
        return -1;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {};

    cout<<obj.equiPoint(arr)<<endl;
    return 0;
}