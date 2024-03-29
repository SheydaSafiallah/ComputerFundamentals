//This is our final project. Mahdieh Shahhoseini, Sargol Moslemi, and I are working on it.

#include <stdio.h>
#include <conio.h> // getch();
#include <windows.h> // clearing by system("CLS"); and coloring by system("COLOR ");
/*******************

Name         | Value
             |
Black        |   0
Blue         |   1
Green        |   2
Aque         |   3
Red          |   4
Purple       |   5
Yellow       |   6
White        |   7
Gray         |   8
Light Blue   |   9
Light Green  |   A
Light Aque   |   B
Light Red    |   C
Light Purple |   D
Light Yellow |   E
Bright White |   F

*******************/
#include <unistd.h> // freezing by sleep(second);
#include <stdlib.h> // change txt color by SetColor(); // Auto Play
#include <dos.h> // change txt color by SetColor();
#include <dir.h> // change txt color by SetColor();
/*******************

Name         | Value
             |
Black        |   0
Blue         |   1
Green        |   2
Cyan         |   3
Red          |   4
Magenta      |   5
Brown        |   6
Light Gray   |   7
Dark Gray    |   8
Light Blue   |   9
Light Green  |   10
Light Cyan   |   11
Light Red    |   12
Light Magenta|   13
Yellow       |   14
White        |   15

*******************/
#include <math.h> // Auto Play
#include <string.h> // Auto Play
#include <time.h> // Auto Play
#define ACTION int // Auto Play
#define NONE -1 // Auto Play
#define NEXT_QUEEN 0 // Auto Play
#define NEXT_ROW 1 // Auto Play

void SetColor(int ForgC);
void title();
void title0();
void title1();
void title2();
void title3();
void title4();
void title5();
void title6();
void title7();
int menu();
void wlcName(char name[]);
void userName(char name[]);
int arrayBoard(int , char name[]);
int printCollisions (int N , char* array);
int isCorrectCordinate(int N , int* allow , char* array , char what, int x, int y);
void aboutGame();
int autoPlay();
typedef struct chess
{
    unsigned* board;
    unsigned numberOfQueens;
    unsigned currentQueens;
} chess;
typedef struct stack
{
    unsigned top;
    unsigned capacity;
    // satck contains array of pointer of chess
    chess** array;
} stack;
void deleteStack(stack* s);
int isEmpty(stack* s);
int isFull(stack* s);
void push(stack* s , chess* c);
void printChess(chess* c);
int collisions(chess* c);
void deleteChess(chess* c);
void getActions(chess* c , ACTION* actionList);
int isGoal(chess* c);
stack* createStack(unsigned size)
{
    stack* s = (stack*)malloc(sizeof(stack));
    s -> top = 0;
    s -> capacity = size;
    s -> array = (chess**)malloc(size * sizeof(chess*));
    return s;
}
chess* pop(stack* s)
{
    if(isEmpty(s))
    {
        printf("Could not pop data, stack is empty.\n");
        exit(0);
    }
    s -> top--;
    return s -> array[s -> top];
}
chess* createChess(unsigned numberOfQueens)
{
    chess* c = (chess*)malloc(sizeof (chess));
    c -> board = (unsigned*)malloc(numberOfQueens * sizeof(unsigned));
    memset(c -> board , 0 , numberOfQueens * sizeof(unsigned));
    c -> currentQueens = 0;
    c -> numberOfQueens = numberOfQueens;
    return  c;
}
chess* clone(chess* c)
{
    unsigned numberOfQueens = c -> numberOfQueens;
    chess* newChess = createChess(numberOfQueens);
    newChess -> board = (unsigned*) malloc(numberOfQueens * sizeof (unsigned));
    memcpy(newChess -> board , c -> board , numberOfQueens * sizeof (unsigned));
    newChess -> numberOfQueens = c -> numberOfQueens;
    newChess -> currentQueens = c -> currentQueens;
    return newChess;
}
chess* next(chess* c, ACTION action)
{
    chess* newChess = clone(c);
    //generate next state of chess board
    if (action == NEXT_QUEEN)
    {
        newChess -> currentQueens++;
    }else if (action == NEXT_ROW)
    {
        newChess -> board[newChess->currentQueens]++;
    }
    return newChess;
}
chess* solve(chess* c)
{
    stack* s = createStack(10000);
    chess* current = NULL;
    push(s , c);

    while(-1)
    {
        if (isEmpty(s))
        {
            deleteStack(s);
            return NULL;
        }
        current = pop(s);
        ACTION actionList[2]={NONE,NONE};
        getActions(current,actionList);
        for (int i=0;i<2;i++)
        {
            if (actionList[i]!=NONE)
            {
                chess* nextChess = next(current,actionList[i]);
                push(s , nextChess);
            }
        }
        if (collisions(current)!=0)
        {
            deleteChess(current);
            continue;
        }
        if (isGoal(current))
        {
            while (!isEmpty(s))
            {
                deleteChess(pop(s));
            }
            deleteStack(s);
            return current;
        }
        deleteChess(current);
    }
}
void won();
void lose();
int CollisionsArray[2][50];
int main()
{
    int x;
    char ch;
    char name[15] = {'U' , 'n' , 'k' , 'n' , 'o' , 'w' , 'n' , '\0'};
    while(-1)
    {
        system("COLOR B0");
        title();
        menu();
        static int check = 0;
        do
        {
            if(check)
            {
                SetColor(12);
                printf("\n\nwrong order! Try Again");
                SetColor(0);
                printf("\t %c%c ", 175, 175);
            }
            scanf(" %c", &ch);
            check++;
        } while(ch < 48 || ch > 57);
        x = ch - 48;
        switch(x)
        {
            case 0:
                system("COLOR E0");
                system("CLS");
                title0();
                userName(name);
                break;
            case 1:
                system("COLOR F0");
                system("CLS");
                arrayBoard(4 , name);
                break;
            case 2:
                system("COLOR F0");
                system("CLS");
                arrayBoard(5 , name);
                break;
            case 3:
                system("COLOR F0");
                system("CLS");
                arrayBoard(6 , name);
                break;
            case 4:
                system("COLOR F0");
                system("CLS");
                arrayBoard(7 , name);
                break;
            case 5:
                system("COLOR F0");
                system("CLS");
                arrayBoard(8 , name);
                break;
            case 6:
                system("COLOR 70");
                system("CLS");
                title6();
                aboutGame();
                break;
            case 7:
                system("COLOR 80");
                system("CLS");
                title7();
                autoPlay();
                break;
        case 8:
            return 0;
            default:
                system("CLS");
                break;
        }
    }

    //return 0;
}

