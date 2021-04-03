#include <iostream>
#include <cmath>
using namespace std;
const double pi=3.14159265;

double Function(double x)//返回函数sqrt(1-x*x)的值
{
    if((1-x*x)<0)return 0;//sqrt(1-x*x)不存在，不进行计算
    return sqrt(1-x*x);
}

double Sin(double x)//返回函数sin(x)的值
{
    return sin(x);
}

double Definite_intergration(double a,double b,double(*Fn)(double x))//计算函数Fn在a,b上的定积分
{
    double deltx=1e-5,sum=0;//deltx为分割区间长度
    while(a<=b)
    {
        sum+=Fn(a)*deltx;
        a+=deltx;
    }
    return sum;
}
int main()
{
    cout<<"王宇 B51714004"<<endl;
    double a,b;
    cout<<"函数sqrt(1-x*x):"<<endl;
    a=-1,b=1;
    cout<<"["<<a<<","<<b<<"]"<<":"<<Definite_intergration(a,b,Function)<<endl;
    a=-2,b=1;
    cout<<"["<<a<<","<<b<<"]"<<":"<<Definite_intergration(a,b,Function)<<endl;
    a=0,b=1;
    cout<<"["<<a<<","<<b<<"]"<<":"<<Definite_intergration(a,b,Function)<<endl;
    cout<<"函数sin(x):"<<endl;
    a=-pi,b=pi;
    cout<<"["<<a<<","<<b<<"]"<<":"<<Definite_intergration(a,b,Sin)<<endl;
    a=0,b=pi;
    cout<<"["<<a<<","<<b<<"]"<<":"<<Definite_intergration(a,b,Sin)<<endl;
    a=0,b=pi/2;
    cout<<"["<<a<<","<<b<<"]"<<":"<<Definite_intergration(a,b,Sin)<<endl;
}
