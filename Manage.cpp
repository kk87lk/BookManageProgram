#include <iostream>
#include "BookClass.h"
#include "VIPClass.h"

int main()
{
    BookInformationManage B;
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
            B.InfoAdd();
            getchar();
            break;
        }
        case 2:
        {
            system("cls");
            fflush(stdin);
            B.InfoDel();
            getchar();
            break;
        }
        case 3:
        {
            system("cls");
            fflush(stdin);
            B.InfoDisplay();
            getchar();
            break;
        }
        case 4:
        {
            system("cls");
            fflush(stdin);
            B.InfoQueryMenu();
            getchar();
            break;
        }
        case 5:
        {
            system("cls");
            fflush(stdin);
            B.InfoQueryMenu();
            getchar();
            break;
        }
        case 6:
        {
            system("cls");
            fflush(stdin);
            B.SaveFile();
            getchar();
            break;
        }
        case 7:
        {
            system("cls");
            fflush(stdin);
            B.DrawData();
            getchar();
            break;
        }
        case 8:
        {
            system("cls");
            fflush(stdin);
            B.NameSort();
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
                    getchar();
                    break;
                }
                case 3:
                {
                    system("cls");
                    fflush(stdin);
                    V.Giveback();
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