/*************************************** txt color *************************************/

void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut , &csbi));
    {
        //Mask out all but the background attribute, and add in the forground color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut , wColor);
    }
    return;
}

/*************************************** titles ****************************************/
void title()
{
    SetColor(1);
    printf("\n");
    printf("\t\t\t\t N_QUEEN_98");
    printf("\n");
    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    printf("\n");
    SetColor(0);
}
/* title of information */
void title0()
{
    printf("\n");
    SetColor(1);
    printf("\t\t\t\t N_QUEEN_98");
    printf("\n");
    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    printf("\n");
    SetColor(0);
    printf("\t\t\t\t%cInformation", 240);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 218, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n");
    printf("\t\t\t%c\t\t\t    %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c\t\t\t    %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c\t User Name:\t    %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c\t\t\t    %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c\t\t\t    %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 192, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    printf("\n");
}

void title1()
{
    printf("\n");
    SetColor(1);
    printf("\t\t\t\t N_QUEEN_98");
    printf("\n");
    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    SetColor(0);
    printf("\n");
    printf("\t\t\t\t %cBeginner", 240);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 218, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n");
}

void title2()
{
    printf("\n");
    SetColor(1);
    printf("\t\t\t\t N_QUEEN_98");
    printf("\n");
    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    SetColor(0);
    printf("\n");
    printf("\t\t\t\t   %cEasy", 240);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 218, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n");
}

void title3()
{
    printf("\n");
    SetColor(1);
    printf("\t\t\t\t N_QUEEN_98");
    printf("\n");
    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    SetColor(0);
    printf("\n");
    printf("\t\t\t\t  %cNormal", 240);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 218, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n");
}

void title4()
{
    printf("\n");
    SetColor(1);
    printf("\t\t\t\t N_QUEEN_98");
    printf("\n");
    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    SetColor(0);
    printf("\n");
    printf("\t\t\t\t   %cHard", 240);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 218, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n");
}

void title5()
{
    printf("\n");
    SetColor(1);
    printf("\t\t\t\t N_QUEEN_98");
    printf("\n");
    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    printf("\n");
    SetColor(0);
    printf("\t\t\t\t  %cMaster", 240);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 218, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n");
}

void title6()
{
    SetColor(1);
    printf("\n");
    printf("\t\t\t\t N_QUEEN_98");
    printf("\n");
    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    printf("\n");
    SetColor(0);
    printf("\t\t\t       %cAbout.N.Queen", 240);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 218, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n");
}

void title7()
{
    printf("\n");
    SetColor(1);
    printf("\t\t\t\t N_QUEEN_98");
    printf("\n");
    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    printf("\n");
    SetColor(0);
    printf("\t\t\t\t %cAuto Play", 240);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 218, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n");
}
//////////////////////////////////// end of titles //////////////////////////////////////
/* menu box */
int menu()
{
    printf("\t\t\t\t    MENU");
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 218, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n\a");
    printf("\t\t\t%c    %c0 Information         %c", 179, 240, 179);
    printf("\n");
    printf("\t\t\t%c    %c1 Beginner     ", 179,  240);
    SetColor(8);
    printf("(4x4)");
    SetColor(0);
    printf("  %c", 179);
    printf("\n");
    printf("\t\t\t%c    %c2 Easy\t     ", 179,  240);
    SetColor(8);
    printf("(5x5)");
    SetColor(0);
    printf("  %c", 179);
    printf("\n");
    printf("\t\t\t%c    %c3 Normal\t     ", 179,  240);
    SetColor(8);
    printf("(6x6)");
    SetColor(0);
    printf("  %c", 179);
    printf("\n");
    printf("\t\t\t%c    %c4 Hard\t     ", 179,  240);
    SetColor(8);
    printf("(7x7)");
    SetColor(0);
    printf("  %c", 179);
    printf("\n");
    printf("\t\t\t%c    %c5 Master\t     ", 179,  240);
    SetColor(8);
    printf("(8x8)");
    SetColor(0);
    printf("  %c", 179);
    printf("\n");
    printf("\t\t\t%c    %c6 About Game          %c", 179,  240, 179);
    printf("\n");
    printf("\t\t\t%c    %c7 Auto play           %c", 179,  240, 179);
    printf("\n");
    printf("\t\t\t%c", 179);
    SetColor(12);
    printf("    %c8 EXIT                ",  240);
    SetColor(0);
    printf("%c", 179);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 192, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    printf("\n\n\n");
    SetColor(7);
    for(int i = 0; i < 2; i++)
    {
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
    }
    for(int i = 0; i < 2; i++)
    {
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
    }
    SetColor(1);
    printf("please enter a number from set: {0, 1, 2, 3, 4, 5, 6}");
    printf("\t %c%c ", 175, 175);
    SetColor(0);
}
/* welcome to user */
void wlcName(char name[])
{
    system("CLS");
    printf("\n");
    printf("\t\t\t\t N_QUEEN_98");
    printf("\n");
    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    printf("\n");
    printf("\t\t\t\t%cInformation", 240);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 218, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n\n");
    printf("\t\t\t\t\a\a HI %s!", name);
    printf("\n\n");
    printf("\t\t\t    WELCOME TO N_QUEEN_98");
    printf("\n\n");
    printf("\t\t\t      KEEP UP THE PACE ^^");
    printf("\n\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 192, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    printf("\n\n\n\n\n");
    printf(" Hey %s ! Let's GO ;) ", name);
}
/* get information */
void userName(char name[])
{
    printf("\t\t\t   Please enter your name: ");
    printf("\n");
    printf("\n\n\t\t\t\t");
    getchar();
    gets(name);
    wlcName(name);
    getchar();
    //sleep(7);
    system("CLS");
}
/* How to play */
void aboutGame()
{
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    SetColor(1);
    printf("\t\t\t%c  Welcome to N_QUEEN_98!   %c", 179, 179);
    SetColor(0);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  The N queens puzzle is   %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  the problem of placing   %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  N chess queens on an     %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  NxN chessboard so that   %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  no queens each other;    %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  two queens share the     %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  same row, column, or     %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  The chess queens can     %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  attack in any direction  %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  as horizontal, vertical  %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  and diagonal way.        %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 192, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 218, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  in this version, rules   %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  are very very simple ;)  %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  What is your desicion?   %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  u can enter ", 179);
    SetColor(2);
    printf("a/A");
    SetColor(0);
    printf(" to ");
    SetColor(2);
    printf("ADD");
    SetColor(0);
    printf("   %c", 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  or ", 179);
    SetColor(4);
    printf("r/R");
    SetColor(0);
    printf(" to ");
    SetColor(4);
    printf("REMOVE");
    SetColor(0);
    printf(" and     %c", 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    printf("\t\t\t%c  ", 179);
    SetColor(3);
    printf("m/M");
    SetColor(0);
    printf(" to back ");
    SetColor(3);
    printf("MENU");
    SetColor(0);
    printf(".        %c", 179);
    printf("\n");
    printf("\t\t\t%c                           %c", 179, 179);
    printf("\n");
    SetColor(1);
    printf("\t\t\t%c  Enjoy the game  ^_^ !    %c", 179, 179);
    SetColor(0);
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 192, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    printf("\n\n");
    printf("\t\t\t Press any key to continue :D");
    getch();
    system("CLS");
}
/* Board */
int numCollisions;
int whatWrong;
int arrayBoard(int N , char name[])
{
    char chRow, chColumn;
    int row, column;
    char what; // A(a) = Add queen D(d) = Delete queen
    char a[N][N];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0;j < N; j++)
        {
            a[i][j] = ' ';
        }
    }
    int allow;
    allow = N;
    static int MOVE;
    switch(N)
    {
        case 4:
            MOVE = 12;
        break;
        case 5:
            MOVE = 14;
        break;
        case 6:
            MOVE = 16;
        break;
        case 7:
            MOVE = 18;
        break;
        case 8:
            MOVE = 20;
        break;
    }
    while(-1)
    {
        switch(N) // 4 title
        {
            case 4:
                title1();
            break;
            case 5:
                title2();
            break;
            case 6:
                title3();
            break;
            case 7:
                title4();
            break;
            case 8:
                title5();
            break;
        }
        printf("\n\n");
        /************************************************* first row *************************************************/
        switch(N) // 4 shifting table
        {
            case 4:
                printf("\t\t\t  ");
            break;
            case 5:
                printf("\t\t       ");
            break;
            case 6:
                printf("\t\t    ");
            break;
            case 7:
                printf("\t\t ");
            break;
            case 8:
                printf("\t      ");
            break;
        }
        printf("%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 203); // first column
        for(int i = 0 ; i < N - 2; i++)
        {
            printf("%c%c%c%c%c%c", 205, 205, 205, 205, 205, 203); // middle column
        }
        printf("%c%c%c%c%c%c", 205, 205, 205, 205, 205, 187); // final column
        printf("\n");
        switch(N) // 4 shifting table
        {
            case 4:
                printf("\t\t\t  ");
            break;
            case 5:
                printf("\t\t       ");
            break;
            case 6:
                printf("\t\t    ");
            break;
            case 7:
                printf("\t\t ");
            break;
            case 8:
                printf("\t      ");
            break;
        }
        printf("%c", 186); // first column
        for(int i = 0; i < N; i++)
        {
            printf("     %c", 186); // other column
        }
        printf("\n");
        if(row == 0)
        {
            if(what == 'a' || what == 'A')
            {
                a[0][column] = 'Q';
            }
            else if(what == 'r' || what == 'R')
            {
                a[0][column] = ' ';
            }
        }
        switch(N) // 4 shifting table
        {
            case 4:
                printf("\t\t\t  ");
            break;
            case 5:
                printf("\t\t       ");
            break;
            case 6:
                printf("\t\t    ");
            break;
            case 7:
                printf("\t\t ");
            break;
            case 8:
                printf("\t      ");
            break;
        }
        printf("%c", 186);
        // COLOR QUEENS
        for(int i = 0; i < N; i++)
        {
            printf("  ");
            int TEST = 1;
            for(int j = 0; j < 50; j++)
            {
                if(CollisionsArray[0][j] == 1 && CollisionsArray[1][j] == i + 1)
                {
                    if(a[0][i] == 'Q')
                    {
                        SetColor(12);
                        printf("%c", a[0][i]);
                        SetColor(0);
                        TEST = 0;
                        break;
                    }
                }
            }
            if(TEST)
            {
                SetColor(2);
                printf("%c", a[0][i]);
                SetColor(0);
            }
            printf("  %c", 186);
        }
        // COLOR QUEENS // END
        printf("\n");
        switch(N) // 4 shifting table
        {
            case 4:
                printf("\t\t\t  ");
            break;
            case 5:
                printf("\t\t       ");
            break;
            case 6:
                printf("\t\t    ");
            break;
            case 7:
                printf("\t\t ");
            break;
            case 8:
                printf("\t      ");
            break;
        }
        printf("%c", 186); // first column
        for(int i = 0; i < N; i++)
        {
            printf("     %c", 186); // other column
        }
        printf("\n");
        /************************************************* in row *************************************************/
        for(int i = 1; i < N - 1; i++)
        {
            switch(N) // 4 shifting table
            {
                case 4:
                    printf("\t\t\t  ");
                break;
                case 5:
                    printf("\t\t       ");
                break;
                case 6:
                    printf("\t\t    ");
                break;
                case 7:
                    printf("\t\t ");
                break;
                case 8:
                    printf("\t      ");
                break;
            }
            printf("%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 206); // first column
            for(int i = 0 ; i < N - 2; i++)
            {
                printf("%c%c%c%c%c%c", 205, 205, 205, 205, 205, 206); // middle column
            }
            printf("%c%c%c%c%c%c", 205, 205, 205, 205, 205, 185); // final column
            printf("\n");
            switch(N) // 4 shifting table
            {
                case 4:
                    printf("\t\t\t  ");
                break;
                case 5:
                    printf("\t\t       ");
                break;
                case 6:
                    printf("\t\t    ");
                break;
                case 7:
                    printf("\t\t ");
                break;
                case 8:
                    printf("\t      ");
                break;
            }
            printf("%c", 186); // first column
            for(int i = 0; i < N; i++)
            {
                printf("     %c", 186); // other column
            }
            printf("\n");
            for(int i = 1; i < N - 1; i++)
            {
                if(row == i)
                {
                    if(what == 'a' || what == 'A')
                    {
                        a[row][column] = 'Q';
                    }
                    else if(what == 'r' || what == 'R')
                    {
                        a[row][column] = ' ';
                    }
                }
            }
            switch(N) // 4 shifting table
            {
                case 4:
                    printf("\t\t\t  ");
                break;
                case 5:
                    printf("\t\t       ");
                break;
                case 6:
                    printf("\t\t    ");
                break;
                case 7:
                    printf("\t\t ");
                break;
                case 8:
                    printf("\t      ");
                break;
            }
            printf("%c", 186);
            // COLOR QUEENS
            for(int j = 0; j < N; j++)
            {
                printf("  ");
                int TEST = 1;
                for(int k = 0; k < 50; k++)
                {
                    if(CollisionsArray[0][k] == i + 1 && CollisionsArray[1][k] == j + 1)
                    {
                        if(a[i][j] == 'Q')
                        {
                            SetColor(12);
                            printf("%c", a[i][j]);
                            SetColor(0);
                            TEST = 0;
                            break;
                        }
                    }
                }
                if(TEST)
                {
                    SetColor(2);
                    printf("%c", a[i][j]);
                    SetColor(0);
                }
                printf("  %c", 186);
            }
            // COLOR QUEENS // END
            printf("\n");
            switch(N) // 4 shifting table
            {
                case 4:
                    printf("\t\t\t  ");
                break;
                case 5:
                    printf("\t\t       ");
                break;
                case 6:
                    printf("\t\t    ");
                break;
                case 7:
                    printf("\t\t ");
                break;
                case 8:
                    printf("\t      ");
                break;
            }
            printf("%c", 186); // first column
            for(int i = 0; i < N; i++)
            {
                printf("     %c", 186); // other column
            }
            printf("\n");
        }
        /************************************************* final row *************************************************/
        switch(N) // 4 shifting table
        {
            case 4:
                printf("\t\t\t  ");
            break;
            case 5:
                printf("\t\t       ");
            break;
            case 6:
                printf("\t\t    ");
            break;
            case 7:
                printf("\t\t ");
            break;
            case 8:
                printf("\t      ");
            break;
        }
        printf("%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 206); // first column
        for(int i = 0 ; i < N - 2; i++)
        {
            printf("%c%c%c%c%c%c", 205, 205, 205, 205, 205, 206); // middle column
        }
        printf("%c%c%c%c%c%c", 205, 205, 205, 205, 205, 185); // final column
        printf("\n");
        if(row == N - 1)
        {
            if(what == 'a' || what == 'A')
            {
                a[N - 1][column] = 'Q';
            }
            else if(what == 'r' || what == 'R')
            {
                a[N - 1][column] = ' ';
            }
        }
        switch(N) // 4 shifting table
        {
            case 4:
                printf("\t\t\t  ");
            break;
            case 5:
                printf("\t\t       ");
            break;
            case 6:
                printf("\t\t    ");
            break;
            case 7:
                printf("\t\t ");
            break;
            case 8:
                printf("\t      ");
            break;
        }
        printf("%c", 186); // first column
        for(int i = 0; i < N; i++)
        {
            printf("     %c", 186); // other column
        }
        printf("\n");
        switch(N) // 4 shifting table
        {
            case 4:
                printf("\t\t\t  ");
            break;
            case 5:
                printf("\t\t       ");
            break;
            case 6:
                printf("\t\t    ");
            break;
            case 7:
                printf("\t\t ");
            break;
            case 8:
                printf("\t      ");
            break;
        }
        printf("%c", 186);
        // COLOR QUEENS
        for(int i = 0; i < N; i++)
        {
            printf("  ");
            int TEST = 1;
            for(int j = 0; j < 50; j++)
            {
                if(CollisionsArray[0][j] == N && CollisionsArray[1][j] == i + 1)
                {
                    if(a[N - 1][i] == 'Q')
                    {
                        SetColor(12);
                        printf("%c", a[N - 1][i]);
                        SetColor(0);
                        TEST = 0;
                        break;
                    }
                }
            }
            if(TEST)
            {
                SetColor(2);
                printf("%c", a[N - 1][i]);
                SetColor(0);
            }
            printf("  %c", 186);
        }
        // COLOR QUEENS // END
        printf("\n");
        switch(N) // 4 shifting table
        {
            case 4:
                printf("\t\t\t  ");
            break;
            case 5:
                printf("\t\t       ");
            break;
            case 6:
                printf("\t\t    ");
            break;
            case 7:
                printf("\t\t ");
            break;
            case 8:
                printf("\t      ");
            break;
        }
        printf("%c", 186); // first column
        for(int i = 0; i < N; i++)
        {
            printf("     %c", 186); // other column
        }
        printf("\n");
        switch(N) // 4 shifting table
        {
            case 4:
                printf("\t\t\t  ");
            break;
            case 5:
                printf("\t\t       ");
            break;
            case 6:
                printf("\t\t    ");
            break;
            case 7:
                printf("\t\t ");
            break;
            case 8:
                printf("\t      ");
            break;
        }
        printf("%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 202); // first column
        for(int i = 0 ; i < N - 2; i++)
        {
            printf("%c%c%c%c%c%c", 205, 205, 205, 205, 205, 202); // middle column
        }
        printf("%c%c%c%c%c%c", 205, 205, 205, 205, 205, 188); // final column
        printf("\n\n");
        printf("MOVE = ");
        switch(N)
        {
            case 4:
                if(MOVE <= 4)
                {
                    SetColor(12);
                    printf("%d", MOVE);
                    SetColor(0);
                }
                else
                {
                    SetColor(2);
                    printf("%d", MOVE);
                    SetColor(0);
                }
            break;
            case 5:
                if(MOVE <= 5)
                {
                    SetColor(12);
                    printf("%d", MOVE);
                    SetColor(0);
                }
                else
                {
                    SetColor(2);
                    printf("%d", MOVE);
                    SetColor(0);
                }
            break;
            case 6:
                if(MOVE <= 6)
                {
                    SetColor(12);
                    printf("%d", MOVE);
                    SetColor(0);
                }
                else
                {
                    SetColor(2);
                    printf("%d", MOVE);
                    SetColor(0);
                }
            break;
            case 7:
                if(MOVE <= 7)
                {
                    SetColor(12);
                    printf("%d", MOVE);
                    SetColor(0);
                }
                else
                {
                    SetColor(2);
                    printf("%d", MOVE);
                    SetColor(0);
                }
            break;
            case 8:
                if(MOVE <= 8)
                {
                    SetColor(12);
                    printf("%d", MOVE);
                    SetColor(0);
                }
                else
                {
                    SetColor(2);
                    printf("%d", MOVE);
                    SetColor(0);
                }
            break;
        }
        printf("\n\n");
        SetColor(5);
        printf("YOU ARE DOING WELL ");
        printf("\"");
        SetColor(13);
        printf("%s", name);
        SetColor(5);
        printf("\"");
        SetColor(0);
        /************************************************* get cordinate *************************************************/
        printf("\n\n\n");
        printCollisions (N , (char*)a);
        printf("\n\n");
        /*
        for(int i = 0; i < 50; i++)
        {
            if(CollisionsArray[0][i] && CollisionsArray[1][i])
            printf("%d%d ", CollisionsArray[0][i], CollisionsArray[1][i]);
        }
        */
        int checkRepetitious = 0;
        do // preventing to enter repetitious cordinate
        {
            if(checkRepetitious)
            {
                SetColor(4);
                if(whatWrong == 1)
                {
                    printf("\nNO ADD! :((");
                }
                else if(whatWrong == 2)
                {
                    printf("\nNO REMOVE! :((");
                }
                SetColor(12);
                printf("   PLEASE TRY AGAIN\n");
                SetColor(0);
            }
            int check = 0;
            printf("\n");
            SetColor(7);
            for(int i = 0; i < 2; i++)
            {
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
                , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
                , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
                , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
                , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
            }
            SetColor(9);
            printf("\nWhat's your decision now?  ");
            SetColor(1);
            printf("{ADD / REMOVE / MENU}");
            printf("\n");
            SetColor(0);
            /******************************************************************************** step 1 *************/
            do // preventing to enter wrong character for decision
            {
                if(check)
                {
                    SetColor(4);
                    printf("\n");
                    printf("Please Enter Correct Character >>  ");
                    SetColor(0);
                }
                scanf(" %c", &what);
                check++;
                if(what == 'a' || what == 'A')
                { // Add/Remove allowed?
                    if(allow == 0)
                    {
                        SetColor(12);
                        printf("You Cannot Add Queen :(\n");
                        SetColor(0);
                        what = 'm';
                    }
                    else
                    {
                        allow--;
                    }
                }
                else if(what == 'r' || what == 'R')
                {
                    if(allow == N)
                    {
                        SetColor(12);
                        printf("You Cannot Remove Queen :(\n");
                        SetColor(0);
                        what = 'm';
                    }
                }
                else if(what == 'm' || what == 'M')
                {
                    system("CLS");
                    main();
                }
                else
                {
                    allow++;
                } // Add/Remove allowed? //END
            } while(what != 'a' && what != 'A' && what != 'r' && what != 'R' && what != 'm' && what != 'M');
            /******************************************************************************** step 2 *************/
            int checkDo = 0;
            do // preventing to enter wrong cordinate
            {
                do
                {
                    if(checkDo)
                    {
                        printf("\n");
                        SetColor(12);
                        printf("Wrong Order\n");
                        SetColor(0);
                    }
                    SetColor(5);
                    printf("Enter cordinate from set{1, ..., %d} >> \t", N);
                    SetColor(0);
                    scanf(" %c %c", &chRow, &chColumn);
                    checkDo++;
                } while(chRow < 48 || chRow > 57 || chColumn < 48 || chColumn > 57);
                column = chColumn - 48;
                row = chRow - 48;
                checkDo++;
            } while(column <= 0 || column > N || row <= 0 || row > N);
            checkRepetitious++;
        } while(isCorrectCordinate(N , &allow , (char*)a , what , row , column));
        row--;
        column--;
        system("CLS");
        MOVE--;
        if(allow == 0 && numCollisions == 0)
        {
            won();
        }
        else if(allow == 0 && MOVE == 0)
        {
            lose();
        }
    }
}


int printCollisions (int N , char* array)
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            CollisionsArray[i][j] = 0;
        }
    }
    static int which;
    which = 0;
    numCollisions = 0;
    /////////////////// ROW CHECK
    int testFor = 1;
    SetColor(8);
    printf("\n\n");
    printf("ROW CHECK");
    printf("\n\n");
    SetColor(0);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(*((array + (i * N)) + j) == 'Q')
            {
                for(int k = j + 1; k < N; k++)
                {
                    if(*((array + (i * N)) + k) == 'Q')
                    {
                        printf("%d >> %d & %d  ", i + 1, j + 1, k + 1);
                        numCollisions++;
                        // put collisions to CollisionArray //
                        testFor = 1;
                        for(int s = 0; s < 50; s++)
                        {
                            if(CollisionsArray[0][s] == i + 1 && CollisionsArray[1][s] == j + 1)
                            {
                                testFor = 0;
                                break;
                            }
                        }
                        if(testFor)
                        {
                            CollisionsArray[0][which] = i + 1;
                            CollisionsArray[1][which] = j + 1;
                            which++;
                        }
                        testFor = 1;
                        for(int s = 0; s < 50; s++)
                        {
                            if(CollisionsArray[0][s] == i + 1 && CollisionsArray[1][s] == k + 1)
                            {
                                testFor = 0;
                                break;
                            }
                        }
                        if(testFor)
                        {
                            CollisionsArray[0][which] = i + 1;
                            CollisionsArray[1][which] = k + 1;
                            which++;
                        }
                        // put collisions to CollisionArray //END
                    }
                }
            }
        }
    }
    /////////////////// COLUMN CHECK
    SetColor(8);
    printf("\n\n");
    printf("COLUMN CHECK");
    printf("\n\n");
    SetColor(0);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(*((array + (j * N)) + i) == 'Q')
            {
                for(int k = j + 1; k < N; k++)
                {
                    if(*((array + (k * N)) + i) == 'Q')
                    {
                        printf("%d >> %d & %d  ", i + 1, j + 1, k + 1);
                        numCollisions++;
                        // put collisions to CollisionArray //
                        testFor = 1;
                        for(int s = 0; s < 50; s++)
                        {
                            if(CollisionsArray[1][s] == i + 1 && CollisionsArray[0][s] == j + 1)
                            {
                                testFor = 0;
                                break;
                            }
                        }
                        if(testFor)
                        {
                            CollisionsArray[0][which] = j + 1;
                            CollisionsArray[1][which] = i + 1;
                            which++;
                        }
                        testFor = 1;
                        for(int s = 0; s < 50; s++)
                        {
                            if(CollisionsArray[1][s] == i + 1 && CollisionsArray[0][s] == k + 1)
                            {
                                testFor = 0;
                                break;
                            }
                        }
                        if(testFor)
                        {
                            CollisionsArray[0][which] = k + 1;
                            CollisionsArray[1][which] = i + 1;
                            which++;
                        }
                        // put collisions to CollisionArray //END
                    }
                }
            }
        }
    }
    /////////////////// DIAGONAL CHECK
    SetColor(8);
    printf("\n\n");
    printf("DIAGONAL CHECK (\\)");
    printf("\n\n");
    SetColor(0);
    // 1 (\)
    for(int i = 0; i < N; i++) // Right Diagonal (Nihal tnx)
    {
        int k = 0, l = i;
        while(k < N && l < N)
        {
            if(*((array + (k * N)) + l) == 'Q')
            {
                int m = k + 1, n = l + 1;
                while(m < N && n < N)
                {
                    if(*((array + (m * N)) + n) == 'Q')
                    {
                        printf("%d,%d && %d,%d   ", k + 1, l + 1, m + 1, n + 1);
                        numCollisions++;
                        // put collisions to CollisionArray //
                        testFor = 1;
                        for(int s = 0; s < 50; s++)
                        {
                            if(CollisionsArray[0][s] == k + 1 && CollisionsArray[1][s] == l + 1)
                            {
                                testFor = 0;
                                break;
                            }
                        }
                        if(testFor)
                        {
                            CollisionsArray[0][which] = k + 1;
                            CollisionsArray[1][which] = l + 1;
                            which++;
                        }
                        testFor = 1;
                        for(int s = 0; s < 50; s++)
                        {
                            if(CollisionsArray[0][s] == m + 1 && CollisionsArray[1][s] == n + 1)
                            {
                                testFor = 0;
                                break;
                            }
                        }
                        if(testFor)
                        {
                            CollisionsArray[0][which] = m + 1;
                            CollisionsArray[1][which] = n + 1;
                            which++;
                        }
                        // put collisions to CollisionArray //END
                    }
                    m++;
                    n++;
                }
            }
            k++;
            l++;
        }
    }
    for(int i = 1; i < N - 1; i++) // Left Diagonal (Nihal tnx)
    {
        int k = i, l = 0;
        while(k < N && l < N)
        {
            if(*((array + (k * N)) + l) == 'Q')
            {
                int m = k + 1, n = l + 1;
                while(m < N && n < N)
                {
                    if(*((array + (m * N)) + n) == 'Q')
                    {
                        printf("%d,%d && %d,%d   ", k + 1, l + 1, m + 1, n + 1);
                        numCollisions++;
                        // put collisions to CollisionArray //
                        testFor = 1;
                        for(int s = 0; s < 50; s++)
                        {
                            if(CollisionsArray[0][s] == k + 1 && CollisionsArray[1][s] == l + 1)
                            {
                                testFor = 0;
                                break;
                            }
                        }
                        if(testFor)
                        {
                            CollisionsArray[0][which] = k + 1;
                            CollisionsArray[1][which] = l + 1;
                            which++;
                        }
                        testFor = 1;
                        for(int s = 0; s < 50; s++)
                        {
                            if(CollisionsArray[0][s] == m + 1 && CollisionsArray[1][s] == n + 1)
                            {
                                testFor = 0;
                                break;
                            }
                        }
                        if(testFor)
                        {
                            CollisionsArray[0][which] = m + 1;
                            CollisionsArray[1][which] = n + 1;
                            which++;
                        }
                        // put collisions to CollisionArray //END
                    }
                    m++;
                    n++;
                }
            }
            k++;
            l++;
        }
    }
    // 2 (/)
    SetColor(8);
    printf("\n\n");
    printf("DIAGONAL CHECK (/)");
    printf("\n\n");
    SetColor(0);
    for(int i = 0 ; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(*((array + (i * N)) + j) == 'Q')
            {
                for(int k = i + 1, l = j - 1; k < N, l >= 0; k++, l--)
                {
                    if(*((array + (k * N)) + l) == 'Q')
                    {
                        printf("%d,%d && %d,%d   ", i + 1, j + 1, k + 1, l + 1);
                        numCollisions++;
                        // put collisions to CollisionArray //
                        testFor = 1;
                        for(int s = 0; s < 50; s++)
                        {
                            if(CollisionsArray[0][s] == i + 1 && CollisionsArray[1][s] == j + 1)
                            {
                                testFor = 0;
                                break;
                            }
                        }
                        if(testFor)
                        {
                            CollisionsArray[0][which] = i + 1;
                            CollisionsArray[1][which] = j + 1;
                            which++;
                        }
                        testFor = 1;
                        for(int s = 0; s < 50; s++)
                        {
                            if(CollisionsArray[0][s] == k + 1 && CollisionsArray[1][s] == l + 1)
                            {
                                testFor = 0;
                                break;
                            }
                        }
                        if(testFor)
                        {
                            CollisionsArray[0][which] = k + 1;
                            CollisionsArray[1][which] = l + 1;
                            which++;
                        }
                        // put collisions to CollisionArray //END
                    }
                }
            }
        }
    }
}

