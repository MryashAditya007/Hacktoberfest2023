// Here is the link to the problem https://www.codechef.com/START98D/problems/BLDST

// Solution

#include <iostream>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--)
	{
	    int n,m;cin>>n>>m;
	    int a[m];
	    
	    for(int i=0;i<m;i++)
	    cin>>a[i];
	    
	    int ans=0;int c=0;int f=0;
	    for(int i=0;i<m;i++)
	    {
	        f=0;
	        while(ans<n)
	        {
	            ans+=a[i];
	            i++;f=1;
	        }
	        
	        if(f==1)
	        i--;
	        
	        if(ans>n)
	        {
	            c++;ans=ans-n;
	        }
	        
	        else{
	            c++;ans=0;
	        }
	    }
	    
	    if(c==m)
	    {
	        if(ans==0)
	        cout<<n<<"\n";
	        
	        else cout<<n-ans<<"\n";
	    }
	    
	    else if(c==m-1 && ans>0)
	    cout<<ans<<"\n";
	    
	    else cout<<"0\n";
	    
	    
	}
	return 0;
}