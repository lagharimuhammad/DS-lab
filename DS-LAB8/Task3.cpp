#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Student
{
public:
    char name[50];
    int roll;
    int score;

    Student() : roll(0), score(0)
    {
        name[0] = '\0';
    }

    Student(const char *n, int r, int s) : roll(r), score(s)
    {
        int i = 0;
        while (n[i] != '\0' && i < 49)
        {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
    }

    void display()
    {
        cout << "Name: " << name << ", Roll: " << roll << ", Score: " << score << endl;
    }
};

int stringCompare(const char *str1, const char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] < str2[i])
            return -1;
        if (str1[i] > str2[i])
            return 1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return 0;
    if (str1[i] == '\0')
        return -1;
    return 1;
}

void stringCopy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

class BSTNode
{
public:
    Student data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(Student s) : data(s), left(NULL), right(NULL) {}
};

class BST
{
private:
    BSTNode *root;

    BSTNode *insertHelper(BSTNode *node, Student student)
    {
        if (node == NULL)
        {
            return new BSTNode(student);
        }
        int cmp = stringCompare(student.name, node->data.name);
        if (cmp < 0)
        {
            node->left = insertHelper(node->left, student);
        }
        else if (cmp > 0)
        {
            node->right = insertHelper(node->right, student);
        }
        return node;
    }

    BSTNode *searchHelper(BSTNode *node, const char *name)
    {
        if (node == NULL)
        {
            return NULL;
        }
        int cmp = stringCompare(name, node->data.name);
        if (cmp == 0)
        {
            return node;
        }
        else if (cmp < 0)
        {
            return searchHelper(node->left, name);
        }
        else
        {
            return searchHelper(node->right, name);
        }
    }

    BSTNode *findMin(BSTNode *node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }

    BSTNode *deleteHelper(BSTNode *node, const char *name)
    {
        if (node == NULL)
        {
            return NULL;
        }
        int cmp = stringCompare(name, node->data.name);
        if (cmp < 0)
        {
            node->left = deleteHelper(node->left, name);
        }
        else if (cmp > 0)
        {
            node->right = deleteHelper(node->right, name);
        }
        else
        {
            if (node->left == NULL)
            {
                BSTNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BSTNode *temp = node->left;
                delete node;
                return temp;
            }
            BSTNode *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data.name);
        }
        return node;
    }

    void inorderHelper(BSTNode *node)
    {
        if (node != NULL)
        {
            inorderHelper(node->left);
            node->data.display();
            inorderHelper(node->right);
        }
    }

    void collectLowScores(BSTNode *node, char names[][50], int &count)
    {
        if (node != NULL)
        {
            collectLowScores(node->left, names, count);
            if (node->data.score < 10)
            {
                stringCopy(names[count], node->data.name);
                count++;
            }
            collectLowScores(node->right, names, count);
        }
    }

    void findMaxScoreHelper(BSTNode *node, Student &maxStudent)
    {
        if (node != NULL)
        {
            if (node->data.score > maxStudent.score)
            {
                maxStudent = node->data;
            }
            findMaxScoreHelper(node->left, maxStudent);
            findMaxScoreHelper(node->right, maxStudent);
        }
    }

    void destroyTree(BSTNode *node)
    {
        if (node != NULL)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BST() : root(NULL) {}

    ~BST()
    {
        destroyTree(root);
    }

    void insert(Student student)
    {
        root = insertHelper(root, student);
        cout << "Inserted: ";
        student.display();
    }

    void search(const char *name)
    {
        BSTNode *result = searchHelper(root, name);
        if (result != NULL)
        {
            cout << "Student found: ";
            result->data.display();
        }
        else
        {
            cout << "Student with name '" << name << "' not found" << endl;
        }
    }

    void deleteLowScores()
    {
        cout << "\n--- Deleting students with score < 10 ---" << endl;
        char lowScoreNames[100][50];
        int count = 0;

        collectLowScores(root, lowScoreNames, count);

        if (count == 0)
        {
            cout << "No students with score < 10" << endl;
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                BSTNode *node = searchHelper(root, lowScoreNames[i]);
                if (node != NULL)
                {
                    cout << "Deleting: ";
                    node->data.display();
                    root = deleteHelper(root, lowScoreNames[i]);
                }
            }
        }
    }

    void findMaxScore()
    {
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        Student maxStudent = root->data;
        findMaxScoreHelper(root, maxStudent);
        cout << "Student with maximum score: ";
        maxStudent.display();
    }

    void display()
    {
        cout << "All Students in BST (sorted by name) " << endl;
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
        }
        else
        {
            inorderHelper(root);
        }
    }

    bool isEmpty()
    {
        return root == NULL;
    }
};

int main()
{
    srand(time(0));

    Student students[10] = 
    {
        Student("Baqar", 101, 100),
        Student("Muhammad", 102, 5),
        Student("Omer", 103, 92),
        Student("Anwer", 104, 78),
        Student("Kamal", 105, 8),
        Student("Syed", 106, 95),
        Student("Rizvi", 107, 88),
        Student("Kashif", 108, 15),
        Student("Mehmood", 109, 72),
        Student("Laghari", 110, 90)
    };

    BST tree;
    cout << "Student BST Management System" << endl;
    cout << endl << "Total students available: 10" << endl;
    cout << "\nAll available students:" << endl;
    for (int i = 0; i < 10; i++)
    {
        students[i].display();
    }
    cout << "Randomly selecting 7 students to insert into BST " << endl;
    bool selected[10] = {false};
    int count = 0;
    while (count < 7)
    {
        int index = rand() % 10;
        if (!selected[index])
        {
            selected[index] = true;
            tree.insert(students[index]);
            count++;
        }
    }
    tree.display();
    cout << "\n--- Search Operation ---" << endl;
    tree.search("Baqar");
    tree.search("Syed");
    tree.search("Anwer");
    tree.search("Kamal");
    tree.search("syed Anwer");
    tree.findMaxScore();
    tree.deleteLowScores();
    tree.display();
    tree.findMaxScore();
    return 0;
}
