class Solution {
public:
int n;
vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
bool possibleToreach(int i,int j,int t, vector<vector<bool>>&visited,vector<vector<int>>& grid){
    if(i<0||j<0||i>=n||j>=n||visited[i][j]||grid[i][j]>t)return false;
    visited[i][j]=true;
    if(i==n-1&&j==n-1)return true;
    for(auto& dir:directions){
        int ni=i+dir[0];
        int nj=j+dir[1];
        if(possibleToreach(ni,nj,t,visited,grid))return true;
    }
    return false;

}
    int swimInWater(vector<vector<int>>& grid) {
         n =grid.size();
        int l=grid[0][0],r=n*n-1;
        int result=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            vector<vector<bool>>visited(n,vector<bool>(n,false));
            if(possibleToreach(0,0,mid,visited,grid)){
                    result=mid;
                    r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};
