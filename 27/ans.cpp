#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

//Function to czech if singular number is prime
bool isPrime(int number) {
	if ( number == 2 || number == 3 ) return true;
	for ( int i = 2; i < number; i++ ) {
		if (number % i == 0) break;
		if (i >= std::sqrt(number) ) return true;
		//No prime number will have a factor above the sqrt of itself
	}
	return false;
}

//This function generates numbers in a range, hence the name.
std::vector<int> numRange(int start, int end) {
	std::vector<int> nums;
	for ( int i = start; i < end; i++ ) {
		nums.push_back(i);
	}
	return nums;
}

int* quadBrute(std::vector<int> numList) {
	//Store equation data to rebuild quadratic equation
	//a = 0, b = 1, n = 2, largest prime = 3
	static int mostPrimes[4] = { 0, 0, 0, 0 };
	for ( int a: numList ) {
		for (int b: numList ) {
			int tempPrime[4] = { 0, 0, 0, 0 };
			for (int n = 0;; n++) {
				int currentAns = std::pow(n, 2) + (a*n) + b;
				//std::cout << a << " " << b <<" " << n << "\n";
				if (n > tempPrime[2] && isPrime(currentAns)) {
					tempPrime[0] = a;
					tempPrime[1] = b;
					tempPrime[2] = n;
					tempPrime[3] = currentAns;
				}
			    else if ( !isPrime(currentAns) ) break;
			}
			if ( tempPrime[2] > mostPrimes[2] ) std::copy(std::begin(tempPrime),
				std::end(tempPrime), std::begin(mostPrimes));
		}
	}
	return mostPrimes;
}

//Pull it all together
int main(int argNum, char** args) {
	//currentAns = std::pow(n, 2) + (a*n) + b;
	int *equation = quadBrute(numRange(-1000,1000));
	std::cout << "a, b, n, the maximum prime, and the factor of a and b\n";
	for (int i = 0; i < 4; i += 1) {
			std::cout << *(equation+i) << "\n";
	}
	//int ans = std::pow(*(equation+2),2) + (*(equation+2) * *(equation+3)) + *(equation+1);
	int ans = *(equation+0) * *(equation+1);
	std::cout << ans << "\n";
	return 0;
}

/*n**2 + an + b
 *
 * |a| < 1000
 * |b| < 1000
 *
 * find most consecutive primes of n in any of these, starting with n = 0
 *
 * THEORY:
 * a and b must be prime
 * EERT wrong.
 */
