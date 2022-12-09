#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int solution1();
int solution2();

int main()
{
    int firstPart = solution1();
    //int secondPart = solution2();
    cout << "Part 1: " << firstPart << endl;
    //cout << "Part 2: " << secondPart << endl;
    
    return 0;
}

int solution1() 
{
    int i;
    int x;
    int solutionPart1 = 0;
    ifstream InputFile;
    string elfRucksack;
    InputFile.open("Input/input.txt",ios::in);
    
    if(InputFile.is_open()) 
    {
        while(getline(InputFile,elfRucksack)) 
        {
            //If the string is empty jump to next while iteration
            if(elfRucksack == "")  
            {
                continue;
            }

            int fullStrLgth = elfRucksack.size();
            //Split up the two strings into their own variables
            string firstCompartment = elfRucksack.substr(0, fullStrLgth / 2);
            string secondCompartment = elfRucksack.substr(fullStrLgth / 2, fullStrLgth);
            
            //Loop thru both strings char by char to find a matching pair
            for (int i = 0; i <= fullStrLgth / 2; i++) 
            {
                for(int x = 0; x <= fullStrLgth / 2; x++)
                {
                    if(firstCompartment[i] == secondCompartment[x])
                    {
                        //If char is less than 'a' its a uppercase char
                        if(firstCompartment[i] < 'a')
                            //A-Z represents the score of 27-52
                            solutionPart1 += firstCompartment[i] - 'A' + 27;
                        //if char is not less than 'a' its a lowercase char
                        else
                            //a-z represents the score of 1-26
                            solutionPart1 += firstCompartment[i] - 'a' + 1;
                        //Exit both for loops
                        i = fullStrLgth / 2;
                        x = fullStrLgth / 2;
                    }
                }
                
            }
        }
        //Close file and return the awnser to our problem :)
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