#include<iostream>
#include<vector>
#include<set>

using namespace std;

class RecursionAndBacktrack {
    public:
    void All_Posible_Str_Permute(int index, vector<bool>& visited, string &NewStr, string &originalStr, vector<string> &result) {
        if (index == originalStr.size()) {
            result.push_back(NewStr);
            return;
        }

        for (int i = 0; i < originalStr.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                NewStr.push_back(originalStr[i]); // you can also use NewStr += originalStr[i];

                // recursion call for next char selection
                All_Posible_Str_Permute(index + 1, visited, NewStr, originalStr, result);

                // backtrack ---> set all as previous for making next combination
                visited[i] = false;
                NewStr.pop_back();
            }
        }
    }

    vector<string> allPermute(string originalStr) {
        vector<string> result;
        vector<bool> visited(originalStr.size(), false); // Initialize visited with the correct size
        string NewStr;

        All_Posible_Str_Permute(0, visited, NewStr, originalStr, result);

        return result;
    }
};

int main() {
    string OriginalStr = "ABC";
    vector<string> res;
    RecursionAndBacktrack obj;

    res = obj.allPermute(OriginalStr);
    cout << "Here is all possible permutation of given string " << OriginalStr << "\n";

    for (auto i : res) {
        cout << i << ", ";
    }
    return 0;
}
