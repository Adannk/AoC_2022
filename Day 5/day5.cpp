#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>

using namespace std;

fstream& GotoLine(std::fstream& file, unsigned int num);
void solution1();
void solution2();

class Stack{
    private:
        int sz;
        int top;
        char *S;
    public:
        Stack(int size){
            sz = size;
            top = -1;
            S = new char[size];
        }
        ~Stack(){
            delete []S;
        }
        void push(char x);
        char pop();
        int isEmpty();
        char stackTop();
};

int main()
{
    solution1();
    solution2();

    return 0;
}

void Stack::push(char x){
    if (top == sz -1)
        std::cout<<"Stack overflow!\nVale: "<<x<<" didn't fit!\n";
    else{
        top++;
        S[top] = x;
    }
}

char Stack::pop(){
    char x = '\n';
    if (top == -1)
        std::cout<<"Stack underflow\n";
    else{
        x = S[top--];
    }
    return x;
}

int Stack::isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

char Stack::stackTop(){
    if(!isEmpty())
        return S[top];
    else
        return -1;
}

fstream& GotoLine(fstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

void solution1()
{
    fstream InputFile("Input/input.txt");
    string line;
    int stackIndex[9];
    class Stack stackOne(55);
    class Stack stackTwo(55);
    class Stack stackThree(55);
    class Stack stackFour(55);
    class Stack stackFive(55);
    class Stack stackSix(55);
    class Stack stackSeven(55);
    class Stack stackEight(55);
    class Stack stackNine(55);

    if(InputFile.is_open()) 
    {
        GotoLine(InputFile, 9);
        getline(InputFile, line);
        for(int i = 0; i < 9; i++)
        {
            int index = i + 1;
            stackIndex[i] = line.find(to_string(index));
        }
        
        int reverse = 8;
        for(int x = 0; x < 8; x++)
        {
            GotoLine(InputFile, reverse);
            getline(InputFile, line);
            if(line[stackIndex[0]] == ' ') ;
            else
                stackOne.push(line[stackIndex[0]]);
            if(line[stackIndex[1]] == ' ') ;
            else
                stackTwo.push(line[stackIndex[1]]);
            if(line[stackIndex[2]] == ' ') ;
            else
                stackThree.push(line[stackIndex[2]]);
            if(line[stackIndex[3]] == ' ') ;
            else
                stackFour.push(line[stackIndex[3]]);
            if(line[stackIndex[4]] == ' ') ;
            else
                stackFive.push(line[stackIndex[4]]);
            if(line[stackIndex[5]] == ' ') ;
            else
                stackSix.push(line[stackIndex[5]]);
            if(line[stackIndex[6]] == ' ') ;
            else
                stackSeven.push(line[stackIndex[6]]);
            if(line[stackIndex[7]] == ' ') ;
            else
                stackEight.push(line[stackIndex[7]]);
            if(line[stackIndex[8]] == ' ') ;
            else
                stackNine.push(line[stackIndex[8]]);
            
            reverse--;
        }

        GotoLine(InputFile, 11);
        while(getline(InputFile, line))
        {
            stringstream ss(line);
            string op, opValue;
            string src, srValue;
            string dest, desValue;
            pair<string, int> operation;
            pair<string, int> source;
            pair<string, int> destination;
            char tempChar;

            getline(ss, op, ' ');
            getline(ss, opValue, ' ');
            getline(ss, src, ' ');
            getline(ss, srValue, ' ');
            getline(ss, dest, ' ');
            getline(ss, desValue, '\n');
            
            operation = make_pair(op, stoi(opValue));
            source = make_pair(src, stoi(srValue));
            destination = make_pair(dest, stoi(desValue));

            for(int y = 0; y < operation.second; y++)
            {
                switch (source.second)
                {
                    case 1:
                        tempChar = stackOne.pop();
                        break;
                    case 2:
                        tempChar = stackTwo.pop();
                        break;
                    case 3:
                        tempChar = stackThree.pop();
                        break;
                    case 4:
                        tempChar = stackFour.pop();
                        break;
                    case 5:
                        tempChar = stackFive.pop();
                        break;
                    case 6:
                        tempChar = stackSix.pop();
                        break;
                    case 7:
                        tempChar = stackSeven.pop();
                        break;
                    case 8:
                        tempChar = stackEight.pop();
                        break;
                    case 9:
                        tempChar = stackNine.pop();
                        break;
                    default:
                        break;
                }

                switch (destination.second)
                {
                    case 1:
                        stackOne.push(tempChar);
                        break;
                    case 2:
                        stackTwo.push(tempChar);
                        break;
                    case 3:
                        stackThree.push(tempChar);
                        break;
                    case 4:
                        stackFour.push(tempChar);
                        break;
                    case 5:
                        stackFive.push(tempChar);
                        break;
                    case 6:
                        stackSix.push(tempChar);
                        break;
                    case 7:
                        stackSeven.push(tempChar);
                        break;
                    case 8:
                        stackEight.push(tempChar);
                        break;
                    case 9:
                        stackNine.push(tempChar);
                        break;
                    
                    default:
                        break;
                }
            }
        }
    }

    else
        std::cout << "Error reading file" << endl;
    
    std::cout << "Part 1: " << stackOne.stackTop() 
                        << stackTwo.stackTop() 
                        << stackThree.stackTop()
                        << stackFour.stackTop()
                        << stackFive.stackTop()
                        << stackSix.stackTop()
                        << stackSeven.stackTop()
                        << stackEight.stackTop()
                        << stackNine.stackTop() << endl;
}

void solution2()
{
        fstream InputFile("Input/input.txt");
    string line;
    int stackIndex[9];
    class Stack stackOne(55);
    class Stack stackTwo(55);
    class Stack stackThree(55);
    class Stack stackFour(55);
    class Stack stackFive(55);
    class Stack stackSix(55);
    class Stack stackSeven(55);
    class Stack stackEight(55);
    class Stack stackNine(55);
    class Stack tempStack(55);

    if(InputFile.is_open()) 
    {
        GotoLine(InputFile, 9);
        getline(InputFile, line);
        for(int i = 0; i < 9; i++)
        {
            int index = i + 1;
            stackIndex[i] = line.find(to_string(index));
        }
        
        int reverse = 8;
        for(int x = 0; x < 8; x++)
        {
            GotoLine(InputFile, reverse);
            getline(InputFile, line);
            if(line[stackIndex[0]] == ' ') ;
            else
                stackOne.push(line[stackIndex[0]]);
            if(line[stackIndex[1]] == ' ') ;
            else
                stackTwo.push(line[stackIndex[1]]);
            if(line[stackIndex[2]] == ' ') ;
            else
                stackThree.push(line[stackIndex[2]]);
            if(line[stackIndex[3]] == ' ') ;
            else
                stackFour.push(line[stackIndex[3]]);
            if(line[stackIndex[4]] == ' ') ;
            else
                stackFive.push(line[stackIndex[4]]);
            if(line[stackIndex[5]] == ' ') ;
            else
                stackSix.push(line[stackIndex[5]]);
            if(line[stackIndex[6]] == ' ') ;
            else
                stackSeven.push(line[stackIndex[6]]);
            if(line[stackIndex[7]] == ' ') ;
            else
                stackEight.push(line[stackIndex[7]]);
            if(line[stackIndex[8]] == ' ') ;
            else
                stackNine.push(line[stackIndex[8]]);
            
            reverse--;
        }

        GotoLine(InputFile, 11);
        while(getline(InputFile, line))
        {
            stringstream ss(line);
            string op, opValue;
            string src, srValue;
            string dest, desValue;
            pair<string, int> operation;
            pair<string, int> source;
            pair<string, int> destination;
            char tempChar;

            getline(ss, op, ' ');
            getline(ss, opValue, ' ');
            getline(ss, src, ' ');
            getline(ss, srValue, ' ');
            getline(ss, dest, ' ');
            getline(ss, desValue, '\n');
            
            operation = make_pair(op, stoi(opValue));
            source = make_pair(src, stoi(srValue));
            destination = make_pair(dest, stoi(desValue));

            for(int y = 0; y < operation.second; y++)
            {
                switch (source.second)
                {
                    case 1:
                        tempChar = stackOne.pop();
                        break;
                    case 2:
                        tempChar = stackTwo.pop();
                        break;
                    case 3:
                        tempChar = stackThree.pop();
                        break;
                    case 4:
                        tempChar = stackFour.pop();
                        break;
                    case 5:
                        tempChar = stackFive.pop();
                        break;
                    case 6:
                        tempChar = stackSix.pop();
                        break;
                    case 7:
                        tempChar = stackSeven.pop();
                        break;
                    case 8:
                        tempChar = stackEight.pop();
                        break;
                    case 9:
                        tempChar = stackNine.pop();
                        break;
                    default:
                        break;
                }
                tempStack.push(tempChar);
            }
            for(int z = 0; z < operation.second; z++)
            {
                tempChar = tempStack.pop();
                switch (destination.second)
                {
                    case 1:
                        stackOne.push(tempChar);
                        break;
                    case 2:
                        stackTwo.push(tempChar);
                        break;
                    case 3:
                        stackThree.push(tempChar);
                        break;
                    case 4:
                        stackFour.push(tempChar);
                        break;
                    case 5:
                        stackFive.push(tempChar);
                        break;
                    case 6:
                        stackSix.push(tempChar);
                        break;
                    case 7:
                        stackSeven.push(tempChar);
                        break;
                    case 8:
                        stackEight.push(tempChar);
                        break;
                    case 9:
                        stackNine.push(tempChar);
                        break;
                    
                    default:
                        break;
                }
            }
        }
    }

    else
        std::cout << "Error reading file" << endl;
    
    std::cout << "Part 2: " << stackOne.stackTop() 
                        << stackTwo.stackTop() 
                        << stackThree.stackTop()
                        << stackFour.stackTop()
                        << stackFive.stackTop()
                        << stackSix.stackTop()
                        << stackSeven.stackTop()
                        << stackEight.stackTop()
                        << stackNine.stackTop() << endl;
}