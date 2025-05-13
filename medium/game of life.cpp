class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int dx[] = {-1,-1,0,1,1,1,0,-1};
        int dy[] = {0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int livecells = 0;
                for(int k=0;k<8;k++){
                    int row = i+dx[k];
                    int col = j+dy[k];
                    if(row<n && row>=0 && col<m && col>=0 && abs(board[row][col])==1){
                        livecells++;
                    }
                }
                if(board[i][j]==1 && (livecells<2 || livecells>3)){
                    board[i][j] = -1;
                }
                if(board[i][j]==0 && livecells==3){
                    board[i][j] = 2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]>=1){
                    board[i][j] = 1;
                }
                else board[i][j] = 0;
            }
        }
    }
};
