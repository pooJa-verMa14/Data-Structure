#include<iostream>
using namespace std;

struct node_friend
{
    string name;
    node_friend *link;

    node_friend(string friend_name)
    {
        name=friend_name;
        link=NULL;
    }
};

struct node_user
{
    string name;
    node_friend *fri;
    node_user *user;
    int count;

    node_user(string user_name)
    {
        name=user_name;
        fri=NULL;
        user=NULL;
        count=0;
    }

};

class socMedia
{
    private:
    node_user *head;

    public:
    socMedia()
    {
        head=NULL;
    }

    void printUser()
    {
        if(head==NULL)
        {
            cout<<"NO ONE HAS REGISTERED YET\n";
        }
        node_user *curr=head;
        cout<<"LIST OF USERS:\n";
        while(curr!=NULL)
        {
            cout<<curr->name<<endl;
            curr=curr->user;
        }
    }

    int countUser()
    {
        int count=0;
        if(head==NULL)
        {
            return 0;
        }
        node_user *curr=head;
        while(curr!=NULL)
        {
            curr=curr->user;
            count++;
        }
        return count++;
    }

    void printfriend(string user_name)
    {
        node_user *ptr=search(user_name);
        if(ptr->fri==NULL)
        {
            cout<<"YOUR FRIEND LIST IS EMPTY\n";
            return;
        }
        node_friend *curr=ptr->fri;
        cout<<"LIST OF '"<<ptr->name<<"'s FRIENDS\n";
        while(curr!=NULL)
        {
            cout<<curr->name<<endl;
            curr=curr->link;
        }
    }

    void insertuser(string user_name)
    {
        node_user *temp = new node_user(user_name);
        temp->user=head;
        head=temp;
        cout<<"NEW USER '"<<user_name<<"' HAS BEEN ADDED TO THE LIST\n";
    }

    node_user *search(string user_name)
    {
        if(head==NULL)
        {
            return NULL;
        }
        node_user *curr=head;
        while(curr!=NULL)
        {
            if(curr->name==user_name)
            {
                return curr;
            }
            else
            {
                curr=curr->user;
            }
        }
        return NULL;
    }

    void insertfriend(string friend_name,string user_name)
    {
        if(user_name==friend_name)
        {
            cout<<"YOU CANNOT BE YOUR FRIEND\n";
            return;
        }
        node_user *temp=search(friend_name);
        node_user *temp2=search(user_name);
        if(temp==NULL)
        {
            cout<<"USER NOT FOUND\n";
            return;
        }
        if(temp2==NULL)
        {
            cout<<"USER NOT FOUND\n";
            return;
        }
        node_friend *temp3 = new node_friend(friend_name);
        temp3->link=temp2->fri;
        temp2->fri=temp3;
        
    }

    void deleteBeg()
    {
        if(head==NULL)
        {
            cout<<"NO ONE HAS REGISTERED YET\n";
        }
        else
        {
            node_user *temp=head->user;
            head->user=NULL;
            head->fri=NULL;
            delete head;
            head=temp;
        }
    }

    void deleteBegf(string friend_name,string user_name)
    {
        node_user *ptr=search(user_name);
        if(ptr==NULL)
        {
            cout<<"NO SUCH USER EXIST\n";
        }
        else
        {
           if(ptr->fri==NULL)
            {
                cout<<ptr->name<<"HAS NO FRIENDS\n";
            }
            else
            {
                node_friend *temp=ptr->fri->link;
                ptr->fri->link=NULL;
                delete ptr->fri;
                ptr->fri=temp;
            } 
        }
    }

    void delUser(string user_name)
    {
        node_user *temp;
       if(head==NULL)
        {
            cout<<"NO ONE HAS REGISTERED YET\n";
            return;
        }
        node_user *curr=head;
        if(curr->name==user_name)
        {
            deleteBeg();
        }
        else
        {
            while(curr->user!=NULL)
            {
                if(curr->user->name==user_name)
                {
                    temp=curr->user;
                    curr->user=temp->user;
                    node_friend *curr1=temp->fri;
                    while(curr1!=NULL)
                    {
                        delfri(user_name,curr1->name);
                        curr1=curr1->link;
                    }
                    temp->user=NULL;
                    temp->fri=NULL;
                    delete temp;
                    temp=NULL;
                    break;
                }
                else
                {
                    curr=curr->user;
                }
            }
            return ;
            
        }
    }

    void delfri(string friend_name,string user_name)
    {
        node_user *user1=search(user_name);
        if(user1!=NULL)
        {
            if(user1->fri==NULL)
            {
                return;
            }
            node_friend *temp=user1->fri;
            if(temp->name==friend_name)
            {
                deleteBegf(friend_name,user_name);
            }
            else
            {
                while(temp->link!=NULL)
                {
                    if(temp->link->name==friend_name)
                    {
                       node_friend *temp1=temp->link;
                        temp->link=temp1->link;
                        temp1->link=NULL;
                        delete temp1;
                        temp1=NULL; 
                    }
                    else
                    {
                        temp=temp->link;
                    }
                }
                
            }
        }
        else
        {
            cout<<"NO SUCH USER EXIST\n";
        }

    }

