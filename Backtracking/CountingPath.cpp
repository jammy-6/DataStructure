#include <bits/stdc++.h>

using namespace std;


int ans = 0;//����·������
int dx[4] = {1,-1,0,0};//x����
int dy[4] = {0,0,1,-1};//y����
bool flag[1000][1000];//����Ƿ񾭹�
int n,m,k;


//�жϵ�ǰλ���Ƿ�Ϸ�
bool isLegal(int x,int y){
    if(x>=0&&x<m&&y>=0&&y<n){
        return true;
    }
    return false;
}

//ͳ��·��
void countPath(const vector<vector<int>>& data,int x,int y,string cs,int d,int k){
    flag[y][x] = true;
    if(stoull(cs)%7==0){
        ans ++;
    }

    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(isLegal(nx,ny)&&!flag[ny][nx]){
            if(d!=i&&k>0){
                countPath(data,nx,ny,cs+to_string(data[ny][nx]),i,k-1);
                flag[ny][nx] = false;
            }else if(d==i){
                countPath(data,nx,ny,cs+to_string(data[ny][nx]),i,k);
                flag[ny][nx] = false;
            }
        }
    }

}

int main(){

    cin>>n>>m>>k;
    vector<vector<int>> data(n,vector<int>(m,0));

    for(int i=0;i<n;i++)    for(int j=0;j<m;j++){
        cin>>data[i][j];
        flag[i][j] = false;
    }
    countPath(data,0,0,to_string(data[0][0]),0,k);
    cout<<ans;
}