#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;
#define debug

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool> >& grid) {
        // Write your code here
        int x = grid.size();
        int y = grid[0].size();
#ifdef debug        
        // TODO: vector<bool> 特化的问题！ clang++编译不过
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                printf("%d ", grid[x][y]);
            }
            printf("\n");
        }
#endif
    }
};

int main() {
    int arr1[] = {1, 1, 0, 1};
    std::vector<bool> v1(arr1, arr1 + 4);
    int arr2[] = {1, 0, 0, 0};
    std::vector<bool> v2(arr2, arr2 + 4);
    int arr3[] = {0, 1, 0, 1};
    std::vector<bool> v3(arr3, arr3 + 4);
    int arr4[] = {1, 1, 0, 1};
    std::vector<bool> v4(arr4, arr4 + 4);
    
    vector<vector<bool> > grid;
    grid.push_back(v1);
    grid.push_back(v2);
    grid.push_back(v3);
    grid.push_back(v4);
    
    Solution s;
    s.numIslands(grid);
    return 0;
}
