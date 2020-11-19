#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <array>
#include <stack>

using namespace std;

const int AZ_LEN = 26;

struct Node{
    int count;
    struct Node* children[AZ_LEN];
};

struct Node* makeNode(){
    struct Node* newNode = new Node;
    newNode->count = 0;
    for (int i=0; i<AZ_LEN; i++){
        newNode->children[i] = NULL;
    }
    return newNode;
}

struct Node* insert(struct Node* root, string key){
    struct Node* currNode = root;
    for (int i=0; i<key.length(); i++){
        int ind = key[i] - 'A';
        if (currNode->children[ind]==NULL){
            currNode->children[ind] = makeNode();
        }
        currNode = currNode->children[ind];
        currNode->count++;
    }
    return currNode;
}

void solve(){
    int n, k;
    cin >> n >> k;

    struct Node* root = makeNode();

    for (int i=0; i<n; i++){
        string word;
        cin >> word;
        struct Node* endNode = insert(root, word);
    }

    stack<Node*> toCheck;
    toCheck.push(root);

    int score = 0;

    while(!toCheck.empty()){
        struct Node* currNode = toCheck.top();
        toCheck.pop();

        // add score
        score += currNode->count / k;

        //enqueue children
        for (int i=0; i<AZ_LEN; i++){
            if (currNode->children[i] != NULL && currNode->children[i]->count > 0){
                toCheck.push(currNode->children[i]);
            }
        }
    }

    cout << score << "\n";
}


int main(){
    int t;
    cin >> t;
    for (int i=1; i<=t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}