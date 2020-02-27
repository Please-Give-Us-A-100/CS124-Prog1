#include <iostream>
#include <map>
#include <string>
#include <list>
#include <tuple>
#include <vector> 
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <functional>
#include <random>
#include <time.h>
#include <limits>
using namespace std; 


struct Point{
	float x, y, z, a; 
	bool visited; 
	float weight; 
}; 

struct Point0D {
	bool visited; 
	float weight; 
}; 

struct Point2D {
	int name; 
	float x, y; 
	bool visited; 
	float weight; 
};

struct Point3D {
	float x, y, z; 
	bool visited; 
	float weight; 
}; 

//struct Point4D {
	
//}; 



 float two_distance(float x1, float y1, float x2, float y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) +  
                pow(y2 - y1, 2) * 1.0); 
}

float three_distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) + pow(z2 - z1, 2) * 1.0);
}


float distance(double x1, double y1, double z1, double a1, double x2, double y2, double z2, double a2){
	return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) + pow(z2 - z1, 2) + pow(a2 - a1, 2)* 1.0); 
}


float prim_0d(int n) {
	float smallest = 20.0;  
	struct Point0D arr[n]; 
	//resets random number generator 

	srand(time(NULL));
	for(int i = 0; i < n; i++) {
		arr[i].visited = false; 
		arr[i]. weight = 2;
	}
	int edges; 
	float total;  
	int smallest_index; 
	int niq = 0; 
	while (edges < n) {
		arr[niq].visited = true; 
		for(int i = 0; i < n ; i ++){
			if (arr[i].visited == false) {
				//cout << "node" << i << "visited \n"; 
				float dist = (float)rand() / RAND_MAX; 
				//cout << "distance between " << niq << " and " << i << " is " << dist << "\n";
				if (dist < arr[i].weight){ 
					arr[i].weight = dist; 
					if (dist < smallest || smallest == 20.0) {
						smallest = dist;
						smallest_index = i; 
						//niq = i; 
						
						//cout << "min found at node " << i << "\n"; 
					}  			
				
				}
				else {
					dist = arr[i].weight;
					if (dist < smallest || smallest == 20.0) {
						smallest = dist;
						smallest_index = i; 
						//niq = i; 
						arr[i].weight = dist; 
						//cout << "min found at node " << i << "\n";  
					}
				
				}
			} 
		} 
		niq = smallest_index; 
		 
		edges++; 
		if (smallest != 20.0) {
			total = total + smallest;
			cout <<"node in question " << niq << "\nadd to total \n" << "smallest " << smallest << "\n"<< total << "\n" << edges << "\n" << "niq is: " << niq << "\n" << "niq weigjt: " << arr[niq].weight << "\n";
			smallest = 20.0; 
		}
		

	}
	return total; 
} 


