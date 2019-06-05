#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//Functions
//This function sets second num to default of 0 defaults should always come after flexible numbers
int addNumbers(int firstNum, int secondNum = 0)
{
    return firstNum + secondNum;
}

int addNumbers(int firstNum, int secondNum, int thirdNum)
{
    return firstNum + secondNum + thirdNum;
}

//Recursive function calls itself multiple times to perform a function till meets paramneter to return number
int getFactorial(int number)
{
    int sum;
    if(number == 1) sum = 1;
    else sum = getFactorial(number -1) * number;
    return sum;
}

void ifsAndSwitches()
{
    //Ifs And Switches
    int age = 70;
    int ageAtlastExam = 18;
    bool isNotDrunk = true;

    //Cant drive too youngg
    if((age >= 1) && (age < 18))
    {
        cout << "You Cant Drive" << endl;
    }
        // if drunk you cant drive (Duh)
    else if (!isNotDrunk)
    {
        cout << "You Cant Drive" << endl;
    }
        // if they are older than 80 and havnt had an eye test in the last 5 years they can drive but if over 100 they cant drive
    else if(age>= 80 && ((age > 100) || ((age - ageAtlastExam) > 5)))
    {
        cout << "You Cant Drive" << endl;
    }
    else
    {
        cout << "You Can Drive" << endl;
    }


    //Switch statement

    int greetingOption = 2;

    switch(greetingOption)
    {
        case 1:
            cout << "Bonjour" << endl;
            break;
        case 2:
            cout << "Hola" << endl;
            break;
        case 3:
            cout << "Dia Duit" << endl;
            break;
        default:
            cout << "Hello" << endl;
    }
}

void basics()
{
    //endl ends the line
    cout << "Hello, World!" << endl;
    cout << "HI";
    cout << "HIII" << endl;


    //Variables
    //You cann creates constants
    const double PI = 3.1415926535;

    //Basic Variables same as java(Within Reason)
    char myGrade = 'A';
    bool isOn = false;
    float Number = 3.12345;
    double OtherNumber = 1.3214544;
    string newString = "STRINGS";

    cout << "String : " << newString <<endl;
    cout << "Grade : " << myGrade <<endl;

    int five = 5;

    //Can have operaters like ++,-- results change based on if operator is before or aft6er the variable
    five--;
    cout << five << endl;

}

void terniaryOperator()
{
    //Terniary Operator
    /* Basic Format:
     * Variable = (condition) ? true : false;
     * if contion is true the value will be what is in the true position and vice versa
     */
    //if 5 is greater than 2 the number will be 5 otherwise it will be 2
    int largestNum = (5>2) ? 5 : 2;
    cout << largestNum << endl;

}

void loops()
{

    //Arrays

    //Basic arrays declare size beforehand
    int myNumbers[5];
    int badNumbers[5] = {4,13,14,24,34};

    //Starts from zero goes to size minus one
    cout << "Bad Number 1: "<< badNumbers[0] << endl;

    //Multidimensional array
    char myName[5][5] = {{'D','E', 'R','E','K'}, {'B','A','N','A','S'}};

    cout << "Second Letter In Second Array " << myName[1][1] <<endl;

    myName[0][2] = 'E';
    cout << "New Value : " << myName[0][2];
    //For Loops
    for(int i = 1; i <= 10; i++)
    {
        cout << i << endl;
    }

    //Nested For Loops
    for(int j = 0; j <2; j++ )
    {
        for(int k = 0; k<5; k++)
        {
            cout << myName[j][k];
        }
        cout << endl;
    }

    //While Loops

    //THis is how you get random numbers in C++
    int randNum = (rand()%100) + 1;
    //Loop will keep runninng if number does not equal 100
    while(randNum != 100)
    {

        cout << randNum << ", ";
        randNum = (rand() % 100) +1;


    }
    cout << randNum;
    cout << endl;



    // Do While Loop
    string numberGuessed;
    int intNumberGuessed = 0;

    do{
        cout << "Guess Number Between 1 and 10" << endl;

        //This allows you to get user Input, cin is keybpoard and numberguessed is the string it will be assigned to
        getline(cin, numberGuessed);

        intNumberGuessed = stod(numberGuessed);

        cout << "Number Guessed : " << numberGuessed << endl;
    }while(intNumberGuessed != 4);

    cout << "You Win" << endl;
}


void learnStrings()
{
    //Strings
    string birthday = "Birthday";
    string happy = "Happy";

    cout << happy << " " << birthday << endl;

    string name;
    getline(cin, name);
    cout << "Hello " << name << endl;
    cout << "Size of Name : " << name.size() << endl;


    //to create a substring
    string fullName = "Derek Banas";
//    string firstName = fullName.assign(fullName,0,5);
//    cout << firstName << endl;

    //find something in string
    int lastnameIndex = fullName.find("Banas",0);
    cout << "Last Name Index : " << lastnameIndex << endl;

    //Insert somehting into string
    fullName.insert(5," justin");
    cout << "Insert Into String : " << fullName << endl;

    //delete from string
    fullName.erase(6,7);
    cout << fullName <<endl;

}

void vectors()
{
    //Vectors
    vector <int> lotteryNumbers(10);
    int lotteryNumArray[5] = {14,25,34,54,39};

    // Only takes first 3 numbers from num array
    lotteryNumbers.insert(lotteryNumbers.begin(),lotteryNumArray,lotteryNumArray+3);

    cout << lotteryNumbers.at(2)<< endl;

    //Adds to back of vector
    lotteryNumbers.push_back(64);

    //Gets Number from last can also use .front to get first
    cout << lotteryNumbers.back() << endl;
}

void functionLesson()
{
    cout << "Functions" << endl;
    cout << addNumbers(2)<< endl;
    cout << addNumbers(2,5) << endl;

    cout << "OverLoad Function" << endl;
    cout << addNumbers(2,3,4) << endl;

    cout << "Factorial of 3 is " << getFactorial(3) <<endl;
}

void fileIO()
{
    //File I/O
    cout << endl;
    cout << "File I/O" << endl;

    string steveQuote = " A Day without sunshine is night";

    ofstream writer ("SteveQuote.txt");
    if(! writer)
    {
        cout << "Error Opening file" << endl;
    }
    else
    {
        //Simply call the writer like youd call cout
        writer << steveQuote << endl;
        writer.close();
    }

    //open another writer and append to what is already in the text file instead of creating a fresh one
    ofstream writer2("SteveQuote.txt", ios::app);

    if(! writer2)
    {
        cout << "Error Opening file" << endl;
    }
    else
    {
        //Simply call the writer like youd call cout
        writer2 << "\n -Hello My Baby" << endl;
        writer2.close();
    }

    //reading from file
    char letter;
    ifstream reader("SteveQuote.txt");

    if(! reader)
    {
        cout << "Error opening file" << endl;
    }
    else
    {
        for(int i = 0; ! reader.eof(); i++)
        {
            reader.get(letter);
            cout <<letter;
        }

        cout << endl;
    }

}

int main() {

//    basics();
//    terniaryOperator();
//    loops();
//    learnStrings();
//    vectors();
//    functionLesson();
    fileIO();

    //Exception handling uses try catch

    return 0;
}



















