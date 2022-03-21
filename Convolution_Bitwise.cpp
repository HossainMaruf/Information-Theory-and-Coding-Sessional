#include <bits/stdc++.h>

typedef unsigned long int ul;

std::string multiply(std::string message, std::string g) {
	int g_len = g.size(), message_len = message.size();
	ul g_value = std::bitset<16>(g).to_ulong(), message_value = std::bitset<16>(message).to_ulong();
	std::vector<ul> result;
	for(int i=0; i<g_len; i++) { if(g_value & (1 << i)) result.push_back(message_value << i); }
	int sum, res_len = result.size();
	std::string code = "";
	for(int i=0; i<(message_len+g_len-1); i++) {
		sum = 0;
		for(int j=0; j<res_len; j++) { if(result[j] & (1 << i)) sum++; }	
		if(sum & 1) code = "1" + code;
		else code = "0" + code;
	}
	return code;
}

std::string convolution(std::string c1, std::string c2) {
	std::string code = "";
	int i = 0;	
	while(c1[i] && c2[i]) {
		code += c1[i];
		code += c2[i];
		i++;
	}
	return code;
}

int main() {
	std::string g1_str = "111", g2_str = "101", message = "10011";
	std::string c1 = multiply(message, g1_str), c2 = multiply(message, g2_str);
	std::cout << c1 << std::endl;
	std::cout << c2 << std::endl;
	std::cout << convolution(c1, c2) << std::endl;


	return 0;
}