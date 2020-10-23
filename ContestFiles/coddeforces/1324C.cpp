#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int count=0,max=0;
        string txt;
        cin>>txt;
 
        for(int i=0;i<txt.size(); i++)
        {
            if(txt[i]=='L')
                count++;
            else
                count=0;
 
            if(count>max)
                max=count;
        }
        cout<<max+1<<"\n";
    }
}
