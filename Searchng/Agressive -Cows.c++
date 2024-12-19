// Use of Binary Search
//use have given Array of stalls and number of cows oyur task is to find minmum of max distance between cows.....


//Brute Force Approach

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    public:
          bool CanPlace(vector<int> &stalls, int i, int k){
            

          }
          int minOfMaxDis(vector<int> &stalls, int k){
            sort(stalls.begin(),stalls.end());
            int n = stalls.size();

            int low  = 0;
            int high = stalls[n-1] - stalls[0];

            for(int i = 0;i<=high; i++){
                if(CanPlace(stalls, i, k )){

                }


            }

          }

};

int main (){
    vector<int>stalls;
    int NumberOfCows = 4;



    return 0;
}