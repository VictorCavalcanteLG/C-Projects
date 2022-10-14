#include <iostream>
#include <cstdlib>
#include <chrono>


using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *Insert(node *source, int data) {
    if (source == NULL) {
        
        node *newNode = new node;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;


        source = newNode;
    }

    else if (source->data < data) {
        source->right = Insert(source->right, data);
    }

    else if (source->data > data) {
        source->left = Insert(source->left, data);
    }

    return source;
}

void InsertVoid(node **source, int data) {
    if (*source == NULL) {
        
        node *newNode = new node;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;

        *source = newNode;

        return;
    }

    else if ((*source)->data < data) {
        InsertVoid(&(*source)->right, data);
    }

    else if ((*source)->data > data) {
        InsertVoid(&(*source)->left, data);
    }
}

void PrintTree(node *source) {

    if (source == NULL) {
        return;
    }

    PrintTree(source->left);

    cout << source->data;
    cout << "  ";

    PrintTree(source->right);
}

bool SearchData(node *source, int data) {
    if (source == NULL) {
        return false;
    }

    if (source->data == data) {
        return true;
    }

    bool result;

    if (source->data > data) {
        result = SearchData(source->left, data);
    }

    if (source->data < data) {
        result = SearchData(source->right, data);
    }

    return result;
}

void DeleteData(node *source, int data) {
    if (source == NULL) {
        return;
    }

    if (source->data == data) {
        
    }

    if (source->data > data) {
        DeleteData(source->left, data);
    }

    if (source->data < data) {
        DeleteData(source->right, data);
    }
}

int main(){
    node *source = NULL;
    node *source2 = NULL;


    for (int i = 0; i < 1000; i++){
        int num = rand()%1500;
        cout << num << endl;


        auto start = std::chrono::high_resolution_clock::now();
        source = Insert(source, num);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> float_ms = end - start;

        cout << "Insert with return, NUM: " << num << "  TEMPO: " << float_ms.count() << endl;
        
        auto start1 = std::chrono::high_resolution_clock::now();
        InsertVoid(&source2, num);
        auto end1 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> float_ms1 = end1 - start1;

        cout << "Insert with void, NUM: " << num << "  TEMPO: " << float_ms1.count() << endl;
        cout << endl;
    }

    cout << "\n\n";
    cout << "INSERT WITH RETURN" << endl;

    PrintTree(source);

    cout << "\n\n";
    cout << "INSERT WITH DOUBLE POINTER" << endl;

    PrintTree(source2);


    cout << SearchData(source, 4);

    return 0;
}