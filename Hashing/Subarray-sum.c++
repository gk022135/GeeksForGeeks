//return number of subArray whose sum is equal to k

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
    public:
      int numSubarray(vector<int>&arr, int k){
        int cnt = 0;
        int sum = 0;

        unordered_map<int, int>trackPrefixSum;

        for(int i =0; i<arr.size(); i++){
            sum = sum + arr[i];
            if(sum == k){
                cnt++;
            }
           int prefixSum = sum -k;

           if(trackPrefixSum.find(prefixSum) != trackPrefixSum.end()){
            cnt = cnt + trackPrefixSum[prefixSum];
           }
           trackPrefixSum[sum]++;
        }
        return cnt;
      }
};

int main(){
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;

    Solution obj;
    cout<<"no of sub-array whose sum equal to "<<k<<" is "<<obj.numSubarray(arr,k)<<endl;

    return 0;
}


/*
concept ye hai ki 
kisi bhi number ko sum kareke target tak pahuch rahe hai yani ki sum- target ye sare element target ke prefix honge
simple in prefix ka sum target ke barabar hoga


*/