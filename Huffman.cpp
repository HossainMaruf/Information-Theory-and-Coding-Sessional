#include <bits/stdc++.h>

typedef std::pair<double, std::string> pds;
typedef std::pair<std::string, std::string> pss;

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("Input.txt", "r", stdin);
    //     freopen("Output.txt", "w", stdout);
    // #endif
    int n, symbol_len;
    double probability;
    std::string symbol;
    std::priority_queue<pds> pq;
    std::cout << "Enter the number of symbols: ";
    std::cin >> n;
    std::cout << "Enter symbol-probability pair" << std::endl;
    for(int i=0; i<n; i++) {
        std::cin >> symbol >> probability;
        pq.push({-probability, symbol});
        if(!i) symbol_len = symbol.length();
    }

    std::stack<pss> st;
    while(!pq.empty()) {
        auto left = pq.top();
        pq.pop();
        if(pq.empty()) break;
        auto right = pq.top();
        pq.pop();
        
        double total = left.first + right.first;
        std::string common = left.second + right.second; 
        pq.push({total, common});
        st.push({left.second, right.second});
    }
    std::map<std::string, std::string> code;
    while(!st.empty()) {
       auto common = st.top(); 
       st.pop();
       int len = common.first.length();
       for(int i=0; i<len; i+=symbol_len) {
        std::string sub = common.first.substr(i, symbol_len);
        code[sub] = code[sub] + "0";
       }
       len = common.second.length();
       for(int i=0; i<len; i+=symbol_len) {
        std::string sub = common.second.substr(i, symbol_len);
        code[sub] = code[sub] + "1";
       }
    }

   for(auto item : code) {
    std::cout << item.first << " " << item.second << std::endl;
   }

    return 0;
}
