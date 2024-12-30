/*
[Naive Approach] Generating all Possible Pairs - O(n^2) time and O(1) space
[Better Approach 1] Sorting and Binary Search - O(n*log(n)) time and O(1) space
[Better Approach 2] Sorting and Two-Pointer Technique - O(n*log(n)) time and O(1) space
[Expected Approach] Using Hash Set - O(n) time and O(n) space

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution{
    public:

    //brute force approach 
    bool NaiveApproach(vector<int> &array, int target){
        int n = array.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int sum = array[i] + array[j];
                if(sum == target){
                    cout<<array[i] + array[j] <<" = "<<target<<endl;
                    return true;
                }

            }
        }
      return false;

    }

    //method 02
    //Sorting and Binary Search - O(n*log(n))
    bool approach2(vector<int> &arr, int target){
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int i =0; i<n; i++){
            int compli = target - arr[i];
            if( binary_search(arr.begin(), arr.end(), compli)) return true;
        }
        return false;
    }
    //method 03
    // Sorting and Two-Pointer Technique

    bool approach3(vector<int> &arr, int target){
        sort(arr.begin(),arr.end());

        int i =0;
        int j = arr.size()-1;

        while(i<j){
            if(arr[i] + arr[j] > target){
                j--;
               
            }
            else if(arr[i] + arr[j] < target){
                i++;
               
            }
            else return true;
        }
        return false;
    }
    //method 04
    //Using Hash Set - O(n) time and O(n) space

    bool approach4(vector<int> &arr, int target){
        unordered_set<int>s;

        for(int i=0; i<arr.size(); i++){
            int compli = target - arr[i];

            if(s.find(compli) != s.end()) return true;

            s.insert(arr[i]);
        }
        return false;

    }

};

int main(){
    vector<int>arr = {0, -1, 2, -3, 1};
    int target = -2;
    Solution obj;

    cout<<"By Brute force Approach\n";
    cout<<obj.NaiveApproach(arr,target)<<endl;

    cout<<"By sorting and Binary search\n";
    cout<<obj.approach2(arr,target)<<endl;

    cout<<"By two pointer approach\n";
    cout<<obj.approach3(arr,target)<<endl;

    cout<<"By unorder set Approach\n";
    cout<<obj.approach4(arr,target)<<endl;
}