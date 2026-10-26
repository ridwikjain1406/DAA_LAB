#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixchainmultiplication(vector<int>&p){
    int n=p.size()-1;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int q=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<dp[i][j]){
                    dp[i][j]=q;
                }
            }
        }
    }
    return dp[1][n];
}

int main(){
    vector<int> p={10,20,30,40,30};
    cout<<"Minimum number of multiplications is: "<<matrixchainmultiplication(p)<<endl;
    return 0;
}
