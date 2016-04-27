#include <iostream>
#include "List.h"
#include <stdlib.h>

using namespace std;

void displayMenu()
{
    cout<<"What would you like to do?"<<endl;
    cout<<"1. Add item"<<endl;
    cout<<"2. Delete item"<<endl;
    cout<<"3. Check budget"<<endl;
    cout<<"4. Edit budget"<<endl;
    cout<<"5. Show list"<<endl;
    cout<<"6. Apply coupon"<<endl;
    cout<<"7. Add/edit list name"<<endl;
    cout<<"8. Delete all items within a category"<<endl;
    cout<<"9. Delete list"<<endl;
    cout<<"10. Quit"<<endl;
}

int main()
{
    List myList;
    int budget;
    int choice;
    cout<<"What is your budget?"<<endl;
    cin>>budget;
    myList.setBudget(budget);
    displayMenu();
    cin>>choice;
    while (choice != 10)
    {
        if (choice == 1)
        {
            string name;
            string cat;
            string price1;
            string amount1;
            int price;
            int amount;
            cout<<"Name of item: "<<endl;
            cin.ignore();
            getline(cin, name);
            cout<<"Category of item: "<<endl;
            getline(cin, cat);
            cout<<"Price of item: "<<endl;
            getline(cin, price1);
            cout<<"Amount to purchase: "<<endl;
            getline(cin, amount1);
            price = atoi(price1.c_str());
            amount = atoi(amount1.c_str());
            myList.addItem(name, cat, price, amount);
        }
        else if (choice == 2)
        {
            string name;
            string delAmount1;
            int delAmount;
            cout<<"Name of item you'd like to delete: "<<endl;
            cin.ignore();
            getline(cin, name);
            cout<<"How many to delete (to delete all, enter -1): "<<endl;
            getline(cin, delAmount1);
            delAmount = atoi(delAmount1.c_str());
            myList.removeItem(name, delAmount);
        }
        else if (choice == 3)
            myList.checkBudget();
        else if (choice == 4)
            myList.editBudget();
        else if (choice == 5)
            myList.displayList();
        else if (choice == 6)
        {
            int couponAmount;
            cout<<"How much is your coupon worth?"<<endl;
            cin>>couponAmount;
            myList.coupon(couponAmount);
        }
        else if (choice == 7)
        {
            string listName;
            cout<<"What would you like your list to be called?"<<endl;
            cin.ignore();
            getline(cin, listName);
            myList.editName(listName);
        }
        else if (choice == 8)
        {
            string catDelete;
            cout<<"Which category would you like to delete?"<<endl;
            cin.ignore();
            getline(cin, catDelete);
            myList.deleteWithinCat(catDelete);
        }
        else if (choice == 9)
            myList.deleteList();
        displayMenu();
        cin>>choice;
    }
    cout<<"Goodbye!"<<endl;
    return 0;
}
