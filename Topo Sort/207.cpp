#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> *adj = new vector<int>[numCourses];
        int *in_degree = new int[numCourses];
        memset(in_degree,0,sizeof(int)*numCourses);
        for(const auto &p:prerequisites) {
        	adj[p.second].push_back(p.first);
        	in_degree[p.first]++;
        }
        queue<int> myqueue;
        int count = 0;
        for(int i = 0;i < numCourses;i++) {
        	if(in_degree[i] == 0)
        		myqueue.push(i);
        }
        while(!myqueue.empty()) {
        	int temp = myqueue.front();
        	count++;
        	myqueue.pop();
        	for(const auto &s:adj[temp]) {
        		in_degree[s]--;
        		if(in_degree[s] == 0)
        			myqueue.push(s);
        	}
        }
        return (count == numCourses);
    }
};

int main() {
	Solution solution;
	vector<pair<int,int> > a;
	a.push_back(make_pair(0,1));
	a.push_back(make_pair(1,0));
	//a.push_back(make_pair(2,0));
	cout << solution.canFinish(2,a) << endl;
}