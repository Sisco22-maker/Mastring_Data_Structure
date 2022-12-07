/*
(اللهم صلْ وسلم وزد وبارك على سيدنا محمد )

꧁IslaM_SobhY꧂

 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define  el "\12"
struct Node
{
    int data;
    Node *next {};
    Node(int data):
        data(data)
        {
            //maybe some code will be here who know!
        }
        //the destructor of the node
        ~Node()
        {
            cout << "Destroy The value: " << data << " at address " << this << el;
        }
};
class LinkedList
{
private:
    Node *head {};
    Node *tail {};
    int sz = 0;
    public:
        //1- the first function to print the linked list
        void Print()
        {
            if(!Vrified())
            {
                cout << "There is something wrong in your list!" <<el;
                return;
            }
            Node *temp_node = head;
            while(temp_node != nullptr)
            {
                cout << temp_node->data << " ";
                temp_node = temp_node->next;
            }
        }
        //2- the second function to insert from the end of the list
        void Insert_end(int value)
        {
            Node *newnode = new Node(value);
            if(head == nullptr)head = tail = newnode;
            tail->next = newnode;
            tail = newnode;
            sz++;
        }
       //3- the third function to get the nth Zero-based element from the list
       Node *Get_nth(int n)
       {
           if(n >= sz)return nullptr;
           Node *temp_head = head;
           while(n--)
           {
            temp_head = temp_head->next;
           }
           return temp_head;
       }
       //4- the fourth function to search a particular element in a list
       int Search(int value)
       {
           // i will use for loop here just for changing
           int i = 0;
           for(Node *curr = head; curr; curr = curr->next,i++)
           {
               if(curr->data == value)
                return i;
           }
           return -1;
       }
     //5- the fifth function to search a particular element in a list improved
      int Search_Improved(int value)
       {
           // i will use for loop here just for changing
           int i = 0;
           Node *temp = head;
           for(Node *curr = head; curr; temp = curr ,curr = curr->next,i++)
           {
               if(curr->data == value)
               {
                   if(i)
                   swap(curr->data,temp->data);
                   return i-1;
               }
           }
           return -1;
       }
       //6- the sixth function to check the code verified
       bool Vrified()
       {
           if(sz == 0)
           {
               if(head != nullptr)return 0;
               if(tail != nullptr)return 0;
           }else if(sz == 1)
           {
                if(head == nullptr)return 0;
               if(tail == nullptr)return 0;
               if(sz == 1)
               {
                   if(head != tail)return 0;
               }else
               {
                   if(head == tail)return 0;
                   if(!tail->next)return 0;
               }
           }
           int len = 0;
           for(Node *curr = head;curr;++len,curr = curr->next)
            if(len  > 10000)return 0; // to make sure that there is no cycle in the list
            // if there is a cycle then the list size will be too big
           if(len != sz)return 0;
           //if(sz !=(int)debug_data.size()) return 0;
           return 1;
       }
       //7-the seventh function to return the whole list as a string
       string debug_to_string()
       {
           if(sz == 0)
               return "";

               ostringstream  oss;
               for(Node *curr = head; curr; curr = curr->next)
               {
                   oss << curr->data;
                   if(curr->next)
                    oss << " ";
               }
               return oss.str();
       }
       //================================================//
       //here you can find the solutions of the Home Work

       //home work number two:
       //making an insert front function
       void Insert_front(int value)
       {
           Node *newnode = new Node(value);
           newnode->next = head;
           head = newnode;
           sz++;
       }
};
int main() {

LinkedList l;
l.Insert_end(5);
l.Insert_end(7);
l.Insert_end(8);
l.Insert_end(9);
l.Insert_front(1);
l.Insert_front(2);
string s = l.debug_to_string();
cout << s << el;


  return 0;
}





