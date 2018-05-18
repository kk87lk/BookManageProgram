#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

struct card
{
    string name;     //卡号
    string password; //密码
    string name1;    //姓名
    string mail;     //邮箱
    string phone;    //电话
};

void regist()
{ //注册

    char *password = new char[20];
    card s;
    ifstream fin;
    string name;
    fin.open("card.dat", ios::in); //关联文件
    cout << "请输入用户名：";
    cin >> name;
    while (fin >> s.name >> s.password) //读取成功返回1
    {
        if (s.name == name)
            cout << "该用户名已被注册" << endl;
        regist();
    }
    cout << "请输入姓名：";
    cin >> s.name1;
    cout << "请输入邮箱地址";
    cin >> s.mail;
    cout >> "请输入手机号码";
    cin >> s.phone;
    char test;
    int i = 0;
    cout << "输入密码:";
    while ((test = getchar()) != '\r')
    {
        if (test == 8) //ASC2码8为退格
        {
            if (i > 0)
            {
                cout << test << " " << test;
                password[i--] = '\0';
            }
        }
        else
        {
            if (i < 20)
            {
                cout << "*";
                password[i] = test;
                i++;
            }
        }
    }
    password[i] = '\0';
    cout << "再次输入密码";
    char *password2 = new char[20];
    i = 0;
    while ((test = getchar()) != '\r')
    {
        if (test == 8)
        {
            if (i > 0)
            {
                cout << test << " " << test;
                password2[i--] = '\0';
            }
        }
        else
        {
            if (i < 20)
            {
                cout << "*";
                password2[i] = test;
                i++;
            }
        }
        password2[i] = '\0';
    }
    if (strcmp(password, password2) != 0)
    {

        cout << "密码两次输入不正确";
        regist();
    }
    else
    {
        cout << "注册成功";
    }
    ofstream fout;
    fout.open("card.dat", ios_base::out | ios_base::app);
    fout << name << " " << password << endl;
    fout.close(); //关闭文件连接，但不会删除流
    cout << "三秒后返回登陆界面";
}

void logo()
{ //登录
    char *password = new char[20];
    string name;
    cout << "用户名：" << endl;
    cin >> name;
    cout << " 密码：" << endl;
    char test;
    int i = 0;
    while ((test = getchar()) != '\r')
    {
        if (test == 8) //ASC2码8为退格
        {
            if (i > 0)
            {
                cout << test << " " << test;
                password[i--] = '\0';
            }
        }
        else
        {
            if (i < 20)
                cout << "*";
            password[i] = test;
            i++;
        }
    }
    password[i] = '\0';
    ifstream fin;
    fin.open("user.dat", ios_base::in);
    if (fin.fail())
    {
        cout << "文件打开失败";
    }
    card s;
    int f1;
    while (fin >> s.name >> s.password)
    {
        if (s.name == name && s.password == password)
        {
            cout << "登陆成功";
            f1 = 1; //登录成功标志
            i = 1;
        }
    }
    if (f1 == 0) //f1==0登录失败
    {
        cout << "用户名或密码错误";
        logo();
    }

    void Borrow()
    {
        while (i == 1)
        {
            string a;
            queue<int> Q;
            cout << "请输入书本编号：" << ;
            cin >> a;
            QueryISBN_b(a);
            QDisplay(recordISBN_b);
        }
        while (i != 1)
        {
            cout << ("请注册会员或登陆您的账号") << ;
            logo();
        }
    }

    void Giveback()
    {
    }