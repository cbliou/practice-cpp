#pragma once
#include <vector>

using namespace std;

bool testPrime(int i);
void generateFib(vector<int>& n, int limit);
bool determinePalindrome(int i);

/* populate grid v with values from init into a dim * dim grid */
void reshapeGrid(vector<int>& init, vector<vector<int>>& v, int dim);

/* return nth triangle number 
   make sure you allow the stack size to be above 1 MB, otherwise your stack overflows for numbers above 4725
*/
uint64_t triangleNumber(int nth);

/* return number of divisors, inclusive of 1, for int i*/
int getNumDivisors(uint64_t i);