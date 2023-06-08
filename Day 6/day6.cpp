#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

int solution1();
int solution2();

int main()
{
    int firstPart = solution1();
    int secondPart = solution2();
    cout << "Part 1: " << firstPart << endl;
    cout << "Part 2: " << secondPart << endl;
}

int solution1()
{
    ifstream InputFile;
    string line;
    int stringLength;
    InputFile.open("Input/input.txt",ios::in);
    if(InputFile.is_open()) 
    {
        getline(InputFile, line);
        InputFile.close();
        stringLength = line.length();
        char charArray[stringLength];
        for(int i = 0; i < stringLength; i++)
        {
            charArray[i] = line[i];
        }

        unordered_set <char> seenChars;

        for (int i = 3; i < stringLength; i++) 
        {
            seenChars.clear();
            for (int j = i - 3; j <= i; j++) {
                if (seenChars.find(charArray[j]) != seenChars.end()) 
                {
                    break;
                }
                seenChars.insert(charArray[j]);
            }
            if (seenChars.size() == 4) 
            {
                return i + 1;
            }
        }

        return -1;
    }

    else
        cout << "Error reading file" << endl;
}

int solution2()
{
    ifstream InputFile;
    string line;
    int stringLength;
    InputFile.open("Input/input.txt",ios::in);
    if(InputFile.is_open()) 
    {
        getline(InputFile, line);
        InputFile.close();
        stringLength = line.length();
        char charArray[stringLength];
        for(int i = 0; i < stringLength; i++)
        {
            charArray[i] = line[i];
        }

        unordered_set <char> seenChars;

        for (int i = 13; i < stringLength; i++) 
        {
            seenChars.clear();
            for (int j = i - 13; j <= i; j++) {
                if (seenChars.find(charArray[j]) != seenChars.end()) 
                {
                    break;
                }
                seenChars.insert(charArray[j]);
            }
            if (seenChars.size() == 14) 
            {
                return i + 1;
            }
        }

        return -1;
    }

    else
        cout << "Error reading file" << endl;
}