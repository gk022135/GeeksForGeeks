// modified binary search can be used in searching element in sorted rotated array




//Do dry for better understanding

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public: 
    int modifiedBS(vector<int> &arr, int target)
    {
        int low = 0;
        int high = arr.size();
        int mid ;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
                return mid;

            if (target < arr[mid])
            {
                if (target >= arr[low] && target < arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (target > arr[mid] && target <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};


int main(){
    vector<int>arr = {4,5,6,8,9,0,1,2,3};
    Solution obj;
    cout<<"target found at "<<obj.modifiedBS(arr,2)<<endl;

    return 0;
}