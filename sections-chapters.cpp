#include <iostream>
#include <string.h>
using namespace std;
struct node
{
    char label[10];
    int ch_count;
    struct node *child[10];
} *root;
class BST
{
public:
    void createTree();
    void display(node *r1);
    BST()
    {
        root = NULL;
    }
};
void BST::createTree()
{
    int tbooks, tchapters, i, j, k;
    root = new node();
    cout << "Enter name of book";
    cin >> root->label;
    cout << "Enter no. of chapters in book";
    cin >> tchapters;
    root->ch_count = tchapters;
    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;
        cout << "Enter Chapter name\n";
        cin >> root->child[i]->label;
        cout << "Enter no.of sections in this Chapter:";
        cin >> root->child[i]->ch_count;
        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter section head";
            cin >> root->child[i]->child[j]->label;
        }
    }
}
void BST::display(node *r1)
{
    int i, j, k, tchapters;
    if (r1 != NULL)
    {
        cout << "\n-----Book Hierarchy----";
        cout << "\n Book title : " << r1->label;
        tchapters = r1->ch_count;
        for (i = 0; i < tchapters; i++)
        {
            cout << "\n  Chapter " << i + 1;
            cout << " " << r1->child[i]->label;
            cout << "\n Sections";
            for (j = 0; j < r1->child[i]->ch_count; j++)
            {
                cout << "\n  " << r1->child[i]->child[j]->label;
            }
        }
    }
}
int main()
{
    int choice;
    BST bst;
    while (1)
    {
        cout << "\n-----------------" << endl;
        cout << "Book Tree Creation" << endl;
        cout << "-----------------" << endl;
        cout << "1.Create" << endl;
        cout << "2.Display" << endl;
        cout << "3.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            bst.createTree();
        case 2:
            bst.display(root);
            break;
        case 3:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
}