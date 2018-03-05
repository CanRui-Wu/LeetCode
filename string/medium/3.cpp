#include <iostream>
#include <cstring>
using namespace std;

int test(string s) {
	int index[256];
	int current_result = 0;
	int max_result = 0;
	memset(index,-1,sizeof(index));
	for(int i = 0;i < s.size();i++) {
		unsigned char temp = s[i];
		if(index[temp] < i - current_result) {
			current_result++;
		} else {
			current_result = i - index[temp];
		}
		index[temp] = i;
		if(current_result > max_result)
			max_result = current_result;
	}
 	return max_result;
}

int main() {
	string a = "abcabcbb",b = "bbbbb",c = "pwwkew",d="c";
	cout << test(a) << " " << test(b) << " " << test(c) << " " << test(d) << endl;
}