#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
    float a[10][10], b[10], x[10], y[10];
    int n = 0, m = 0, i = 0, j = 0;
    
    // Defining matrix
    n = 3;
    a[0][0]=2; a[0][1]=3; a[0][3]=1;
    a[1][0]=5; a[1][1]=4; a[1][3]=6;
    a[2][0]=8; a[2][1]=7; a[2][3]=9;
    
    // Right side of equations
    b[0]=2;
    b[1]=3;
    b[2]=4;

    // Initial root values
    x[0]=x[1]=x[2]=0;
    m = 6;
    
    while (m > 0)
    {
        for (i = 0; i < n; i++)
        {
            y[i] = (b[i] / a[i][i]);
            for (j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
            }
            printf("x%d = %f    ", i + 1, y[i]);
        }
        cout << "\n";
        m--;
    }
    return 0;
}