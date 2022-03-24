/*

ANSI Escape codes are a standard for in-band signaling to control cursor location,
color, font styling, and other options on video text terminals and terminal emulators

I also use  ANSI Escape Codes to change the text color.

refere here more   https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

*/
#include <bits/stdc++.h>
#include <conio.h> // to import getch() method, which allows to take a single character from the user and proceed to the next iteration without pressing enter key
#include <cmath>   // for pow(2.n) to calculate the total number of moves allowed
#include <windows.h>

using namespace std;

class Stack // user defined Stack data structure
{
private:
    int static const size = 100000;
    int arr[size];
    int top = -1;

public:
    bool is__empty()
    {
        if (top == -1)
            return true;
        return false;
    }

    bool is__full()
    {
        if (top == size - 1)
            return true;
        return false;
    }

    void push(int num)
    {
        if (!is__full())
        {
            top++;
            arr[top] = num;
            return;
        }
    }

    void pop()
    {
        if (!is__empty())
        {
            top--;
            return;
        }
    }

    int get_length()
    {
        return top + 1;
    }

    void display()
    {
        if (!is__empty())
        {
            for (int i = 0; i <= top; i++)
                cout << arr[i] << " ";
        }
    }

    int peek() // returns the top value but not remove it
    {
        if (!is__empty())
            return arr[top];
        return -1;
    }
    int specific_value(int n) // returns a specific stack element by its index
    {
        if (n <= top)
        {
            return arr[n];
        }
        else
            return -1;
    }

    void stack_reset()
    {
        top = -1;
    }
};

Stack Rod_1, Rod_2, Rod_3;
int n = 0; // it is global variable and used as disk size,show_tower,fill_rod_1

// method decalations, there implementation is give below them
void take_user_choice();
void start_playing_the_game();
void take_disk_size();
void invalid_disk_number_error_message();

/*
1, enter disk number
2, after winning

 */

void launch_window() // the fist method called in the game and displays a general description about the game
{
    system("cls");
    cout << "\n\n\n\t\x1B[1;;34m\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\n";
    cout << "        \xb2                                                                                  \t\t\t\t\t\t\xb2\n";
    cout << "\t\xb2 \t The Towers of Hanoi is an ancient mathematical puzzle played with three rods and N number of disks.     \t\t\xb2\n";
    cout << "\t\xb2 \t At the start, all the disks are in the leftmost stack, with the largest disk on the bottom and the smallest \t\t\xb2\n";
    cout << "\t\xb2 \t on the top.                                                                                \t\t\t\t\xb2\n";
    cout << "        \xb2                                                                                  \t\t\t\t\t\t\xb2\n";
    cout << "\t\xb2 \t The goal of the puzzle is to get all the disks over to the rightmost stack,\t\t\t\t\t\t\xb2\n";
    cout << "\t\xb2 \t obeying the following three simple rules:\t\t\t\t\t\t\t\t\t\t\xb2 \n";
    cout << "        \xb2                                                                                  \t\t\t\t\t\t\xb2\n";
    cout << "\t\xb2 \t1. Only one disk can be moved at a time.\t\t\t\t\t\t\t\t\t\t\xb2\n";
    cout << "        \xb2                                                                                  \t\t\t\t\t\t\xb2\n";
    cout << "\t\xb2 \t2. disk can only be moved if it is the uppermost disk on a stack.\t\t\t\t\t\t\t\xb2\n";
    cout << "        \xb2                                                                                  \t\t\t\t\t\t\xb2\n";
    cout << "\t\xb2 \t3. No disk may be placed on top of a smaller disk.\t\t\t\t\t\t\t\t\t\xb2\n";
    cout << "        \xb2                                                                                  \t\t\t\t\t\t\xb2\n";
    cout << "        \xb2                                                                                  \t\t\t\t\t\t\xb2\n";
    cout << "\t\xb2\t          .....press anykey to continiue playing the game.....   Press E or e to EXIT \t\t\t\t\t\xb2\n";
    cout << "        \xb2                                                                                  \t\t\t\t\t\t\xb2\n";
    cout << "\t\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\x1B[0m\n\n\n\n";
}

