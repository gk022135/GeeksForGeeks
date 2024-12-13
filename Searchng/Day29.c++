// Problem Statement :- sorted and rotated Minimum
// a sorted array is roted at some unknown poin the task is to find the minimum element in it

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//method 01
class solution{
    public:
        int findMin(vector<int>& arr) {
            return *min_element(arr.begin(),arr.end());
        }

};

int  main(){
    vector<int>arr = {4,5,6,1,2,3};

    solution obj;
    cout<<" "<<obj.findMin(arr)<<endl;
    return 0;
}