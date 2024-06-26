#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <random>
#include <unordered_map>
#include <cctype>
#include <unistd.h>

using namespace std;

ifstream openInputFile(const string &);

ofstream openOutputFile(const string &);

int randomNumber(int);

bool found(int *, int, int);

void displayQuestion(string &);

string operator+(const string &, int);

void start(string);

void option();

int main();

class Flashcard 
{
    public:
    string file_name;
    int question_number;
    char tag;
    
    public:
    //default constructor
    Flashcard() 
    {
        file_name = "/home/kartik/Desktop/College/SDF2/";
        question_number = 0;
        tag = ' ';
    }
    
    //sets the question number
    void setQuestionNumber(int number) 
    {
        question_number = number;
    }

    //searches for the question and returns it
    string findQuestion() 
    {
        ifstream file = openInputFile(file_name);
        string line, question;
        int index = 0;
        while(getline(file, line) && index <= question_number) 
        {
            if(line.at(0) == tag)
                index++;
            question = line;
        }
        file.close();
        return question;
    }

    //returns the answer
    string findAnswer(const string &question) 
    {
        ifstream file = openInputFile(file_name);
        string line, answer = "";
        while(getline(file, line)) 
        {
            if(line.find(question) != string::npos) 
            {
                getline(file, line);
                answer = line;
            }
        }
        file.close();
        return answer;
    }

    //asks the user to enter the file
    void getFileName() 
    {
        string name;
        cout << "Please enter the file name: ";
        cin >> name;
        file_name = file_name + name;
    }

    //total number of questions in a file
    int totalNumberOfQuestions() 
    {
        ifstream file = openInputFile(file_name);
        string line;
        int count = 0;
        while(getline(file, line)) 
        {
            if(line.at(0) == tag)
                count++;
        }
        file.close();
        return count;
    }

    //gives a random sequence of questions
    int *randomSequence() 
    {
        int size = totalNumberOfQuestions();
        int *array = new int[size]();
        int number = 0;
        for(int index = 0; index < size; index++) 
        {
            number = randomNumber(size);
            if(!found(array, number, index))
                array[index] = number;
            else 
            {
                index--;
                continue;
            }
        }
        return array;
    }

    virtual void add(const string &name) = 0;
};

//returns the file in read mode
ifstream openInputFile(const string &name) 
{
    ifstream file(name);
    if(!file.is_open()) 
        throw runtime_error("Error opening file at location: " + name);
    return file;
}

//returns the file in append mode
ofstream openOutputFile(const string &name) 
{
    ofstream file(name, ios::app);
    if(!file.is_open()) 
        throw runtime_error("Error opening file at location: " + name);
    return file;
}

//checks if the a question is already asked or not
bool found(int *array, int search, int size) 
{
    for(int index = 0; index < size; index++) 
    {
        if(array[index] == search)
            return true;
    }
    return false;
}

//generates a random number between 0 and maximum
int randomNumber(int maximum) 
{
    srand(time(nullptr));
    return rand() % maximum;
}

//formats the question before question
void displayQuestion(string &question) 
{
    int index = question.find(" ");
    if(index == string::npos) 
        throw ("Error displaying");
    cout << question.substr(index + 1) << endl;
}

//concatenates a string and a number
string operator+(const string &name, int number) 
{
    return name + to_string(number);
}

class Standard : public Flashcard 
{
    private:
    string question;
    string answer;

    public:
    //default constructor
    Standard() 
    {
        question = "";
        answer = "";
        tag = 'Q';
        file_name = "/home/kartik/Desktop/College/SDF2/Standard/";
    }

    //gets a randomNumber question from the file
    void getQuestion() 
    {
        getFileName();
        string input;
        int size = totalNumberOfQuestions();
        int *array = new int[size];
        array = randomSequence();
        for(int index = 0; index < size; index++) 
        {
            question_number = array[index];
            question = findQuestion();
            displayQuestion(question);
            cin >> input;
            if(input == "exit") 
            {
                cout << "Thank you" << endl;
                exit(0);
            }
            answer = findAnswer(question);
            if(answer == input)
                cout << "Correct" << endl;
            else 
                cout << "Wrong" << endl;
        }
        delete [] array;
    }

