#include <bits/stdc++.h>

unsigned int number_of_parity_bits(unsigned int n) {
	unsigned int p = 1;
	while(!(pow(2, p) >= (n + p + 1))) p++;
	return p;
}
bool powerOfTwo(int n) {
    return n && (!(n & (n-1)));
}

int main() {
	#ifndef ONLINE_JUDGE
	    freopen("Input.txt", "r", stdin);
	    freopen("Output.txt", "w", stdout);
	#endif
	std::string s, received_code = "110001101";
	std::cin >> s;
	std::cout << "Message: " << s << std::endl;
	unsigned int n = s.size(), p = number_of_parity_bits(n), sum = 0;
	unsigned long int N = std::bitset<32>(s).to_ulong(), mask = 1;	
	std::bitset<9> hamming_code;	
	for(int i=1; i<=p; i++) {
		sum = 0;
		for(int j=1, k=0; j<=(n+p); j++) {
			if(!powerOfTwo(j)) {
				sum = ((j & (mask << (i-1))) && (N & (mask << k))) ? (sum + 1) : sum;
				if(i==1 && (N & (mask << k))) hamming_code |= (mask << (j-1));
				k++;
			}
		}
		if(sum & mask) hamming_code |= (mask << ((int)pow(2, i-1) - 1));
	}
	std::cout << "Hamming Code: " << hamming_code << std::endl;

	// Error Detection Process
	int error_location = 0;
	N = std::bitset<16>(received_code).to_ulong();
	for(int i=1; i<=p; i++) {
		sum = 0;
		if(N & (mask << ((int)pow(2,i-1) - 1))) sum += 1;
		for(int j=1; j<=(n+p); j++) {
			if(!powerOfTwo(j)) {
				sum = ((j & (mask << (i-1))) && (N & (mask << (j-1)))) ? (sum + 1) : sum;
			}
		}
		if(sum & mask) error_location += ((sum & mask) * pow(2, i-1));
	}			
	std::cout << "Received Code: " << received_code << std::endl;
	if(error_location) {
		std::cout << "Error Location: " << error_location << std::endl;
		std::cout << "Corrected Code: " << std::bitset<9>(N |= (mask << (error_location - 1))) << std::endl;
	}
	else std::cout << "Code is Error Free" << std::endl;
	return 0;
}