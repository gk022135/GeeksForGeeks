#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    int  BinarySearch(vector<int> &arr, int target,int l, int h){
        int low = l;
        int high = h;

        int  mid = low + (high - low)/2;

        if(arr[mid] == target) return mid;

        if(target > arr[mid]){
            return BinarySearch(arr, target, mid + 1 ,high);
        }
        if(target < arr[mid]){
            return BinarySearch(arr,target, low, mid-1);
        }
        return mid;

    }
};

int main(){
    vector<int> arr = {-1,2,3,4,5,6,7,8,9,23};

    Solution obj;
    cout<<"target find at "<<obj.BinarySearch(arr,7,0,10)<<endl;

    
    return 0;
}