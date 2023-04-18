#include <iostream>
#include <fstream>

using namespace std;
int solution1();
int solution2();

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main()
{
    int firstPart = solution1();
    int secondPart = solution2();
    cout << "Part 1: " << firstPart << endl << "Part 2: " << secondPart << endl;
    
    return 0;
}

int solution1() {
    int myHand = 0;
    int opponentsHand = 0;
    int solutionPart1 = 0;
    ifstream InputFile;
    InputFile.open("Input/input.txt",ios::in);
    char c;

    if(InputFile.is_open()) 
    {
        while(InputFile.good()) 
        {
            InputFile.get(c);
            if (c == ' ')
                continue;
            
            if(c == 'A')
                opponentsHand = ROCK;
            if(c == 'B')
                opponentsHand = PAPER;
            if(c == 'C')
                opponentsHand = SCISSORS;

            if(c == 'X')
                myHand = ROCK;
            if(c == 'Y')
                myHand = PAPER;
            if(c == 'Z')
                myHand = SCISSORS;

            
            
            if(c == '\n')
            {
                //****************************************
                if((myHand == ROCK) && (opponentsHand == ROCK))
                {
                    solutionPart1 += myHand;
                    myHand = 0;
                    opponentsHand = 0;
                }
                else if((myHand == ROCK) && (opponentsHand == PAPER))
                {
                    solutionPart1 += myHand;
                    myHand = 0;
                    opponentsHand = 0;
                
                }
                else if((myHand == ROCK) && (opponentsHand == SCISSORS))
                {
                    myHand += 6;
                    solutionPart1 += myHand;
                    myHand = 0;
                    opponentsHand = 0;
                }
                //****************************************
                if((myHand == PAPER) && (opponentsHand == PAPER))
                {
                    myHand += 3;
                    solutionPart1 += myHand;
                    myHand = 0;
                    opponentsHand = 0;
                }
                else if((myHand == PAPER) && (opponentsHand == SCISSORS))
                {
                    solutionPart1 += myHand;
                    myHand = 0;
                    opponentsHand = 0;
                
                }
                else if((myHand == PAPER) && (opponentsHand == ROCK))
                {
                    myHand += 6;
                    solutionPart1 += myHand;
                    myHand = 0;
                    opponentsHand = 0;
                }
                //****************************************
                if((myHand == SCISSORS) && (opponentsHand == SCISSORS))
                {
                    myHand += 3;
                    solutionPart1 += myHand;
                    myHand = 0;
                    opponentsHand = 0;
                }
                else if((myHand == SCISSORS) && (opponentsHand == ROCK))
                {
                    solutionPart1 += myHand;
                    myHand = 0;
                    opponentsHand = 0;
                
                }
                else if ((myHand == SCISSORS) && (opponentsHand == PAPER))
                {
                    myHand += 6;
                    solutionPart1 += myHand;
                    myHand = 0;
                    opponentsHand = 0;
                }
                //****************************************
            }
        }
    }

    if(!InputFile.eof() && InputFile.fail())
        cout << "error reading file" << endl;

    InputFile.close();
    return solutionPart1;
}

int solution2() {
    int myHand = 0;
    int opponentsHand = 0;
    int solutionPart2 = 0;
    ifstream InputFile;
    InputFile.open("Input/input.txt",ios::in);
    char c;

    if(InputFile.is_open()) 
    {
        while(InputFile.good()) 
        {
            InputFile.get(c);
            if (c == ' ')
                continue;
            
            if(c == 'A')
                opponentsHand = ROCK;
            if(c == 'B')
                opponentsHand = PAPER;
            if(c == 'C')
                opponentsHand = SCISSORS;

            if(c == 'X')
                myHand = ROCK;
            if(c == 'Y')
                myHand = PAPER;
            if(c == 'Z')
                myHand = SCISSORS;

            
            
            if(c == '\n')
            {
                //****************************************
                if(myHand == ROCK)
                {
                    if(opponentsHand == PAPER)
                    {
                        myHand = ROCK;
                        solutionPart2 += myHand;
                        myHand = 0;
                        opponentsHand = 0;
                    }
                    else if(opponentsHand == ROCK)
                    {
                        myHand = SCISSORS;
                        solutionPart2 += myHand;
                        myHand = 0;
                        opponentsHand = 0;
                    }
                    else if(opponentsHand == SCISSORS)
                    {
                        myHand = PAPER;
                        solutionPart2 += myHand;
                        myHand = 0;
                        opponentsHand = 0;
                    }
                }
                //****************************************
                if(myHand == PAPER)
                {
                    if(opponentsHand == PAPER)
                    {
                        myHand = PAPER;
                        solutionPart2 += myHand;
                        solutionPart2 += 3;
                        myHand = 0;
                        opponentsHand = 0;
                    }
                    else if(opponentsHand == ROCK)
                    {
                        myHand = ROCK;
                        solutionPart2 += myHand;
                        solutionPart2 += 3;
                        myHand = 0;
                        opponentsHand = 0;
                    }
                    else if(opponentsHand == SCISSORS)
                    {
                        myHand = SCISSORS;
                        solutionPart2 += myHand;
                        solutionPart2 += 3;
                        myHand = 0;
                        opponentsHand = 0;
                    }
                }
                //****************************************
                if(myHand == SCISSORS)
                {
                    if(opponentsHand == PAPER)
                    {
                        myHand = SCISSORS;
                        solutionPart2 += myHand;
                        solutionPart2 += 6;
                        myHand = 0;
                        opponentsHand = 0;
                    }
                    else if(opponentsHand == ROCK)
                    {
                        myHand = PAPER;
                        solutionPart2 += myHand;
                        solutionPart2 += 6;
                        myHand = 0;
                        opponentsHand = 0;
                    }
                    else if(opponentsHand == SCISSORS)
                    {
                        myHand = ROCK;
                        solutionPart2 += myHand;
                        solutionPart2 += 6;
                        myHand = 0;
                        opponentsHand = 0;
                    }
                }
                //****************************************
            }
        }
    }

    
    if(!InputFile.eof() && InputFile.fail())
        cout << "error reading file" << endl;

    InputFile.close();
    return solutionPart2;
}