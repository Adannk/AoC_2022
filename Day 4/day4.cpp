#include <iostream>
#include <fstream>

using namespace std;
pair<int, int> solution();
int solution2();
bool isContained(pair<int, int> firstPair, pair<int, int> secondPair);
bool overlap(pair<int, int> firstPair, pair<int, int> secondPair);

int main()
{
    pair<int, int> result = solution();
    cout << "Part 1: " << result.first << endl;
    cout << "Part 2: " << result.second << endl;
    
    return 0;
}

pair<int, int> solution()
{
    ifstream InputFile;
    string firstSet;
    string secondSet;
    InputFile.open("Input/input.txt",ios::in);
    pair<int, int> fN;
    pair<int, int> sN;
    pair<int, int> solution;
    if(InputFile.is_open()) 
    {
        while(getline(InputFile,firstSet, ',') && getline(InputFile, secondSet)) 
        {
            int firstDeli = firstSet.find('-');
            int secondDeli = secondSet.find('-');
            int firstEnd = firstSet.find('\n');
            int secondEnd = secondSet.find('\n');

            fN.first = stoi(firstSet.substr(0, firstDeli));
            fN.second = stoi(firstSet.substr(firstDeli + 1, firstEnd));

            sN.first = stoi(secondSet.substr(0, secondDeli));
            sN.second = stoi(secondSet.substr(secondDeli + 1, secondEnd));

            if(isContained(fN, sN))
                solution.first++;
            if(overlap(fN, sN))
                solution.second++;
        }
    }
    else
        cout << "Error reading file" << endl;

    

    return solution;
}

bool isContained(pair<int, int> firstPair, pair<int, int> secondPair)
{
    if((firstPair.first <= secondPair.first) && (firstPair.second >= secondPair.second) || 
        (firstPair.first >= secondPair.first) && (firstPair.second <= secondPair.second))
            return true;
    else
        return false;
}

bool overlap(pair<int, int> firstPair, pair<int, int> secondPair)
{
    if((firstPair.first <= secondPair.second) && (secondPair.first <= firstPair.second))
            return true;
    else
        return false;
}