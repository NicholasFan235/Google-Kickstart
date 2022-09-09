#include <bits/stdc++.h>


int N;
std::vector<int> A;

bool isValidForward(int i, int j)
{
    bool failed = false;
    int diff = A[i+1] - A[i];
    for (int k = i; k < j; k++)
    {
        if (A[k+1] - A[k] != diff)
        {
            if (failed) return false;
            failed = true;
        }
    }
    return true;
}

bool isValidBackward(int i, int j)
{
    bool failed = false;
    int diff = A[j]-A[j-1];
    for (int k = j; k > i; k--)
    {
        if (A[k+1]-A[k] != diff)
        {
            if (failed) return false;
            failed = true;
        }
    }
    return true;
}

bool isValid(int i, int j)
{
    if (abs(j-i) < 3) return true;
    return isValidBackward || isValidBackward;
}


void solve()
{

}


int main()
{
    
}

