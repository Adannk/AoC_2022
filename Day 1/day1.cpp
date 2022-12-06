#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
vector<int> solution();

int main()
{
    vector<int> totalCaloriesPerElv = solution();

	sort(totalCaloriesPerElv.begin(), totalCaloriesPerElv.end(), greater<int>());

	int topThreeElvs = totalCaloriesPerElv[0] + totalCaloriesPerElv[1] + totalCaloriesPerElv[2];
	
	cout << totalCaloriesPerElv[0] << endl;
    cout << topThreeElvs;
    
    return 0;
}

vector<int> solution()
{
	vector<int> totalCaloriesPerElv;
    int currentElvCalories = 0;
    ifstream InputFile;

	string line;
    InputFile.open("Input/input.txt",ios::in);
	if (InputFile.is_open())
	{
		while (getline(InputFile,line))
		{
			int currentCalories = atoi(line.c_str());

			if (currentCalories == 0) 										//if atoi fails and fins \n add currentElvCalories to vector of total Calories per Elv
			{																
				totalCaloriesPerElv.push_back(currentElvCalories);
				currentElvCalories = 0;										//Reset currentElvCalories
				continue;													
			}
			currentElvCalories += currentCalories;							//if atoi succeeds add that line from file to currentElvCalories
		}

		InputFile.close();													//Close file after loading our list
	}

	else
	{
		cout << "Error reading file";
	}

    return totalCaloriesPerElv;												//Return list
}