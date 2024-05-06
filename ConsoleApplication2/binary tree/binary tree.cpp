﻿// binary tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct node
{
    int info;
    node* l, * r;
};

void push(int a, node** t)
{
    if ((*t) == NULL)
    {
        *t = new node;
        (*t)->info = a;
        (*t)->l = (*t)->r = NULL;
        return;
    }
    else
    {
        if (a > ((*t)->info))
            push(a, &(*t)->r);
        else
            push(a, &(*t)->l);
    }
}

void print(node* t,int u)
{
    if (t == NULL)
        return;
    else
    {
        print(t->l, ++u);                   //С помощью рекурсивного посещаем левое поддерево
        for (int i = 0; i < u; ++i) 
            std::cout << "|";
        std::cout << t->info << std::endl;            //И показываем элемент
        u--;
    }
    print(t->r, ++u);

}

int main()
{
    node* tree = NULL;
    int n;                              //Количество элементов
    int s;                              //Число, передаваемое в дерево
    std::cout << "amount of elements  ";
    std::cin >> n;                           //Вводим количество элементов

    for (int i = 0; i < n; ++i)
    {
        std::cout << "element  ";
        std::cin >> s;                       //Считываем элемент за элементом

        push(s, &tree);                 //И каждый кладем в дерево
    }
    std::cout << "the tree\n";
    print(tree, 0);
    std::cin.ignore().get();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
