#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
	if(numRows == 1)
		return s;
	string result;
	int index;
	int odd;
	for(int i = 0;i < numRows;i++) {
		odd = 0;
		index = i;
		while(index < s.size()) {
			result += s[index];
			if(i == 0 || i == numRows-1) {
				index += 2*(numRows-1);
			} else {
				if(odd == 0)
					index += 2*(numRows-i-1);
				else
					index += 2*i;
			}
			odd = 1 - odd;
		}
	}
	return result;
}

int main() {
	cout << convert("ABC", 8) << endl;
}