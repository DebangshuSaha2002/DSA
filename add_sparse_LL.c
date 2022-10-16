#include<iostream>
using namespace std;
//Structure of Sparse Matri
typedef struct sp
 {
 int row,col,val;
 struct sp *next;
 }sparse;

class spmatrix{
      sparse *head;

      public:
      spmatrix()
      {
 head=NULL;
      }
 void read_spmatrix()
      {
 sparse *temp,*last;
 int r,c,v,no,val;
 cout<<"Enter how many rows and coluns are there: ";
 cin>>r>>c;
 cout<<"Enter how many non zero values are there: ";
 cin>>no;
 head=new sparse;
 head->row=r;
 head->col=c;
 head->val=no;
 head->next=NULL;
 v=0;
 while(v<no)
 {
  temp=new sparse;
  cout<<"Enter row col value:  ";
  cin>>temp->row>>temp->col>>temp->val;
  temp->next=NULL;
  if(head->next==NULL)
  {
    head->next=temp;
    last=temp;
  }
  else
  {
   last->next=temp;
   last=temp;
  }
  v++;
 }
      }
//Display sparse matrix
    void print_spmatrix()
    {
 sparse *temp;
 temp=head;
 while(temp)
 {
  cout<<temp->row<<" "<<temp->col<<" "<<temp->val<<"\n";
  temp=temp->next;
 }
    }

//Insertion of sparse matrix
 void insert_term(sparse *t)
 {
  sparse *tr,*temp;
  temp=new sparse;
  temp->col=t->col;
  temp->row=t->row;
  temp->val=t->val;
  temp->next=NULL;

   if(head==NULL)
  {
   head=new sparse;
   head->next=temp;
   head->val=1;
  }
  else
  {
   tr=head->next;
   while(tr->next!=NULL)
   {
    if(tr->row==temp->row&&tr->col==temp->col)
    {
      tr->val=tr->val+temp->val;
      return;
    }
    tr=tr->next;
   }
   if(tr->row==temp->row&&tr->col==temp->col)
   {
    tr->val=tr->val+temp->val;
    return;
   }

     tr->next=temp;
    (head->val)++;

   }

  }
//Muliplication of sparse matrix

  spmatrix mul_spmatrix(spmatrix m)
 {
  spmatrix res;
  sparse *t1,*t2,*temp;
  temp=new sparse;
  t1=head->next;
  t2=m.head->next;
  while(t1!=NULL)
  {
   t2=m.head->next;
   while(t2->next!=NULL)
   {
    if(t1->col==t2->row)
    {
    temp->row=t1->row;
    temp->col=t2->col;
    temp->val=(t1->val)*(t2->val);
    temp->next=NULL;
    res.insert_term(temp);
    }
    t2=t2->next;
   }
   if(t2->next==NULL)
   {
    if(t1->col==t2->row)
    {
    temp->row=t1->row;
    temp->col=t2->col;
    temp->val=(t1->val)*(t2->val);
    temp->next=NULL;
    res.insert_term(temp);
    }
   }
   t1=t1->next;
  }

   res.head->row=head->row;
  res.head->col=m.head->col;
  return res;
 }

//Addition of sparse matrix

    spmatrix add_spmatrix(spmatrix m)     
    {
 spmatrix res;
 if(head->row!=m.head->row||head->col!=m.head->col)
 {
  cout<<"Additon is not possible";
  return res;
 }
 sparse *t1,*t2,*temp;
 temp=new sparse;
 t1=head->next;
 t2=m.head->next;
 while(t1!=NULL&&t2!=NULL)
 {
  if(t1->row==t2->row)
  {
   if(t1->col==t2->col)
   {
   temp->row=t1->row;
   temp->col=t1->col;
   temp->val=t1->val+t2->val;
   temp->next=NULL;
   res.insert_term(temp);
   t1=t1->next;
   t2=t2->next;
   }
   if(t1->col<t2->col)
   {
     temp->row=t1->row;
     temp->col=t1->col;
     temp->val=t1->val;
     res.insert_term(temp);
     t1=t1->next;
   }
   else
   {
     temp->row=t2->row;
     temp->col=t2->col;
     temp->val=t2->val;
     res.insert_term(temp);
     t2=t2->next;
   }
   }
   else
   {

    if(t1->row<t2->row)
   {
     temp->row=t1->row;
     temp->col=t1->col;
     temp->val=t1->val;
     res.insert_term(temp);
     t1=t1->next;
   }
   else
   { temp->row=t1->row;
     temp->col=t2->col;
     temp->val=t2->val;
     res.insert_term(temp);
     t2=t2->next;
   }

    }

  }
 while(t1!=NULL)
 {
    temp->row=t1->row;
    temp->col=t1->col;
    temp->val=t1->val;
    res.insert_term(temp);
    t1=t1->next;
 }
 while(t2!=NULL)
 {
   temp->row=t2->row;
   temp->col=t2->col;
   temp->val=t2->val;
   res.insert_term(temp);
   t2=t2->next;
 }
 res.head->row=head->row;
 res.head->col=head->col;
 return res;
    }

};
//Menu of sparse matrix
void main()
{
     spmatrix s1,s2,s3;

     s1.read_spmatrix();
     s2.read_spmatrix();

   cout<<"\nFirst sparse Matrix: \n";
     s1.print_spmatrix();

     cout<<"\nSecond sparse matrix: \n";
     s2.print_spmatrix();

   s3=s1.add_spmatrix(s2);
     cout<<"\nResult: \n";
     s3.print_spmatrix();


   s3.mul_spmatrix(s2);
 // s3.print_spmatrix();
     cin.get();
  cin.get();
  }