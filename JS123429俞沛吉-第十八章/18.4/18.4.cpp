#include<iostream>
#include<iomanip>

using namespace std;

template<typename T>
class Array
{
    friend ostream& operator<<(ostream& output, const Array& a)
    {
        // output private ptr-based array
        for (size_t i = 0; i < a.size; ++i)
        {
            output << setw(12) << a.ptr[i];
            if ((i + 1) % 4 == 0) // 4 numbers per row of output
                output << endl;
        } // end for
        if (a.size % 4 != 0) // end last line of output
            output << endl;
        return output; // enables cout << x << y;
    } // end function operator<<

    friend istream& operator>>(istream& input, Array& a)
    {
        for (size_t i = 0; i < a.size; ++i)
            input >> a.ptr[i];
        return input; // enables cin >> x >> y;
    } // end function

public:
    explicit Array(int = 10); // default constructor
    ~Array(); // destructor
    size_t getSize() const; // return size

    bool operator==(const Array<T>&) const; // equality operator
    bool operator!=(const Array<T>&) const;

    T& operator[](int);
    T operator[](int) const;

    Array<T>(const Array<T>&); // copy constructor
    const Array<T>& operator=(const Array<T>&); // assignment operator


private:
    size_t size; // pointer-based array size
    T* ptr; // pointer to first element of pointer-based array
}; // end class Array

template<typename T>
Array<T>::Array(int arraySize)
{
    if (arraySize > 0)
        size = arraySize;
    else
        size = 10;
    ptr = new T[size];
    for (size_t i = 0; i < size; ++i)
        ptr[i] = 0; // set pointer-based array element
} // end Array default constructor

// copy constructor for class Array;
// must receive a reference to an Array
template<typename T>
Array<T>::Array(const Array<T>& arrayToCopy)
    : size(arrayToCopy.size),
    ptr(new T[size])
{
    for (size_t i = 0; i < size; ++i)
        ptr[i] = arrayToCopy.ptr[i]; // copy into object
} // end Array copy constructor

// destructor for class Array
template<typename T>
Array<T>::~Array()
{
    delete[] ptr; // release pointer-based array space
} // end destructor

// return number of elements of Array
template<typename T>
size_t Array<T>::getSize() const
{
    return size; // number of elements in Array
} // end function getSize

template<typename T>
bool Array<T>::operator==(const Array<T>& right) const
{
    if (size != right.size)
        return false; // arrays of different number of elements

    for (size_t i = 0; i < size; ++i)
        if (ptr[i] != right.ptr[i])
            return false; // Array contents are not equal

    return true; // Arrays are equal
} // end function operator==

template<typename T>
bool Array<T>::operator!=(const Array<T>& right) const
{
    return !(*this == right);
} // end function operator!=

template<typename T>
T& Array<T>::operator[](int subscript)
{
    return ptr[subscript]; // reference return
} // end function operator[]

template<typename T>
T Array<T>::operator[](int subscript) const
{
    return ptr[subscript]; // returns copy of this element
} // end function operator[]

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
template<typename T>
const Array<T>& Array<T>::operator=(const Array<T>& right)
{
    if (&right != this) // avoid self-assignment
    {
        if (size != right.size)
        {
            delete[] ptr; // release space
            size = right.size; // resize this object
            ptr = new T[size];
        } // end inner if
        for (size_t i = 0; i < size; ++i)
            ptr[i] = right.ptr[i];
    } // end outer if
    return *this; // enables x = y = z, for example
} // end function operator=

int main()
{
    Array<double> a1(3);
    Array<double> a2(3);
    cout << a1.getSize() << endl;
    cout << "Please input the elements: " << endl;
    cin >> a1 >> a2;
    cout << a1 << a2;
    if (a1 != a2)
        cout << "Not equal!" << endl;
    if (a1 == a2)
        cout << "Equal!" << endl;
    a1[2] = 1.2;
    cout << "a1[2]=" << a1[2] << endl;
    Array<double>a3 = a2;
    cout << a3;

    return 0;
}