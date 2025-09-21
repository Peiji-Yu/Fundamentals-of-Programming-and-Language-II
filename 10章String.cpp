#include<cstring>
#include<iostream>
#include<iomanip>

#pragma warning(disable : 4996)

using namespace std;

#ifndef STRING_H
#define STRING_H

class String
{
    friend ostream &operator<<(ostream &, const String  &);
    friend istream &operator>>(istream &, String &);
public:
    String (const char* ="");
    String (const String &);
    ~String();
    
    const String &operator=(const String &);
    const String &operator+=(const String &);
    
    bool operator!() const;
    bool operator==(const String &) const;
    bool operator!=(const String &) const;
    bool operator<(const String &) const;
    bool operator>(const String &) const;
    bool operator<=(const String &) const;
    bool operator>=(const String &) const;
    
    char &operator[](int);
    char operator[](int) const;
    String operator()(int, int=0) const;
    int getLength() const;
    void setString(const char *);
private:
    int length;
    char *sPtr;
};
#endif

String::String(const char *s):length((s!=0)?strlen(s):0)
{
    //cout<<"Conversion constructor "<<s<<endl;
    setString(s);
}

void String::setString(const char *string2)
{
    sPtr=new char[length+1];
    if(string2!=0)
        strcpy(sPtr,string2);
    else
        sPtr[0]='\0';
}

String::String(const String &copy):length(copy.length)
{
    //cout<<"Copy constructor "<<copy.sPtr<<endl;
    setString(copy.sPtr);
}

String::~String()
{
    //cout<<"Destructor:"<<sPtr<<endl;
    delete [] sPtr;
}

const String &String::operator=(const String &right)
{
    cout<<"operator= called"<<endl;
    
    if(&right!= this)
    {
        delete [] sPtr;
        length=right.length;
        setString(right.sPtr);
    }
    else
        cout<<"Attempted assignment of a String to itself"<<endl;
    return *this;
}

const String &String::operator+=(const String &right)
{
    int newLength=length+right.length;
    char *tempPtr=new char[newLength+1];
    
    strcpy(tempPtr, sPtr);
    strcpy(tempPtr+length, right.sPtr);
    
    delete [] sPtr;
    sPtr=tempPtr;
    length=newLength;
    return *this;
}

bool String::operator!() const
{
    return length==0;
}

bool String::operator==(const String &right) const
{
    return strcmp(sPtr, right.sPtr)==0;
}

bool String::operator!=(const String &right) const
{
    return !(*this==right);
}

bool String::operator<(const String &right) const
{
    return strcmp(sPtr, right.sPtr)<0;
}

bool String::operator>(const String &right) const
{
    return right<*this;
}

bool String::operator<=(const String &right) const
{
    return !(right<*this);
}

bool String::operator>=(const String &right) const
{
    return !(*this<right);
}

char &String::operator[](int subscript)
{
    return sPtr[subscript];
}

char String::operator[](int subscript) const
{
    return sPtr[subscript];
}

String String::operator()(int index, int subLength) const
{
    if(index<0 || index>=length || subLength<0)
        return "";
    int len;
    if((subLength==0)||(index+subLength>length))
        len=length-index;
    else
        len=subLength;
    
    char *tempPtr=new char[len+1];
    strncpy(tempPtr, &sPtr[index], len);
    tempPtr[len]='\0';
    
    String tempString(tempPtr);
    delete []tempPtr;
    return tempString;
}

int String::getLength() const
{
    return length;
}

ostream &operator<<(ostream &output, const String &s)
{
    output<<s.sPtr;
    return output;
}

istream &operator>>(istream &input, String &s)
{
    char temp[100];
    input>>setw(100)>>temp;
    s.setString(temp);
    return input;
}

int main()
{
    String s1("happy"),s2(" birthday");
    cout<<"s1是："<<s1<<",s2是："<<s2<<endl;
    cout<<boolalpha
    <<"s1是否等于s2 "<<(s1==s2)<<endl
    <<"s1是否不等于s2 "<<(s1!=s2)<<endl
    <<"s1是否大于s2 "<<(s1>s2)<<endl
    <<"s1是否小于s2 "<<(s1<s2)<<endl
    <<"s1是否大于等于s2 "<<(s1>=s2)<<endl
    <<"s1是否小于等于s2 "<<(s1<=s2)<<endl
    <<"s1是否为空 "<<!s1<<endl;
    
    cout<<"s1+=s2是："<<(s1+=s2)<<endl;
    
    s1+=" to you!";
    cout<<s1<<endl;
    
    cout<<"s1从0字符取长14的子串"<<s1(0,14)<<endl;
    cout<<"s1从15字符取默认长度的子串"<<s1(15)<<endl;
    
    String s3(s1);
    cout<<"s3是："<<s3<<endl;
    
    s1[0]='H';
    cout<<s1<<endl;
}





