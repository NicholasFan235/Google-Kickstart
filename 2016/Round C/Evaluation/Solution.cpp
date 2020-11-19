#include <bits/stdc++.h>

int N;
std::unordered_map<std::string, std::vector<std::string>> links;
std::unordered_set<std::string> assignments;
std::unordered_set<std::string> visited;
std::unordered_set<std::string> path;

void parseLine(std::string s){
    std::string a = s.substr(0, s.find("="));
    assignments.insert(a);
    s.erase(0, s.find("(")+1);
    s.pop_back();
    size_t pos = 0;
    std::string token;
    while ((pos=s.find(",")) != std::string::npos){
        token = s.substr(0, pos);
        s.erase(0, pos+1);
        links[token].push_back(a);
    }
    if (!s.empty()) links[s].push_back(a);
}

bool hasCycle(std::string s){
   if (path.count(s)) return true;
   if (visited.count(s)) return false;
   visited.insert(s);
   path.insert(s);
   for (const auto l : links[s]){
       if (hasCycle(l)) return true;
   }
   path.erase(s);
   return false;
}

void printLinks(){
    std::cout << std::endl;
    for (const auto l : links){
        printf("%s -> ", l.first.c_str());
        for (const auto p : l.second){
            printf("%s ", p.c_str());
        }
        printf("\n");
    }
    std::cout << std::endl;
}

void solve(){
    // check all variables have assignments
    for (const auto l : links){
        if (assignments.count(l.first)==0){
            std::cout << "BAD" << std::endl;
            return;
        }
    }

    visited.clear();
    // check for loops
    for (const auto l : links){
        path.clear();
        if (hasCycle(l.first)){
            std::cout << "BAD" << std::endl;
            return;
        }
    }
    std::cout << "GOOD" << std::endl;
}

int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> N;
        links.clear();
        std::string s;
        for (int n = 0; n < N; n++){
            std::cin >> s;
            parseLine(s);
        }
        std::cout << "Case #" << t << ": ";
        solve();
    }
}