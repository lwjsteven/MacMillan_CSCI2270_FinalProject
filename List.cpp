#include "List.h"
#include <iostream>
using namespace std;

void List::setBudget(int in_budget)
{
    budget = in_budget;
}

void List::checkBudget()
{
    cout<<"Your budget has $"<<budget<<" remaining."<<endl;
}

void List::addItem(string in_name, string in_cat, int in_price, int in_amount)
{
    listItem *look = root;
    while (look != NULL && look->name != in_name)
    {
        look = look->next;
    }
    if (look == NULL)
    {
        listItem *addItem = new listItem(in_name, in_cat, in_price, in_amount);
        if (root == NULL)
            root = addItem;
        else
        {
            listItem* tmp = root;
            while (tmp->next != NULL)
                tmp = tmp->next;
            addItem->previous = tmp;
            tmp->next = addItem;
        }
    }
    else
        look->amount = look->amount + in_amount;
    budget = budget - in_price*in_amount;
    if (budget < 0)
    {
        cout<<"You have gone over your budget!"<<endl;
    }
}

void List::removeItem(string name, int delAmount)
{
    listItem *tmp = root;
    while (tmp->name != name && tmp != NULL)
        tmp = tmp->next;
    if (tmp != NULL)
    {
        if (tmp->amount == delAmount)
            delAmount = -1;
        if (delAmount == -1)
        {
            int price = tmp->price;
            int numDeleted = tmp->amount;
            if (tmp->previous != NULL)
                tmp->previous->next = tmp->next;
            if (tmp->next != NULL)
                tmp->next->previous = tmp->previous;
            if (tmp->next == NULL && tmp->previous == NULL)
            {
                root = NULL;
                //root->next = NULL;
                //root->previous = NULL;
            }
            delete tmp;
            budget = budget + price*numDeleted;
        }
        else if (tmp->amount > delAmount)
        {
            tmp->amount = tmp->amount - delAmount;
            budget = budget + tmp->price * delAmount;
        }
        else
            cout<<"You don't have that many on your list to delete!"<<endl;
    }
    else
        cout<<"That item is not in your list!"<<endl;
}

void List::displayList()
{
    cout<<listName<<endl;
    listItem *tmp = root;
    if (tmp == NULL)
        cout<<"List empty!"<<endl;
    while (tmp != NULL)
    {
        cout<<tmp->name<<" : $"<<tmp->price<<" : "<<tmp->category<<" : "<<tmp->amount<<" wanted"<<endl;
        tmp = tmp->next;
    }
}

void List::coupon(int couponAmount)
{
    budget = budget + couponAmount;
}

void List::editBudget()
{
    int choice;
    int change;
    cout<<"Would you like to 1) Add to budget, or 2) Decrease budget?"<<endl;
    cin>>choice;
    if (choice == 1)
    {
        cout<<"How much would you like to add?"<<endl;
        cin>>change;
        budget = budget + change;
    }
    else if (choice == 2)
    {
        cout<<"How much would you like to take away?"<<endl;
        cin>>change;
        budget = budget - change;
        if (budget <= 0)
            cout<<"You are over your budget now!"<<endl;
    }
    else
        cout<<"That wasn't a choice silly"<<endl;
}

void List::editName(string in_name)
{
    listName = in_name;
}

void List::deleteWithinCat(string catDelete)
{
    listItem *tmp = root;
    listItem *tmp2;
    while (tmp != NULL)
    {
        if (tmp->category == catDelete)
        {
            tmp2 = tmp->next;
            removeItem(tmp->name, -1);
            tmp = tmp2;
        }
        else
            tmp = tmp->next;
    }
}

void List::deleteList()
{
    listItem *tmp = root;
    listItem *tmp2;
    while (tmp != NULL)
    {
        tmp2 = tmp->next;
        removeItem(tmp->name,-1);
        tmp = tmp2;
    }
    listName = "No list name";
}

List::List()
{
    root = NULL;
    listName = "No list name";
}

List::~List()
{
    //dtor
}