    void mutual(string user1_name,string user2_name)
    {
        int flag=0;
        node_user *user1=search(user1_name);
        node_user *user2=search(user2_name);
        node_friend *temp1=user1->fri;
        while(temp1!=NULL)
        {
            node_friend *temp2=user2->fri;
            while(temp2!=NULL)
            {
                if(temp1->name==temp2->name)
                {
                    if(flag==0)
                    {
                        cout<<"MUTUAL FRIENDS ARE\n";
                    }
                    cout<<temp1->name<<endl;
                    flag=1;
                    break;
                }
                else
                {
                    temp2=temp2->link;
                }
            }
            temp1=temp1->link;
        }
        if(flag!=1)
        {
            cout<<"NO MUTUAL FRIENDS EXIST\n";
        }
    }

    int adjacent(string user1_name,string user2_name)
    {
        if(user1_name==user2_name)
        {
            return 0;
        }
        node_user *temp=search(user1_name);
        node_user *temp1=search(user2_name);
        if(temp==NULL)
        {
            cout<<"USER WITN NAME "<<user1_name<<" NOT FOUND\n";
            return 0;
        }
        if(temp1==NULL)
        {
            cout<<"USER WITN NAME "<<user1_name<<" NOT FOUND\n";
            return 0;
        }
        node_friend *temp2=temp->fri;
        while(temp2!=NULL)
        {
            if(temp2->name==user2_name)
            {
                return 1;
            }
            else
            {
                temp2=temp2->link;
            }
        }
        return 0;
    }

    void adjancyMatrix()
    {
        for(int i=0;i<(countUser())*8;i++)
        {
            cout<<"*";
        }
        cout<<endl;
        node_user *curr=head;
        for(int i=0;i<=countUser();i++)
        {
            node_user *temp=head;
            for(int j=0;j<=countUser();j++)
            {
                if(i==0 || j==0)
                {
                    if(i==0 && j==0)
                    {
                        cout<<"| / |";
                        continue;
                    }
                    else if(i==0 && j!=0)
                    {
                        node_user *temp2=head;
                        int k=1;
                        while(k<j)
                        {
                            temp2=temp2->user;
                            k++;
                        }
                        cout<<"| "<<temp2->name<<" |";
                        continue;
                    }
                    else 
                    {
                        node_user *curr1=head;
                        int l=1;
                        while(l<i)
                        {
                            curr1=curr1->user;
                            l++;
                        }
                        cout<<"| "<<curr1->name<<" |";
                        continue;
                    }
                }
               else
               {
                    cout<<"| "<<adjacent(temp->name,curr->name)<<" |";
                    temp=temp->user;
               }
            }
            cout<<endl;
           if(i!=0)
           {
                curr=curr->user;
           }
        }
        for(int i=0;i<(countUser())*8;i++)
        {
            cout<<"*";
        }
        cout<<endl;
    }   
};

int main(void)
{
    socMedia sM;
    int ch;
    string user1_name,friend_name,user2_name;
    node_user *temp;
    cout<<"WELCOME TO MINI SOCIAL MEDIA\n";
    do
    {
        cout << "******************MENU********************" << endl;
        cout << "| PRESS 0: TO ADD USER                   |\n| PRESS 1: TO ADD FRIEND                 |\n| PRESS 2: TO PRINT USERS                |\n| PRESS 3: TO PRINT FRIENDS              |\n| PRESS 4: TO DELETE USER                |\n| PRESS 5: TO DELETE FRIEND              |\n| PRESS 6: TO FIND MUTUAL FRIENDS        |\n| PRESS 7: TO ADJENCY MATRIX             |\n| PRESS 8: TO LOG OUT                    |\n";
        cout << "******************************************" << endl;
        cout << "Enter: ";
        cin >> ch;
        switch (ch)
        {
        case 0:
            cout<<"ENTER THE NAME OF USER==>";
            cin>>user1_name;
            cout<<endl;
            sM.insertuser(user1_name);
            break;
        case 1:
            cout<<"ENTER YOUR NAME==>";
            cin>>user1_name;
            cout<<endl;
            cout<<"SELECT USER==>";
            cin>>friend_name;
            cout<<endl;
            sM.insertfriend(friend_name,user1_name);
            sM.insertfriend(user1_name,friend_name);
            cout<<friend_name<<" AND "<<user1_name<<" ARE FRIENDS NOW\n";
            break;
        case 2:
            sM.printUser();
            break;
        case 3:
            cout<<" ENTER YOUR NAME==>";
            cin>>user1_name;
            cout<<endl;
            sM.printfriend(user1_name);
            break;
        case 4:
            cout<<"ENTER THE NAME OF USER==>";
            cin>>user1_name;
            cout<<endl;
            sM.delUser(user1_name);
            break;
        case 5:
            cout<<"ENTER THE NAME OF USER==>";
            cin>>user1_name;
            cout<<endl;
            cout<<"ENTER THE NAME OF FRIEND==>";
            cin>>friend_name;
            cout<<endl;
            sM.delfri(friend_name,user1_name);
            sM.delfri(user1_name,friend_name);
            break;
        case 6:
            cout<<"ENTER THE NAME OF 1st USER==>";
            cin>>user1_name;
            cout<<endl;
            cout<<"ENTER THE NAME OF 2nd USER==>";
            cin>>user2_name;
            cout<<endl;
            sM.mutual(user1_name,user2_name);
            break;
        case 7:
             sM.adjancyMatrix();
        }
    } while (ch != 8);       
}