    //adds a new question to the file
    void add(const string &name) 
    {
        system("clear");
        ofstream file = openOutputFile(name);
        string line;
        //clear the buffer before the input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter the question: ";
        getline(cin, line);
        file << "Q: " << line << endl;
        cout << "Please enter the answer: ";
        getline(cin, line);
        file << line << endl;
        file.close();
        cout << "Successful" << endl;
    }
};

class BothSide : public Flashcard 
{
    private:
    string *side;

    public:
    //default constructor
    BothSide() 
    {
        side = new string[2]();
        tag = '1';
        file_name = "/home/kartik/Desktop/College/SDF2/BothSide/";
    }

    //gets a randomNumber question from the file
    void getQuestion() 
    {
        getFileName();
        string input;
        int size = totalNumberOfQuestions();
        int *array = new int[size];
        array = randomSequence();
        for(int index = 0; index < size; index++) 
        {
            question_number = array[index];
            side[0] = findQuestion();
            displayQuestion(side[0]);
            cin >> input;
            if(input == "exit") 
            {
                cout << "Thank you" << endl;
                exit(0);
            }
            side[1] = findAnswer(side[0]);
            if(side[1] == input)
                cout << "Correct" << endl;
            else
                cout << "Wrong" << endl;
        }
        delete [] array;
    }       

    //adds a sides to the file
    void add(const string &name) 
    {
        system("clear");
        ofstream file = openOutputFile(name);
        string line;
        //clear the buffer before the input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter the side 1: ";
        getline(cin, line);
        file << "1: " << line << endl;
        cout << "Please enter the side 2: ";
        getline(cin, line);
        file << "2: " << line << endl;
        file.close();
        cout << "Successful" << endl;
    }

    //destructor
    ~BothSide() 
    {
        delete [] side;
    }
};

class TrueFalse : public Flashcard 
{
    private:
    string statement, isTrue;

    public:
    //default constructor
    TrueFalse() 
    {
        statement = "";
        isTrue = true;
        tag = 'S';
        file_name = "/home/kartik/Desktop/College/SDF2/TrueFalse/";
    }

    //gets a randomNumber question from the file
    void getQuestion() 
    {
        getFileName();
        int size = totalNumberOfQuestions();
        int *array = new int[size];
        array = randomSequence();
        string input;
        for(int index = 0; index < size; index++) 
        {
            question_number = array[index];
            statement = findQuestion();
            displayQuestion(statement);
            cin >> input;
            if(input == "exit") 
            {
                cout << "Thank you" << endl;
                exit(0);
            }
            isTrue = findAnswer(statement);
            if(isTrue == input)
                cout << "Correct" << endl;
            else
                cout << "Wrong" << endl;
        }
        delete [] array;
    }

    //adds a statement to the file
    void add(const string &name) 
    {
        system("clear");
        ofstream file = openOutputFile(name);
        string line;
        //clear the buffer before the input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a statement: ";
        getline(cin, line);
        file << "S: " << line << endl;
        cout << "Please enter whether the statement is true or false: ";
        getline(cin, line);
        file << line << endl;
        file.close();
        cout << "Successful" << endl; 
    }
};

class Deck : private Standard, private BothSide, private TrueFalse 
{
    private:
    vector <string> files_used;
    vector <Flashcard*> cards;
    int *sequence;
    string question, answer, deck_name, temporary_file, temporary_file_name;
    static int counter; 
    unordered_map<string, string> pair;

    public:
    //default constructor
    Deck() 
    {
        sequence = new int[3]();
        question = answer = " ";
        deck_name = temporary_file = "/home/kartik/Desktop/College/SDF2/Deck/";
    }

    //checks if the file is unique or not
    bool uniqueFile(string name) 
    {
        int length = files_used.size();
        for(int index = 0; index < length; index++) 
        {
            if(name == files_used.at(index))
                return true;
        }
        return false;
    }

