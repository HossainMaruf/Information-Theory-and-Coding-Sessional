#include <bits/stdc++.h>

std::vector<int> get_polynomial(std::string binary) {
	std::vector<int> polynomial = {};
	int len = binary.size();
	for(int i=0, power=0; i<len; i++, power++) { 
		if(binary[i] - 48)	
			polynomial.push_back(power); 
	}
	return polynomial;
}

void print(std::vector<int>& record) {
	int len = record.size();
	for(int i=0; i<len; i++)
		std::cout << record[i] << " ";
	std::cout << "\n";
}

std::string gM(std::vector<int>& g, std::vector<int>& M) {
	int g_len = g.size(), M_len = M.size();
	std::vector<int> result;
	for(int i=0; i<1; i++) {
		for(int j=0; j<M_len; j++) {
			result.push_back(g[i] + M[j]);
		}
	}
	print(result);
	return "";
}


int main() {

	std::string top = "111", bottom = "101", message = "10011";
	std::vector<int> top_poly = get_polynomial(top);
	std::vector<int> bottom_poly = get_polynomial(bottom);
	std::vector<int> message_poly = get_polynomial(message);
	print(top_poly); print(bottom_poly); print(message_poly);
	gM(top_poly, message_poly);


	return 0;
}