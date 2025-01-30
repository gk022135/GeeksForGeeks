//you have given an  integer n and integer k you mhave to make combination of k numbers from
//n = 4,k =2, arr = [1,2,3,4];  combination of k number from n is [[1,2],[1,3],[1,4],[2,1],[2,3],[2,4],[3,1] ....]

/*
<-----------intution--------->
<---------------------------->
*/

#include<iostream>
#include<vector>

using namespace std;

class Combination{
    public:
    void generateCombinatin(vector<int> &arr,vector<vector<int>> &result, vector<bool> &visited, int k, int index, vector<int> combinationArr){

        if(index == k){
            result.push_back(combinationArr);
            return ;
        }

        for(int i =0; i<arr.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                combinationArr[index] = arr[i];
                generateCombinatin(arr, result, visited, k, index+1, combinationArr);
                // combinationArr ko bactrack nahi kiya kyu ki iska size k ke brabar hai toh full hone per overide ho jyega
                visited[i] = false;
            }
        }

    }
    vector<vector<int>> classMainFunction(int n, int k){
        vector<int> arr;
        vector<vector<int>>result;
        vector<int>combinationArr(k);
        vector<bool>visited(n, false);

        for(int i=0; i<n; i++){
            arr.push_back(i+1);
        }

        generateCombinatin(arr, result, visited, k, 0, combinationArr);

        return result;
    }
};

int main(){
    vector<vector<int>>res;
    int n,k;
    cout<<"enter number and selection of numbers";
    cin>>n>>k;

    Combination obj;
    res = obj.classMainFunction(n, k);

    cout<<"here is all possible combination\n";
    cout<<"[";
    for(auto i:res){
        cout<<"[";
        for(auto x : i){
            cout<<x<<",";
        }
        cout<<"]";
    }
    cout<<"]";

    return 0;
}