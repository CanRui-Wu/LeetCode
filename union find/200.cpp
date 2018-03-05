#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//DFS verison
// class Solution {
// public:
// 	void dfs(vector<vector<char> >& grid,int i,int j,bool **visit) {
// 		stack<pair<int,int> > mystack;
// 		mystack.push(make_pair(i,j));
// 		while(!mystack.empty()) {
// 			int row = mystack.top().first;
// 			int col = mystack.top().second;
// 			mystack.pop();
// 			if(row+1 < grid.size() && !visit[row+1][col] && grid[row+1][col] == '1') {
// 				visit[row+1][col] = true;
// 				mystack.push(make_pair(row+1,col));
// 			}
// 			if(col+1 < grid[row].size() && !visit[row][col+1] && grid[row][col+1] == '1') {
// 				visit[row][col+1] = true;
// 				mystack.push(make_pair(row,col+1));
// 			}
// 			if(row != 0 && !visit[row-1][col] && grid[row-1][col] == '1') {
// 				visit[row-1][col] = true;
// 				mystack.push(make_pair(row-1,col));
// 			}
// 			if(col != 0 && !visit[row][col-1] && grid[row][col-1] == '1') {
// 				visit[row][col-1] = true;
// 				mystack.push(make_pair(row,col-1));
// 			}
// 		} 
// 		return;
// 	}
//     int numIslands(vector<vector<char> >& grid) {
//     	bool **visit = new bool*[grid.size()];
//     	for(int i = 0;i < grid.size();i++) {
//     		visit[i] = new bool[grid[i].size()];
//     		for(int j = 0;j < grid[i].size();j++)
//     			visit[i][j] = false;
//     	}
//     	int count = 0;
//     	for(int i = 0;i < grid.size();i++) {
//     		for(int j = 0;j < grid[i].size();j++) {
//     			if(!visit[i][j] && grid[i][j] == '1') {
//     				dfs(grid,i,j,visit);
//     				count++;
//     			}
//     		}
//     	}
//     	return count;
//     }
// };

//Union Find Version
class Solution {
public:
	int find(int index,int *union_find_set) {
		if(union_find_set[index] == -1)
			return index;
		union_find_set[index] = find(union_find_set[index],union_find_set); 
		return union_find_set[index];
	}
	void union_set(int index1,int index2,int *union_find_set) {
		if(index1 != index2)
			union_find_set[index2] = index1; 
	}
    int numIslands(vector<vector<char> >& grid) {
    	if(grid.size() == 0 || grid[0].size() == 0)
    		return 0;
    	int total_length = grid.size()*grid[0].size();
    	int *union_find_set = new int[total_length];
    	for(int i = 0;i < total_length;i++) {
    		union_find_set[i] = -1;
    	}
    	for(int i = 0;i < grid.size();i++) {
    		for(int j = 0;j < grid[0].size();j++) {
    			if(i+1 < grid.size() && grid[i][j] == '1' && grid[i+1][j] == '1') {
    				int num1 = find(i*grid[0].size()+j,union_find_set);
    				int num2 = find((i+1)*grid[0].size()+j,union_find_set);
    				union_set(num1,num2,union_find_set);
    			}
    			if(j+1 < grid[0].size() && grid[i][j] == '1' && grid[i][j+1] == '1') {
    				int num1 = find(i*grid[0].size()+j,union_find_set);
    				int num2 = find(i*grid[0].size()+j+1,union_find_set);
    				union_set(num1,num2,union_find_set);
    			}
    		}
    	}
    	int count = 0;
    	for(int i = 0;i < grid.size();i++) {
    		for(int j = 0;j < grid[0].size();j++) {
    			if(grid[i][j] == '1' && union_find_set[i*grid[0].size()+j] == -1)
    				count++;
    		}
    	}
    	return count;
    }
};

int main() {
	Solution solution;
	vector<vector<char> > grid;
	vector<char> t1 = {'1'};
	grid.push_back(t1);
	t1 = {'1'};
    grid.push_back(t1);
    //t1 = {'1','1','1'};
	// grid.push_back(t1);
	// t1 = {'0','0','0','1','1'};
	//grid.push_back(t1);
	cout << solution.numIslands(grid) << endl;
}