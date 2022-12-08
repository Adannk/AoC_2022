#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int solution1();
int solution2();

int main()
{
    
    int firstPart = solution1();
    int secondPart = solution2();
    cout << "Part 1: " << firstPart << endl;
    cout << "Part 2: " << secondPart << endl;
    
    
    return 0;
}
int solution1() 
{
    int solutionPart1 = 0;
    ifstream InputFile;
    InputFile.open("Input/input.txt",ios::in);
    string line;

    if(InputFile.is_open()) 
    {
        while(getline(InputFile,line)) 
        {
            int i = 0;
            int x = 0;
            string firstLineFromTxtFile = line.c_str();
            if(firstLineFromTxtFile == "")
            {
                continue;
            }
            int fullStringSize = firstLineFromTxtFile.size();
            string firstSubString = firstLineFromTxtFile.substr(0, fullStringSize / 2);
            string secondSubString = firstLineFromTxtFile.substr(fullStringSize / 2, fullStringSize);
            
            for (int i = 0; i <= fullStringSize / 2; i++) 
            {
                for(int x = 0; x <= fullStringSize / 2; x++)
                {
                    if(firstSubString[i] == secondSubString[x])
                    {
                        if(firstSubString[i] < 'a')
                            solutionPart1 += firstSubString[i] - 'A' + 27;
                        else
                            solutionPart1 += firstSubString[i] - 'a' + 1;
                        i = fullStringSize / 2;
                        x = fullStringSize / 2;
                    }
                }
                
            }
        }
        InputFile.close();
        return solutionPart1;
    }

    else
        cout << "Error reading file" << endl;

    return solutionPart1;
}
int solution2() 
{
    int solutionPart2 = 0;
    ifstream InputFile;
    InputFile.open("Input/input.txt",ios::in);
    string line;
    InputFile.close();
    
    return solutionPart2;
}