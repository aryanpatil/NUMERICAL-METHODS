// C++ program for implementation of Newton Raphson Method for 
// solving equations 
#include<bits/stdc++.h> 
#define EPSILON 0.001 
using namespace std; 

// An example function whose solution is determined using 
// Bisection Method. The function is x^3 - 3x + 1 
double func(double x) 
{ 
	return x*x*x - 3*x + 1; 
} 

// Derivative of the above function which is 3*x^x - 3 
double derivFunc(double x) 
{ 
	return 3*x*x - 3; 
} 

// Function to find the root 
void newtonRaphson(double x) 
{ 
	double h = func(x) / derivFunc(x); 
	while (abs(h) >= EPSILON) 
	{ 
		h = func(x)/derivFunc(x); 

		// x(i+1) = x(i) - f(x) / f'(x) 
		x = x - h; 
	} 

	cout << "The value of the root of f(x) = x^3 - 3x + 1 is : " << x << endl; 
} 

// Driver program to test above 
int main() 
{ 
	double x0 = 0.3; // Initial values assumed 
	newtonRaphson(x0); 
	return 0; 
} 
