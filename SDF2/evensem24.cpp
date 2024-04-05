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

using namespace std;

ifstream openInputFile(const string &);

ofstream openOutputFile(const string &);

int randomNumber(int);

bool found(int *, int, int);

void displayQuestion(string &);

string operator+(const string &, int);

class Flashcard {
    protected:
    string file_name;
    int question_number;
    char tag;
    
    public:
    Flashcard() {
        file_name = "/home/kartik/Projects/SDF2/";
        question_number = 0;
        tag = ' ';
    }

    virtual void add(const string &name) = 0;

    void setQuestionNumber(int number) {
        question_number = number;
    }

    //searches for the question and returns it
    string findQuestion() {
        ifstream file = openInputFile(file_name);
        string line, question;
        int index = 0;
        while(getline(file, line) && index <= question_number) {
            if(line.at(0) == tag)
                index++;
            question = line;
        }
        file.close();
        return question;
    }

    //returns the answer
    string findAnswer(const string &question) {
        ifstream file = openInputFile(file_name);
        string line, answer = "";
        while(getline(file, line)) {
            if(line.find(question) != string::npos) {
                getline(file, line);
                answer = line;
            }
        }
        file.close();
        return answer;
    }

    //asks the user to enter the file
    void getFileName() {
        string name;
        cout << "Please enter the file name: ";
        cin >> name;
        file_name = file_name + name;
    }

    //total number of questions in a file
    int totalNumberOfQuestions() {
        ifstream file = openInputFile(file_name);
        string line;
        int count = 0;
        while(getline(file, line)) {
            if(line.at(0) == tag)
                count++;
        }
        file.close();
        return count;
    }

    //gives a random sequence of questions
    int *randomSequence() {
        int size = totalNumberOfQuestions();
        int *array = new int[size]();
        int number = 0;
        for(int index = 0; index < size; index++) {
            number = randomNumber(size);
            if(!found(array, number, index))
                array[index] = number;
            else {
                index--;
                continue;
            }
        }
        return array;
    }
};

//returns the file in read mode
ifstream openInputFile(const string &name) {
    ifstream file(name);
    if(!file.is_open()) {
        cerr << "Error opening file at location: " << name << endl;
        exit(1);
    }
    return file;
}

//returns the file in append mode
ofstream openOutputFile(const string &name) {
    ofstream file(name, ios::app);
    if(!file.is_open()) {
        cerr << "Error opening file at location: " << name << endl;
        exit(1);
    }
    return file;
}

//checks if the a question is already asked or not
bool found(int *array, int search, int size) {
    for(int index = 0; index < size; index++) {
        if(array[index] == search)
            return true;
    }
    return false;
}

//generates a random number between 0 and maximum
int randomNumber(int maximum) {
    srand(time(nullptr));
    return rand() % maximum;
}

//formats the question before question
void displayQuestion(string &question) {
    int index = question.find(" ");
    if(index == string::npos) {
        cout << "Something is not right" << endl;
        exit(1);
    }
    cout << question.substr(index + 1) << endl;
}

string operator+(const string &name, int number) {
    return name + to_string(number);
}

class Standard : public Flashcard {
    private:
    string question;
    string answer;

    public:
    //default constructor
    Standard() {
        question = "";
        answer = "";
        tag = 'Q';
        file_name = "/home/kartik/Projects/SDF2/Standard/";
    }

