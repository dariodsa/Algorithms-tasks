#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

int a,b,c,d,e,t;
int dp[4][1000][1<<10];
bool arr[4][1000];

int rek(int r, int s) {
   //if(arr[r][s]) return 0;
   //printf("%d %d | %d\n",r,s,a);
   if(r == 4) return rek(0, s+1);
   if(s == a) return 1;

   if(arr[r][s] == 1) return rek(r+1, s);


   int mask = 0;
   for(int i=0;i<4;++i) mask = mask*2 + arr[i][s];
   if(s + 1 < a)
       for(int i=0;i<4;++i) mask = mask*2 + arr[i][s+1];
   
   int & ret = dp[r][s][mask];

   if(ret >= 0) return ret;

   ret = 0;

   int CURR = arr[r][s] == 0;
   int RIGHT = s + 1 < a && arr[r][s+1] == 0;
   int DOWN = r + 1 < 4 && arr[r+1][s] == 0;

   if( CURR && DOWN ) {
       arr[r][s] = 1; arr[r+1][s] = 1;
       ret += rek(r+1,s);
       arr[r][s] = 0; arr[r+1][s] = 0;
   }
   if( CURR && RIGHT ) {
       arr[r][s] = 1; arr[r][s+1] = 1;
       ret += rek(r+1,s);
       arr[r][s] = 0; arr[r][s+1] = 0;
   }
   return ret;

}

int main() {
    scanf("%d",&t);
    for(int i=1;i<=t;++i) {
       scanf("%d",&a);
       memset(dp,-1,sizeof(dp));
       printf("%d %d\n",i,rek(0,0)); 
    }
    return 0;
}
