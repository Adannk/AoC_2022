#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
vector<int> solution();

int main()
{
    vector<int> totalCaloriesPerElf = solution();
	
	sort(totalCaloriesPerElf.begin(), totalCaloriesPerElf.end(), greater<int>());

	int topThreeElfs = totalCaloriesPerElf[0] + totalCaloriesPerElf[1] + totalCaloriesPerElf[2];
	
	cout << totalCaloriesPerElf[0] << endl;
    cout << topThreeElfs;
    
    return 0;
}

vector<int> solution()
{
	vector<int> totalCaloriesPerElf;
    int currentElfCalories = 0;
    ifstream InputFile;

	string line;
    InputFile.open("Input/input.txt",ios::in);
	if (InputFile.is_open())
	{
		while (getline(InputFile,line))
		{
			int currentCalories = atoi(line.c_str());
			
			//if atoi find empy line
			if (currentCalories == 0) 										
			{
				//add currentElfCalories to totalCaloriesPerElf and Resets currentElfCalories
				totalCaloriesPerElf.push_back(currentElfCalories);
				currentElfCalories = 0;										
			}
			//if atoi is number
			else
			{	
				//add it to currentElfCalories
				currentElfCalories += currentCalories;
			}
										
		}

		InputFile.close();													//Close file after loading our list
	}

	else
	{
		cout << "Error reading file";
	}

    return totalCaloriesPerElf;												//Return list
}