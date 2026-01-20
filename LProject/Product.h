#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace Store {

    class Product
    {
    protected:
        int id;
        string code;
        string name;
        double price;
        string description;

        static int totalCount; 

    public:
        Product();
        Product(string code, string name, double price, string description);
        virtual ~Product();

        int getId() const;
        string getName() const;
        double getPrice() const;
        string getCode() const;

        void setName(string name);
        void setPrice(double price);

        virtual void showInfo() const;
        virtual void save(ofstream& file) const;
        virtual void load(ifstream& file);
        virtual int getType() const = 0;

        static int getTotalCount();

        bool operator==(const Product& other) const;
    };
}