#include <iostream>
#include <string>
using namespace std;

class Shape{
public:
    Shape(string s=""):name(s){cout<<"Shape Constructor"<<endl;}
    ~Shape(){cout<<"Shape Destructor"<<endl;}
    void setN(string s){name=s;}
    string getN(){return name;}
    double area(){return 0;}
    void print(){cout<<"Shape:"<<name<<endl;}
private:
    string name;
};

class Circle:public Shape{
public:
    Circle(string s, double r):Shape(s),radius(r){cout<<"Circle Constructor"<<endl;}
    ~Circle(){cout<<"Circle Destructor"<<endl;}
    void setR(double r){radius=r;}
    double getR(){return radius;}
    double area(){return 3.14*radius*radius;}
    void print(){Shape::print();  cout<<"radius: "<<radius<<"area: "<<area()<<endl;}
private:
    double radius;
};

class Rectangle:public Shape{
public:
    Rectangle(string s, double w, double l):Shape(s),width(w),length(l){cout<<"Rectangle Constructor"<<endl;}
    ~Rectangle(){cout<<"Rectangle Destructor"<<endl;}
    double getW(){return width;}
    double area(){return width*length;}
    void print(){Shape::print();cout<<"length: "<<length<<"width: "<<width<<"area: "<<area()<<endl;}
private:
    double width,length;
};

class Square:public Rectangle{
public:
    Square(string s, double d):Rectangle(s, d, d){cout<<"Square Constructor"<<endl;}
    ~Square(){cout<<"Square Destructor"<<endl;}
    void print(){Shape::print(); cout<<"length: "<<getW()<<"area: "<<area()<<endl;}
    Circle inCircle()
    {
        return Circle("circle",getW()/2);
    }
};

 int main()
 {
     /*
     Square s("square",4);
     Rectangle r("rec",5,6);
     Circle c("circle",2);
     Shape s1("shape");
     
    
     Shape * a[5]={&s,&r,&c,&s1,&s1};

     for(int i=0;i<5;i++)
     {
         a[i]->print();
     }
     
     Shape b[5]={s,r,c,s1,s1};
     
     for(int i=0;i<5;i++)
         b[i].print();
     */
     
     
     
      Shape *p=new Square("square",4);
      p->print();
      delete p;
 }
