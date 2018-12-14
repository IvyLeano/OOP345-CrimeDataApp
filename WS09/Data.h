/* W09
* Data.h
* Ivy Leano
*/

#include<iostream>
#include<iomanip>
#include<string>
#include <cstring>
using namespace std;

namespace sict 
{
	const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;

	template<class T>
	T min(const T * data, int n)
	{
		T min;

		for (int i = 1; i < n; i++) 
		{
			min = data[0];
			if (data[i] < min) 
			{
				min = data[i];
			}
		}

		return min;
	}

	template<class T>
	T max(const T * data, int n)
	{
		T max;

		for (int i = 1; i < n; i++) 
		{
			max = data[0];
			if (data[i] > max) 
			{
				max = data[i];
			}
		}

		return max;
	}

	template<class T>
	T sum(const T * data, int n)
	{
		T sum = data[0];

		for (int i = 1; i < n; i++) 
		{
			sum += data[i];
		}

		return sum;
	}

	template<class T>
	double average(const T * data, int n)
	{
		T avg = sum(data, n) / n;
		return avg;
	}

	template<class T>
	bool read(std::istream & input, T * data, int n)
	{
		int x = 0;

		for (int i = 0; i < n; i++) 
		{
			input.ignore();
			input >> data[i];
			if (input.fail()) 
			{
				x = 1;
			}
		}

		return (x == 0);
	}

	template<class T>
	void display(const char * name, const T * data, int n)
	{
		cout << setw(20) << name;

		for (int i = 0; i < n; i++) 
		{
			cout << setw(COLUMN_WIDTH) << data[i];
		}
		cout << endl;
	}

	template<class T>
	T readRow(std::istream& input, const char* name, T* data, int n)
	{
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) 
		{
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int* year, const int* population, const int* violentCrime, const double* violentCrimeRate, const int* grandTheftAuto, const int n);
}


