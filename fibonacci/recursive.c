#include <stdio.h>
#include <time.h>

void get_formatted_time(char* outTime);
void print_time();
long long int fib1(long long int n);

int main (int argc, char *argv[])
{
	// First argument should be which fibonacci number to compute
	int fibNumber = atoi(argv[1]);

	print_time();

	for (int i = 0; i <= fibNumber; ++i)
	{
		// Retrieving fibonacci number
		long long int fib = fib1(i);

		// Printing results
		printf("Fib(%i) = %llu\n", i, fib);

		print_time();
	}

	return 0;
}

// unsigned long fib1(int n)
//	function calculates fibonacci number for nth term using recursion
//
// @param n
//	Which fibonacci number to calculate
long long int fib1(long long int n)
{
	if (n == 0 || n == 1)
		return n;
	else
		return fib1(n - 1) + fib1(n - 2);
}

// void get_formatted_time()
//	function returns current time formatted as HH:MM:SS
void get_formatted_time(char* outTime)
{
	// Initializing timer
	time_t timer;
	timer = time (NULL);

	timer = localtime(&timer);

	// Generating current time string
	strftime (outTime, 9, "%I:%M:%S ", timer);
}

// void print_time()
//	function prints time
void print_time()
{
	// Initializing char array
	char time[9];

	get_formatted_time(time);

	printf("Current time: %s\n", time);

}