void move(Stack &source, Stack &destination) // move a disk form source rod to the other rod, destination
{
    destination.push(source.peek());
    source.pop();
    return;
}

void Navigation_key() // navigation keys to move one disk from the other
{
    cout << "\n\t\t Navigation keys\n";
    cout << "\t\t\t  Press 12 to move disk from rod 1 to rod 2 \t Press 21 to move disk from rod 2 to rod 1 \t Press 31 to move disk from rod 3 to rod 1 \n";
    cout << "\t\t\t  Press 13 to move disk from rod 1 to rod 3 \t Press 23 to move disk from rod 2 to rod 3 \t Press 32 to move disk from rod 3 to rod 2 \n\n";
}

void show_tower() // displays the three stack for the user
{

    for (int i = n - 1; i >= 0; i--)
    {

        cout << "\t\t\t\t\xb2";
        cout.width(4);
        cout << ((Rod_1.specific_value(i) >= 1 && Rod_1.specific_value(i) <= n) ? to_string(Rod_1.specific_value(i)) : "");
        cout.width(3);
        cout << "";

        cout << "\xb2 \t\t\t\xb2";
        cout.width(4);
        cout << ((Rod_2.specific_value(i) >= 1 && Rod_2.specific_value(i) <= n) ? to_string(Rod_2.specific_value(i)) : "");
        cout.width(3);
        cout << "";

        cout << "\xb2\t\t\t\xb2";
        cout.width(4);
        cout << ((Rod_3.specific_value(i) >= 1 && Rod_3.specific_value(i) <= n) ? to_string(Rod_3.specific_value(i)) : "");
        cout.width(3);
        cout << "";
        cout << "\xb2\n";

        //

        cout << "\t\t\t\t\xb2";
        cout.width(4);
        cout << "______";
        cout.width(1);
        cout << "_";

        cout << "\xb2 \t\t\t\xb2";
        cout.width(4);
        cout << "______";
        cout.width(1);
        cout << "_";

        cout << "\xb2\t\t\t\xb2";
        cout.width(4);
        cout << "______";
        cout.width(1);
        cout << "_";
        cout << "\xb2\n";
    }

    cout << "\n\t\t\t\t";
    cout.width(4);
    cout << " Rod 1";
    cout.width(3);
    cout << "  ";

    cout << "\t\t\t";
    cout.width(4);
    cout << " Rod 2";
    cout.width(3);
    cout << "";

    cout << "\t\t\t";
    cout.width(4);
    cout << "  Rod 3";
    cout.width(3);
    cout << "";

    cout << "\n\n";
}

void fill_rod_1(int n) // fills rod 1 when the user enters number of disk from 1 to n, upside down
{
    for (int i = n; i >= 1; i--)
    {
        Rod_1.push(i);
    }
}

void exit_game() // exit from the game
{
    system("cls");

    cout << "\t\t\x1B[31m\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t\t\t\t\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t\x1B[41;37m SORRY, YOU HAVE EXITED FROM THE GAME !! \x1B[0m\t\t \x1B[31m\xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t\t\t\t\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t\t\t\t\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\x1B[0m";
    cout << "\n\n\n";
    exit(0); // exit from the game or terminate
}

void move_from_empty_disk_error_message() // displays error message if the user tries to move from empty disk
{
    system("cls");
    cout << "\n\n\n\t \x1B[1;31m+------------------------------------------------------------------------------------+\n";
    cout << "\t | \t\x1B[1;41;37m  You are trying to move from an empty Rod !!!   Please try another move. \x1B[0m  \x1B[1;31m  |\n";
    cout << "\t +------------------------------------------------------------------------------------+\x1b[0m\n";
}

