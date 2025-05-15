#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
    public:
        void nSumRecursive(vector<vector<int>>& result, vector<int>& temp,
                           vector<int>& nums, int start, int n, int target) {
            // Base case: 2Sum using two pointers
            if (n == 2) {
                int left = start, right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({temp.begin(), temp.end()});
                        result.back().push_back(nums[left]);
                        result.back().push_back(nums[right]);
    
                        // Skip duplicates
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
    
                        left++, right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
                return;
            }
    
            // Recursive case: reduce nSum to (n-1)Sum
            for (int i = start; i <= nums.size() - n; i++) {
                // Skip duplicates
                if (i > start && nums[i] == nums[i - 1]) continue;
    
                temp.push_back(nums[i]);
                nSumRecursive(result, temp, nums, i + 1, n - 1, target - nums[i]);
                temp.pop_back();
            }
        }
    
        vector<vector<int>> inGeneral(vector<int>& nums, int target, int n) {
            vector<vector<int>> result;
            vector<int> temp;
            sort(nums.begin(), nums.end());
    
            nSumRecursive(result, temp, nums, 0, n, target);
            return result;
        }
    };
    int main() {
        Solution sol;
        vector<int> nums = {-1,0,1,2,-1,-4};
        int target = 0;
        int n = 3;
    
        vector<vector<int>> result = sol.inGeneral(nums, target, n);
    
        for (auto& vec : result) {
            for (int num : vec) cout << num << " ";
            cout << endl;
        }
    
        return 0;
    }
    