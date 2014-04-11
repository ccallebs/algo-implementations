#include <stdio.h>
#include <time.h>

void get_formatted_time(char* outTime);
void print_time();
long long int fib2(long long int n1, long long int n2);

int main (int argc, char *argv[])
{
	// First argument should be which fibonacci number to compute
	int fibNumber = atoi(argv[1]);

	print_time();

	long long int fibNumbers[fibNumber+1];

	for (int i = 0; i <= fibNumber; ++i)
	{
		if (i == 0)
		{
			fibNumbers[i] = 0;
		}
		else if (i == 1 || i == 2)
		{
			fibNumbers[i] = 1;
		}
		else
		{
			fibNumbers[i] = fibNumbers[i-1] + fibNumbers[i-2];
		}

		// Printing results
		printf("Fib(%i) = %llu\n", i, fibNumbers[i]);

		print_time();
	}

	return 0;
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
