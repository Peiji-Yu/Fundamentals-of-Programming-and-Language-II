
#include <iostream>
#include <vector>
using namespace std;

class IntegerSet{
public:
    IntegerSet():a(101,false){
    }
    IntegerSet(int s[],int size):a(101,false){
        for(int i=0;i<size;i++)
            a[s[i]]=true;
    }
    IntegerSet unionOfSets(const IntegerSet& right){
        IntegerSet result;
        for(int i=0;i<101;i++)
            if(a[i]||right.a[i])
                result.insertElement(i);
        return result;
    }
   
    void insertElement(int k){
        if(k>=0&&k<=100)
            a[k]=true;
        else
            cout<<"index error!"<<endl;
    }
   
    void printSet(){
        int count=0;
        for(int i=0;i<101;i++)
            if(a[i])
            {
                cout<<i<<" ";
                count++;
                if(count%10==0)
                    cout<<endl;
            }
        cout<<endl;
        if(count==0)
            cout<<"---"<<endl;
    }
    
private:
    vector<bool> a;
};


int main() {
    // insert code here...
    IntegerSet a;
    cout<<"Set a is:";
    a.printSet();
    a.insertElement(1);
    a.insertElement(2);
    a.insertElement(3);
    a.deleteElement(3);
    cout<<"Set a is:";
    a.printSet();
    int set[5]={1,3,5,7,9};
    IntegerSet b(set,5);
    cout<<"The union of set a and b:";
    a.unionOfSets(b).printSet();
    
    return 0;
}
