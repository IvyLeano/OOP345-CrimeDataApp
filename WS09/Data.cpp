/* W09
* Data.cpp
* Ivy Leano
*/

#include<iostream>
#include "Data.h"

using namespace std;

namespace sict 
{
	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) 
	{
		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"

		float popChange = ((float)(max(population, n)) - (float)(min(population, n))) / 1000000;

		cout << fixed;
		cout << "Population change from " << year[0] << " to " << year[4] << " is " << setprecision(2) << popChange << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005

		int VC = (max(violentCrime, n) - min(violentCrime, n)) / 1000000;

		if (VC > 0) 
		{
			cout << "Violent Crime trend is up" << endl;
		}
		else 
		{
			cout << "Violent Crime trend is down" << endl;
		}

		// Q3 print the GTA number accurate to 0 decimal places

		cout << fixed;
		cout << "There are " << setprecision(2) << average(grandTheftAuto, n) / 1000000 << " million Grand Theft Auto incidents on average a year" << endl;

		// Q4. Print the min and max violentCrime rates

		cout << "The Minimum Violent Crime rate was " << setprecision(0) << min(violentCrimeRate, n) << endl;
		cout << "The Maximum Violent Crime rate was " << setprecision(0) << max(violentCrimeRate, n) << endl;

	}
}