#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int scheduleCourse(vector<vector<int> >& courses) {
        vector<pair<int,int> > my_courses;
        for(int i = 0;i < courses.size();i++)
        	my_courses.push_back(make_pair(courses[i][0],courses[i][1]));
        sort(my_courses.begin(),my_courses.end());
        int result = 0;
        for(int i = 0;i < my_courses.size();i++) {
        	if(my_courses[i].first <= my_courses[i].second) {
        		result++;
        		for(int j = i+1;j < my_courses.size();j++)
        			my_courses[j].second -= my_courses[i].first;
        	}
        }
        return result;
    }
};

int main() {
	Solution solution;
	vector<vector<int> > courses;
	vector<int> temp = {100,200};
	vector<int> temp2 = {200,1300};
	vector<int> temp3 = {1000, 1250};
	vector<int> temp4 = {2000, 3200};
	courses.push_back(temp);
	courses.push_back(temp2);
	courses.push_back(temp3);
	courses.push_back(temp4);
	cout << solution.scheduleCourse(courses) << endl;
}