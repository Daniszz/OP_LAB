

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
class Comparator
{
public:
	bool operator()(const pair<string, int>& a, const pair <string, int>& b)
	{
		if (a.second != b.second)
			return a.second < b.second;
		else
			return a.first > b.first;
	}
};
int main()
{
	ifstream f("1.txt");
	string input;
	if (!getline(f, input))
	{
		cout << "Eroare";
		return 0;
	}
	//cout << input;
	map<string, int> count;
	string sep(" ,?!.");
	string copie;
	int ff = input.find_first_of(sep);
	int lf = 0;
	
	while (ff != std::string::npos)
	{
		if (ff != lf)
		{
			copie = input.substr(lf, ff - lf);
			
				transform(copie.begin(), copie.end(), copie.begin(), ::tolower);
			
		
			count[copie]++;
			
		}
		lf = ff + 1;
		ff = input.find_first_of(sep, lf);
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, Comparator> p;
	for (auto x : count)
	{
		p.push(make_pair(x.first, x.second));
	}
	while (p.size())
	{
		pair<string, int> c = p.top();
		cout << c.first << " => " << c.second << endl;
		p.pop();
	}

	return 0;
}

