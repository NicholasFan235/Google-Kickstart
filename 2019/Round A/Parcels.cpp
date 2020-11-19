#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int MAX_INT = 1023;

int distanceGrid[250][250];
int r, c;

int corners[4][250][2];

void propagateDistance(queue<array<int, 2>>* toCheck){
    while (!toCheck->empty()){
        // check surrounding cells
        array<int, 2> coord = toCheck->front();
        toCheck->pop();

        if (coord[0] > 0){
            if (distanceGrid[coord[0]-1][coord[1]] == MAX_INT){
                distanceGrid[coord[0]-1][coord[1]] = distanceGrid[coord[0]][coord[1]]+1;
                toCheck->push({coord[0]-1, coord[1]});
            }
        }
        if (coord[0] < r-1){
            if (distanceGrid[coord[0]+1][coord[1]] == MAX_INT){
                distanceGrid[coord[0]+1][coord[1]] = distanceGrid[coord[0]][coord[1]]+1;
                toCheck->push({coord[0]+1, coord[1]});
            }
        }
        if (coord[1] > 0){
            if (distanceGrid[coord[0]][coord[1]-1] == MAX_INT){
                distanceGrid[coord[0]][coord[1]-1] = distanceGrid[coord[0]][coord[1]]+1;
                toCheck->push({coord[0], coord[1]-1});
            }
        }
        if (coord[1] < c-1){
            if (distanceGrid[coord[0]][coord[1]+1] == MAX_INT){
                distanceGrid[coord[0]][coord[1]+1] = distanceGrid[coord[0]][coord[1]]+1;
                toCheck->push({coord[0], coord[1]+1});
            }
        }
    }
}

void printGrid(){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            std::cout << distanceGrid[i][j] << ", ";
        }
        std::cout << "\n";
    }
}

void resetGrid(int val){
    for (int i=0; i<250; i++){
        for (int j=0; j<250; j++){
            distanceGrid[i][j] = val;
        }
    }
}

bool isPossible(int distance){
    int limits[4];
    int counts[4];
    for (int i=0; i<4; i++){
        limits[i] = -r-c-1;
        counts[i] = 0;
    }
    memset(corners, 0, sizeof(corners));
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (distanceGrid[i][j] > distance){
                for (int k = 0; k<4; k++){
                    int lim = ((k%2)*2-1)*i + (((k>>1)%2)*2-1)*j;
                    if (lim>limits[k]){
                        limits[k] = lim;
                        counts[k]=0;
                        corners[k][counts[k]][0] = i;
                        corners[k][counts[k]][1] = j;
                        counts[k]++;
                    }
                    else if (lim==limits[k]){
                        corners[k][counts[k]][0] = i;
                        corners[k][counts[k]][1] = j;
                        counts[k]++;
                    }
                }
            }
        }
    }
    
    bool isEmpty = true;
    for (int i =0; i < 4; i++){
        if (counts[i]>0) isEmpty = false;
    }
    if (isEmpty){
        return 1;
    }

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            bool goodPosition = true;
            for (int k = 0; k < 4; k++){
                for (int l = 0; l < counts[k]; l++){
                    int d = abs(corners[k][l][0]-i) + abs(corners[k][l][1]-j);
                    if (d>distance)
                        goodPosition = false;
                    if (!goodPosition) break;
                }
                if (!goodPosition) break;
            }
            if (goodPosition) return 1;
        }
    }

    return 0;
}

void solve(){
    cin >> r >> c;
    //cout << "\n\n";
    resetGrid(MAX_INT);

    queue<array<int, 2>> toCheck;

    for (int i = 0; i < r; i++){
        string offices;
        cin >> offices;
        for (int j = 0; j < c; j++){
            char hasOffice = offices[j];
            if (hasOffice == '1'){
                distanceGrid[i][j] = 0;
                toCheck.push({i, j});
            }
        }
    }

    propagateDistance(&toCheck);

    //printGrid();

    int upperBound = r+c;
    int lowerBound = 0;

    int lastUpper = r+c;
    int lastLower = 0;

    while (upperBound != lowerBound){
        int checkDist = (upperBound + lowerBound) / 2;
        //cout << checkDist << ": ";
        if (isPossible(checkDist)){
            upperBound = checkDist;
        }
        else{
            lowerBound = checkDist;
        }

        if (lastUpper == upperBound && lastLower == lowerBound){
            break;
        }
        lastUpper = upperBound; lastLower = lowerBound;
    }

    std::cout << upperBound << "\n";
}

int main(){
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++){
        std::cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
