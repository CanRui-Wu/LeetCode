#include <iostream>
#include <vector>
#include <bitset>
using namespace std;


class Solution {
public:
    bool validUtf8(vector<int>& data) {
    	int current,count;
        for(int i = 0;i < data.size();i++) {
        	current = data[i];
        	count = 1;
        	while((current & 0x80) != 0) {
        		current = current << 1;
        		count++;
        	}
        	if(count == 1) {
        		continue;
        	}
        	count -= 1;
        	if(count > 4 || count == 1)
        		return false;
        	cout << count << endl;
        	while(count != 1) {
        		if(++i >= data.size())
        			return false;
        		current = data[i];
        		if((current & 0xC0) != 128)
        			return false;
        		count--;
        	}

        }
        return true;
    }
};

int main() {
	Solution solution;
	vector<int> test{145};
	bitset<8> bs1(145);
	cout << bs1 << endl;
	cout << solution.validUtf8(test) << endl;
}