#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    //Approach -01 Brute force T.C = O(n3);
    int TripleSumCount(vector<int>&nums, int target){
        int n = nums.size();
        int cnt = 0;

        for(int i =0;i<n; i++){
            for(int j =i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == target) cnt++;
                }
            }
        }
        return cnt;
    }
    //approach 02 (not complete some more conditions required)
    int TripleSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            int secondTarget = target - nums[i];
            int l = i + 1;
            int r = n - 1;

            unordered_map<int, int> hash;
            while (l < r)
            {
                int sum = nums[l] + nums[r];

                if (sum == secondTarget)
                {
                    cnt++;
                    l++;
                    r--;
                }
                if (sum < secondTarget)
                {
                    l++;
                }
                else
                    r--;
            }
        }
        return cnt;
    }
    // Approach -03
    int tripSumCnt(vector<int> &nums, int target)
    {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int firstCompli = target - nums[i];
            unordered_map<int, int> hash;

            for (int l = i + 1; l < n; l++)
            {
                int secondCompli = firstCompli - nums[l];
                cnt += hash[secondCompli];
                hash[nums[l]]++;
            }
        }
        return cnt;
    }
};

int main(){
    // vector<int>nums = {-3, -1, -1, 0, 1, 2};
    vector<int>nums = {2, 0, 1, 1, 5};
    int target = 1;

    Solution obj;
    cout<<"number of triplets are : "<<obj.tripSumCnt(nums, target)<<endl;
    return 0;
}