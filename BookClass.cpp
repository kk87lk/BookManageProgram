#include <iostream>
#include <string>

using namespace std;

class BookManage
{
    private:
        struct BookInfo
        {
            string ISBN;
            string BookName;
            string Author;
            char ClassificationNumber;
            string PublishingHouse;
            string PublicationDate;
            double Price;
        };
};