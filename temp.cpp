#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
string str,ptr;
cin>>str>>ptr;
int n=str.size();
int m=ptr.size();
int lps[n+5]={0};
int prevlps=0,i=1;
while(i<m)
{
     if(ptr[i]==ptr[prevlps])
     {
        lps[i]=prevlps+1;
        prevlps++;
        i++;
     }
     else if(prevlps==0)
     {
        lps[i]=0;
        i++;
     }
     else
     {
        prevlps=lps[prevlps-1];
     }
}
i=0;int j=0;
while(i<n)
{
     if(str[i]==ptr[j])
     {
        i++;
         j++;   
     }
     else 
     {
         if(j==0)
         i++;
         else
         j=lps[j-1];
     }
     if(j==m)
     {
         cout<<i-j<<endl;
         j=0;
     }
}
return 0;
}