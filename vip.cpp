#include <iostream>
#include <fstream>

using namespace std;

struct vip
{
    string name;      //卡号
    string password;  //密码
    string name1;     //姓名
    string mail;      //邮箱
    int phone;        //电话
    char location[50] //地址
        int info;     //挂失信息，info=0表示没有挂失，info=1表示已挂失
} vipcard[100];
