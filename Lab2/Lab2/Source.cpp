#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>


using namespace std;
using namespace std::chrono;

bool testUpdateTopScore(int);

vector<int> my_sort(vector<int> &in) 
{
	int j = 0;
	for (int i = 0;i<in.size() - 1;i++) //one for loop
	{
		if (in[i] < in[i + 1])
		{
			int temp = in[i];
			in[i] = in[i + 1];
			in[i + 1] = temp;
		}
		if (i == in.size() - 2)//reset index
		{
			i = -1;
			j++;
		}
		if (j == in.size() - 2)//end sorting
		{
			break;
		}
	}

	return in;
}

bool updateTopScores(vector<int> &in, vector<int> & out)
{
	out = my_sort(in);//call sort
	return true;
}

void main()
{
	
	//test case
	int a = 10;
	for (int i = 0; i < 5; i++)
	{
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		cout << testUpdateTopScore(a);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		std::cout << ":  It took  " << time_span.count() << " seconds  for "<<a<<" data " << endl;
		a *= 5;
	}

}


/////////////////test///////////////

bool testUpdateTopScore(int size)
{
	vector<int> vec;
	for (int i = 0; i < size; i++)
	{
		vec.push_back(rand() % 100 + 1);
	}


	sort(vec.rbegin(), vec.rend());


	vec.push_back(rand() % 100 + 1);

	vector<int> vec1(vec);

	sort(vec1.rbegin(), vec1.rend());

	vector<int> vec_sorted;

	updateTopScores(vec, vec_sorted);


	return (vec_sorted == vec1);
}

////////////////////////////////////