void pressed_wrong_key_error_message() // displays error message when the user press wrong key
{
    system("cls");
    cout << "\n\n\n\t\x1B[1;31m +-------------------------------------------------------------------------------------+\n";
    cout << "\t | \t\x1B[1;41;37m You have pressed wrong key, Please read the instruction very carefuly !!! \x1B[0m \x1B[1;31m   |\n";
    cout << "\t\x1B[1;31m +-------------------------------------------------------------------------------------+\x1B[0m\n";
}

void wrong_move_error_message() // displays error message when the user moves large disk on top of smaller .
{
    system("cls");
    cout << "\n\n\n\t\x1B[1;31m +------------------------------------------------------------------------------------+\n";
    cout << "\t |\t\x1B[1;41;37m Wrong move! You can't move larger number on the top of smaller number !!! \x1B[0m\x1B[1;31m   |\n";
    cout << "\t \x1B[1;31m+------------------------------------------------------------------------------------+\x1B[0m\n";
}

void congratulation() // after the user completed playing the game , this message will appear
{
    system("cls");
    cout << "\n\n\n\n\n";

    cout << "\t\t\x1b[1;32m\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t\t\t\t\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t  BRAVO, YOU WON THE GAME !!!\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t\t\t\t\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\n\n\n\n";
    show_tower();
    cout << "\x1b[0m";
    cout << "\n\n\n";

    Sleep(2000);

    cout << "\n\t\x1B[1;32m +----------------------------------------------------------------------------------+\n";
    cout << "\t | \t\x1B[1;36m \t You are amazing player, Do You Want to Play the Game Again !   \x1B[0m \x1B[1;32m   |\n";
    cout << "\t\x1B[1;32m +----------------------------------------------------------------------------------+\x1B[0m\n\n";
    Sleep(2000);

    Rod_1.stack_reset(); // The rods should be empty before new game is started
    Rod_2.stack_reset();
    Rod_3.stack_reset();

    take_disk_size();
}

void game_over() // if the user is out of move this message becomes displayed
{
    system("cls");

    cout << "\t\t\x1B[31m\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t\t\t\t\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t\t\t\t\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t \x1B[41;37m GAMEOVER !!! \x1B[0m\t\t\t\t\t\t \x1B[31m\xb2\xb2\n";

    cout << "\t\t\xb2\xb2\t\t\t\t\t\t\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\x1b[0m \x1b[1;31m press anykey to continiue playing the game...  Press E or e to EXIT \x1b[0m \t \x1b[31m\xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t\t\t\t\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 \x1b[0m";
    cout << "\n\n";

    Rod_1.stack_reset();
    Rod_2.stack_reset();
    Rod_3.stack_reset();

    take_user_choice();
}

void invalid_disk_number_error_message() // if the user enters invalid number for disk size this message will appear
{
    system("cls");

    cout << "\n\n\t\t\x1B[31m\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t\t\t\t\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t\t\t\t\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\x1B[1;41;37m  Sorry, You have entered invalid input.  \x1B[0m \x1B[31m  \t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\x1B[1;41;37m please try again. \x1b[0m \x1B[31m \t\t\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\t\t\t\t\t\t\t\t\t\t \xb2\xb2\n";
    cout << "\t\t\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2";
    cout << "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\x1b[0m";
    cout << "\n\n";

    exit(0);
}

void game_exiting_options_message() // tells the user how to exit from the game anytime
{
    cout << "\n\n\n\t\x1B[1;32m +-------------------------------------------------------------------------------------------------------------------------+\n";
    cout << "\t | \t\x1B[1;36m After entering the number of Disks, you can exit from the game anytime you want by pressing 'e' or 'E'  !!!   \x1B[0m \x1B[1;32m   |\n";
    cout << "\t\x1B[1;32m +-------------------------------------------------------------------------------------------------------------------------+\x1B[0m\n\n";
}

/////////////////////////

