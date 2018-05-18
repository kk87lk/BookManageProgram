#include <iostream>
#include <fstream>
#include "BookClass.h"

using namespace std;

class VIP
{
  private:
    struct vip
    {
        string Account;
        string Password;
        string Name;
        string Phone;
        string BorrowRecord_1;
        string BorrowRecord_2;
        string BorrowRecord_3;
    } Membership[1000];
    int l = 0;

  public:
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
        cout << "You have borrowed the following books" << endl;
        cout << setw(16) << setiosflags(ios::left) << "ISBN"
             << setw(16) << setiosflags(ios::left) << "BookName"
             << setw(16) << setiosflags(ios::left) << "Author"
             << setw(16) << setiosflags(ios::left) << "ClassNum"
             << setw(16) << setiosflags(ios::left) << "PublishHouse"
             << setw(16) << setiosflags(ios::left) << "PublishDate"
             << setw(16) << setiosflags(ios::left) << "Price"
             << setw(16) << setiosflags(ios::left) << "NUM" << endl;
        if (Membership[l].BorrowRecord_1.empty() != true)
        {
            while (Book[i].ISBN != Membership[l].BorrowRecord_1)
                i++;
            cout << setw(16) << setiosflags(ios::left) << Book[i].ISBN
                 << setw(16) << setiosflags(ios::left) << Book[i].BookName
                 << setw(16) << setiosflags(ios::left) << Book[i].Author
                 << setw(16) << setiosflags(ios::left) << Book[i].ClassificationNumber
                 << setw(16) << setiosflags(ios::left) << Book[i].PublishingHouse
                 << setw(16) << setiosflags(ios::left) << Book[i].PublicationDate
                 << setw(16) << setiosflags(ios::left) << Book[i].Price
                 << setw(16) << setiosflags(ios::left) << "1" << endl;
            i = 0;
        }
        if (Membership[l].BorrowRecord_2.empty() != true)
        {
            while (Book[i].ISBN != Membership[l].BorrowRecord_2)
                i++;
            cout << setw(16) << setiosflags(ios::left) << Book[i].ISBN
                 << setw(16) << setiosflags(ios::left) << Book[i].BookName
                 << setw(16) << setiosflags(ios::left) << Book[i].Author
                 << setw(16) << setiosflags(ios::left) << Book[i].ClassificationNumber
                 << setw(16) << setiosflags(ios::left) << Book[i].PublishingHouse
                 << setw(16) << setiosflags(ios::left) << Book[i].PublicationDate
                 << setw(16) << setiosflags(ios::left) << Book[i].Price
                 << setw(16) << setiosflags(ios::left) << "2" << endl;
            i = 0;
        }
        if (Membership[l].BorrowRecord_3.empty() != true)
        {
            while (Book[i].ISBN != Membership[l].BorrowRecord_3)
                i++;
            cout << setw(16) << setiosflags(ios::left) << Book[i].ISBN
                 << setw(16) << setiosflags(ios::left) << Book[i].BookName
                 << setw(16) << setiosflags(ios::left) << Book[i].Author
                 << setw(16) << setiosflags(ios::left) << Book[i].ClassificationNumber
                 << setw(16) << setiosflags(ios::left) << Book[i].PublishingHouse
                 << setw(16) << setiosflags(ios::left) << Book[i].PublicationDate
                 << setw(16) << setiosflags(ios::left) << Book[i].Price
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

    bool logo() //��½
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
        if (logo() != true)
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
            while (Book[i].ISBN.empty() != true)
            {
                if (Book[i].ISBN == ISBN_M)
                {
                    if (Membership[l].BorrowRecord_1.empty() == true)
                        Book[i].Subscription = true;
                    Membership[l].BorrowRecord_1 = ISBN_M;

                    if (Membership[l].BorrowRecord_1.empty() != true &&
                        Membership[l].BorrowRecord_2.empty() == true)
                        Book[i].Subscription = true;
                    Membership[l].BorrowRecord_2 = ISBN_M;

                    if (Membership[l].BorrowRecord_1.empty() != true &&
                        Membership[l].BorrowRecord_2.empty() != true &&
                        Membership[l].BorrowRecord_3.empty() == true)
                        Book[i].Subscription = true;
                    Membership[l].BorrowRecord_3 = ISBN_M;
                    else
                    {
                        cout << "The maxium borrow number was 3!";
                        return false;
                    }
                }
                else
                    i++;
            }
        }
        return false;
    }
};

bool Giveback()
{
    system("cls");
    if (logo() != true)
    {
        cout << "Error Account or Password!";
        return false;
    }
    else
    {
        ListDisplay();
        int co = 0;
        cout << "Choose the NUM you want to giveback:";
        cin >> co;
        switch (co)
        {
        case 1:
        {
            while (Book[i].ISBN != Membership[l].BorrowRecord_1)
                i++;
            Book[i].Subscription = false;
            Membership[l].BorrowRecord_1 = NULL;
            cout << "Giveback successfully";
            break;
        }
        case 2:
        {
            while (Book[i].ISBN != Membership[l].BorrowRecord_2)
                i++;
            Book[i].Subscription = false;
            Membership[l].BorrowRecord_2 = NULL;
            cout << "Giveback successfully";
            break;
        }
        case 3:
        {
            while (Book[i].ISBN != Membership[l].BorrowRecord_3)
                i++;
            Book[i].Subscription = false;
            Membership[l].BorrowRecord_3 = NULL;
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
int main()
{
    VIP v;
    v.DrawData_m();
    v.regist();
    v.SaveFile_m();
    cout << v.logo();
}