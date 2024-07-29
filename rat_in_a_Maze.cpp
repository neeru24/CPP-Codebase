#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
    private:
    bool isSafe(vector<vector<int>> &m,int n,int x,int y,vector<vector<int>> visited){
        if((x>=0 && x<n) && (y>=0 && y<n) && m[x][y]==1 && visited[x][y]==0){
            return true;
        }
        else{
            return false;
        }
    }

    void solve(vector<vector<int>> &m,int n,int x,int y,string path,vector<string>& ans,
    vector<vector<int>> visited){

        //base case --->reached at destination
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return ;
        }

        visited[x][y]=1;

        //down
        int newx = x+1;
        int newy = y;
        if(isSafe(m,n,newx,newy,visited)){
            path.push_back('D');
            solve(m,n,newx,newy,path,ans,visited);
            path.pop_back();
        }

        //Left
        newx = x;
        newy = y-1;
        if(isSafe(m,n,newx,newy,visited)){
            path.push_back('L');
            solve(m,n,newx,newy,path,ans,visited);
            path.pop_back();
        }

        //Right
        newx = x;
        newy = y+1;
        if(isSafe(m,n,newx,newy,visited)){
            path.push_back('R');
            solve(m,n,newx,newy,path,ans,visited);
            path.pop_back();
        }

       //Up
        newx = x-1;
        newy = y;
        if(isSafe(m,n,newx,newy,visited)){
            path.push_back('U');
            solve(m,n,newx,newy,path,ans,visited);
            path.pop_back();
        }


        visited[x][y]=0; //backtracking
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {

        // 0---> not allowed
        // 1--->allowed

        vector<string> ans;

        //not allowed at starting coordinate
        if(m[0][0]==0){
            return ans;
        }

        //starting coordinate
        int srcx =0;
        int srcy =0;


        vector<vector<int>> visited = m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }


        string path="";
        solve(m,n,srcx,srcy,path,ans,visited);
        sort(ans.begin(),ans.end());
        return ans;

    }
};

int main() {
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    int n = m.size();

    Solution obj;
    vector<string> result = obj.findPath(m, n);

    for (const string& path : result) {
        cout << path << " ";
    }

    return 0;
}