    //creates a new deck
    void create() 
    {
        int choice = 0;
        string name, file_name;
        system("clear");
        cout << "Creating a new empty deck" << endl;
        cout << endl << "Please enter the name of the deck:";
        cin >> name;
        deck_name = deck_name + name;
        Standard *standard = new Standard();
        BothSide *bothside = new BothSide();
        TrueFalse *truefalse = new TrueFalse();
        cout << "We have three types of flashcards" << endl;
        do 
        {
            system("clear");
            cout << "Choose one:" << endl << "\t0. Exit" << endl << "\t1. Standard Flashcard" << endl << "\t2. Both Side Flashcard" << endl << "\t3. True False Flashcard" << endl;
            cin >> choice;
            counter = counter + 1;
            temporary_file_name = (temporary_file + counter) + ".txt";
            system("clear");
            switch (choice) 
            {
                case 1:
                    cards.push_back(standard);
                    addFlashcard(standard);
                    break;

                case 2:
                    cards.push_back(bothside);
                    addFlashcard(bothside);
                    break;

                case 3:
                    cards.push_back(truefalse);
                    addFlashcard(truefalse);
                    break;
            }
        } while(choice != 0);
        saveToFile();
        start(" ");
    }

    //adds a flashcard to the deck
    void addFlashcard(Flashcard *card) 
    {
        card->getFileName();
        if(uniqueFile(card->file_name)) 
        {
            cout << "File has already been added" << endl;
            addFlashcard(card);
        }
        else
            files_used.push_back(card->file_name);
        sequence = card->randomSequence();
        int size = card->totalNumberOfQuestions();
        for(int index = 0; index < size; index++) 
        {
            card->setQuestionNumber(sequence[index]);
            question = card->findQuestion();
            answer = card->findAnswer(question);
            add();
        }
    }

    //adds the question and answer to the file
    void add() 
    {
        ofstream file = openOutputFile(temporary_file_name);
        file << question << endl;
        file << answer << endl;
        file.close();
    }

    //saves the deck to a file
    void saveToFile() 
    {
        string line;
        vector<string> series;
        for(int index = 1; index < counter; index++) 
        {
            temporary_file_name = (temporary_file + index) + ".txt";
            ifstream file = openInputFile(temporary_file_name);
            while(getline(file, line)) 
            {
                if(line.at(0) == 'Q' || line.at(0) == '1' || line.at(0) == 'S')
                {
                    int position = line.find(" ");
                    string ques;
                    ques = line.substr(position + 1);
                    question = "Q: " + ques;
                }
                else 
                {
                    if(line.at(0) == '2')
                    {
                        int position = line.find(" ");
                        string ans;
                        ans = line.substr(position + 1);
                        answer = ans;
                    }
                    else
                        answer = line;
                    pair[question] = answer;
                }
            }
            remove(temporary_file_name.c_str());
        }
        ofstream file = openOutputFile(deck_name);
        series = shuffleQuestions();
        for(int index = 0; index < series.size(); index++) 
        {
            auto it = pair.find(series.at(index));
            if(it != pair.end()) 
            {
                file << it->first << endl;
                file << it->second << endl;
            }
        }
        file.close();
    }

    //shuffles the questions
    vector<string> shuffleQuestions() 
    {
        vector<string> series;
        vector<string> solution;
        for(const auto &value: pair)
            series.push_back(value.first);
        int size = series.size();
        int *array = new int[size];
        int number = 0;
        for(int index = 0; index < size; index++)
        {
            number = randomNumber(size);
            if(!found(array, number, index)) 
            {
                array[index] = number;
                solution.push_back(series.at(number));
            }
            else 
            {
                index--;
                continue;
            }
        }
        return solution;
    }

    //destructor
    ~Deck() 
    {
        delete [] sequence;
    }
};

int Deck::counter = 0;

class Quiz : private Deck 
{
    public:
    string file_name, deck_location, question, answer;
    int score;

    //default constructor
    Quiz() 
    {
        file_name = question = answer = " ";
        deck_location = "/home/kartik/Desktop/College/SDF2/Deck/";
        score = 0;
    }

