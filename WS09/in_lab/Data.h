/*
Name: Alisa Tam
Student #: 131580177
Email: aabramovici@myseneca.ca
Section: OOP244 A
*/

#include <iomanip>

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	//
	template <typename T> double max(const T* data, int n) {
		T largest = static_cast<T>(SMALLEST_NUMBER);
		for (int i = 0; i < n; i++) {
			if (data[i] > largest) {
				largest = data[i];
			}
		}

		return static_cast<double>(largest);
	}


	// min returns the smallest item in data
	//
	template <typename T> double min(const T* data, int n) {
		T smallest = static_cast<T>(LARGEST_NUMBER);
		for (int i = 0; i < n; i++) {
			if (data[i] < smallest) {
				smallest = data[i];
			}
		}

		return static_cast<double>(smallest);
	}

        
	// sum returns the sum of n items in data
	//
	template <typename T>double sum(const T* data, int n) {

		double this_sum = 0;
		for (int i = 0; i < n; i++) {
			this_sum += static_cast<double>(data[i]);

		}

		return this_sum;
	}
   
	// average returns the average of n items in data
	//
	template<typename T> double average(const T* data, int n) {
		return sum(data, n) / static_cast<double>(n);
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template<typename T> bool read(std::istream& input, T* data, int n) {

		for (int i = 0; i < n; i++) {
			char comma;
			input >> comma >> data[i];

			if (input.fail()) {
				return false;
			}
		}

		return true;
	}
	// display inserts n items of data into std::cout
	//

	template<typename T> void display(const char* name, const T* data, int n) {
		std::cout << std::setw(20) << std::right << name;
		for (int i = 0; i < n; i++) {
			std::cout << std::setw(COLUMN_WIDTH) << std::right << data[i];
		}
		std::cout << std::endl;
	}

	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

