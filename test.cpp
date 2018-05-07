#include <iostream>
#include <string>
#include <iomanip>

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
        int QueryISBN(string ISBN)
        {
            i = 0;
            while(Book[i].ISBN.empty() != true)
            {
                if(Book[i].ISBN == ISBN)
                    return i;
                i++;
            }
            return -1;
        }
        int QueryName(string name)
        {
            i = 0;
            while(Book[i].BookName.empty() != true)
            {
                if(Book[i].BookName == name)
                    return i;
                i++;
            }
            return -1;
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
            cout << setw(16) << setiosflags(ios::left) << "ISBN" 
                 << setw(16) << setiosflags(ios::left) << "BookName" 
                 << setw(16) << setiosflags(ios::left) << "Author" 
                 << setw(16) << setiosflags(ios::left) << "ClassNum"
                 << setw(16) << setiosflags(ios::left) << "PublishHouse"
                 << setw(16) << setiosflags(ios::left) << "PublishDate" 
                 << setw(16) << setiosflags(ios::left) << "Price" << endl;
            if(i != -1) goto once;
            i++;
            while(Book[i].ISBN.empty() != true)
            {
                cout << setw(16) << setiosflags(ios::left) << Book[i].ISBN 
                     << setw(16) << setiosflags(ios::left) << Book[i].BookName
                     << setw(16) << setiosflags(ios::left) << Book[i].Author
                     << setw(16) << setiosflags(ios::left) << Book[i].ClassificationNumber
                     << setw(16) << setiosflags(ios::left) << Book[i].PublishingHouse
                     << setw(16) << setiosflags(ios::left) << Book[i].PublicationDate 
                     << setw(16) << setiosflags(ios::left) << Book[i].Price;
                i++;
            };
            return;
        once:cout << setw(16) << setiosflags(ios::left) << Book[i].ISBN 
                  << setw(16) << setiosflags(ios::left) << Book[i].BookName
                  << setw(16) << setiosflags(ios::left) << Book[i].Author
                  << setw(16) << setiosflags(ios::left) << Book[i].ClassificationNumber
                  << setw(16) << setiosflags(ios::left) << Book[i].PublishingHouse
                  << setw(16) << setiosflags(ios::left) << Book[i].PublicationDate 
                  << setw(16) << setiosflags(ios::left) << Book[i].Price;
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
                        InfoDisplay(reco);
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
                        InfoDisplay(reco);
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
int main()
{
	BookInformationManage s;
	s.InfoAdd();
	s.InfoDisplay(-1);
	s.InfoQueryMenu();
}