//The FLashcard App
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
//All function definitions here
void start();
void welcome();
void chooser();
void cls();
void stop(int milliseconds);
void flashcard();
void tutorial();
void disp();
void input();
int check(char code[]);
int check4(char code[100]);
int checkExist(char code[5]);
void newFile(char code[4]);
void addCode(char code[4]);
void openFile(char code[4]);
void quiz(char code[4]);
void appender(char code[4]);
void standardmaker(char code[4]);
void bothsidemaker(char code[4]);
void truefalsemaker(char code[4]);
void backwardsmaker(char code[4]);
//Main code starts here
int main()
{
    //It will start the program
    start();
    return 0;
}
void cls()
{
    //It will clear the screen
    system("clear");
}
void start()
{
    cls();
    //It will welcome the user
    welcome();
}
void welcome()
{
    printf("Welcome to Flashcard Maker\n");
    printf("Please choose an option\n");
    chooser();
}
void chooser()
{
    //It will ask the user to choose an option
    int choice;
    printf("Press 1 to use the flashcards\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("You have chosen the flashcard option!\n");
        stop(1000);
        cls();
        flashcard();
        break;
    default:
        printf("Thanks for using this app!");
        exit(0);
        break;
    }
}
//This puts the code to sleep for specified number of milliseconds
void stop(int milliseconds)
{
    sleep(milliseconds/1000);
}
void flashcard()
{
    printf("Welcome to the flashcard factory\n");
    printf("Press 1 for tutorial\n");
    printf("Press 2 to start\n");
    printf("Press 3 to exit\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Tutorial\n");
        stop(1000);
        cls();
        tutorialMain();
        break;
    case 2:
        printf("Starting\n");
        stop(1000);
        cls();
        disp();
        break;
    case 3:
        printf("Exiting\n");
        stop(1000);
        cls();
        break;
    default:        
        printf("Invalid choice\n");
        start();
        break;
    }
}
void disp()
{
    cls();
    printf("The following decks exist here:\n");
    //Reads from contents.txt and prints the contents
    FILE *fp;
    char ch;
    fp = fopen("contents.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(fp);
    printf("\n");
    input();
}
void input()
{
    printf("Enter the code of the deck you want to use: ");
    char code[100];
    scanf("%s", code);
    int codeType = check(code);
    if(codeType==1)
    {
        printf("The word is not 4 letters long!");
        stop(1000);
        cls();
        input();
    }
    else if(codeType==2)
    {
        openFile(code);
    }
    else if(codeType==3)
    {
        printf("The document does not exist!");
        printf("Making new document!");
        stop(1000);
        cls();
        newFile(code);
    }
}
int check(char code[])
{
    //Checks if code is valid
    if(check4(code))
    {
        return 1;
    }
    else if(checkExist(code))
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
int check4(char code[100])
{
    //Checks if code is 4 characters long
    if(strlen(code) != 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkExist(char code[5])
{
    //Checks if code exists
    FILE *fp;
    char ch[100];
    fp = fopen("contents.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while(fgets(ch, 5, fp) != NULL)
    {
        if(strcmp(ch, code) == 0)
        {
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
void newFile(char code[4])
{
    //This will create a new file in decks folder
    FILE *fp;
    char filename[100];
    strcpy(filename, "decks/");
    strcat(filename, code);
    strcat(filename, ".txt");
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fclose(fp);
    addCode(code);
    appender(code);
}
void addCode(char code[4])
{
    //This will add the code to contents.txt
    FILE *fp;
    fp = fopen("contents.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "%s\n", code);
    fclose(fp);
}
void openFile(char code[4])
{
    cls();
    printf("Enter 1 to add a new section to the deck: \n");
    printf("Enter 2 to be quizzed on a section: \n");
    printf("Enter 3 to exit: \n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Adding new section\n");
        stop(1000);
        cls();
        appender(code);
        break;
    case 2:
        printf("Quizzing\n");
        stop(1000);
        cls();
        quiz(code);
        break;
    case 3:
        printf("Exiting\n");
        stop(1000);
        cls();
        break;
    default:
        printf("Invalid choice\n");
        openFile(code);
        break;
    }
}
//This module is used to append new questions to existing cards
void appender(char code[4])
{
    printf("Welcome to the appender!\n");
    printf("Press 1 to see the tutorial\n");
    printf("Press 2 to start\n");
    printf("Press 3 to exit\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Tutorial\n");
        stop(1000);
        cls();
        tutorialMain();
        break;
    case 2:
        printf("Starting\n");
        stop(1000);
        cls();
        break;
    case 3:
        printf("Exiting\n");
        stop(1000);
        cls();
        start();
        exit(0);
        break;
    default:
        printf("Invalid choice\n");
        appender(code);
        break;
    }
    //The loop will end only when someone jumps out of the codezome
    while(1==1)
    {
        cls();
    printf("Press 1 for standard flashcard\n");
    printf("Press 2 for Bothside flashcard\n");
    printf("Press 4 for true false flashcard\n");
    printf("Press 7 for exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Standard flashcard\n");
        stop(1000);
        cls();
        standardmaker(code);
        break;
    case 2:
        printf("Bothside flashcard\n");
        stop(1000);
        cls();
        bothsidemaker(code);
        break;
    case 3:
        printf("Backwards flashcard\n");
        stop(1000);
        cls();
        backwardsmaker(code);
        break;
    case 4:
        printf("True false flashcard\n");
        stop(1000);
        cls();
        truefalsemaker(code);
        break;
    case 7:
        printf("Exiting\n");
        stop(1000);
        cls();
        start();
        exit(0);
        break;
    default:
        printf("Invalid choice\n");
        cls();
        appender(code);
        break;
    }
    }
}
//A normal flashcard maker
void standardmaker(char code[4])
{
    printf("Welcome to the standard flashcard maker!\n");
    printf("Enter the question: ");
    char question[100];
    scanf(" %[^\n]s", question);
    // Dummy fgets to consume the newline character
    char dummy[2];
    fgets(dummy, 2, stdin);
    printf("Enter the answer: ");
    char answer[100];
    scanf(" %[^\n]s", answer);
    // Dummy fgets to consume the newline character
    char dummy2[2];
    fgets(dummy, 2, stdin);
    FILE *fp;
    char filename[100];
    strcpy(filename, "decks/");
    strcat(filename, code);
    strcat(filename, ".txt");
    char paste[100];
    strcpy(paste, "1");
    strcat(paste, "~");
    strcat(paste, question);
    strcat(paste, "~");
    strcat(paste, answer);
    fp = fopen(filename, "a");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "%s\n", paste);
    fclose(fp);
}
//THis will create a backwards card
void backwardsmaker(char code[4])
{
    printf("Welcome to the standard flashcard maker!\n");
    printf("Enter the question: ");
    char question[100];
    scanf(" %[^\n]s", question);
    // Dummy fgets to consume the newline character
    char dummy[2];
    fgets(dummy, 2, stdin);
    printf("Enter the answer: ");
    char answer[100];
    scanf(" %[^\n]s", answer);
    // Dummy fgets to consume the newline character
    char dummy2[2];
    fgets(dummy, 2, stdin);
    FILE *fp;
    char filename[100];
    strcpy(filename, "decks/");
    strcat(filename, code);
    strcat(filename, ".txt");
    char paste[100];
    strcpy(paste, "1");
    strcat(paste, "~");
    strcat(paste, answer);
    strcat(paste, "~");
    strcat(paste, question);
    fp = fopen(filename, "a");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "%s\n", paste);
    fclose(fp);
}
//This will generate both side carsd
//Both side cards are asked from either side
void bothsidemaker(char code[4])
{
    printf("Welcome to the bothside flashcard maker!\n");
    printf("Enter the question: ");
    char question[100];
    scanf(" %[^\n]s", question);
    // Dummy fgets to consume the newline character
    char dummy[2];
    fgets(dummy, 2, stdin);
    printf("Enter the answer: ");
    char answer[100];
    scanf("%[^\n]s", answer);
    // Dummy fgets to consume the newline character
    char dummy2[2];
    fgets(dummy, 2, stdin);
    FILE *fp;
    char filename[100];
    strcpy(filename, "decks/");
    strcat(filename, code);
    strcat(filename, ".txt");
    char paste[100];
    strcpy(paste, "2");
    strcat(paste, "~");
    strcat(paste, question);
    strcat(paste, "~");
    strcat(paste, answer);
    fp = fopen(filename, "a");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "%s\n", paste);
    strcpy(paste, "2");
    strcat(paste, "~");
    strcat(paste, answer);
    strcat(paste, "~");
    strcat(paste, question);
    fclose(fp);
}
//This will generate true false flashcards
void truefalsemaker(char code[4])
{
    printf("Welcome to the true false flashcard maker!\n");
    printf("Enter the question: ");
    char question[100];
    scanf(" %[^\n]s", question);
    // Dummy fgets to consume the newline character
    char dummy[2];
    fgets(dummy, 2, stdin);
    printf("Enter 1 for true and 2 for false: ");
    char answer[100];
    scanf(" %[^\n]s", answer);
    // Dummy fgets to consume the newline character
    char dummy2[2];
    fgets(dummy, 2, stdin);
    if(strcmp(answer,"1")==0)
    {
        strcpy(answer, "True");
    }
    else if(strcmp(answer,"2")==0)
    {
        strcpy(answer, "False");
    }
    FILE *fp;
    char filename[100];
    strcpy(filename, "decks/");
    strcat(filename, code);
    strcat(filename, ".txt");
    char paste[100];
    strcpy(paste, "3");
    strcat(paste, "~");
    strcat(paste, question);
    strcat(paste, "~");
    strcat(paste, answer);
    fp = fopen(filename, "a");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "%s\n", paste);
    fclose(fp);
}
void quiz(char code[4])
{
    printf("Welcome to the quizzer!");
    //Open the file
    FILE *fp;
    char filename[100];
    strcpy(filename, "decks/");
    strcat(filename, code);
    strcat(filename, ".txt");
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    //Read the file, line  by line
    char ch[100];
    while(fgets(ch, 100, fp) != NULL)
    {
        //Now we have to split the line into 3 parts
        //First part is the type of flashcard
        //Second part is the question
        //Third part is the answer
        int type = ch[0] - '0';
        cls();
        printf("Type: %d\n", type);
        char *p = ch;
        int i=2;
        while(*(p+i) != '~')
        {
            printf("%c", *(p+i));
            i++;
        }
        printf("\n");
        i++;
        printf("Press 1 to see the answer: ");
        int choice;
        scanf("%d", &choice);
        while(*(p+i) != '\0')
        {
            printf("%c", *(p+i));
            i++;
        }
        printf("\n");
        printf("Press 1 to continue: ");
        scanf("%d", &choice);
    }
}
//THis will print out the tutorial for the main program
void tutorialMain()
{
    cls();
    printf("Welcome to the tutorial!");
    stop(5000);
    cls();
    printf("Flashcards are a very efficient way of studying!\n");
    stop(5000);
    cls();
    printf("WHen the code starts, you are presented the list of all the existing DECKS.\n");
    stop(5000);
    cls();
    printf("If you enter a code that exists, then the file will open up that file.");
    stop(5000);
    cls();
    printf("Otherwise, the code itself will make the file with the CODE given\n");
    stop(5000);
    cls();
    printf("Then there are two modes, quiz and append");
    stop(5000);
    cls();
    printf("The quiz mode asks you questions");
    stop(5000);
    cls();
    printf("The append mode lets you add questions");
    stop(5000);
    cls();
    printf("The append mode has several options like Standard, both side card, true false etc");
    stop(5000);
    cls();
    printf("Happy Leaning!");
    stop(5000);
    cls();
}