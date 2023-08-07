#include<bits/stdc++.h>
using namespace std;

unsigned long long power(unsigned long long a,unsigned long long x,unsigned long long y)
{
   unsigned long long res=1;
    for(int i=1;i<=x;i++)
    {
        res=(res*a)%y;
    }
    return res;
}
unsigned long long  gcd( unsigned long long  a,unsigned long long b)
{
   unsigned long long r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
bool isprime(long long n)
{
    unsigned long long i=1,k=2;
    if(n<=1 || n==4)
    {
        return false;
    }
    if(n==2 || n==3)
    {
        return true;
    }
    while(i<=k)
    {
       unsigned long long a=2+rand()%(n-3);

        if(gcd(a,n)!=1)
        {
            return false;
        }
        if(power(a,n-1,n)!=1)
        {
            return false;
        }
        i++;
    }
    return true;
}
int main()
{
    long long n;
    cin>>n;
    if(isprime(n))
    {
        cout<<"Number is prime"<<endl;
    }
    else
    {
        cout<<"Number is Composite"<<endl;
    }
}


