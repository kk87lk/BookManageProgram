#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
#include <fstream>

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

        void InfoDisplay()
        {
            i = 0;
            system("cls");
            cout << setw(16) << setiosflags(ios::left) << "ISBN" 
                 << setw(16) << setiosflags(ios::left) << "BookName" 
                 << setw(16) << setiosflags(ios::left) << "Author" 
                 << setw(16) << setiosflags(ios::left) << "ClassNum"
                 << setw(16) << setiosflags(ios::left) << "PublishHouse"
                 << setw(16) << setiosflags(ios::left) << "PublishDate" 
                 << setw(16) << setiosflags(ios::left) << "Price" << endl;
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
                            break;
                        }
                        QDisplay(recordISBN);
                        while(recordISBN.empty() == false)
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
                            break;
                        }
                        QDisplay(recordName);
                        while(recordName.empty() == false)
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
                            break;
                        }
                        QDisplay(recordAuthor);
                        while(recordAuthor.empty() == false)
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

        int InfoModify()
        {
            string ISBNm;
            cout << "Input the ISBN of the book you want to modify:";
            cin >> ISBNm;
            i = 0;
            while(Book[i].ISBN.empty() != true)
            {
                if(Book[i].ISBN == ISBNm)
                {
                    int ch = -1;
                    while (ch != 0)
                    {
                        system("cls");
                        cout << "1--Name." << endl;
                        cout << "2--Author." << endl;
                        cout << "3--ClassificationNumber." << endl;
                        cout << "4--PublishingHouse." << endl;
                        cout << "5--PublicationDate." << endl;
                        cout << "6--Price." << endl;
                        cout << "0--Exit." << endl;
                        cin >> ch;
                        switch (ch)
                        {
                        case 1:
                        {
                            system("cls");
                            cout << "Input the Name of this book:";
                            cin >> Book[i].BookName;
                            break;
                        };
                        case 2:
                        {
                            system("cls");
                            cout << "Input the Author of this book:";
                            cin >> Book[i].Author;
                            break;
                        };
                        case 3:
                        {
                            system("cls");
                            cout << "Input the ClassificationNumber of this book:";
                            cin >> Book[i].ClassificationNumber;
                            break;
                        };
                        case 4:
                        {
                            system("cls");
                            cout << "Input the PublishingHouse of this book:";
                            cin >> Book[i].PublishingHouse;
                            break;
                        };
                        case 5:
                        {
                            system("cls");
                            cout << "Input the PublishingDate of this book:";
                            cin >> Book[i].PublicationDate;
                            break;
                        };
                        case 6:
                        {
                            system("cls");
                            cout << "Input the Price of this book:";
                            cin >> Book[i].Price;
                            break;
                        };
                        case 0:
                            return 0;
                        default:
                            cout << "Error option.";
                        }
                    }
                }
                i++;
            }
            cout << "Couldn't found the book.";
            return -1;
        }

        void InfoDel()
        {
            system("cls");
            i = 0;
            string Pum;
            cout << "Input the ISBN of the book you want to delete:";
            cin >> Pum;
            while(Book[i].ISBN != Pum && Book[i].ISBN.empty() != true)
                i++;
            if(Book[i].ISBN.empty() == true)
            {
                cout << "Couldn't found the book.";
                return;
            }
            else
            {
                for (; Book[i].ISBN.empty() != 0; i++)
                    Book [i] = Book [i + 1];
                return;
            }
        }
        
        void NameSort(int left, int right)
        {
            int ltemp = left, rtemp = right;  
            string f = Book[(left + right) / 2].BookName;  
            while (ltemp < rtemp)  
            {  
                while (Book[ltemp].BookName < f)  
                {  
                    ltemp++;  
                }  
                while (Book[rtemp].BookName > f)  
                {  
                    rtemp--;  
                }  
                if (ltemp < rtemp) {  
                    string temp = Book[ltemp].BookName;  
                    Book[ltemp].BookName = Book[rtemp].BookName;  
                    Book[rtemp].BookName = temp;  
                    ltemp++;  
                    rtemp--;  
                }  
            }  
            if (ltemp == rtemp) {  
                ltemp++;  
            }  
            if (left < rtemp) {  
                NameSort(left, ltemp - 1);  
            }  
            if (ltemp < right) {  
                NameSort(rtemp + 1, right);  
            }
        }

        bool SaveFile()
        {
            ofstream BooksData("BookData.dat");
            i = 0;
            while(!Book[i].ISBN.empty())
            {
                BooksData << Book[i].ISBN;
                BooksData << " ";
                BooksData << Book[i].BookName;
                BooksData << " ";
                BooksData << Book[i].Author;
                BooksData << " ";
                BooksData << Book[i].ClassificationNumber;
                BooksData << " ";
                BooksData << Book[i].PublishingHouse;
                BooksData << " ";
                BooksData << Book[i].PublicationDate;
                BooksData << " ";
                BooksData << Book[i].Price;
                BooksData << "\n";
                i++;
            }
            BooksData.close();
        }

        bool DrawData()
        {
            ifstream file("BookData.dat");
            string ch;
            i = 0;
            while(!file.eof())
            {
                file >> Book[i].ISBN;
                file >> Book[i].BookName;
                file >> Book[i].Author;
                file >> Book[i].ClassificationNumber;
                file >> Book[i].PublishingHouse;
                file >> Book[i].PublicationDate;
                file >> Book[i].Price;
                i++;
            }
            file.close();
        }
};