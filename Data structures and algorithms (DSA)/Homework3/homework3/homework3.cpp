#include <iostream>
#include <sstream>
#include "interface.h"
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Invalid input!" << endl;
		return -1;
	}
	auto t1 = high_resolution_clock::now();
	ifstream a(argv[1]);
	ifstream b(argv[2]);

	Comparator c;
	ComparisonReport report;

	try
	{
		report = c.compare(a, b);

		cout << "file1 contains " << report.uniqueWords[0].countOfUniqueWords() + report.commonWords.countOfUniqueWords()
			<< " unique words and " << report.commonWords.countOfUniqueWords() << " from them are/is containing into file2(" <<
			(double)(100* report.commonWords.countOfUniqueWords())/(double)(report.uniqueWords[0].countOfUniqueWords() + report.commonWords.countOfUniqueWords()) 
			<< " %)" << endl;

		cout << "file2 contains " << report.uniqueWords[1].countOfUniqueWords() + report.commonWords.countOfUniqueWords()
			<< " unique words and " << report.commonWords.countOfUniqueWords() << " from them are/is containing into file1(" <<
			(double)(100 * report.commonWords.countOfUniqueWords()) / (double)(report.uniqueWords[1].countOfUniqueWords() + report.commonWords.countOfUniqueWords())
			<< " %)" << endl;

		//report.commonWords.print();
		//report.uniqueWords[0].print();
		//report.uniqueWords[1].print();
	}
	catch (const std::exception&)
	{
		cout << "There was error comparing two files." << endl;
	}
	auto t2 = high_resolution_clock::now();
	/* Getting number of milliseconds as an integer. */
	auto ms_int = duration_cast<milliseconds>(t2 - t1);

	/* Getting number of milliseconds as a double. */
	duration<double, std::milli> ms_double = t2 - t1;

	std::cout << ms_int.count() << "ms\n";
	std::cout << ms_double.count() << "ms\n";
}