// in selection sort we peak a element and check compare it weather a smallest elementexist or no if yes than swap them

#include<iostream>
#include<vector>

using namespace std;

class Sorting{

    void selectionSort(vector<int> &nums){
        
        int n = nums.size();

        for(int i = 0; i<n; i++){
            int min_idx = i;

            for(int j =i+1; j<n; j++){
                if(nums[min_idx] > nums[j]){
                    min_idx = j;
                }
            }
            swap(nums[min_idx], nums[j]);

        }


    }
};