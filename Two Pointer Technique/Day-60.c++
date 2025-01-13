// Container With Most Water

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
     int maxWater(vector<int> &arr) {
        int n = arr.size();
        int area = 0;
        int l = 0;
        int r = n-1;

        while(l< r){
            int height = min(arr[l], arr[r]);
            int base = abs(l-r);

            area = max(area,height*base);

            if(arr[l] < arr[r]) l++;
            else r--;
        }
        return area;
     }
};

int main(){
    Solution obj;
    vector<int>arr = {1, 5, 4, 3};

    cout<<"maximum water can be filled : " <<obj.maxWater(arr)<<endl;

    return 0;
}
