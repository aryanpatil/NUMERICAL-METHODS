#include<bits/stdc++.h>
#include<math.h>

using namespace std;
int main()
{
    int n;                         
    int i,j;                       
    float ax[10]={21, 25, 29, 33, 37};                   
    float ay[10]={18.4708, 17.8144, 17.1070, 16.3432, 15.5154};                   
    float x;                       
    float nr,dr;
    float y=0;                      
    float h;                        
    float p;                        
    float diff[20][20];             
    float y1,y2,y3,y4;              

    cout<<"GAUSS' FORWARD INTERPOLATION FORMULA !! ";

    
    n = 5;


    cout<<"\n\n Enter the value of x: ";
    
    cin>>x;


    h=ax[1]-ax[0];
    for(i=0;i<n-1;i++)
    diff[i][1]=ay[i+1]-ay[i];

    for(j=2;j<=4;j++)
    for(i=0;i<n-j;i++)
        diff[i][j]=diff[i+1][j-1]-diff[i][j-1];

    i=0;
    do
    {
    i++;
    }
    while(ax[i]<x);

    i--;
    p=(x-ax[i])/h;
    y1=p*diff[i][1];
    y2=p*(p-1)*diff[i-1][2]/2;
    y3=(p+1)*p*(p-1)*diff[i-2][3]/6;
    y4=(p+1)*p*(p-1)*(p-2)*diff[i-3][4]/24;


    y=ay[i]+y1+y2+y3+y4;

    cout << "\n Value at " << x << " is " << y << endl;

    return 0;
}

