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
using namespace std; 


struct Point2D {
	int name; 
	double x, y; 
	bool visited; 
	double weight; 
};

double two_distance(double x1, double y1, double x2, double y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) +  
                pow(y2 - y1, 2) * 1.0); 
}

struct Point3D {
	double x, y, z; 
}; 

struct Point4D {
	double x, y, z, a; 
}; 

double prim_2d(int n) {
	double smallest = 20.0;  
	struct Point2D arr[n]; 
	//resets random number generator 

	srand(time(NULL));
	for(int i = 0; i < n; i++) {
		arr[i].name = i; 
		arr[i].x = (double)rand() / RAND_MAX;
		arr[i].y = (double)rand() / RAND_MAX;
		arr[i].visited = false; 
		arr[i]. weight = 2;
	}
	int edges; 
	double total;  
	int smallest_index; 
	int niq = 0; 
	while (edges < n) {
		arr[niq].visited = true; 
		for(int i = 0; i < n ; i ++){
			if (arr[i].visited == false) {
				cout << "node" << i << "visited \n"; 
				double dist = two_distance(arr[i].x, arr[i].y, arr[niq].x, arr[niq].y); 
				if (dist < arr[i].weight){ 
					if (dist < smallest || smallest == 20.0) {
						cout << "min found at node " << i << "\n"; 
						smallest = dist;
						smallest_index = i; 
						niq = i; 
						arr[i].weight = dist; 
					}  
					
				
				}
				
			}
			
		
		} 
		 
		edges++; 
		if (smallest != 20.0) {
			total = total + smallest;
			cout <<"node in question " << niq << "\nadd to total \n" << "smallest " << smallest << "\n"<< total << "\n" << edges << "\n";
			smallest = 20.0; 
		}
		
		

	}
	
	/*for(int i = 0; i < n -1 ; i ++){
		arr[niq].visited = true; 
		if (arr[i].visited == false) {
			for (int j = i + 1; j < n; j++ ) {
				double dist = two_distance(arr[j].x, arr[j].y, arr[niq].x, arr[niq].y); 
				if (dist < arr[j].weight){
					smallest = dist; 
					smallest_index = j; 
					niq = j; 
					arr[j].weight = dist;
				
				}
			}
		}
		edges++; 
		total = total + smallest;
		cout << "add to total \n" << total << "\n" << edges << "\n"; 
	} */
	return total; 

} 

/*double prim_2d_2(int k, int n, struct Point2D arr[]) { 
	arr[k].visited = true; 
	double total;
	double smallest;  
	int smallest_index; 
	for(int i = 0; i < n - 1; i ++){
		if (arr[i].visited == false) {
			double dist = two_distance(arr[i].x, arr[i].y, arr[k].x, arr[k].y); 
			if (dist < arr[i].weight){
				smallest = dist; 
				int smallest_index = i; 
				arr[i].weight = dist;
				
			}
			prim_2d(smallest_index, n, arr); 
			total = total + smallest;
			
		}
			
	}
	return total; 
}
*/



int main() {
	int n = 1024; 
	int trials = 5; 
	double tot; 
	for (int i = 0; i < trials; i++){
		tot += prim_2d(n); 
	}
	double avg = tot/trials; 
	cout << "avergae \n" << avg <<"\n"; 
	return 0; 
}