#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <array>
#include <queue>
#include <stack>

using namespace std;

const int AZ_LEN = 26;

struct Node{
    int count;
    struct Node* children[AZ_LEN];
    struct Node* parent;
};

struct Word{
    int length;
    string word;
    struct Node* endNode;

    bool operator < (const Word other) const{
        return length < other.length;
    }
};

struct Node* makeNode(struct Node* parent){
    struct Node* newNode = new Node;
    newNode->count = 0;
    for (int i=0; i<AZ_LEN; i++){
        newNode->children[i] = NULL;
        newNode->parent = parent;
    }
    return newNode;
}

struct Word* makeWord(string word, struct Node* endNode){
    struct Word* newWord = new Word;
    newWord->length = word.length();
    newWord->word = word;
    newWord->endNode = endNode;
}

struct Node* insert(struct Node* root, string key){
    struct Node* currNode = root;
    for (int i=0; i<key.length(); i++){
        int ind = key[i] - 'A';
        if (currNode->children[ind]==NULL){
            currNode->children[ind] = makeNode(currNode);
        }
        currNode = currNode->children[ind];
        currNode->count++;
    }
    return currNode;
}

void remove(struct Node* root, string key){
    struct Node* currNode = root;
    for (int i=0; i<key.length(); i++){
        int ind = key[i] - 'A';
        currNode = currNode->children[ind];
        currNode->count--;
    }
}

struct Node* removeLastChar(struct Node* endNode){
    endNode->count--;
    return endNode->parent;
}

int compareFront(string s1, string s2, int number){
    if (s1.length()<number || s2.length()<number){
        return 1;
    }
    for (int i = 0; i < number; i++){
        if (s1[i]!=s2[i]){
            return 1;
        }
    }
    return 0;
}

void solve(){
    int n, k;
    cin >> n >> k;

    struct Node* root = makeNode(NULL);
    priority_queue<Word> words;

    for (int i=0; i<n; i++){
        string word;
        cin >> word;
        struct Node* endNode = insert(root, word);
        struct Word* newWord = makeWord(word, endNode);
        words.push(*newWord);
    }

    int totalBundles = n/k;
    int currBundles = 0;
    int score = 0;
    int ctr;
    
    while (true){
        struct Word currWord = words.top();
        struct Node* endNode = currWord.endNode;

        cout << currWord.word << ", " << currWord.length << "\n";

        if (currWord.word.length() == 0 || words.empty()){
            break;
        }

        if (endNode->count >= k){
            currBundles++;
            score += currWord.length; // add score
            // Remove matching string from words and trie
            string removeString = currWord.word;
            remove(root, currWord.word); // remove found word
            words.pop();
            int toRemove = k-1;
            stack<Word> tempStack; // search queue for other words, temp stack to re add to queue
            while (toRemove >0){
                Word top = words.top();
                if (compareFront(removeString, top.word, removeString.length()) != 0){
                    tempStack.push(top);
                }
                else
                {
                    remove(root, top.word);
                    toRemove--;
                }
                words.pop();
            }
            while (!tempStack.empty()){
                words.push(tempStack.top());
                tempStack.pop();
            }
        }
        else{
            endNode = removeLastChar(currWord.endNode);
            words.pop();
            //cout << currWord.word << ", " << currWord.word.length() << "->";
            currWord.word.pop_back();
            //cout << currWord.word << ", " << currWord.word.length() << "    ";
            if (!currWord.word.empty())
            {
                currWord = *makeWord(currWord.word, endNode);
                words.push(currWord);
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