    //displays the question
    void quiz() 
    {
        string line;
        system("clear");
        cout << "Please enter the name of the file: ";
        cin >> file_name;
        deck_location = deck_location + file_name;
        ifstream file = openInputFile(deck_location);
        while(getline(file, line)) 
        {
            cout << endl;
            if(line.at(0) == 'Q') 
            {
                system("clear");
                displayQuestion(line);
                getline(file, line);
                cin >> answer;
                if(answer == "exit") 
                {
                    cout << "Thank you" << endl;
                    start(" ");
                }
                if(line == answer)
                {
                    cout << "Correct" << endl;
                    score = score + 1;
                    sleep(1);
                }
                else
                {
                    cout << "Wrong" << endl;
                    cout << "The correct answer is: " << line << endl;
                    sleep(2);
                }
            }
        }
        cout << "Calculating score.";
        sleep(1);
        cout << ".";
        sleep(1);
        cout << ".";
        sleep(1);
        system("clear");
        cout << "Your score is: " << score << endl;
        file.close();
    }
};

class User 
{
    protected:
    string username, password;

    public:
    //default constructor
    User() 
    {
        username = password = " ";
    }

    //checks if the username is valid or not
    void getUsername() 
    {
        cout << endl << "The username should start with a letter and should contain only letters and numbers" << endl;
        cout << "Please enter the username:";
        //clear the buffer before the input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, username);
        if(username.empty() || isalpha(username.at(0)) == false) 
        {
            cerr << "Not allowed" << endl;
            getUsername();
        }
        for(int index = 1; index < username.length(); index++) 
        {
            if(isalnum(username.at(index)) == false || username.at(index) == ' ') 
            {
                cerr << "Not allowed" << endl;
                getUsername();
            }
        }
        cout << endl << "Username entered successfully" << endl;
    }

    //checks if the password is valid or not
    void getPassword() 
    {
        cout << endl << "The password should contain atleast 8 characters and should contain atleast one uppercase, one lowercase, one number and one special character" << endl;
        cout << "Please enter the password:";
        getline(cin, password);
        if(password.empty() || password.length() < 8) 
        {
            cerr << "Not allowed" << endl;
            getPassword();
        }
        int count[4] {0};
        for(int index = 0; index < password.length(); index++) 
        {
            if(password.at(index) == ' ') 
            {
                cerr << "Not allowed" << endl;
                getPassword();   
            }
            if(isupper(password.at(index)))
                ++count[0];
            else if(islower(password.at(index)))
                ++count[1];
            else if(isdigit(password.at(index)))
                ++count[2];
            else
                ++count[3];
        }
        for(int index = 0; index < 4; index++) 
        {
            if(count[index] < 1) 
            {
                cerr << "Not allowed" << endl;
                getPassword();
            }
        }
        cout << endl << "Password entered successfully" << endl;
    }

    //logs in the user
    void login() {
        int found = 0;
        getUsername();
        getPassword();
        ifstream file = openInputFile("/home/kartik/Desktop/College/SDF2/user.txt");
        string line;
        while(getline(file, line)) 
        {
            if(line.find(username) != string::npos && line.find(password) != string::npos) 
            {
                found = 1;
                cout << endl << "Welcome" << endl;
                sleep(1);
                break;
            }
        }
        file.close();
        if(found == 0) 
        {
            cout << "Username or password is incorrect" << endl;
            inputDetails();
        }
    }

    //checks if the username is already in use
    bool checkAvailablity() 
    {
        ifstream file = openInputFile("/home/kartik/Desktop/College/SDF2/user.txt");
        string line;
        while(getline(file, line)) 
        {
            if(line.find(username) != string::npos) 
            {
                file.close();
                return false;
            }
        }
        file.close();
        return true;
    }
    
    //sign up the user
    void signUp() 
    {
        getUsername();
        if(checkAvailablity() == false) 
        {
            cout << "Username already in use" << endl;
            sleep(2);
            inputDetails();   
        }
        getPassword();
        ofstream file = openOutputFile("/home/kartik/Desktop/College/SDF2/user.txt");
        file << username << ": " << password << endl;
        file.close();
        cout << "Welcome" << endl;
        sleep(1);
    }

    //input the details
    void inputDetails() 
    {
        int choice = 0;
        system("clear");
        cout << "Choose one:" << endl << "\t0. Exit" << endl << "\t1. Login" << endl << "\t2. Sign Up" << endl;
        cin >> choice;
        system("clear");
        if(choice == 1)
            login();
        else if(choice == 2)
            signUp();
        else if(choice == 0)
            main();
        else
            inputDetails();
        start(username); 
    }

