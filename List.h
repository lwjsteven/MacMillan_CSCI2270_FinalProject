#ifndef LIST_H
#define LIST_H
#include <string>

struct listItem
{
    std::string name;
    std::string category;
    int price;
    int amount;
    listItem *next;
    listItem *previous;
    listItem(){};
    listItem(std::string in_name, std::string in_cat, int in_price, int in_amount)
    {
        name = in_name;
        category = in_cat;
        price = in_price;
        amount = in_amount;
        next = NULL;
        previous = NULL;
    }
};

class List
{
    public:
        List();
        virtual ~List();
        void addItem(std::string in_name, std::string in_cat, int in_price, int in_amount);
        void removeItem(std::string name, int delAmount);
        void setBudget(int in_budget);
        void coupon(int couponAmount);
        void deleteList();                                   //NOT
        void deleteWithinCat(std::string catDelete);
        void editName(std::string in_name);
        void checkBudget();
        void editBudget();
        void displayList();
    protected:
    private:
        int budget;
        std::string listName;
        listItem* root;
};

#endif // LIST_H
