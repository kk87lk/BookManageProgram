#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
#include <fstream>

using namespace std;
class BookInformationManage
{
  public:
    struct BookInformation
    {
        string ISBN;
        string BookName;
        string Author;
        char ClassificationNumber;
        string PublishingHouse;
        string PublicationDate;
        double Price;
        bool Subscription = false;
    } Book[5000];
    int i = 0;

    bool InfoAdd()
    {
        i = 0;
        while (Book[i].ISBN.empty() != true)
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
             << setw(16) << setiosflags(ios::left) << "Price"
             << setw(16) << setiosflags(ios::left) << "Subscription" << endl;
        while (Book[i].ISBN.empty() != true)
        {
            cout << setw(16) << setiosflags(ios::left) << Book[i].ISBN
                 << setw(16) << setiosflags(ios::left) << Book[i].BookName
                 << setw(16) << setiosflags(ios::left) << Book[i].Author
                 << setw(16) << setiosflags(ios::left) << Book[i].ClassificationNumber
                 << setw(16) << setiosflags(ios::left) << Book[i].PublishingHouse
                 << setw(16) << setiosflags(ios::left) << Book[i].PublicationDate
                 << setw(16) << setiosflags(ios::left) << Book[i].Price
                 << setw(16) << setiosflags(ios::left) << Book[i].Subscription << endl;
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
            switch (c)
            {
            case 1:
            {
                system("cls");
                string s;
                cout << "Input the ISBN you want to search:";
                cin >> s;
                int reco = QueryISBN(s);
                if (reco == -1)
                {
                    cout << "Couldn't found the book.";
                    break;
                }
                QDisplay(recordISBN);
                while (recordISBN.empty() == false)
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
                if (reco == -1)
                {
                    cout << "Couldn't found the book.";
                    break;
                }
                QDisplay(recordName);
                while (recordName.empty() == false)
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
                if (reco == -1)
                {
                    cout << "Couldn't found the book.";
                    break;
                }
                QDisplay(recordAuthor);
                while (recordAuthor.empty() == false)
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
        fflush(stdin);
        cin >> ISBNm;
        i = 0;
        while (Book[i].ISBN.empty() != true)
        {
            if (Book[i].ISBN == ISBNm)
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
        while (Book[i].ISBN != Pum && Book[i].ISBN.empty() != true)
            i++;
        if (Book[i].ISBN.empty() == true)
        {
            cout << "Couldn't found the book.";
            return;
        }
        else
        {
            for (; Book[i].ISBN.empty() == false; i++)
            {
            	Book[i].ISBN = Book[i + 1].ISBN;
            	Book[i].Author = Book[i + 1].Author;
            	Book[i].BookName = Book[i + 1].BookName;
            	Book[i].ClassificationNumber = Book[i + 1].ClassificationNumber;
            	Book[i].Price = Book[i + 1].Price;
            	Book[i].PublicationDate = Book[i + 1].PublicationDate;
            	Book[i].PublishingHouse = Book[i + 1].PublishingHouse;
            	Book[i].Subscription = Book[i + 1].Subscription;
			}
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
            if (ltemp < rtemp)
            {
                string temp = Book[ltemp].BookName;
                Book[ltemp].BookName = Book[rtemp].BookName;
                Book[rtemp].BookName = temp;
                ltemp++;
                rtemp--;
            }
        }
        if (ltemp == rtemp)
        {
            ltemp++;
        }
        if (left < rtemp)
        {
            NameSort(left, ltemp - 1);
        }
        if (ltemp < right)
        {
            NameSort(rtemp + 1, right);
        }
    }

    bool SaveFile()
    {
        ofstream BooksData("BookData.dat");
        i = 0;
        while (!Book[i].ISBN.empty())
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
            BooksData << " ";
            BooksData << Book[i].Subscription;
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
        while (!file.eof())
        {
            file >> Book[i].ISBN;
            file >> Book[i].BookName;
            file >> Book[i].Author;
            file >> Book[i].ClassificationNumber;
            file >> Book[i].PublishingHouse;
            file >> Book[i].PublicationDate;
            file >> Book[i].Price;
            file >> Book[i].Subscription;
            i++;
        }
        file.close();
    }

  private:
    queue<int> recordAuthor;
    queue<int> recordISBN;
    queue<int> recordName;

    int QueryISBN(string ISBN)
    {
        i = 0;
        while (Book[i].ISBN.empty() != true)
        {
            if (Book[i].ISBN == ISBN)
                recordISBN.push(i);
            i++;
        }
        if (recordISBN.empty() == true)
            return -1;
        else
            return 0;
    }
    int QueryName(string name)
    {
        i = 0;
        while (Book[i].BookName.empty() != true)
        {
            if (Book[i].BookName == name)
                recordName.push(i);
            i++;
        }
        if (recordName.empty() == true)
            return -1;
        else
            return 0;
    }
    int QueryAuthor(string author)
    {
        i = 0;
        while (Book[i].Author.empty() != true)
        {
            if (Book[i].Author == author)
                recordAuthor.push(i);
            i++;
        }
        if (recordAuthor.empty() == true)
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
        while (Q.empty() == false)
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
};
class VIP : BookInformationManage
{
  private:
    struct vip
    {
        string Account;
        string Password;
        string Name;
        string Phone;
        string BorrowRecord_1 = "0";
        string BorrowRecord_2 = "0";
        string BorrowRecord_3 = "0";
    } Membership[1000];
    int l = 0;

  public:
    BookInformationManage BB;
    bool SaveFile_m()
    {
        system("cls");
        ofstream MemberData("MembersData.dat");
        l = 0;
        while (!Membership[l].Phone.empty())
        {
            MemberData << Membership[l].Account;
            MemberData << " ";
            MemberData << Membership[l].Password;
            MemberData << " ";
            MemberData << Membership[l].Name;
            MemberData << " ";
            MemberData << Membership[l].Phone;
            MemberData << " ";
            MemberData << Membership[l].BorrowRecord_1;
            MemberData << " ";
            MemberData << Membership[l].BorrowRecord_2;
            MemberData << " ";
            MemberData << Membership[l].BorrowRecord_3;
            MemberData << "\n";
            l++;
        }
        MemberData.close();
    }

    bool DrawData_m()
    {
        system("cls");
        ifstream file_M("MembersData.dat");
        string ch;
        l = 0;
        while (!file_M.eof())
        {
            file_M >> Membership[l].Account;
            file_M >> Membership[l].Password;
            file_M >> Membership[l].Name;
            file_M >> Membership[l].Phone;
            file_M >> Membership[l].BorrowRecord_1;
            file_M >> Membership[l].BorrowRecord_2;
            file_M >> Membership[l].BorrowRecord_3;
            l++;
        }
        file_M.close();
    }

    void ListDisplay()
    {
        system("cls");
        i = 0;
        cout << "You have borrowed the following books\n" << endl;
        cout << setw(16) << setiosflags(ios::left) << "ISBN"
             << setw(16) << setiosflags(ios::left) << "BookName"
             << setw(16) << setiosflags(ios::left) << "Author"
             << setw(16) << setiosflags(ios::left) << "ClassNum"
             << setw(16) << setiosflags(ios::left) << "PublishHouse"
             << setw(16) << setiosflags(ios::left) << "PublishDate"
             << setw(16) << setiosflags(ios::left) << "Price"
             << setw(16) << setiosflags(ios::left) << "NUM" << endl;
        if (Membership[l].BorrowRecord_1 != "0")
        {
            while (BB.Book[i].ISBN != Membership[l].BorrowRecord_1)
                i++;
            cout << setw(16) << setiosflags(ios::left) << BB.Book[i].ISBN
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].BookName
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].Author
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].ClassificationNumber
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].PublishingHouse
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].PublicationDate
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].Price
                 << setw(16) << setiosflags(ios::left) << "1" << endl;
            i = 0;
        }
        if (Membership[l].BorrowRecord_2 != "0")
        {
            while (BB.Book[i].ISBN != Membership[l].BorrowRecord_2)
                i++;
            cout << setw(16) << setiosflags(ios::left) << BB.Book[i].ISBN
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].BookName
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].Author
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].ClassificationNumber
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].PublishingHouse
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].PublicationDate
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].Price
                 << setw(16) << setiosflags(ios::left) << "2" << endl;
            i = 0;
        }
        if (Membership[l].BorrowRecord_3 != "0")
        {
            while (BB.Book[i].ISBN != Membership[l].BorrowRecord_3)
                i++;
            cout << setw(16) << setiosflags(ios::left) << BB.Book[i].ISBN
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].BookName
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].Author
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].ClassificationNumber
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].PublishingHouse
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].PublicationDate
                 << setw(16) << setiosflags(ios::left) << BB.Book[i].Price
                 << setw(16) << setiosflags(ios::left) << "3" << endl;
            i = 0;
        }
        return;
    }

    bool regist()
    {
        system("cls");
        l = 0;
        while (Membership[l].Account.empty() != true)
            l++;
        if (l == 999)
        {
            cout << "Full";
            return false;
        }
        cout << "Input the Account of the new Membership:";
        cin >> Membership[l].Account;
        int rec = l;
        l = 0;
        while (l < rec)
        {
            if (Membership[l].Account == Membership[rec].Account)
            {
                cout << "Same account was exist!";
                return false;
            }
            l++;
        }
        l = rec;
        system("cls");
        cout << "Input the Password of the new Membership:";
        cin >> Membership[l].Password;
        system("cls");
        cout << "Input the Name of the new Membership:";
        cin >> Membership[l].Name;
        system("cls");
        cout << "Input the PhoneNumber of the new Membership:";
        cin >> Membership[l].Phone;
        system("cls");
        cout << "Success" << endl;
        getchar();
        system("cls");
        return true;
    }

    bool Logo() //???
    {
        system("cls");
        char *password = new char[20];
        string name;
        cout << "Account:" << endl;
        cin >> name;
        cout << "Password:" << endl;
        cin >> password;
        l = -1;
        do
        {
            l++;
        } while (Membership[l].Account != name);
        if (Membership[l].Password == password)
            return true;
        else
            return false;
        return false;
    }

    bool Borrow()
    {
        system("cls");
        if (Logo() != true)
        {
            cout << "Error Account or Password!";
            return false;
        }
        else
        {
            system("cls");
            i = 0;
            string ISBN_M;
            cout << "Input the ISBN of book you want to borrow:";
            cin >> ISBN_M;
            while (!BB.Book[i].ISBN.empty())
            {
                if (BB.Book[i].ISBN == ISBN_M)
                {
                	if(BB.Book[i].Subscription == true)
                	{
                		cout << "This book has been borrowed.";
                		system("pause");
                		return false;
					}
                    string com = "0";
                    if (Membership[l].BorrowRecord_1 == com)
                        {
							BB.Book[i].Subscription = true;
	                    Membership[l].BorrowRecord_1 = ISBN_M;
	                    goto end;
						}
				
                    else if (Membership[l].BorrowRecord_1 != com &&
                        Membership[l].BorrowRecord_2 == com)
                    {    
						BB.Book[i].Subscription = true;
						Membership[l].BorrowRecord_2 = ISBN_M;
						goto end;
					}
                    else if (Membership[l].BorrowRecord_1 != com &&
                        Membership[l].BorrowRecord_2 != com &&
                        Membership[l].BorrowRecord_3 == com)
                    {
                        BB.Book[i].Subscription = true;
                        Membership[l].BorrowRecord_3 = ISBN_M;
                        goto end;
                    }
                    else if(1)
                    {
                        cout << "The maxium borrow number was 3!";
                        return false;
                    }
                }
                else
                    i++;
            }
        }
 end:   return false;
    }
    bool Giveback()
    {
        system("cls");
        if (Logo() != true)
        {
            cout << "Error Account or Password!";
            return false;
        }
        else
        {
            ListDisplay();
            string com = "0";
            int co = 0;
            cout << "Choose the NUM you want to giveback:";
            cin >> co;
            switch (co)
            {
            case 1:
            {
                while (BB.Book[i].ISBN != Membership[l].BorrowRecord_1)
                    i++;
                BB.Book[i].Subscription = false;
                Membership[l].BorrowRecord_1 = com;
                cout << "Giveback successfully";
                break;
            }
            case 2:
            {
                while (BB.Book[i].ISBN != Membership[l].BorrowRecord_2)
                    i++;
                BB.Book[i].Subscription = false;
                Membership[l].BorrowRecord_2 = com;
                cout << "Giveback successfully";
                break;
            }
            case 3:
            {
                while (BB.Book[i].ISBN != Membership[l].BorrowRecord_3)
                    i++;
                BB.Book[i].Subscription = false;
                Membership[l].BorrowRecord_3 = com;
                cout << "Giveback successfully";
                break;
            }
            default:
                break;
            }
            return true;
        }
    }

    void Stat_Member()
    {
        system("cls");
        l = 0;
        i = -1;
        cout << setw(16) << setiosflags(ios::left) << "VIPAccount"
             << setw(16) << setiosflags(ios::left) << "BookName"
             << setw(16) << setiosflags(ios::left) << "BookName"
             << setw(16) << setiosflags(ios::left) << "BookName" << endl;
        while (Membership[l].Account.empty() != true)
        {
            cout << setw(16) << setiosflags(ios::left) << Membership[l].Account
                 << setw(16) << setiosflags(ios::left) << Membership[l].BorrowRecord_1
                 << setw(16) << setiosflags(ios::left) << Membership[l].BorrowRecord_2
                 << setw(16) << setiosflags(ios::left) << Membership[l].BorrowRecord_3 << endl;
            l++;
        }
        return;
    }
};
int main()
{
    VIP V;
    int e = -1;
    while (e != 0)
    {
        system("cls");
        cout << "BookInformationManageSystem" << endl;
        cout << "1--Add books." << endl;
        cout << "2--Delete books." << endl;
        cout << "3--Modify books." << endl;
        cout << "4--Display books." << endl;
        cout << "5--Search books." << endl;
        cout << "6--Save bookdata." << endl;
        cout << "7--Draw bookdata." << endl;
        cout << "8--Bookdata sort." << endl;
        cout << "9--Vip system." << endl;
        cout << "0--Exit." << endl;
        cin >> e;
        switch (e)
        {
        case 1:
        {
            system("cls");
            fflush(stdin);
            V.BB.InfoAdd();
            getchar();
            break;
        }
        case 2:
        {
            system("cls");
            fflush(stdin);
            V.BB.InfoDel();
            getchar();
            break;
        }
        case 3:
        {
            system("cls");
            fflush(stdin);
            V.BB.InfoModify();
            getchar();
            break;
        }
        case 4:
        {
            system("cls");
            fflush(stdin);
            V.BB.InfoDisplay();
            getchar();
            break;
        }
        case 5:
        {
            system("cls");
            fflush(stdin);
            V.BB.InfoQueryMenu();
            getchar();
            break;
        }
        case 6:
        {
            system("cls");
            fflush(stdin);
            V.BB.SaveFile();
            getchar();
            break;
        }
        case 7:
        {
            system("cls");
            fflush(stdin);
            V.BB.DrawData();
            getchar();
            break;
        }
        case 8:
        {
            system("cls");
            fflush(stdin);
            V.BB.NameSort(0, 4999);
            getchar();
            break;
        }
        case 9:
        {
            V.DrawData_m();
            int el = -1;
            while (el != 0)
            {
                system("cls");
                cout << "1--Membership regist." << endl;
                cout << "2--Borrow books." << endl;
                cout << "3--Giveback books." << endl;
                cout << "4--Statistics." << endl;
                cout << "0--Exit." << endl;
                cin >> el;
                switch (el)
                {
                case 1:
                {
                    system("cls");
                    fflush(stdin);
                    V.regist();
                    getchar();
                    break;
                }
                case 2:
                {
                    system("cls");
                    fflush(stdin);
                    V.Borrow();
                    V.BB.SaveFile();
                    getchar();
                    break;
                }
                case 3:
                {
                    system("cls");
                    fflush(stdin);
                    V.Giveback();
                    V.BB.SaveFile();
                    getchar();
                    break;
                }
                case 4:
                {
                    system("cls");
                    fflush(stdin);
                    V.Stat_Member();
                    getchar();
                    break;
                }
                case 0:
                {
                    V.SaveFile_m();
                    break;
                }
                default:
                    system("cls");
                    cout << "Error option." << endl;
                    fflush(stdin);
                    getchar();
                    break;
                }
            }
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
            system("cls");
            cout << "Error option." << endl;
            fflush(stdin);
            getchar();
            break;
        }
    }
}
