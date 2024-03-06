#include <iostream>
using namespace std;


template <typename Type>
class MyBinaryTree {
private:
    struct Knot {  //структура для узлов (из каждого узла появляются еще два)
        Knot* left;
        Knot* right;
        Type value;

        Knot(Type value_1){ //Конструктор
            value = value_1;
            left = NULL;
            right = NULL;
        }
    };

    Knot* start;//начало дерева

    void push_1(Knot*& A, Type value) { //функция для "закидывания" нового значения в соответсвии с условием
        if (A == nullptr) { //Если узел пустой то создаем на его месте новый с заданным значением
            A = new Knot(value);
        }

        if (value < A->value) { //Если нет, то спускаемся налево или направо
            push_1(A->left, value);
        }

        if (value > A->value) {
            push_1(A->right, value);
        }
    }

    void print(Knot* A, int indent) {
        int n = 10;
        if (A == nullptr)
            return;

        indent += n; //отступ

        print(A->right, indent);

        cout << endl;
        for (int i = n; i < indent; i++)
            cout << " ";
        cout << A->value << endl;

        print(A->left, indent);
    }



    void destructor(Knot* a) {
        if (a == nullptr)
            return;

        destructor(a->left);
        destructor(a->right);
        delete a;
    }

public:

    MyBinaryTree() { //Конструктор
        start = NULL;
    }

    ~MyBinaryTree() {//Деструктор
        destructor(start);
    }

    void push(Type value) {
        push_1(start, value);
    }

    friend std::ostream& operator<<(std::ostream& os, MyBinaryTree& tree)
    {
        tree.print(tree.start, 0);
        return os;
    }


};

int main() {
    MyBinaryTree<int> tree;
    tree.push(5);
    tree.push(3);
    tree.push(7);
    tree.push(1);
    tree.push(4);
    tree.push(6);
    tree.push(8);
    tree.push(2);
    tree.push(10);
    tree.push(0);
    cout << tree;



    MyBinaryTree<double> tree_2;
    tree_2.push(5.1);
    tree_2.push(3.1);
    tree_2.push(7.1);
    tree_2.push(1.1);
    tree_2.push(4.1);
    tree_2.push(6.1);
    tree_2.push(8.1);
    tree_2.push(2.1);
    tree_2.push(10.1);
    tree_2.push(0.1);
    cout << tree_2;

    return 0;
}
