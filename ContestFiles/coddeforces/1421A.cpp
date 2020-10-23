#include<bits\stdc++.h>
using namespace std;
long gcd(long,long);
int main()
{int t;
cin>>t;
while(t--)
{
	long a,b;
	cin>>a>>b;
	long c=gcd(a,b);
	long long ans=(a^c)+(b^c);
	if(ans>a+b)
	ans=a+b;
	cout<<ans<<"\n";
}
	
}
long gcd(long A,long B)
{long g=0;
	long j = 0, x = 0; 
  
    // While either A or B is non-zero 
    while (A || B) { 
  
        // Position at which both A and B 
        // have a set bit 
        if ((A & 1) && (B & 1)) { 
  
            // Inserting a set bit in x 
            x += (1 << j); 
        } 
  
        // Left shifting both numbers to 
        // traverse all the bits 
        A >>= 1; 
        B >>= 1; 
        j += 1; 
    } 
    return x;
}
