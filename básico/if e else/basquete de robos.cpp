#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d,p;
    
    scanf("%d", &d);
    
    if ( d<= 800 )
    {
        p=1;
    }
    else if( d>800 && d<=1400)
    {
        p=2;
    }
    else
    {
        p=3;
    }
    
    printf("%d\n", p);
    
    return 0;
}