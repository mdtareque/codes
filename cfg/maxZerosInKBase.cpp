/*
Given a decimal integer n, find an integer k >= 2 such that the representation of n in base k has the maximum possible number of zeros. If there are several answers, output the smallest one.

Example

For n = 9, the output should be
maxZeros(n) = 2.
    [input] integer n
    A positive integer.
    [output] integer
    The desired numeral system base.
*/

//https://codefights.com/tournaments/kN9EkoPKGZhbgDFnt/B
int maxZeros(int n) {
  int answer = 0,
      maxZeros = 0;
  for (int k = 2; k <= n; k++) {
    int numZeros = 0,
        value = n;
    while (value) {
      if (value % k == 0) {
        numZeros++;
      }
      value /= k;
    }
    if (numZeros > maxZeros) {
     // ...
	maxZeros = numZeros;
	answer = k;
	
    }
  }
  return answer;
}

