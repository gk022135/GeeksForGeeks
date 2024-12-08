// try to sort 0's  1's 2's

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // method 1 for sort this

    //    vector<int>sort012(vector<int>&arr){

    //     sort(arr.begin(),arr.end());
    //     return arr;
    //    }

    // method 2
    // vector<int> sort123(vector<int> &arr)
    // {
    //     int i =0;
    //     int prt = 0;
    //     int j = arr.size();

    //     while(i<j){
    //         if(arr[prt] == 0){
    //             swap(arr[prt++],arr[i++]);
    //         }
    //         else if(arr[prt] == 1){
    //            prt++;
    //         }
    //         else swap(arr[prt] ,arr[j--]);
    //     }
    //     return arr;
    // }
};