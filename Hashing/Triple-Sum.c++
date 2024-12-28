// given arr make triplets whise sum is equal to a given target

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    public:
      vector<vector<int>> TripleSum(vector<int>& arr, int target){

        vector<vector<int>>res;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for(int i =0; i<n-2; i++){
            if(i>0 && arr[i] == arr[i-1]) continue;

            int left = i +1, right = n-1;
            while(left < right){
                int sum = arr[i] + arr[left] + arr[right];

                if(sum == 0){
                    res.push_back({arr[i], arr[left], arr[right]});
                    left++;
                    right--;

                    while(left<right && arr[left] == arr[left-1]) left++;

                    while(left<right && arr[right] == arr[right+1]) right--;
                }
                else if(sum < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return res;

      }
};

int main(){
    vector<int> arr = {1,23,-23,0,1,-1,0,4,-4,0};
    vector<vector<int>>res;

    Solution obj;

    res = obj.TripleSum(arr, 0);
    

    for(int i = 0; i<res.size(); i++){
        for(int j=0; j<res[0].size(); j++){
            cout<<res[i][j]<<", ";
        }
    }
    return 0;
}