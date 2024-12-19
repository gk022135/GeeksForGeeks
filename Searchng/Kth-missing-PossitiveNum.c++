/*
Given a sorted array of distinct positive integers arr[], we need to find the kth positive number that is missing from arr[].  
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    
    int kthMissing(vector<int> &arr, int k) {
        int cnt = 0;
        vector<int> res;
        int n = arr.size();
        int j = 0;
        for(int i = 0;i<arr[n-1]; i++){
            if(j<n){
                if(arr[j] != i+1){
                    res.push_back(i+1);
                    cnt++;
                }
                else{
                    j++;
                }
            }
        }

        if(cnt != k){
            for(int i = arr[n-1] + 1; i<=arr[n-1] + k;i++){
                res.push_back(i);
            }
        }
        // cout<<res[0]<<" "<<res[2];
        return res[k-1];
    }
};

int main(){
    vector<int> arr = {2,3,4,7,11};
    int k = 5;

    Solution obj;
    cout<<k<<"th missing element is "<<obj.kthMissing(arr,k)<<endl;

    return 0;
}