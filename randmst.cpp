
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
//#include <bits/stdc++.h>
//what exactly are you using from this header file? i dont think we should include this
//because it messes with the runtime for our program 
using namespace std;


// Function to calculate distance between two points
// Found on https://www.geeksforgeeks.org/program-calculate-distance-two-points/
float two_distance(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}

// Function to calculate distance between three points
float three_distance(int x1, int y1, int z1, int x2, int y2, int z2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) + pow(z2 - z1, 2) * 1.0);
}

double * one_dim(int n) {
  double mat [n][n];
  for (int i; i <= n; i++) {
      for (int j; j <= n; j++) {
        /* random algorithm taken from: https://l.facebook.com/l.php?u=https%3A%2F
        2Fstackoverflow.com%2Fquestions%2F6218399%2Fhow-to-generate-a-random-numbe
        r-between-0-and-1%3Ffbclid%3DIwAR3r1JVNyAvtTWXeNXs2ti89zELUQWnMzJYK1_l3kP
        u71rb5Pe2ycYdXlQ0&h=AT1nfuxMUDlA0OQA7jpm0ETFTUw7Mu6ZkLsGJVnmcm6vnXnoL_Lbhp
        nRnW8iuL65bbVPBm9QDDSIdGxqSuTwNU4GLva6hR4AhsflrZ9T_G01zGK41t-PLC5A5hhMTtuf
        NoXbjQ */
        mat[i][j] = (double)rand() / (double)RAND_MAX;
        printf("%lf \n", mat[i][j]);
      }
  }
  return *mat; 
}

double * two_dim(int n) {
  // Creates vector to keep track of vertex coordinates
  vector<int> V;
  //Initiliza distance array
  double mat [n][n];
  // Fill Vertex vector with random tuples
  for (int i; i<= n; i++) {
	double x = (double)rand() / (double)RAND_MAX; 
    double y = (double)rand() / (double)RAND_MAX;
    V.push_back((x,y));
  }

  for (int i; i <= n; i++) {
      for (int j; j <= n; j++) {
        mat[i][j] = two_distance(V[i][0],V[j][0],V[i][1],V[j][1]);
      }
    }
    return *mat;
}

double* three_dim(int n) {
  // Creates vector to keep track of vertex coordinates
  vector<int> V;
  //Initiliza distance array
  double mat [n][n];
  // Fill Vertex vector with random tuples
  for (int i; i<= n; i++) {
    double x = (double)rand() / (double)RAND_MAX;
    double y = (double)rand() / (double)RAND_MAX;
    double z = (double)rand() / (double)RAND_MAX;
    V.push_back((x,y,z));
  }
  for (int i; i <= n; i++) {
      for (int j; j <= n; j++) {
        for(int k; k<= n; k++) {
          mat[i][j] = three_distance(V[i][0],V[j][0],V[k][0],V[i][1],V[j][1],V[k][1]);
        }
      }
  }
  return mat;
}

// cin << nump << numt << dim;
int main() {
int n = 2;
one_dim(n); 
two_dim(n); 
three_dim(n); 
}


