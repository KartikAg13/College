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

using namespace std;

ifstream openInputFile(const string &);

ofstream openOutputFile(const string &);

int randomNumber(int);

bool found(int *, int, int);

void displayQuestion(string &);

string operator+(const string &, int);

void start(string);

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
    {
        cerr << "Error opening file at location: " << name << endl;
        exit(1);
    }
    return file;
}

//returns the file in append mode
ofstream openOutputFile(const string &name) 
{
    ofstream file(name, ios::app);
    if(!file.is_open()) 
    {
        cerr << "Error opening file at location: " << name << endl;
        exit(1);
    }
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
    {
        cout << "Something is not right" << endl;
        exit(1);
    }
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
            if(input.find("exit") != string::npos) 
            {
                cout << "Thank you" << endl;
                exit(0);
            }
            answer = findAnswer(question);
            if(answer.find(input) != string::npos)
                cout << "Correct" << endl;
            else 
                cout << "Wrong" << endl;
        }
        delete [] array;
    }

    //adds a new question to the file
    void add(const string &name) 
    {
        ofstream file = openOutputFile(name);
        string line;
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
            if(input.find("exit") != string::npos) 
            {
                cout << "Thank you" << endl;
                exit(0);
            }
            side[1] = findAnswer(side[0]);
            if(side[1].find(input) != string::npos)
                cout << "Correct" << endl;
            else
                cout << "Wrong" << endl;
        }
        delete [] array;
    }       

    //adds a sides to the file
    void add(const string &name) 
    {
        ofstream file = openOutputFile(name);
        string line;
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
            if(input.find("exit") != string::npos) 
            {
                cout << "Thank you" << endl;
                exit(0);
            }
            isTrue = findAnswer(statement);
            if(isTrue.find(input) != string::npos)
                cout << "Correct" << endl;
            else
                cout << "Wrong" << endl;
        }
        delete [] array;
    }

    //adds a statement to the file
    void add(const string &name) 
    {
        ofstream file = openOutputFile(name);
        string line;
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
    //make changes as soon as possible
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
            if(name.find(files_used.at(index)) != string::npos)
                return true;
        }
        return false;
    }

    //make a array of strings which keeps track of all the files already used in the deck
    void create() 
    {
        int choice = 0;
        string name, file_name;
        cout << "Creating a new empty deck" << endl;
        cout << "Please enter the name of the deck:";
        cin >> name;
        deck_name = deck_name + name;
        Standard *standard = new Standard();
        BothSide *bothside = new BothSide();
        TrueFalse *truefalse = new TrueFalse();
        cout << "We have three types of flashcards" << endl;
        do 
        {
            cout << "Choose" << endl;
            cout << "0. Exit" << endl << "1. Standard" << endl << "2. Both Side" << endl << "3. True False" << endl;
            cin >> choice;
            counter = counter + 1;
            temporary_file_name = (temporary_file + counter) + ".txt";
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

    void add() 
    {
        ofstream file = openOutputFile(temporary_file_name);
        file << question << endl;
        file << answer << endl;
        file.close();
    }

    //issue in this function
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
        cout << "Please enter the name of the file: ";
        cin >> file_name;
        deck_location = deck_location + file_name;
        ifstream file = openInputFile(deck_location);
        while(getline(file, line)) 
        {
            cout << endl;
            if(line.at(0) == 'Q') 
            {
                displayQuestion(line);
                getline(file, line);
                cin >> answer;
                if(answer.find("exit") != string::npos) 
                {
                    cout << "Thank you" << endl;
                    start(" ");
                }
                if(line.find(answer) != string::npos)
                {
                    cout << "Correct" << endl;
                    score = score + 1;
                }
                else
                {
                    cout << "Wrong" << endl;
                    cout << "The correct answer is: " << line << endl;
                }
            }
        }
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
                cout << "Welcome" << endl;
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
            inputDetails();   
        }
        getPassword();
        ofstream file = openOutputFile("/home/kartik/Desktop/College/SDF2/user.txt");
        file << username << ": " << password << endl;
        file.close();
        cout << "Welcome" << endl;
    }

    //input the details
    void inputDetails() 
    {
        int choice = 0;
        cout << "Choose one:" << endl << "0. Exit" << endl << "1. Login" << endl << "2. Sign Up" << endl;
        cin >> choice;
        if(choice == 1)
            login();
        else if(choice == 2)
            signUp();
        else 
        {
            cout << "Wrong input" << endl;
            inputDetails();
        }
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

//starts the application
void start(string name = " ") 
{
    int choice = 0;
    cout << "Choose one:" << endl << "0. Exit" << endl << "1. Deck" << endl << "2. Quiz" << endl << "3. Stats" << endl;
    cin >> choice;
    Deck deck;
    Quiz quiz;
    Statistics stats;
    switch (choice) 
    {
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
            cout << "Wrong input" << endl;
            break;
    }
}

int main() 
{
    /*
    int choice = 0;
    cout << "Welcome to the flashcard application" << endl;
    cout << "Choose one:" << endl << "0. Exit" << endl << "1. User" << endl;
    cin >> choice;
    if(choice == 1) 
    {
        User user;
        user.inputDetails();
    }
    else if(choice == 0)
        cout << "Thank you" << endl;
    else 
    {
        cout << "Wrong input" << endl;
        main();
    }
    return 0;
    */
}