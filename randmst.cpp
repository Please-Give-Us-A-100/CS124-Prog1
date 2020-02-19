
#include <cstdlib>
// cin << nump << numt << dim;
int main() {
int n = 2;
double mat [n][n];

for (int i; i < n; i++) {
    for (int j; j < n; j++) {
      /* random algorithm taken from: https://l.facebook.com/l.php?u=https%3A%2F
      2Fstackoverflow.com%2Fquestions%2F6218399%2Fhow-to-generate-a-random-numbe
      r-between-0-and-1%3Ffbclid%3DIwAR3r1JVNyAvtTWXeNXs2ti89zELUQWnMzJYK1_l3kP
      u71rb5Pe2ycYdXlQ0&h=AT1nfuxMUDlA0OQA7jpm0ETFTUw7Mu6ZkLsGJVnmcm6vnXnoL_Lbhp
      nRnW8iuL65bbVPBm9QDDSIdGxqSuTwNU4GLva6hR4AhsflrZ9T_G01zGK41t-PLC5A5hhMTtuf
      NoXbjQ */
      mat[i][j] = (double)rand() / (double)RAND_MAX;
    }
}
}