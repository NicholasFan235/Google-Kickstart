#include <bits/stdc++.h>

int N;
std::vector<std::string> people;

int numUnique(std::string s){
    std::set<char> uniques;
    s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
    for (const auto c : s){
        uniques.insert(c);
    }
    //std::cout << s << ": " << uniques.size() << std::endl;
    return uniques.size();
}

void solve(){
    std::string curr;
    int curMax = -1;
    for (const auto p : people){
        int newNum = numUnique(p);
        if (newNum >= curMax){
            if (newNum != curMax){
                curr = p;
                curMax = newNum;
            }
            else{
                if (p < curr) curr = p;
            }
        }
    }
    std::cout << curr << std::endl;
}

int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> N;
        std::string s;
        std::getline(std::cin, s);
        people.clear();
        for (int n = 0; n < N; n++){
            std::getline(std::cin, s);
            people.push_back(s);
        }
        std::cout << "Case #" << t << ": ";
        solve();
    }
}