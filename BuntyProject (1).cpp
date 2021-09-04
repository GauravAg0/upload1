
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef struct node
{
    char k[100];
    char m[100];
    class node *left;
    class node *right;
} node;
class dict
{
public:
    node *root;
    void create();
    void disp(node *);
    node *insert(node *root, node *temp);
    int search(node *, char[]);
    int update(node *, char[]);
    node *del(node *, char[]);
    node *min(node *);
};
void dict ::create()
{
    class node *temp;
    int ch;
    do
    {
        temp = new node;
        cout << "\nEnter Keyword : ";
        fflush(stdin);
        cin.getline(temp->k, 100);
        cout << "Enter Meaning : ";
        fflush(stdin);
        cin.getline(temp->m, 100);
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL)
        {
            this->root = temp;
        }
        else
        {
            this->root = insert(this->root, temp);
        }
        cout << "\nDo u want to add more (y=1/n=0):";
        cin >> ch;

    } while (ch == 1);
}

node *dict ::insert(node *root, node *temp)
{
    if (root == NULL)
    {
        root = temp;
        return root;
    }

    if (strcmp(temp->k, root->k) < 0)
        root->left = insert(root->left, temp);
    else
        root->right = insert(root->right, temp);
    return root;
}

void dict::disp(node *root)
{
    if (root != NULL)
    {
        disp(root->left);
        cout << "Key Word :" << root->k<<endl;
        cout << "Meaning :" << root->m<<endl<<endl;
        disp(root->right);
    }
}

int dict ::search(node *root, char k[20])
{
    int c = 0;
    while (root != NULL)
    {
        c++;
        if (strcmp(k, root->k) == 0)
        {
            cout << "\nNo of Comparisons to find the word : " << c<<endl;
            cout<<"Meaning of "<<root->k<<" is : "<<root->m<<endl;
            return 1;
        }
        if (strcmp(k, root->k) < 0)
            root = root->left;

        if (strcmp(k, root->k) > 0)
            root = root->right;
    }
    return -1;
}

int dict ::update(node *root, char k[20])
{
    while (root != NULL)
    {
        if (strcmp(k, root->k) == 0)
        {
            cout << "\nEnter new meaning of " << root->k <<" : ";
            fflush(stdin);
            fflush(stdin);
            cin.getline(root->m, 100);
            cout<<endl;
            return 1;
        }

        else if (strcmp(k, root->k) < 0)
            root = root->left;
        else if (strcmp(k, root->k) > 0)
            root = root->right;
    }
    return -1;
}

node *dict ::del(node *root, char k[20])
{
    node *temp;
    if (root == NULL)
    {
        cout << "\nElement Not Found\n";
        return root;
    }
    if (strcmp(k, root->k) < 0)
    {
        root->left = del(root->left, k);
        return root;
    }
    if (strcmp(k, root->k) > 0)
    {
        root->right = del(root->right, k);
        return root;
    }

    cout<<"Keyword deleted.\n";
    if (root->right == NULL && root->left == NULL)
    {
        temp = root;
        delete temp;
        return NULL;
    }
    if (root->right == NULL)
    {
        temp = root;
        root = root->left;
        delete temp;
        return root;
    }
    else if (root->left == NULL)
    {
        temp = root;
        root = root->right;
        delete temp;
        return root;
    }

    temp = min(root->right);
    strcpy(root->k, temp->k);
    root->right = del(root->right, temp->k);
    return root;
}

node *dict ::min(node *q)
{
    while (q->left != NULL)
    {
        q = q->left;
    }
    return q;
}

int main()
{
    int ch;
    dict d;
    d.root = NULL;
    do
    {
        cout << "\nMenu\n1.Create\n2.Disp\n3.Search\n4.Update\n5.Delete\n6.Exit\nEnter your response : ";
        fflush(stdin);
        cin >> ch;
        switch (ch)
        {
        case 1:
            d.create();
            break;
        case 2:
            if (d.root == NULL)
            {
                cout << "\nDictionary is Empty. First add keywords then try again.\n";
            }
            else
            {
                d.disp(d.root);
            }
            break;
        case 3:
            if (d.root == NULL)
            {
                cout << "\nDictionary is Empty. First add keywords then try again.\n";
            }
            else
            {
                cout << "\nEnter Keyword which u want to search:";
                char k[20];
                cin >> k;
                if (d.search(d.root, k) == 1)
                    cout << "\nKeyword Found\n";
                else
                    cout << "\nKeyword Not Found\n";
            }
            break;
        case 4:
            if (d.root == NULL)
            {
                cout << "\nDictionary is Empty. First add keywords then try again.\n";
            }
            else
            {
                cout << "\nEnter Keyword to update:";
                char k[20];
                cin >> k;
                if (d.update(d.root, k) == 1)
                    cout << "\nMeaning Updated\n";
                else
                    cout << "\nKeyword Not Found\n";
            }
            break;
        case 5:
            if (d.root == NULL)
            {
                cout << "\nDictionary is Empty. First add keywords then try again.\n";
            }
            else
            {
                cout << "\nEnter Keyword which you want to delete :";
                char k[20];
                cin >> k;
                if (d.root == NULL)
                {
                    cout << "\nDictionary is Empty!!\n";
                }
                else
                {
                    d.root = d.del(d.root, k);
                }
            }

        case 6: break;
        }
    } while (ch <= 5);
    return 0;
}
