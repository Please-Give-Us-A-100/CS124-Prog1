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


struct Point0D{
	float weight; 
	bool visited; 
}; 

struct Point2D {
	int name; 
	float x, y; 
	bool visited; 
	float weight; 
};

float two_distance(float x1, float y1, float x2, float y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) +  
                pow(y2 - y1, 2) * 1.0); 
}

struct Point3D {
	float x, y, z; 
}; 

struct Point4D {
	float x, y, z, a; 
}; 

/*float prim_0d(int n) {
	float smallest = 20.0;  
	struct Point2D arr[n]; 
	//resets random number generator 

	srand(time(NULL));
	for(int i = 0; i < n; i++) {
		arr[i].visited = false; 
		arr[i]. weight = (float)rand() / RAND_MAX;
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
*/
float prim_2d(int n) {
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
	
	/*for(int i = 0; i < n -1 ; i ++){
		arr[niq].visited = true; 
		if (arr[i].visited == false) {
			for (int j = i + 1; j < n; j++ ) {
				float dist = two_distance(arr[j].x, arr[j].y, arr[niq].x, arr[niq].y); 
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


/*float prim_2d_2(int k, int n, struct Point2D arr[]) { 
	arr[k].visited = true; 
	float total;
	float smallest;  
	int smallest_index; 
	for(int i = 0; i < n - 1; i ++){
		if (arr[i].visited == false) {
			float dist = two_distance(arr[i].x, arr[i].y, arr[k].x, arr[k].y); 
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
	int n =  5; 
	int trials = 5; 
	/*float tot; 
	for (int i = 0; i < trials; i++){
		tot += prim_2d(n); 
	}
	float avg = tot/trials; 
	cout << "avergae \n" << avg <<"\n"; */
	
	float sum = prim_2d(n); 
	cout << "sum: " << sum << "\n"; 
	return 0; 
}