#include <bits/stdc++.h>

bool exist(std::map<std::string, int>& table, std::string key) {
	return table.find(key)  != table.end();
}

unsigned int representation_bits(int number) {
	return ceil(log2(number));
}

std::string toBinary(int n, int bits) {
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    for(int i=r.size(); i<bits; i++) r = "0" + r;
    return r;
}

int main() {
	std::string message = "000101110010100101";
	int len = message.size(), slow = 0, position = 3;
	std::map<std::string, int> table;	
	std::vector<int> repeat_position = {0,1,2};
	table.insert({"0", 1});
	table.insert({"1", 2});

	for(int i=0,k=1; i<len; i++) {
		std::string sub_string = message.substr(slow, k);
		if(!exist(table, sub_string)) {
			table.insert({sub_string, position++});
			repeat_position.push_back(table.find(message.substr(slow, k-1))->second);
			slow = i+1; k = 1;
		} else k++;
	}

	std::map<int, std::string> sorted_table;
	for(auto &itr : table) { sorted_table.insert({itr.second, itr.first}); }
	
	int bits = representation_bits(position);

	for(auto itr = sorted_table.begin(); itr != sorted_table.end(); itr++) {
		int idx = itr->first, len = itr->second.size();
		if(idx < 3) std::cout << itr->first << " " << itr->second << std::endl;
		else std::cout << itr->first << " " << itr->second << " " << toBinary(repeat_position[idx], bits-1) + (itr->second)[len-1] << std::endl;
	}

	return 0;
}