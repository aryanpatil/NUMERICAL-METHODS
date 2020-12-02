#include<bits/stdc++.h>
#include<math.h>
#define SIZE 10

using namespace std;

int main()
{
	 float a[SIZE][SIZE], x[SIZE],x_new[SIZE];
	 float temp, lambda_new, lambda_old, error;
	 int i,j,n, step=1;

     /* Setting precision and writing floating point values in fixed-point notation. */
     cout<< setprecision(3)<< fixed;

	 /* Inputs */
	 /* Reading order of square matrix */
	 n = 2;

     /* Reading tolerable error */
	 error = 0.0001;

	 /* Reading Square Matrix of Order n */
	 a[1][1]=5; a[1][2]=4;
     a[2][1]=1; a[2][2]=2;

	 /* Reading Intial Guess Vector */
	 x[1]=1;
     x[2]=0;

	 /* Initializing Lambda_Old */
	 lambda_old = 1;
	 /* Multiplication */

	 /* Setting label for repetition */
	 up:
	 for(i=1;i<=n;i++)
	 {
		  temp = 0.0;
		  for(j=1;j<=n;j++)
		  {
		   	temp = temp + a[i][j]*x[j];
		  }
		  x_new[i] = temp;
	 }

	 /* Replacing x by x_new */
	 for(i=1;i<=n;i++)
	 {
	  	x[i] = x_new[i];
	 }

	 /* Finding largest value from x*/
	 lambda_new = fabs(x[1]);
	 for(i=2;i<=n;i++)
	 {
		  if(fabs(x[i])>lambda_new)
		  {
		   	lambda_new = fabs(x[i]);
		  }
	 }

	 /* Normalization */
	 for(i=1;i<=n;i++)
	 {
	  	x[i] = x[i]/lambda_new;
	 }

	 /* Display */
	 cout<< endl<< endl<<"STEP-"<< step<< endl;
	 cout<<"Eigen Value = "<< lambda_new<< endl;
	 cout<<"Eigen Vector: "<< endl;
	 cout<<"[";
	 for(i=1;i<=n;i++)
	 {
	  	cout<< x[i]<<"\t";
	 }
     cout<<"\b\b\b]"; /* \b is for backspace */

	 /* Checking Accuracy */
	 if(fabs(lambda_new-lambda_old)>error)
	 {
		  lambda_old=lambda_new;
		  step++;
		  goto up;
	 }

     cout << endl;

	 return(0);
}