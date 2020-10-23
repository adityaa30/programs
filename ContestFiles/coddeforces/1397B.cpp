#include<bits\stdc++.h>
using namespace std;
long root(double x, int n) 
{ 
  
// Initialize boundary values  
double low, high; 
    low = 1; 
    high = x;  
  
// used for taking approximations  
// of the answer  
double epsilon = 0.00001; 
  
// Do binary search  
double guess = (low + high) / 2; 
while (abs((pow(guess, n)) - x) >= epsilon) 
{ 
    if (pow(guess, n) > x) 
    { 
        high = guess ; 
    }  
    else
    { 
        low = guess ; 
    } 
    guess = (low + high) / 2; 
} 
  long a=(long)guess;
return a;
}
int main()
{
	long n,c=0,d=0,e=0;
	cin>>n;
	vector<long> a(n);
	long long count1=0,count2=0,count3=0;
	cin>>a[0];
	for(long i=1;i<n;i++)
	{cin>>a[i];
	}
	sort(a.begin(),a.end());
	c=root((double)a[n-1],n-1);
	d=c+1;
	e=c-1;
	for(int i=0;i<n;i++)
	{
		count1+=max(a[i]-(long)pow(c,i),(long)pow(c,i)-a[i]);
		count2+=max(a[i]-(long)pow(d,i),(long)pow(d,i)-a[i]);
		count3+=max(a[i]-(long)pow(e,i),(long)pow(e,i)-a[i]);
	}

	cout<<min(count1,min(count2,count3));
	
	
}
