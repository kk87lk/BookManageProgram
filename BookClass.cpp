#include <iostream>
#include <string>
#include <iomanip>
#include <queue>

using namespace std;

class BookInformationManage
{
    private:
        struct BookInformation
        {
            string ISBN;
            string BookName;
            string Author;
            char ClassificationNumber;
            string PublishingHouse;
            string PublicationDate;
            double Price;
        }Book[5000];
        
        int i = 0;
        queue<int> recordAuthor;
        queue<int> recordISBN;
        queue<int> recordName;
        
        int QueryISBN(string ISBN)
        {
            i = 0;
            while(Book[i].ISBN.empty() != true)
            {
                if(Book[i].ISBN == ISBN)
                    recordISBN.push(i);
                i++;
            }
            if(recordISBN.empty() == true)
                return -1;
            else 
                return 0;
        }
        int QueryName(string name)
        {
            i = 0;
            while(Book[i].BookName.empty() != true)
            {
                if(Book[i].BookName == name)
                    recordName.push(i);
                i++;
            }
            if(recordName.empty() == true)
                return -1;
            else 
                return 0;
        }
        int QueryAuthor(string author)
        {
            i = 0;
            while(Book[i].Author.empty() != true)
            {
                if(Book[i].Author == author)
                    recordAuthor.push(i);
                i++;
            }
            if(recordAuthor.empty() == true)
                return -1;
            else 
                return 0;
        }
        int QDisplay(queue<int> Q)
        {
            int r = 0;
            cout << setw(16) << setiosflags(ios::left) << "ISBN" 
                 << setw(16) << setiosflags(ios::left) << "BookName" 
                 << setw(16) << setiosflags(ios::left) << "Author" 
                 << setw(16) << setiosflags(ios::left) << "ClassNum"
                 << setw(16) << setiosflags(ios::left) << "PublishHouse"
                 << setw(16) << setiosflags(ios::left) << "PublishDate" 
                 << setw(16) << setiosflags(ios::left) << "Price" << endl;
            while(Q.empty() == false)
            {
                r = Q.front();
                Q.pop();
                cout << setw(16) << setiosflags(ios::left) << Book[r].ISBN 
                     << setw(16) << setiosflags(ios::left) << Book[r].BookName
                     << setw(16) << setiosflags(ios::left) << Book[r].Author
                     << setw(16) << setiosflags(ios::left) << Book[r].ClassificationNumber
                     << setw(16) << setiosflags(ios::left) << Book[r].PublishingHouse
                     << setw(16) << setiosflags(ios::left) << Book[r].PublicationDate 
                     << setw(16) << setiosflags(ios::left) << Book[r].Price << endl;
            }
        }
    
    public:
        bool InfoAdd()
        {
            i = 0;
            while(Book[i].ISBN.empty() != true)
                i++;
            if (i == 4999)
            {
                cout << "Full";
                return false;
            }
            cout << "Input the ISBN of the new book:";
            cin >> Book[i].ISBN;
            system("cls");
            cout << "Input the Name of the new book:";
            cin >> Book[i].BookName;
            system("cls");
            cout << "Input the Author of the new book:";
            cin >> Book[i].Author;
            system("cls");
            cout << "Input the ClassificationNumber of the new book:";
            cin >> Book[i].ClassificationNumber;
            system("cls");
            cout << "Input the PublishingHouse of the new book:";
            cin >> Book[i].PublishingHouse;
            system("cls");
            cout << "Input the PublishDate of the new book:";
            cin >> Book[i].PublicationDate;
            system("cls");
            cout << "Input the Price of the new book:";
            cin >> Book[i].Price;
            system("cls");
            cout << "Success" << endl;
            getchar();
            system("cls");
            return true;
        }

        void InfoDisplay(int i)
        {
            i = 0;
            cout << setw(16) << setiosflags(ios::left) << "ISBN" 
                 << setw(16) << setiosflags(ios::left) << "BookName" 
                 << setw(16) << setiosflags(ios::left) << "Author" 
                 << setw(16) << setiosflags(ios::left) << "ClassNum"
                 << setw(16) << setiosflags(ios::left) << "PublishHouse"
                 << setw(16) << setiosflags(ios::left) << "PublishDate" 
                 << setw(16) << setiosflags(ios::left) << "Price" << endl;
            i++;
            while(Book[i].ISBN.empty() != true)
            {
                cout << setw(16) << setiosflags(ios::left) << Book[i].ISBN 
                     << setw(16) << setiosflags(ios::left) << Book[i].BookName
                     << setw(16) << setiosflags(ios::left) << Book[i].Author
                     << setw(16) << setiosflags(ios::left) << Book[i].ClassificationNumber
                     << setw(16) << setiosflags(ios::left) << Book[i].PublishingHouse
                     << setw(16) << setiosflags(ios::left) << Book[i].PublicationDate 
                     << setw(16) << setiosflags(ios::left) << Book[i].Price << endl;
                i++;
            };
            return;
        }

        int InfoQueryMenu()
        {
            int c = -1;
            while (c != 0)
            {
                system("cls");
                cout << "1--ISBN." << endl;
                cout << "2--Name." << endl;
                cout << "3--Author." << endl;
                cout << "0--Exit." << endl;
                cin >> c;
                switch(c)
                {
                    case 1:
                    {
                        system("cls");
                        string s;
                        cout << "Input the ISBN you want to search:";
                        cin >> s;
                        int reco = QueryISBN(s);
                        if(reco == -1) 
                        {
                            cout << "Couldn't found the book.";
                            return -1;
                        }
                        QDisplay(recordISBN);
                        while(recordISBN.empty == false)
                            recordISBN.pop();
                        fflush(stdin);
                        getchar();
                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        string s;
                        cout << "Input the Name of book you want to search:";
                        cin >> s;
                        int reco = QueryName(s);
                        if(reco == -1) 
                        {
                            cout << "Couldn't found the book.";
                            return -1;
                        }
                        QDisplay(recordName);
                        while(recordName.empty == false)
                            recordName.pop();
                        fflush(stdin);
                        getchar();
                        break;
                    }
                    case 3:
                    {
                        system("cls");
                        string s;
                        cout << "Input the Author of book you want to search:";
                        cin >> s;
                        int reco = QueryAuthor(s);
                        if(reco == -1) 
                        {
                            cout << "Couldn't found the book.";
                            return -1;
                        }
                        QDisplay(recordAuthor);
                        while(recordAuthor.empty == false)
                            recordAuthor.pop();
                        fflush(stdin);
                        getchar();
                        break;
                    }
                    case 0:
                        return 0;
                    
                    default:
                        system("cls");
                        cout << "Error option." << endl;
                        fflush(stdin);
                        getchar();
                        break;
                }
            
            }
        }

        void InfoDel()
        {
            int n = 0;
            
        }
        
};