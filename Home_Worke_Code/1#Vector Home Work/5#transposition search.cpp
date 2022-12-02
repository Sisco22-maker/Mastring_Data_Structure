/*
(اللهم صلْ وسلم وزد وبارك على سيدنا محمد )

꧁IslaM_SobhY꧂

 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define  el "\12"
/*
==========================================
Creating the first data structure in the course :)
==========================================
*/
class Vector
{
private:
    int *arr;
    int sz; // for the user size
    int capacity;// for the capacity size
public:
    Vector(int sz)
    :sz(sz)
    {
        //just for asserting if the sz is less than zero
        sz = max(sz,1);
        capacity = sz + 10;
        arr = new int[capacity];
        //this function is invoked one time to assign
       //every element in the vector to zero value
       Assign_To_Zero();
    }
      //-------------------------------------------------------//
      Assign_To_Zero()
      {
          for(int i = 0; i < capacity; i++)
          {
              arr[i] = 0;
          }
      }

      //-------------------------------------------------------//
    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
    }
    //-------------------------------------------------------//
    int GetAt(int ind)
    {
        return arr[ind];
    }
      //-------------------------------------------------------//
    int SetAt(int ind,int val)
    {
        arr[ind] = val;
    }
      //-------------------------------------------------------//
    int GetFront()
    {
        return arr[0];
    }
      //-------------------------------------------------------//
    int GetBack()
    {
        return arr[sz-1];
    }
      //-------------------------------------------------------//
    /*
    what if you want to make a push back function ?
    you can simply make this by creating a new one
    then we copy the content of the first one in the
    new one then we assign the previous pointer to the
    new one and delete the new one from the memory
    => attention!
    this code is too slow so we have to make a faster one
    */
      //-------------------------------------------------------//
    void PushInSlowVersion(int value)
    {
        //all of this takes n^2
        //this too slow man!
        int *arr2 = new int[sz+1];
        for(int i = 0; i < sz; i++)
        {
            arr2[i] = arr[i];
        }
        arr[sz++] = value;
        swap(arr,arr2);
        delete arr2;
        arr2 = nullptr;
    }
    //-------------------------------------------------------//
    /*
    here we just expanding our capacity of the vector
    we multiply it by 2
    the increasing of the capacity is exponential
    */
    void expand_capacity()
    {
        capacity *=2;
        int *arr2 = new int[capacity];
        for(int i = 0; i < sz; i++)
        {
            arr2[i] = arr[i];
            swap(arr2,arr);
            delete arr2;
            arr2 = nullptr;
        }
    }




      //-------------------------------------------------------//
    void PushInNewVersion(int value)
    {
        if(sz == capacity)
            expand_capacity();
        arr[sz++] = value;
    }
    //-------------------------------------------------------//

    //a simple insertion function that depends on shifting
    void InsertAt(int ind,int value)
    {
        //check for the capacity in the vector
        if(sz == capacity)
            expand_capacity();
        for(int i = sz-1; i >= ind; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[ind] = value;
        sz++;
    }
    //-------------------------------------------------------//

    //doing the transpostion function
    int Find_Transposition(int value)
    {
        for(int i = 0; i <= sz; i++)
        {
            if(arr[i] == value)
            {
                if(i == 0)
                    return 0;
                swap(arr[i],arr[i-1]);
                return i- 1;
            }
        }
        return -1;//if you did not find the element at all
    }
    //-------------------------------------------------------//






};
int main() {
Vector v(4);
v.SetAt(0,1);
v.SetAt(1,2);
v.SetAt(2,3);
v.SetAt(3,4);
v.SetAt(4,5);
  return 0;
}





