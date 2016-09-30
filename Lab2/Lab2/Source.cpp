#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool testUpdateTopScore();

vector<int> my_sort(vector<int> &in) //two loop sorting
{
	for (int i = 0; i < in.size(); i++)
	{
		for (int j = 0; j < in.size() - 1; j++)
		{
			if (in[j] < in[j + 1])
			{
				int temp = in[j];
				in[j] = in[j + 1];
				in[j + 1] = temp;
			}
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
	vector<int> topScores = { 443, 439, 438, 438, 434, 418, 418, 417, 413, 411, 444 };
	vector<int> topScores_sorted;
	updateTopScores(topScores, topScores_sorted);

	for (int i = 0; i < topScores_sorted.size(); i++)
	{
		cout << topScores_sorted[i] << " , ";//print sorted vector
	}

	cout << endl;
	//test case
	for (int i = 0; i < 5; i++)
	{
		cout << testUpdateTopScore() << endl;
	}

}


/////////////////test///////////////

bool testUpdateTopScore()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}

	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(arr[i]);
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