void ____wrong_input_error_message()
{
    system("cls");
    cout << "\n\n\n\t\x1B[1;31m +-----------------------------------------------------------------------------------------------------------------------+\n";
    cout << "\t | \t\x1B[1;31m \t\t\t\t INVALID INPUT !!! \t\t\t\t\t\t\t\t |\n";
    cout << "\t | \t\t\t Disk size can only be counting numbers like 1,2,... not any other character.\t\t\t |\n";
    cout << "\t | \t\t\t\t\t\t\t\t   \t\t\t\t\t\t\t |\n";
    cout << "\t | \t\t\t\t\t\t\t        Enter a valid input, please . . .  \t\t\t\x1B[0m \x1B[1;31m|\n";
    cout << "\t\x1B[1;31m +-----------------------------------------------------------------------------------------------------------------------+\x1B[0m\n\n";
}

int tenth_multiplier(int digit_count) // accepts the digit count of a number, like 124 has 3 digit count
{
    int ten = 1; // it  multiplied with 10 in the for loop, being 1 doesn't change the value

    for (int i = 1; i <= digit_count; i++)
    {
        ten = ten * 10;
    }
    return ten; /* returns the digit count of a number or tenth-multiplier
                        1,2,...9 have tenth-multiplier of 1
                        10,20,...90 have tenth-multiplier of 2
                        100,200,...900 have tenth-multiplier of 3  etc. */
}

int convert_to_number(string user_input)
{
    /*
    if the numbers enterd by the user are all numbers, this function converts these string to integer equivalent
    like string num = "1234" to int Number = 1234
     */
    int Number = 0;
    for (int i = 0; i < user_input.length(); i++)
    {
        int digit_count = user_input.length() - (1 + i); // counts the number of digit, 124 has 3 digit
        Number += (user_input[i] - '0') * tenth_multiplier(digit_count);
    }
    return Number;
}

void Enter_Integer_only()
{

    string num;
    int digit_count = 0;

    ____wrong_input_error_message();

    cout << "\n\n\t\tEnter only a number, please ...";
    cin >> num;

    if (num == "E" || num == "e")
        exit_game();

    for (int i = 0; i < num.length(); i++)
    {
        if (isdigit(num[i]))
            ++digit_count;
    }

    if (digit_count == num.length()) // is the digit count equals with string.length(), all the input characters are numbers
    {
        n = convert_to_number(num); // the number is assigned to n,as you know  n is used in start_playing_the_game(). And do not confused with n b/ce you know
        start_playing_the_game();
    }

    else
        Enter_Integer_only();
}

void take_disk_size() // takes the disk size from the user
{
    string num; // takes whatever the user enters
    int c = 0;  // if all the user input is number(Natural Numbers 1,2...), it holds digit count

    cout << "\n\n\t\tEnter the number of disks..... ";
    cin >> num;

    if (num == "E" || num == "e")
        exit_game();

    for (int i = 0; i < num.length(); i++)
    {
        if (isdigit(num[i]))
            ++c;
    }

    if (c == num.length()) // is the digit count equals with string.length(), all the input characters are numbers
    {
        n = convert_to_number(num);
        start_playing_the_game();
    }
    else
    {
        game_exiting_options_message();
        Enter_Integer_only();
    }
}

////////////////

void take_user_choice() // checks if the user wants to continue playing or exit the game
{
    char choice = getch(); // takes  a single character from the user adn proceed to the next line
    system("cls");

    if ((choice == 'e') || (choice == 'E')) // if the user enter 'e'or 'E' the game will exit
        exit_game();
    else
        take_disk_size();
}

