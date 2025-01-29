// as we can find the number of permutation of string in same way we can find the number of permutation of given arr of number
//  lets implement it 

// < ----------------------------------------------------->

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Permute_of_Nums{
    public:
      void Get_All_Permute(int index, vector<bool> &visited, vector<int> &newNums, vector<int> &OriginalNums, vector<vector<int>> &res){
        if(index == OriginalNums.size()){
            res.push_back(newNums);
            return ;
        }

        for(int i =0; i<OriginalNums.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                newNums.push_back(OriginalNums[i]);

                // recursion

                Get_All_Permute(index+1, visited, newNums, OriginalNums, res);

                //back to original number arr i.e backtracking

                visited[i] = false;
                newNums.pop_back(); 
            }
        }

      }
      vector<vector<int>> All_Permute(vector<int> &OriginalNums){

        vector<vector<int>>res;
        vector<bool>visited(OriginalNums.size(), false);
        vector<int>newNums;

        Get_All_Permute(0, visited, newNums, OriginalNums, res);

        return res;
      }
};

int main(){
    vector<int>nums = {1,2,3,4,5};
    vector<vector<int>>result;

    Permute_of_Nums obj;

    result = obj.All_Permute(nums);

    cout<<"here is all permution of given nums array \n";
    for(auto i : result){
        for(auto x : i){
            cout<<x;
        }
        cout<<", ";
    }

    return 0;
}