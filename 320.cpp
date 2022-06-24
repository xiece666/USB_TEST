#include<bits/stdc++.h>
using namespace std;
int n,p[310],ans=-1,dp[310][310];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		p[i+n]=p[i];
	}
	for(int i=2;i<2*n;i++){
		for(int j=i-1;j>0&&i-j<n;j--){
			for(int k=j;k<i;k++){
				dp[j][i]=max(dp[j][i],dp[j][k]+dp[k+1][i]+p[j]*p[k+1]*p[i+1]);
			}
			ans=max(ans,dp[j][i]);
		}
	}
	printf("%d",ans);
	return 0;
}