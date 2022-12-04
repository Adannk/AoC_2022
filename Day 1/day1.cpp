#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
vector<int> readFromFile();
void part1_solution(vector <int>);
void part2_solution(vector <int>);

int main()
{
    vector<int> sonarM = readFromFile();
    
    
	
    
    
    return 0;
}

vector<int> readFromFile()
{
    vector <int> subMoving;
    ifstream readFromFile;
    string line;
    readFromFile.open("Input/input.txt",ios::in);
	if (readFromFile.is_open())
	{
		while (getline(readFromFile,line))
		{
			subMoving.push_back(stoi(line));
		}
		readFromFile.close();
	}
	else
	{
		cout << "Error reading file";
	}
    return subMoving;
}