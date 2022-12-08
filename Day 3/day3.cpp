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
            //If the string is empty skip this while itteration
            if(elfRucksack == "")  
            {
                continue;
            }

            int fullStrLgth = elfRucksack.size();
            string firstCompartment = elfRucksack.substr(0, fullStrLgth / 2);
            string secondCompartment = elfRucksack.substr(fullStrLgth / 2, fullStrLgth);
            
            //Loop threw both strings
            for (int i = 0; i <= fullStrLgth / 2; i++) 
            {
                for(int x = 0; x <= fullStrLgth / 2; x++)
                {
                    //If you find a matching char add the "score" to solutionPart1
                    if(firstCompartment[i] == secondCompartment[x])
                    {
                        //If char is lesser then 'a' its a uppercase char
                        if(firstCompartment[i] < 'a')
                            //A-Z represents the score of 27-52
                            solutionPart1 += firstCompartment[i] - 'A' + 27;
                        //if its not lesser then 'a' its a lowercase char
                        else
                            // represents the score of 27-52
                            solutionPart1 += firstCompartment[i] - 'a' + 1;
                        i = fullStrLgth / 2;
                        x = fullStrLgth / 2;
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