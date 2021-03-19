#include<iostream>
using namespace std;

int main()
{
    int input[100] = {0},index = 0,input_num = 0;
    cout << "Input some numbers :";
    while(cin >> input_num)
    {
        input[index] = input_num;
        index ++;

        char ch = getchar();
        if(ch == '\n'){break;}
    }

    for(int i=0;i<index;i++)
    {
        for(int j=i;j<index;j++)
        {
            if(input[i] < input[j])
            {
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }

    cout << "Sorted Result: ";
    for(int i=0;i<index;i++)
    {
        cout << input[i];
        if(i != (index-1))
        {
            cout << " ";
        }
        else{cout << endl;}
    }

    return 0;
    
}