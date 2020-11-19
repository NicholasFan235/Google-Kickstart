#include <bits/stdc++.h>

#define mod 1000000000

void solve(std::string p){
    std::stack<long long int> m;
    long long int cm = 1;
    m.push(cm);

    long long int px = 0;
    long long int py = 0;

    for (int i = 0; i < p.size(); i++){
        //std::cout << p[i] << ": ";
        if (p[i]>='0' && p[i]<='9'){
            long long int nw = p[i++] - '0';
            cm = (cm*nw)%mod;
            //std::cout << cm << std::endl;
            m.push(cm);
            continue;
        }
        if (p[i] == ')'){
            m.pop();
            cm = m.top();
            //std::cout << cm << std::endl;
            continue;
        }
        switch (p[i]){
            case 'N':
                py -= cm;
                if (py<0) py+= mod;
                break;
            case 'S':
                py = (py+cm)%mod;
                break;
            case 'E':
                px = (px + cm) % mod;
                break;
            case 'W':
                px -= cm;
                if (px<0) px+=mod;
                break;
        }
        //std::cout << px << " " << py << std::endl;
    }
    std::cout << px+1 << " " << py+1 << std::endl;
}

int main(){
    int T;
    std::cin >> T;

    for (int i = 1; i <= T; i++){
        std::string p;
        std::cin >> p;
        std::cout << "Case #" << i << ": ";
        solve(p);
    }
}