int isCorrectCordinate(int N , int* allow , char* array , char what, int x, int y)
{
    whatWrong = 0;
    if(what == 'a' || what == 'A')
    {
        if(*((array + (x - 1) * N) + (y - 1)) == 'Q')
        {
            whatWrong = 1;
            (*allow)++;
            return 1;
        }
        return 0;
    }
    else if(what == 'r' || what == 'R')
    {
        if(*((array + (x - 1) * N) + (y - 1)) == ' ')
        {
            whatWrong = 2;
            (*allow)--;
            return 1;
        }
        return 0;
    }
    return 0;
}

int autoPlay()
{
    unsigned NofQauto;//NUMBER OF QUEEN THAT USE IN AUTOPLAY MODE
    printf("enter size");
    scanf("%d", &NofQauto);
    system("CLS");
    chess* c = createChess(NofQauto);
    //start clock
    clock_t t;
    t = clock();
    chess* result  = solve(c);
    //stop clock
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Solving this function took %f seconds =) \n\n\n", time_taken);

    if (result==NULL)
    {
        printf("Answer not found!\n");
    }else
    {
        printChess(result);
    }
    deleteChess(result);
    getch();
    system("CLS");
}

void deleteStack(stack* s)
{
    //first delete content inside of s
    free(s -> array);
    free(s);
}