    //gets a randomNumber question from the file
    void getQuestion() {
        getFileName();
        string input;
        int size = totalNumberOfQuestions();
        int *array = new int[size];
        array = randomSequence();
        for(int index = 0; index < size; index++) {
            question_number = array[index];
            question = findQuestion();
            displayQuestion(question);
            cin >> input;
            if(input.find("exit") != string::npos) {
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
    void add(const string &name) {
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

class BothSide : public Flashcard {
    private:
    string *side;

    public:
    //default constructor
    BothSide() {
        side = new string[2]();
        tag = '1';
        file_name = "/home/kartik/Projects/SDF2/BothSide/";
    }

    //gets a randomNumber question from the file
    void getQuestion() {
        getFileName();
        string input;
        int size = totalNumberOfQuestions();
        int *array = new int[size];
        array = randomSequence();
        for(int index = 0; index < size; index++) {
            question_number = array[index];
            side[0] = findQuestion();
            displayQuestion(side[0]);
            cin >> input;
            if(input.find("exit") != string::npos) {
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
    void add(const string &name) {
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

    ~BothSide() {
        delete [] side;
    }
};

class TrueFalse : public Flashcard {
    private:
    string statement, isTrue;

    public:
    //default constructor
    TrueFalse() {
        statement = "";
        isTrue = true;
        tag = 'S';
        file_name = "/home/kartik/Projects/SDF2/TrueFalse/";
    }

    //gets a randomNumber question from the file
    void getQuestion() {
        getFileName();
        int size = totalNumberOfQuestions();
        int *array = new int[size];
        array = randomSequence();
        string input;
        for(int index = 0; index < size; index++) {
            question_number = array[index];
            statement = findQuestion();
            displayQuestion(statement);
            cin >> input;
            if(input.find("exit") != string::npos) {
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

    void add(const string &name) {
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

class Deck : private Standard, private BothSide, private TrueFalse {
    private:
    int code;
    vector <Flashcard*> cards;
    int *sequence;
    string question, answer, deck_name, temporary_file;
    static int counter; 
    unordered_map<string, string> pair;

    public:
    //make changes as soon as possible
    Deck() {
        code = 0;
        sequence = new int[3]();
        question = answer = "";
        deck_name = temporary_file = "/home/kartik/Projects/SDF2/Deck/";
    }

    bool search() {
        ifstream file = openInputFile("/home/kartik/Projects/SDF2/deck_info.txt");
        string line;
        while(getline(file, line)) {
            if(stoi(line) == code) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

    //make a array of strings which keeps track of all the files already used in the deck
    void create() {
        int choice = 0;
        string name, file_name;
        code = randomNumber(9999);
        if(code <= 1000 && !search())
            create();
        ofstream file = openOutputFile("/home/kartik/Projects/SDF2/deck_info.txt");
        file << code << endl;
        file.close();
        cout << "Creating a new empty deck" << endl;
        cout << "Please enter the name of the deck: " << endl;
        cin >> name;
        deck_name = deck_name + name;
        Standard *standard = new Standard();
        BothSide *bothside = new BothSide();
        TrueFalse *truefalse = new TrueFalse();
        cout << "We have three types of flashcards" << endl;
        do {
            cout << "Choose" << endl;
            cout << "0. Exit" << endl << "1. Standard" << endl << "2. Both Side" << endl << "3. True False" << endl;
            cin >> choice;
            counter = counter + 1;
            file_name = (temporary_file + counter) + ".txt";
            switch (choice) {
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

                default: 
                    cout << "Wrong input" << endl << "Try again" << endl;
                    break;
            }
        } while(choice != 0);
        saveToFile();
    }

    void addFlashcard(Flashcard *card) {
        card->getFileName();
        sequence = card->randomSequence();
        int size = card->totalNumberOfQuestions();
        for(int index = 0; index < size; index++) {
            card->setQuestionNumber(sequence[index]);
            question = card->findQuestion();
            answer = card->findAnswer(question);
            add();
        }
    }

    void add() {
        ofstream file = openOutputFile(temporary_file);
        file << "Q: " << question << endl;
        file << answer << endl;
        file.close();
    }

    void saveToFile() {
        string line, name;
        vector<string> series;
        for(int index = 1; index <= counter; index++) {
            name = (temporary_file + index) + ".txt";
            ifstream file = openInputFile(name);
            while(getline(file, line)) {
                if(line.at(0) == 'Q')
                    question = line;
                else {
                    answer = line;
                    pair[question] = answer;
                }
            }
            remove(name.c_str());
        }
        ofstream file = openOutputFile(deck_name);
        series = shuffleQuestions();
        for(int index = 0; index < series.size(); index++) {
            auto it = pair.find(series.at(index));
            if(it != pair.end()) {
                file << "Q: " << it->first << endl;
                file << it->second << endl;
            }
        }
        file.close();
    }

    vector<string> shuffleQuestions() {
        vector<string> series;
        //for each loop
        for(const auto &value: pair)
            series.push_back(value.first);
        //Seed for the random number engine
        random_device rd;
        //Mersenne Twister engine for randomness   
        mt19937 g(rd());    
        shuffle(series.begin(), series.end(), g);
        return series;
    }

    void quiz() {
        string line, name;
        cout << "Please enter the name of the file: ";
        getline(cin, name);
        deck_name = deck_name + name;
        ifstream file = openInputFile(deck_name);
        while(getline(file, line)) {
            if(line.find("exit") != string::npos) {
                cout << "Thank you" << endl;
                exit(0);
            }
            else if(line.at(0) == 'Q') {
                displayQuestion(line);
                getline(file, line);
                cin >> answer;
                if(line.find(answer) != string::npos)
                    cout << "Correct" << endl;
                else
                    cout << "Wrong" << endl;
            }
        }
    }

};

int Deck::counter = 0;

int main() {
    cout << "Standard" << endl;
    Standard s;
    //s.getQuestion();
    cout << "BothSide" << endl;
    BothSide b;
    //b.getQuestion();
    cout << "TrueFalse" << endl;
    TrueFalse t;
    //t.getQuestion();
    //Deck::counter = 0;
    return 0;
}