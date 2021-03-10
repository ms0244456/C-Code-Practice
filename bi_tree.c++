#include <iostream>
using namespace std;
/*
    定義節點結構
    每一個node包含值以及左右子節點
*/
struct node
{
    char data;
    node * left_child;
    node * right_child;
} * Bi_tree;    //宣告一個二元樹

//建樹
bool createBinaryTree(node * &t)
{
    //輸入要建樹之元素
    char ch;
    cin >> ch;
    //若輸入元素為0,則代表t節點無元素
    if(ch == '0'){t = NULL;}
    else
    {
        t = new node;
        //若t為空,則跳出
        if(t == NULL)
        {
            return false;
        }
        //若t不為空,則此節點為ch,並建立左右子節點
        else
        {
            t->data = ch;
            createBinaryTree(t->left_child);
            createBinaryTree(t->right_child);
        }
    }
    return true;
}
//前中後序皆為印出節點的步驟
//前序拜訪,根 左 右
void PreOrderTravel(node * t)
{
    //若t為空,跳出
    if(t == NULL){return;}
    else
    {
        //先印根,然後左,最後右
        cout << t->data;
        PreOrderTravel(t->left_child);
        PreOrderTravel(t->right_child);
    }
}
//中序拜訪,左 根 右
void InOrderTravel(node * t)
{
    //若t為空,跳出
    if(t == NULL){return;}
    else
    {
        //先左,然後印根,最後右
        InOrderTravel(t->left_child);
        cout << t->data;
        InOrderTravel(t->right_child);
    }
}
//後序拜訪,左 右 根
void PostOrderTravel(node * t)
{
    //若t為空,跳出
    if(t == NULL){return;}
    else
    {
        //先左,然後右,最後印根
        PostOrderTravel(t->left_child);
        PostOrderTravel(t->right_child);
        cout << t->data;
    }
}

int main()
{
    createBinaryTree(Bi_tree);
    cout << "PreOrder" << endl;
    PreOrderTravel(Bi_tree);
    cout << endl;
    cout << "InOrder" << endl;
    InOrderTravel(Bi_tree);
    cout << endl;
    cout << "PostOrder" << endl;
    PostOrderTravel(Bi_tree);
    cout << endl;
    return 0;
}