int isEmpty(stack* s)
{
    return s -> top == 0;
}

int isFull(stack* s)
{
    return s -> top == s -> capacity;
}
void push(stack* s, chess* c)
{
    if(isFull(s))
    {
        printf("Could not insert data, Stack is full.\n");
        exit(0);
    }
    s -> array[s -> top] = c;
    s -> top++;
}

void printChess(chess* c)
{
    for (unsigned i = 1; i <= c -> numberOfQueens; i++)
    {
        for (unsigned j = 1; j <= c -> numberOfQueens; j++)
        {
            if (c -> board[j - 1] == i)
            {
                printf("Q");
            }else
            {
                printf("-");
            }
            printf("\t");
        }
        printf("\n\n");
    }
}

int collisions(chess* c)
{
    for(unsigned i=0;i<c->numberOfQueens;i++)
    {
        int x1, x2, y1, y2;
        if(c -> board[i] != 0)
        {
            x1 = (int)i;
            y1 = (int)c -> board[i];
            for(unsigned j = i+1; j< c -> numberOfQueens; j++)
            {
                if(c -> board[j] != 0)
                {
                    x2 = (int)j;
                    y2 = (int)c -> board[j];
                    if(abs(y2 - y1) == abs(x2 - x1) || y2 - y1 == 0)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0; //no conflicts
}

void deleteChess(chess* c)
{
    if(c == NULL) return;
    free(c -> board);
    free(c);
}

void getActions(chess* c , ACTION* actionList)
{

    if(c -> board[c -> currentQueens] < c -> numberOfQueens)
    {
        actionList[0] = NEXT_ROW;
    }
    else
    {
        actionList[0] = NONE;
    }

    if(c -> board[c -> currentQueens] != 0 && c -> currentQueens < c -> numberOfQueens - 1)
    {
        actionList[1] = NEXT_QUEEN;
    }
    else
    {
        actionList[1] = NONE;
    }
}

int isGoal(chess* c){
    return c -> numberOfQueens == c -> currentQueens + 1 && c -> board[c -> currentQueens] != 0;
}

void won()
{
    system("COLOR A0");
    title();
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 218, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for(int i = 0; i < 2; i++)
    {
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
    }
    printf(" Press Enter to continue :D");
    getch();
    system("CLS");
    main();
}

void lose()
{
    system("COLOR C0");
    title();
    printf("\n");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    , 218, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
    , 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for(int i = 0; i < 2; i++)
    {
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196
        , 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
    }
    printf(" Press Enter to continue :D");
    getch();
    system("CLS");
    main();
}
