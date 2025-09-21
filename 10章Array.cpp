#include<iostream>
#include<iomanip>
using namespace std;
class Array
{
   friend ostream &operator<<( ostream &, const Array & );
   friend istream &operator>>( istream &, Array & );

public:
   explicit Array( int = 10 ); // default constructor
   ~Array(); // destructor
   size_t getSize() const; // return size

   bool operator==( const Array & ) const; // equality operator
   bool operator!=( const Array & ) const;
 
   int &operator[]( int );
   int operator[]( int ) const;
    
   Array( const Array & ); // copy constructor
   const Array &operator=( const Array & ); // assignment operator

  
private:
   size_t size; // pointer-based array size
   int *ptr; // pointer to first element of pointer-based array
}; // end class Array

Array::Array( int arraySize )
{
    if(arraySize>0)
        size=arraySize;
    else
        size=10;
    ptr=new int[size];
    for ( size_t i = 0; i < size; ++i )
      ptr[ i ] = 0; // set pointer-based array element
} // end Array default constructor

// copy constructor for class Array;
// must receive a reference to an Array
Array::Array( const Array &arrayToCopy )
   : size( arrayToCopy.size ),
     ptr( new int[ size ] )
{
   for ( size_t i = 0; i < size; ++i )
      ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object
} // end Array copy constructor

// destructor for class Array
Array::~Array()
{
   delete [] ptr; // release pointer-based array space
} // end destructor

// return number of elements of Array
size_t Array::getSize() const
{
   return size; // number of elements in Array
} // end function getSize

bool Array::operator==( const Array &right ) const
{
   if ( size != right.size )
      return false; // arrays of different number of elements

   for ( size_t i = 0; i < size; ++i )
      if ( ptr[ i ] != right.ptr[ i ] )
         return false; // Array contents are not equal

   return true; // Arrays are equal
} // end function operator==

bool Array::operator!=( const Array &right ) const
{
    return !( *this == right);
} // end function operator!=

int &Array::operator[]( int subscript )
{
    return ptr[ subscript ]; // reference return
} // end function operator[]

int Array::operator[]( int subscript ) const
{
   return ptr[ subscript ]; // returns copy of this element
} // end function operator[]

istream &operator>>( istream &input, Array &a )
{
   for ( size_t i = 0; i < a.size; ++i )
      input >> a.ptr[ i ];
   return input; // enables cin >> x >> y;
} // end function

ostream &operator<<( ostream &output, const Array &a )
{
   // output private ptr-based array
   for ( size_t i = 0; i < a.size; ++i )
   {
      output << setw( 12 ) << a.ptr[ i ];
      if ( ( i + 1 ) % 4 == 0 ) // 4 numbers per row of output
         output << endl;
   } // end for
   if ( a.size % 4 != 0 ) // end last line of output
      output << endl;
   return output; // enables cout << x << y;
} // end function operator<<


// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
const Array &Array::operator=( const Array &right )
{
   if ( &right != this ) // avoid self-assignment
   {
      if ( size != right.size )
      {
         delete [] ptr; // release space
         size = right.size; // resize this object
         ptr = new int[ size ];
      } // end inner if
      for ( size_t i = 0; i < size; ++i )
         ptr[ i ] = right.ptr[ i ];
   } // end outer if
   return *this; // enables x = y = z, for example
} // end function operator=





int main()
{
   Array a1(3), a2;
   cout<<a1.getSize()<<endl;
   cout<<"please input the elements:"<<endl;
   cin>>a1>>a2;
   cout<<a1<<a2;
   if(a1!=a2)
       cout<<"Not equal!"<<endl;
   a1[2]=12;
   cout<<"a[2]="<<a1[2]<<endl;
   Array a3(a1); //Array a3=a1;
  
}
