#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//to include a seperate file add the header
#include "team.h"
#include "mathsFunctions.cpp"
using namespace std;


class Animal
{
    private:
        int height;
        int weight;
        string name;

        static int numOfAnimals;

    public:
        int getHeight(){ return height;};
        int getWeight(){ return weight;};
        string getName() { return name;};
        void setHeight(int cm) { height = cm;};

        void setAll(int,int,string);

        Animal(int height, int weight ,string name)
        {
            this -> height = height;
            this -> weight = weight;
            this -> name = name;
            numOfAnimals++;
        };

        //deconstructor it is called when class is no longer in scope/use or it is called
        ~Animal()
        {
            cout << this->name << " Destroyed" << endl;
        };

        Animal()
        {
            this -> height = 0;
            this -> weight = 0;
            this -> name = "Susan";
            numOfAnimals++;
        };

        static int getNumOfAnimals() { return numOfAnimals;};
};

//Superclass

class Dog : public Animal
{
    private:
        string sound = "Woof";

    public:
    void getSound() { cout << this->getName() << " Says " << sound << endl;};

    Dog(int height, int weight, string name, string bark) : Animal(weight,height,name)
    {
        this -> sound = bark;
    }

};
class Car
{
    private:
        int weight;
        string brand;

        static int numOfCars;

    public:
        int getWeight() { return weight; };
        string getBrand() {return brand; };
    //functions can be declared in class but initialized outside even the constructor as seen here
    Car(int, string);

    ~Car();

    Car();

    void toString();
};

Car::Car(int weight, string brand) {
    this -> weight = weight;
    this -> brand = brand;
    Car::numOfCars++;
}
Car::Car() {
    this -> weight = 200;
    this -> brand = "Skoda";
    Car::numOfCars++;
}

Car::~Car() {
    cout << " Car Crashed" <<endl;
}
void Car::toString() {
    cout << "Brand " << this -> brand << endl;
    cout << "Weight " << this -> weight << endl;
}
int Car::numOfCars = 0;



int Animal::numOfAnimals = 0;

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

        //This allows you to get user Input, cin is keyboard and numberguessed is the string it will be assigned to
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
        //for each item in the reader as long as it is not end of file(eof)
        for(int i = 0; ! reader.eof(); i++)
        {
            reader.get(letter);
            cout <<letter;
        }

        cout << endl;
    }

}

void changeAge(int * age)
{
    cout << "I used to be " << *age << endl;

    *age = 21;
}

void pointers()
{
    int myAge = 39;
    char myGrade = 'A';

    //Determines how many bytes data takes up
    cout << " Size of Int " << sizeof(myAge) << endl;
    cout << " Size of Char " << sizeof(myGrade) << endl;

    //can reference where the bytes of data are stored with a reference operator which is &
    cout << "My age is located at: " << &myAge <<endl;

    //Pointers are used to have values change in functions even if the function does not return a new value
    /**
     *  int age = 5
     *
     *  addage(age)
     *
     *  in this main thread age is still 5 but in add age age has changed but has not been passed back eg age = addage(age)
     */
    //to create a pointer its using a star
    int* agePtr = &myAge;

    //Age Pointer now has reference to myAge
    cout << "Address of pointer " << agePtr <<endl;

    //You can now access the adat held at the address which will be 39
    cout << " Data at memory address: " << *agePtr << endl;

    //if you pass a pointer to a function the global value can be changed
    changeAge(agePtr);
    cout << myAge << endl;
}

void playingWithClasses()
{
    Animal hippo(200,200,"George");
    Animal tiger;

    cout << hippo.getName() << endl;
    cout << tiger.getName() << endl;

    Car micra(300, "Nissan");
    Car shitbox;

    cout << micra.getBrand() <<endl;
    cout << shitbox.getBrand() <<endl;

    micra.toString();


    Dog frodo(200,200, "george", "WOOOOOOF");

    frodo.getSound();

    cout << " Number Of Animals " << Animal::getNumOfAnimals() << endl;
}


void teamLeague()
{
    team manUnited("man U", "Red Devils");
    manUnited.chant();
    int num = addTwoNumbers(1,2);
    cout << num << endl;
};

int main() {

    cout << " 1.Basics " <<endl;
    cout << " 2.Terniary Operator " <<endl;
    cout << " 3.Loops " <<endl;
    cout << " 4.Strings " <<endl;
    cout << " 5.Vectors " <<endl;
    cout << " 6.Functions " <<endl;
    cout << " 7.FileIO " <<endl;
    cout << " 8.Pointers " <<endl;
    cout << " 9.Classes " <<endl;
    cout << " 10.External Files " <<endl;
    cout << " Please Choose option" <<endl;
    string numberGuessed;
    int intNumberGuessed = 0;
    getline(cin, numberGuessed);

    intNumberGuessed = stod(numberGuessed);


    switch(intNumberGuessed)
    {
        case 1:
            basics();
            break;
        case 2:
            terniaryOperator();
            break;
        case 3:
            loops();
            break;
        case 4:
            learnStrings();
            break;
        case 5:
            vectors();
            break;
        case 6:
            functionLesson();
            break;
        case 7:
            fileIO();
            break;
        case 8:
            pointers();
            break;
        case 9:
            playingWithClasses();
            break;
        case 10:
            teamLeague();
            break;
        default:
            cout << "Not option" << endl;
    }
//    basics();
//    terniaryOperator();
//    loops();
//    learnStrings();
//    vectors();
//    functionLesson();
//    fileIO();
//    pointers();
//    playingWithClasses();
//    teamLeague();
    //Exception handling uses try catch

    return 0;
}



















