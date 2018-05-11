#include <iostream>
#include <fstream>

using namespace std;

struct card
{
    string name;//卡号
    string password;//密码
    string name1;//姓名
    string mail;//邮箱
    int phone;//电话
    char location[50]//地址
    int info;//挂失信息，info=0表示没有挂失，info=1表示已挂失
}   vipcard[100];


void regist()
 {  //注册
    
     char *password = new char[20];
     card s;
     ifstream fin;
     string name;
     fin.open("user.dat", ios::in);//关联文件
     cout << "请输入用户名：";
     cin >> name;
     while(fin >> s.name >> s.password)//读取成功返回1
     {
         if(s.name == name)
         cout << "该用户名已被注册" << endl;
         regist();
     }

     string name1;
     cout << "请输入姓名：";
     cin >> name1; 
     char test;
     int i = 0;
    cout << "输入密码:";
     while((test = getchar()) != '\r')
     {
        if(test == 8)//ASC2码8为退格
         {
             if(i > 0)
            {
             cout << test << " " << test;
             password[i--] = '\0'; 
             }
         }
         else
         {
             if(i < 20)
             {
                 cout << "*" ;
                 password[i] = test;
                 i++;
             }
         }
     }
     password[i] = '\0';
     cout << "再次输入密码" ;
    char *password2 = new char[20];
    i=0;
     while((test = getchar()) != '\r')
     {
         if(test == 8)
         {
             if(i > 0)
             {
                 cout << test << " " << test ;
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
     fout.open("user.dat", ios_base::out | ios_base::app);
     fout << name << " " << password << endl;
     fout.close();//关闭文件连接，但不会删除流
          cout << "三秒后返回登陆界面";
     nterface();//界面
 }


 void logo()
 {//登录
     char *password = new char [20];
     string name;
     cout << "用户名："<< endl;
     cin >> name;
     cout <<" 密码："<< endl;
     char test;
     int i = 0;
    while((test = getchar()) != '\r')
     {
         if(test==8)//ASC2码8为退格
         {
         if(i>0)
         {
             cout << test << " " << test;
             password[i--] = '\0';
         }
         }
         else
         {
             if(i < 20)
             cout << "*";
             password[i] = test;
             i++;
         }
     }
     password[i] = '\0';
     ifstream fin;
     fin.open("user.dat", ios_base::in);
     if(fin.fail())
     {
         cout << "文件打开失败";
     }
     card s;
     int f1;
    while(fin>>s.name>>s.password)
     {
         if(s.name == name && s.password == password)
         {
             cout << "登陆成功";
             f1 = 1;//登录成功标志
             nterface();
         }
     }
     if(f1 == 0)//f1==0登录失败
     {
         cout << "用户名或密码错误";
         logo();
     }
 
 void create()
{
    int a = 1, k;
    int info;
    if ((fp = fopen("card.txt", "a+")) == NULL)
    {
        printf("档案不能打开!\n");
        exit(0);
    }      
    while(a==1)
    {
printf("当输入的卡号为0时停止输入饭卡信息!\n");
        printf("请输入卡号，且卡号为4位:");
        scanf("%d",&num);
if(num>=10000.0)
{
printf("请输入4位数卡号！\n");
printf("返回上一菜单！\n");
return;
}
if(num<=999)
{
printf("请输入4位数卡号！\n");
printf("返回上一菜单！\n");
return;
}
        for(k=0;k<i;k++)
        {
            while(vipcard[k].num==num)
            {
                printf("该卡号已被注册！\n");
printf("返回上一菜单！\n");
exit(0);
            }
        printf("请输入密码，且密码为10位：");
        std::cin << vipcard[k].num1 <<;endl;
        }
vipcard[i].num=num;
printf("请输入姓名:");
scanf("%s",&name);
        strcpy(vipcard[i].name,name);
        printf("请输入挂失信息（0表示没有挂失，1表示已经挂失）:");
        scanf("%d",&info);
        vipcard[i].info=info;
for(k=0;k<=i;k++)
        {
fprintf(fp,"%d %s %d %d\n",vipcard[i].num,vipcard[i].name,vipcard[i].info);
        }
i++;
        printf(".........................\n");
        printf("输入1继续注册输入0返回上一菜单\n");
        printf("..........................\n");
        scanf("%d",&a);
    }
fclose(fp);
return;
}