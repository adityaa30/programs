#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,sqr;
    stack<int> st;
    vector<int> v;
    
     n=2000;
    
    v.push_back(1);
    st.push(n);
    sqr = sqrt(n);
    
    for(int i=2;i<=sqr;i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            
            if(i*i != n)
                st.push(n/i);
        }
    }
        
    while(!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    
    int max,number,sum,value;
    max = 0;
    
    for(int j: v)
    {
        sum = 0;
        value = j;
        
        while(value!=0)
        {
            sum += value%10;
            value = value/10;
        }
        
        if(sum > max)
        {
            max = sum;
            number = j;
        }
    }
    
    cout << number << endl;
    
    return 0;
}