    friend void start();
};

class Statistics : public Quiz, public User 
{
    public:
    string file_location;
    unordered_map<string, int> list_of_scores;

    //default constructor
    Statistics() 
    {
        file_location = "/home/kartik/Desktop/College/SDF2/Statistics/";
    }

    //stores the stats in the file
    void stats(Quiz &quiz, string name) 
    {
        score = quiz.score; 
        string file_name = quiz.file_name;
        file_location = file_location + file_name;
        ofstream file = openOutputFile(file_location);
        file << name << ": " << score << endl;
        file.close();
    }

    //display the stats in the order of the scores
    void displayStats() 
    {
        system("clear");
        int position = 0;
        string current_user;
        string current_score;
        vector<int> sorted_scores;
        string name;
        cout << "Please enter the name of the file: ";
        cin >> name;
        file_location = file_location + name;
        ifstream file = openInputFile(file_location);
        string line;
        while(getline(file, line)) 
        {
            position = line.find(" ");
            current_user = line.substr(0, position - 1);
            current_score = line.substr(position + 1);
            list_of_scores[current_user] = stoi(current_score);
            sorted_scores.push_back(stoi(current_score));
        }
        file.close();
        sort(sorted_scores.begin(), sorted_scores.end());
        for(int index = 0; index < sorted_scores.size(); index++) 
        {
            for(auto it = list_of_scores.begin(); it != list_of_scores.end(); it++) 
            {
                if(it->second == sorted_scores.at(index))
                    cout << it->first << ": " << it->second << endl;
            }
        }
    }

    //destructor
    ~Statistics() 
    {
        list_of_scores.clear();
    }
};

int main() 
{
    try
    {
        int choice = 0;
        system("clear");
        cout << "Welcome to the Flashcard application" << endl;
        cout << "Choose one: " << endl << "\t0. Exit" << endl << "\t1. User" << endl << "\t2. Add Flashcards" << endl;
        cin >> choice;
        if(choice == 0)
        {
            system("clear");
            cout << "Thank you" << endl;
            exit(0);
        }
        else if(choice == 1)
        {
            User user;
            user.inputDetails();
        }
        else if(choice == 2)
            option();
        else
            throw "Wrong input";
    }
    catch(const char *name) 
    {
        cout << name << endl;
        sleep(2);
        main();
    }
    catch(const runtime_error &e)
    {
        cout << e.what() << endl;
        sleep(2);
        main();
    }
    return 0;
}

//starts the application
void start(string name = " ") 
{
    try
    {
        int choice = 0;
        system("clear");
        cout << "Choose one:" << endl << "\t0. Exit" << endl << "\t1. Deck" << endl << "\t2. Quiz" << endl << "\t3. Stats" << endl;
        cin >> choice;
        Deck deck;
        Quiz quiz;
        Statistics stats;
        switch (choice) 
        {
            case 0:
            main();
            break;

            case 1:
            deck.create();
            break;

            case 2:
            quiz.quiz();
            stats.stats(quiz, name);
            break;

            case 3:
            stats.displayStats();
            break;

            default:
            start(name);
            break;
        }
    }
    catch(const char *str)
    {
        cout << str << endl;
        sleep(2);
        start(name);
    }
}

void option()
{
    try
    {
        int choice = 0;
        system("clear");
        cout << "Choose one: " << endl << "\t0. Exit" << endl << "\t1. Standard Flashcard" << endl << "\t2. Both Side Flashcard" << endl << "\t3. True False Flashcard" << endl;
        cin >> choice;
        Standard standard;
        BothSide both_side;
        TrueFalse true_false;
        switch (choice)
        {
            case 0:
            main();
            break;

            case 1:
            standard.getFileName();
            standard.add(standard.file_name);
            main();
            break;

            case 2:
            both_side.getFileName();
            both_side.add(both_side.file_name);
            main();
            break;
            
            case 3:
            true_false.getFileName();
            true_false.add(true_false.file_name);
            main();
            break;

            default:
            option();
            break;
        }
    }
    catch(const char *name)
    {
        cout << name << endl;
        sleep(2);
        option();
    }
}