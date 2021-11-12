//#include <iostream>
#include "dlist.h"

using namespace std;

int main() {
    string command = "restart";
    long long i, sum, time, time_check;
    int colors;
    DList<int> list = DList<int>();
    while(true)
    {
        if(command == "no")
            break;
        else if(command == "restart")
        {
            sum = 0;
            time = 0;

            cout << "How many colors?\n";
            cin >> colors;
            cout << "What is the check time?\n";
            cin >> time_check;
        }
        else if(command == "help")
        {
            cout << "'no' to stop \n'restart' to restart\n'help' to see all commands\n'yes' to continue\n";
        }


        i = 0;
        for(;i < time_check; i++)
        {
            int current = random()%colors+1;
            bool chose = false;
            if(list.start->previous == list.start)
                chose = true;
            Node<int>* x = list.cursor;
            for(int j = 0;!chose && j < 5; j++)
            {
                if(x == list.start)
                    break;
                if(x->src == current) {
                    chose = true;
                    list.cursor = x;
                }

                x = x->previous;
            }
            x = list.cursor;
            for(int j = 0;!chose && j < 5; j++)
            {
                if(x == list.start)
                    break;
                if(x->src == current) {
                    chose = true;
                    list.cursor = x;
                }
                x = x->next;
            }
            if
            (
                   list.cursor->previous->src == current
                   || list.cursor->next->src == current
            )
            {
                while(list.cursor != list.start && list.cursor->src == current)
                {
                    if(list.cursor->previous->src == current)
                        list.delete_before_cursor();
                    else
                        list.delete_cursor();
                    sum++;
                }
            }
            else
                list.push_cursor(current);
        }
        time += i;
        cout << "\nCurrent list is ";
        cout << list;
        cout << "\nCurrent time is " << time << "\nCurrent points are " << sum << "\nContinue? (Enter 'help' to see all commands)\n";
        cin >> command;
        cout << endl;
    }

    return 0;
}
