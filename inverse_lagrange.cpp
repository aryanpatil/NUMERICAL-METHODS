// C++ code for solving inverse interpolation 

#include <bits/stdc++.h> 
using namespace std; 

// Consider a structure 
// to keep each pair of 
// x and y together 
struct Data { 
	double x, y; 
}; 

// Function to calculate 
// the inverse interpolation 

double inv_interpolate(Data d[], int n, double y) 
{ 
	// Initialize final x 
	double x = 0; 

	int i, j; 

	for (i = 0; i < n; i++) { 

		// Calculate each term 
		// of the given formula 
		double xi = d[i].x; 
		for (j = 0; j < n; j++) { 

			if (j != i) { 
				xi = xi 
					* (y - d[j].y) 
					/ (d[i].y - d[j].y); 
			} 
		} 

		// Add term to final result 
		x += xi; 
	} 

	return x; 
} 

// Driver Code 
int main() 
{ 

	// Sample dataset of 4 points 
	// Here we find the value 
	// of x when y = 4.5 
	Data d[] = { { 1.27, 2.3 }, 
				{ 2.25, 2.95 }, 
				{ 2.5, 3.5 }, 
				{ 3.6, 5.1 } }; 

	// Size of dataset 
	int n = 4; 

	// Sample y value 
	double y ; 
    cout << "Enter the value of y: ";
    cin >> y;

	// Using the Inverse Interpolation 
	// function to find the 
	// value of x when y is entered by user is 
	cout << "Value of x at y = : "<< y << " is " 
		<< inv_interpolate(d, n, y)<< endl; 

	return 0; 
} 
