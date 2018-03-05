#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> *adj = new vector<int>[numCourses];
        int *in_degree = new int[numCourses];
        memset(in_degree,0,sizeof(int)*numCourses);
        for(const auto &p:prerequisites) {
            adj[p.second].push_back(p.first);
            in_degree[p.first]++;
        }
        queue<int> myqueue;
        vector<int> result;
        for(int i = 0;i < numCourses;i++) {
            if(in_degree[i] == 0)
                myqueue.push(i);
        }
        while(!myqueue.empty()) {
            int temp = myqueue.front();
            result.push_back(temp);
            myqueue.pop();
            for(const auto &s:adj[temp]) {
                in_degree[s]--;
                if(in_degree[s] == 0)
                    myqueue.push(s);
            }
        }
        if(result.size() < numCourses)
            result.clear();
        return result;
    }
};

int main() {
	Solution solution;
	vector<pair<int,int> > a;
	a.push_back(make_pair(1,0));
	a.push_back(make_pair(3,1));
	a.push_back(make_pair(2,0));
    a.push_back(make_pair(3,2));
    vector<int> b;
	b = solution.findOrder(4,a);
    for(int i = 0;i < b.size();i++)
        cout << b[i] << " ";
    cout << endl;
}