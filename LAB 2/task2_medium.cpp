// MEDIUM
//Search an element in row-wise and column-wise sorted matrix 

#include <iostream>
#include <vector>

using namespace std;

bool matSearch(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
  
    // loop to find x
	for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
        	if(mat[i][j] == x)
                return true;
        }
    }
  
    // If no x = return false
    return false;
}

int main() {
    vector<vector<int>> mat = {{5, 89, 62},
                               {11, 52, 50},
                               {48, 67, 93}};
    int x = 52;
    if(matSearch(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}