#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n, p;
    cin >> n >> p;

    priority_queue<int> skills;
    queue<int> tempSkills;
    
    for (int i = 0; i < n; i++){
        int s;
        cin >> s;
        skills.push(s);
    }

    int hours = 0;
    hours = p * skills.top();
    for (int i = 0; i < p; i++){
        hours -= skills.top();
        tempSkills.push(skills.top());
        skills.pop();
    }

    int minHours = hours;
    for (int i = 0; i < n-p; i++){
        hours -= (p-1) * tempSkills.front();
        tempSkills.pop();
        hours += p * tempSkills.front();
        hours -= skills.top();
        tempSkills.push(skills.top());
        skills.pop();

        if (hours < minHours){
            minHours = hours;
        }
    }

    cout << minHours << "\n";
}

int main(){
    int t;
    cin >> t;
    for (int i=1; i<=t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}