float prim(int n, int d) { 

	// Initializes array 
	struct Point arr[n]; 
	 
	
	// resets random number generator 
	srand(time(NULL));
	for(int i = 0; i < n; i++) {
		arr[i].visited = false; 
		arr[i]. weight = 50.0;
		arr[i].x = 0.0;
		arr[i].y = 0.0; 
		arr[i].z = 0.0; 
		arr[i].a = 0.0; 
		// initializes coordinates for higher dimension 
		if (d == 2) {
			arr[i].x = (float)rand() / RAND_MAX;
			arr[i].y = (float)rand() / RAND_MAX;
			if (d == 3) {
				arr[i].z = (float)rand() / RAND_MAX;
				if (d == 4) {
					arr[i].a = (float)rand() / RAND_MAX;
				}
			}
		}
		//arr[i]. weight = std::numeric_limits<float>::max();;
	}

	int edges; 
	float total;  
	// Smallest initialized to overestimated bound
	float smallest = 20.0; 
	// Saves and updates index of smallest node 
	int smallest_index;
	// "Node in question" -- node being explored
	int niq = 0; 
	float dist; 
	while (edges < n) {
		arr[niq].visited = true; 
		for(int i = 0; i < n ; i ++){
			if (arr[i].visited == false) {
				//cout << "node" << i << "visited \n"; 
				if (d == 0) {
					dist = (float)rand() / RAND_MAX; 
				}
				else {
					dist = distance(arr[i].x, arr[i].y, arr[i].z, arr[i].a, arr[niq].x, arr[niq].y, arr[niq].z, arr[niq].a); 
				}
				//cout << "distance between " << niq << " and " << i << " is " << dist << "\n";
				if (dist < arr[i].weight){ 
					arr[i].weight = dist; 
					if (dist < smallest || smallest == 20.0) {
						smallest = dist;
						smallest_index = i; 
						//niq = i; 
						
						//cout << "min found at node " << i << "\n"; 
					}  			
				}
				else {
					dist = arr[i].weight;
					if (dist < smallest || smallest == 20.0) {
						smallest = dist;
						smallest_index = i; 
						//niq = i; 
						arr[i].weight = dist; 
						//cout << "min found at node " << i << "\n";  
					}	
				}
			} 
		} 
		niq = smallest_index; 		 
		edges++; 
		if (smallest != 20.0) {
			total = total + smallest;
			//cout <<"node in question " << niq << "\nadd to total \n" << "smallest " << smallest << "\n"<< total << "\n" << edges << "\n" << "niq is: " << niq << "\n" << "niq weigjt: " << arr[niq].weight << "\n";
			smallest = 20.0; 
		}		

	}
	return total; 
} 

float prim(int n) {
	float smallest = 20.0;  
	struct Point2D arr[n]; 
	//resets random number generator 

	srand(time(NULL));
	for(int i = 0; i < n; i++) {
		arr[i].name = i; 
		arr[i].x = (float)rand() / RAND_MAX;
		//cout << "x: " << arr[i].x << "\n"; 
		arr[i].y = (float)rand() / RAND_MAX;
		//cout << "y: " << arr[i].y << "\n"; 
		arr[i].visited = false; 
		arr[i]. weight = 2;
	}
	int edges; 
	float total;  
	int smallest_index; 
	int niq = 0; 
	while (edges < n) {
		arr[niq].visited = true; 
		for(int i = 0; i < n ; i ++){
			if (arr[i].visited == false) {
				cout << "node" << i << "visited \n"; 
				float dist = two_distance(arr[i].x, arr[i].y, arr[niq].x, arr[niq].y); 
				cout << "distance between " << niq << " and " << i << " is " << dist << "\n";
				if (dist < arr[i].weight){ 
					arr[i].weight = dist;
					if (dist < smallest || smallest == 20.0) {
						smallest = dist;
						smallest_index = i; 
						//niq = i; 
						 
						cout << "min found at node " << i << "\n"; 
					}  			
				
				}
				else {
					dist = arr[i].weight;
					if (dist < smallest || smallest == 20.0) {
						smallest = dist;
						smallest_index = i; 
						//niq = i; 
						arr[i].weight = dist; 
						cout << "min found at node " << i << "\n";  
					}
				
				}
			} 
		} 
		niq = smallest_index; 
		 
		edges++; 
		if (smallest != 20.0) {
			total = total + smallest;
			cout <<"node in question " << niq << "\nadd to total \n" << "smallest is: " << smallest << "\n"<< total << "\n" << edges << "\n" << "niq is: " << niq << "\n" << "niq weight: " << arr[niq].weight << "\n";
			smallest = 20.0; 
		}
		

	}
	return total; 
} 


int main() {
	int n =  1024; 
	int trials = 5; 
	int d = 0; 
	/*float tot; 
	for (int i = 0; i < trials; i++){
		tot += prim_2d(n); 
	}
	float avg = tot/trials; 
	cout << "avergae \n" << avg <<"\n"; */
	
	float sum = prim(n, d); 
	cout << "sum: " << sum << "\n"; 
	return 0; 
}