void start_playing_the_game()
{
    system("cls");

    /*

     - if the user input is too large, data type -int may not be enough to hold the total number of moves
       hence long long modifier is used,
     - And the total number of move never becomes negative, making unsigned ensures only positive numbers are stored

     */
    unsigned long int Number_of_move = pow(2, n) - 1;
    unsigned long int total = Number_of_move + 3;
    unsigned long int counter = total;

    fill_rod_1(n);
    cout << "\x1B[1;33;44m";
    cout << "\n\n\n\n\t\t\t\tMOVE : " << 0 << " \x1B[0m\t\t\t\t\t \x1B[1;33;44mNUMBER OF MOVES LEFT : " << counter << "\x1B[0m\n\n\n";
    cout << "\x1B[1;34m";
    show_tower();
    cout << "\x1B[0m";

    for (unsigned long int i = 0; i <= total; i++)
    {

        Navigation_key();

        cout << "\n\n\t\tEnter your next move...";

        string next_move;
        cin >> next_move;

        int numberOfmoves = i + 1;

        if (next_move == "12") // case 12:
        {
            if (Rod_1.get_length() == 0)
            {
                move_from_empty_disk_error_message();
            }

            else if (Rod_1.peek() > Rod_2.peek() && !Rod_2.is__empty())
            {
                wrong_move_error_message();
            }

            else
            {
                move(Rod_1, Rod_2);
                system("cls");
            }
        }

        else if (next_move == "13") // case 13: // a_>c

        {
            if (Rod_1.get_length() == 0)
            {
                move_from_empty_disk_error_message();
            }

            else if (Rod_1.peek() > Rod_3.peek() && !Rod_3.is__empty())
            {
                wrong_move_error_message();
            }
            else
            {
                move(Rod_1, Rod_3);
                system("cls");
            }
        }

        else if (next_move == "21") // case 21: // b->a

        {
            if (Rod_2.get_length() == 0)
            {
                move_from_empty_disk_error_message();
            }
            else if (Rod_2.peek() > Rod_1.peek() && !Rod_1.is__empty())
            {
                wrong_move_error_message();
            }
            else
            {
                move(Rod_2, Rod_1);
                system("cls");
            }
        }

        else if (next_move == "23") // case 23: // b->a
        {
            if (Rod_2.get_length() == 0)
            {
                move_from_empty_disk_error_message();
            }
            else if (Rod_2.peek() > Rod_3.peek() && !Rod_3.is__empty())
            {
                wrong_move_error_message();
            }
            else
            {
                move(Rod_2, Rod_3);
                system("cls");
            }
        }

        else if (next_move == "31") // case 31: // c->a
        {
            if (Rod_3.get_length() == 0)
            {
                move_from_empty_disk_error_message();
            }
            else if (Rod_3.peek() > Rod_1.peek() && !Rod_1.is__empty())
            {
                wrong_move_error_message();
            }

            else
            {
                move(Rod_3, Rod_1);
                system("cls");
            }
        }

        else if (next_move == "32") // case 32: // c ->b
        {
            if (Rod_3.get_length() == 0)
            {
                move_from_empty_disk_error_message();
            }
            else if (Rod_3.peek() > Rod_2.peek() && !Rod_2.is__empty())
            {
                wrong_move_error_message();
            }
            else
            {
                move(Rod_3, Rod_2);
                system("cls");
            }
        }

        else if (next_move == "e" || next_move == "E") // if the user input is one of them, the game will exit
            exit_game();

        else
        {
            pressed_wrong_key_error_message();
        }

        cout << "\x1B[1;33;44m";
        cout << "\n\n\n\n\t\t\t\tMOVE : " << numberOfmoves << "\x1B[0m\t\t\t\t\t\x1B[1;33;44mNUMBER OF MOVES LEFT : " << --counter << "\x1B[0m\n\n\n";
        cout << "\x1B[1;34m";
        show_tower();
        cout << "\x1B[0m";

        if ((Rod_1.is__empty() && Rod_2.is__empty()) && Rod_3.get_length() == n) // checkes if the game is completed and go to displays congratulation message
            congratulation();

        if (numberOfmoves == total) // checks if the move is equal to the allowed move
            game_over();
    }
}

int main()
{
    launch_window();
    take_user_choice();
    return 0;
}
