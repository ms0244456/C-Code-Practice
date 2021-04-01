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
            if(input[i] > input[j])
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

    int num = 0;
    cout << "input a number: ";
    cin >> num;

    //binary_search
    int hi = index,low=0;
    int flag = 0;
    while(hi > low)
    {
        if(num == input[(hi+low)/2])
        {
            flag = 1;
            break;
        }
        else if(num > input[(hi+low)/2])
        {
            low = (hi + low) / 2 + 1;
        }
        else{
            hi = (hi + low) / 2 + - 1;
        }
    }

    if(flag == 1){cout << "We can find " << num << " in the sorted array."<<endl; }
    else{cout << "We cannot find " << num << " in the sorted array."<<endl;}

    return 0;
    
}
