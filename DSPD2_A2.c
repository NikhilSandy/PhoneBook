#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Name_Size 30
#define Num_Size 10
//Structure maintaining details about personal and proffessional contacts
struct Tree_Node
{
    int type; //0 for personal and 1 for professional;
    char* name;
    long long int  mob_num;
    char* email;
    char* office_num;
    char* address;
    char* office;
    int calls;
    char** dates;
    int* duration;
    int total_time;
    struct Tree_Node* left;
    struct Tree_Node* right;
    int height;
}*per_root = NULL,*prof_root=NULL;


//To intialize values of a Contact
void Contact_Intializer(struct Tree_Node* ptr, char* name, long long int mob_num,char* email, char *office_num ,char* address ,char* office ,int type)
{
                ptr->name = name;
                ptr->mob_num = mob_num;
                ptr->email = email;
                ptr->office_num = office_num;
                ptr->address = address;
                ptr->office = office;
                ptr->type = type;
                ptr->height = 0;
}

//To print a particular  contact 
void Print_Contact(struct Tree_Node* ptr)
{
      if(ptr->type == 1)
      {
        printf("Professional\n");
        printf("%s\n",ptr->name);
        printf("%lld\n",ptr->mob_num);
        printf("%s\n",ptr->email);
        printf("%s\n",ptr->office_num);
        printf("%s\n",ptr->address);
        printf("%s\n",ptr->office);
        printf("--------------------------------------\n");
      }
      
      else if(ptr->type == 0 )
      {
          printf("Personal\n");
          printf("%s\n",ptr->name);
          printf("%lld\n",ptr->mob_num);
          printf("%s\n",ptr->email);
          printf("--------------------------------------\n");
      }
      
}
//To find maximum
int max(int a,int b)
{
    int retval;
    if(a>b)
    {
        retval = a;
    }

    else
    {
        retval = b;
    }
    return retval;
}
//To find height
int height(struct Tree_Node* root)
{
    int retval;
    if(root == NULL)
    {
        retval = -1;
    }
    else 
    {
        retval = root->height;
    }
    return retval;

}
//Function  to rotate right
struct Tree_Node* right_rotate(struct Tree_Node* y)
{
    struct Tree_Node* x;
    if(y->left == NULL)
    {
        x = y ;
    }
    else 
    {
        x = y->left;
        y->left = x->right;
        x->right = y;
        x->height = 1+ max(height(x->left),height(x->right));
        y->height = 1+ max(height(y->left),height(y->right));
    }

    return x;
}
//Function  to rotate left
struct Tree_Node* left_rotate(struct Tree_Node* y)
{
    struct Tree_Node* x;
    if(y->right == NULL)
    {
        x = y ;
    }

    else 
    {
        x = y->right;
        y->right = x->left;
        x->left = y;
        x->height = 1+ max(height(x->left),height(x->right));
        y->height = 1+ max(height(y->left),height(y->right));
    }

    return x;
}
//Function  to balance factor of a node
int Balance_Factor(struct Tree_Node* ptr)
{
    int retval;
    if(ptr == NULL)
    {
       retval =0;
    }
    else
    {
        retval = height(ptr->left) - height(ptr->right);
    }
    return retval;
}
//To insert contacts using mobile number as a key
struct Tree_Node* insert(struct Tree_Node* root, char* name, long long int mob_num,char* email, char *office_num ,char* address ,char* office ,int type)
{
    //When first time insert is called 
    if(root == NULL)
    {
        root = (struct Tree_Node*)malloc(sizeof(struct Tree_Node));
        Contact_Intializer(root,name,mob_num,email,office_num,address,office,type);
        root->left = NULL;
        root->right = NULL;
        printf("Contact is created successfully\n");
    }
    
    else
    {
            //Check if our num is less than curr num present in root
            if(mob_num < root->mob_num) 
            {
                root->left = insert(root->left,name,mob_num,email,office_num,address,office,type);
            }
            //Check if our num is greater than curr num present in root
            else if(mob_num > root->mob_num)
            {
                root->right = insert(root->right,name,mob_num,email,office_num,address,office,type);
            }
            //Check if our num is equal to curr num present in root
            else if(mob_num == root->mob_num)
            {
                if(strcmp(name,root->name)<0)
                {
                    
                    root->left = insert(root->left,name,mob_num,email,office_num,address,office,type);
                    
                }
                else
                {
                    root->right = insert(root->right,name,mob_num,email,office_num,address,office,type);
                }
            }
            root->height = 1+max(height(root->left),height(root->right));

            int balance = Balance_Factor(root);

            if(balance > 1 && mob_num<root->left->mob_num)
            {
                printf("Yes\n");
                root = right_rotate(root);
            }
            else if(balance <-1 && mob_num>root->right->mob_num)
            {
                printf("Yes\n");
                root = left_rotate(root);
            }

            else if(balance>1 && mob_num>root->left->mob_num)
            {
                printf("Yes\n");
                root->left = left_rotate(root->left);
                root = right_rotate(root);
            }

            else if(balance<-1 && mob_num<root->right->mob_num)
            {
                printf("Yes\n");
                root->right = right_rotate(root->right);
                root = left_rotate(root);

            }
    }
    
    return root;
}

//Copy the contents of one node into target node
void Copy_Contact(struct Tree_Node* ptr1 ,struct Tree_Node* ptr2)
{
    if(ptr2->type == 0)
    {
       char* name = (char*)malloc(sizeof(char)*Name_Size);
       char* email = (char*)malloc(sizeof(char)*Name_Size);
       ptr1->name = strcpy(name,ptr2->name);
       ptr1->mob_num = ptr2->mob_num;
       ptr1->email = strcpy(email,ptr2->email);
       ptr1->type = ptr2->type;

    }
    else
    {
       char* name = (char*)malloc(sizeof(char)*Name_Size);
       char* email = (char*)malloc(sizeof(char)*Name_Size);
       char* office_num = (char*)malloc(sizeof(char)*Num_Size);
       char* address  = (char*)malloc(sizeof(char)*Name_Size);
       char* office = (char*)malloc(sizeof(char)*Name_Size);
       ptr1->name = strcpy(name,ptr2->name);
       ptr1->mob_num = ptr2->mob_num;
       ptr1->email = strcpy(email,ptr2->email);
       ptr1->office_num = strcpy(office_num,ptr2->office_num );
       ptr1->address = strcpy(address,ptr2->address);
       ptr1->office = strcpy(office,ptr2->office);
       ptr1->type = ptr2->type;
    } 

}

//Function to find minimum node in right subtree
struct Tree_Node* Inorder_Successor(struct Tree_Node* node)
{
    struct Tree_Node* current = NULL;
    /* loop down to find the leftmost leaf */
    if(node!=NULL)
    {
       current = node->right;
       while (current->left != NULL )
       {
          current = current->left;
       }
    }

    return current;
}

//function to delete a node ina tree given its key
struct Tree_Node* Delete(struct Tree_Node* root , long long int mob_num)
{
    if(root != NULL)
    {
        if(mob_num<root->mob_num)
        {
            root->left = Delete(root->left,mob_num);
        }

        else if(mob_num>root->mob_num)
        {
            root->right = Delete(root->right,mob_num);
        }

        else
        {
            //Node with one child or no child
            if(root->left == NULL || root->right == NULL)
            {
                struct Tree_Node* temp = root->left ? root->left:root->right;
                if(temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else
                {
                    Copy_Contact(root,temp);
                    root->left = NULL;
                    root->right = NULL;
                }
                free(temp);
            }

            else
            {
                struct Tree_Node* temp = Inorder_Successor(root);
                Copy_Contact(root,temp);
                root->right = Delete(root->right,temp->mob_num);
            }
        }

        if(root!=NULL)
        {
            root->height = 1 + max(height(root->left),height(root->right));

            int balance = Balance_Factor(root);

            if(balance>1 && Balance_Factor(root->left)>=0)
            {
                root =  right_rotate(root);
            }
            
            else if(balance >1 && Balance_Factor(root->left)<0)
            {
                 root->left = left_rotate(root->left);
                 root =  right_rotate(root);
            }

            else if(balance< -1 && Balance_Factor(root->right)<=0)
            {
                root = left_rotate(root);

            }

            else if(balance< -1 && Balance_Factor(root->right)>0)
            {
                root->right = right_rotate(root->right);
                root = left_rotate(root);

            }
        }
    }

    return root;

}

// Given  the key to search , search in both personal and proffesional trees and print the matches if any.
void Search(long long int mob_num)
{
    struct Tree_Node* curr;
    curr = per_root;
    int flag = 0;
    //searching in personal contact tree
    while(curr !=NULL &&!flag)
    {
        if(mob_num > curr->mob_num)
        {
            curr = curr->right;
        }

        else if(mob_num < curr->mob_num)
        {
            curr = curr->left;
        }

        else
        {
           printf("Results Matching The Search In Personal Tree\n");
           Print_Contact(curr);
           flag = 1;
        }

    }
    //searching in proffesional contact tree
    curr = prof_root;
    int flag1 = 0;
    while(curr !=NULL &&!flag1)
    {
        if(mob_num > curr->mob_num)
        {
            curr = curr->right;
        }

        else if(mob_num < curr->mob_num)
        {
            curr = curr->left;
        }

        else
        {
           printf("Results Matching The Search In Professional Tree\n");
           Print_Contact(curr);
           flag1 = 1;
        }

    }
    if(flag ==0 && flag1 ==0)
    {
        printf("No results matched to search\n");
    }

    
}

//inorder traversal
void InOrder_Traversal(struct Tree_Node* Root)
{
    if(Root!=NULL)
    {
        InOrder_Traversal(Root->left);
        Print_Contact(Root); //Visiting the node
        InOrder_Traversal(Root->right);
    }
}

//reverse inorder traversal
void Reverse_InOrder(struct Tree_Node* Root)
{
    if(Root!=NULL)
    {
        Reverse_InOrder(Root->right);
        Print_Contact(Root); //Visiting the node
        Reverse_InOrder(Root->left);
    }

}

//Function to Display the contents of the personal linked list and proffesional linked list provided the type of Tree_Nodes in linked list
void Display_All(int type)
{
    struct Tree_Node* nptr;
    if(type == 0)
    {
         printf("Displaying Personal Tree\n");
         nptr = per_root;
         InOrder_Traversal(nptr);
    }

    else if (type == 1)
    {
        printf("Displaying Personal Tree\n");
        nptr = prof_root;
        InOrder_Traversal(nptr);
    }

    else
    {
        printf("Please Enter Valid Type to Display contacts");
    }
    
}

//Displaying the nodes in the tree in decreasing order of the keys
void Decresing_Display(int type)
{
    struct Tree_Node* nptr;
    if(type == 0)
    {
         printf("Displaying Personal Tree\n");
         nptr = per_root;
         Reverse_InOrder(nptr);
    }

    else if (type == 1)
    {
        printf("Displaying Personal Tree\n");
        nptr = prof_root;
        Reverse_InOrder(nptr);
    }

    else
    {
        printf("Please Enter Valid Type to Display contacts");
    }
}

//Function to edit the contact details

void Edit(struct Tree_Node* ptr,char* name, long long int mob_num,char* email, char *office_num ,char* address ,char* office)
{
    //To edit proffessional contact
    if(ptr->type == 1)
    {
       if(name!=NULL)
       {
          ptr->name = name;
       }
    
       if (mob_num!=0)
       {
          ptr->mob_num = mob_num;
       }
    
       if(email!=NULL)
       {
          ptr->email = email;
       }
    
       if(office_num!=NULL)
       {
          ptr->office_num = office_num;
       }
    
       if(address!=NULL)
       {
          ptr->address = address;
       }

       if(office!=NULL)
       { 
          ptr->office = office;
       }
       //case whhen mob_num(key)is edited
       if(mob_num!=0)
       {
          struct Tree_Node* temp = (struct Tree_Node*)malloc(sizeof(struct Tree_Node));
          Copy_Contact(temp,ptr);
          prof_root = Delete(prof_root,ptr->mob_num);
          prof_root = insert(prof_root,temp->name,mob_num,temp->email,temp->office_num,temp->address,temp->office,temp->type);
       }
       printf("Modified Contact\n");
    }
    //To edit personal contact
    else 
    {
       if(name!=NULL)
       {
          ptr->name = name;
       }

       if(email!=NULL)
       {
          ptr->email = email;
       }
       //case whhen mob_num(key)is edited
       if(mob_num!=0)
       {
          struct Tree_Node* temp = (struct Tree_Node*)malloc(sizeof(struct Tree_Node));
          Copy_Contact(temp,ptr);
          per_root = insert(per_root,temp->name,mob_num,temp->email,temp->office_num,temp->address,temp->office,temp->type);
          per_root = Delete(per_root,ptr->mob_num);
       }
       printf("Modified Contact \n");
    }
}
// Function to display the nodes in sorted mannner(increasing,decreasing) based on the option provided
void Sort(struct Tree_Node* root,int opt)
{
    switch(opt)
    {
        case 1:
             Display_All(root->type);
             break;
            
        case -1:
            Decresing_Display(root->type);
            break;
        default:
            printf("Enter the correct option for sorting\n");
    }

}

//function to display the nodes in tree having mob_num in the given range
void Range_Search(struct Tree_Node* root,long long int start ,long long int end)
{
    if(root!=NULL)
    {
        Range_Search(root->left,start,end);
        if(root->mob_num<=end && root->mob_num>=start)
        {
            Print_Contact(root);
        }
        Range_Search(root->right,start,end);
    }

}

//Function to insert the nodes in a tree using name as a key
struct Tree_Node* name_based_insert(struct Tree_Node* root, char* name, long long int mob_num,char* email, char *office_num ,char* address ,char* office ,int type)
{
    if(root == NULL)
    {
        root = (struct Tree_Node*)malloc(sizeof(struct Tree_Node));
        Contact_Intializer(root,name,mob_num,email,office_num,address,office,type);
        root->left = NULL;
        root->right = NULL;
        printf("Contact is created successfully\n");
    }
    
    else
    {
            //Check if our name is less than curr name present in root
            if(strcmp(name,root->name)<0)
            {
                root->left = name_based_insert(root->left,name,mob_num,email,office_num,address,office,type);
            }
            else if(strcmp(name, root->name)>0)
            {
                root->right = name_based_insert(root->right,name,mob_num,email,office_num,address,office,type);
            }
            //Check if our name is equal to curr name present in root
            else if(strcmp(name,root->name)==0)
            {

                if(mob_num < root->mob_num)
                {
                    
                    root->left = name_based_insert(root->left,name,mob_num,email,office_num,address,office,type);
                    
                }
                else
                {
                    root->right = name_based_insert(root->right,name,mob_num,email,office_num,address,office,type);
                }
            }
            root->height = 1+max(height(root->left),height(root->right));

            int balance = Balance_Factor(root);

            if(balance > 1 && strcmp(name,root->left->name)<0)
            {
                printf("left left\n");
                root = right_rotate(root);
            }
            else if(balance <-1 && strcmp(name,root->right->name)>0)
            {
                printf("right righht\n");
                root = left_rotate(root);
            }

            else if(balance>1 && strcmp(name,root->left->name)>0)
            {
                printf("left right\n");
                root->left = left_rotate(root->left);
                root = right_rotate(root);
            }

            else if(balance<-1 && strcmp(name,root->right->name)<0)
            {
                printf("right left\n");
                root->right = right_rotate(root->right);
                root = left_rotate(root);
            }
    }
    
    return root;
    
}

//Function that recursively takes out the node from mob_num based tree and insert them in name_root but using name as key this time
struct Tree_Node* name_based_sort(struct Tree_Node* name_root,struct Tree_Node* num_root )
{
    if(num_root!=NULL)
    {
       name_root = name_based_insert(name_root,num_root->name,num_root->mob_num,num_root->email,num_root->office_num,num_root->address,num_root->office,num_root->type);
       name_root = name_based_sort(name_root,num_root->left);
       name_root = name_based_sort(name_root,num_root->right);
    }
    return name_root;
}
//Function to display the nodes in increasing order of names
void Display_Name_Increasing(struct Tree_Node* root)
{
    struct Tree_Node* nptr = root;
    printf("Displaying Contancts Sorted Based On Name\n");
    InOrder_Traversal(nptr); 
}

int main()
{

    printf("Enter the number of contacts you wants to insert\n");
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        
        char* name = (char*)malloc(sizeof(char)*Name_Size);
        long long int mob_num ;
        char* email = (char*)malloc(sizeof(char)*Name_Size);
        char* office_num = (char*)malloc(sizeof(char)*Num_Size);
        char* address  = (char*)malloc(sizeof(char)*Name_Size);
        char* office = (char*)malloc(sizeof(char)*Name_Size);
        int type;
        printf("Enter the type of the contact\n");
        scanf("%d",&type);

        if(type == 0)
        {
            printf("Enter the name of the contact\n");
            scanf("%s",name);
            printf("Enter the mob_num of the contact\n");
            scanf("%lld",&mob_num);
            printf("Enter the email of the contact\n");
            scanf("%s",email);
            per_root = insert(per_root,name,mob_num,email,NULL,NULL,NULL,type);
            //Display_All(0);
            
        }
        else
        {
            printf("Enter the name of the contact\n");
            scanf("%s",name);
            printf("Enter the mob_num of the contact\n");
            scanf("%lld",&mob_num);
            printf("Enter the email of the contact\n");
            scanf("%s",email);
            printf("Enter the office_num of the contact\n");
            scanf("%s",office_num);
            printf("Enter the address of the contact\n");
            scanf("%s",address);
            printf("Enter the office of the contact\n");
            scanf("%s",office);
            prof_root  = insert(prof_root,name,mob_num,email,office_num,address,office,type);
            
        }
    }
    int flag = 0;
    do
    {
       printf("Press 0 to Exit the Program\n");
       printf("Press 1 to Edit the contact details\n");
       printf("Press 2 to Delete the contact details\n");
       printf("Press 3 to Search for  the contact details\n");
       printf("Press 4 to Sort the phone book\n");
       printf("Press 5 to Display the contact details\n");
       printf("Press 6 for Range Search\n");
       printf("Press 7 to Sort the Phone Book based on Name\n");
       int opt;
       printf("Enter the Option\n");
       scanf("%d",&opt);
       int x,y;
       long long int n,n1,n2;
       struct Tree_Node* name_root = NULL;
       switch(opt)
       {
       case 0:
           flag=1;
           break;
       case 1:
           printf("Editing the Contact\n");
           printf("Press 0 for Personal and 1 for Professional\n");
           scanf("%d",&x);
           printf("Enter the mob_num(key) of contact to be Edited to\n");
           scanf("%lld",&n);
           if(x==0)
           {
               Edit(per_root,NULL,n,NULL,NULL,NULL,NULL);
           }
           else if(x==1)
           {
               Edit(prof_root,NULL,n,NULL,NULL,NULL,NULL);
           }

           else
           {
               printf("Enter the valid type\n");
           }
           break;
    
       case 2 :
           printf("Deleting The Contact\n");
           printf("Press 0 for Personal and 1 for Professional\n");
           scanf("%d",&x);
           printf("Enter the mob_num(key) of contact to be deleted\n");
           scanf("%lld",&n);
           if(x==0)
           {
               per_root = Delete(per_root,n);
           }
           else if(x==1)
           {
               prof_root = Delete(prof_root,n);
           }

           else
           {
               printf("Enter the valid type\n");
           }
           break;

        case 3:
           printf("Searching for the Contact\n");
           printf("Enter the mob_num(key) of contact to be Searched\n");
           scanf("%lld",&n);
           Search(n);
           break;
        case 4:
           printf("Sorting the contacts\n");
           printf("Press 0 for Personal and 1 for Professional\n");
           scanf("%d",&x);
           if(x==0)
           {
               printf("Enter 1 to sort in increasing order and  -1 to sort in decreasig order\n");
               scanf("%d",&y);
               Sort(per_root,y);
           }
           else if(x==1)
           {
               printf("Enter 1 to sort in increasing order and  -1 to sort in decreasig order\n");
               scanf("%d",&y);
               Sort(prof_root,y);
           }

           else
           {
               printf("Enter the valid type\n");
           }
           break;
        case 5:
           printf("Press 0 for Personal and 1 for Professional\n");
           scanf("%d",&x);
           if(x==0)
           {
               Display_All(x);
           }
           else if(x==1)
           {
               Display_All(x);
           }

           else
           {
               printf("Enter the valid type\n");
           }
           break;
        case 6:
           printf("Range Search\n");
           printf("Press 0 for Personal and 1 for Professional\n");
           scanf("%d",&x);
           printf("Enter the start(mob_num) and end(mob_num) of range for searching\n");
           scanf("%lld %lld",&n1,&n2);
           if(x==0)
           {
               Range_Search(per_root,n1,n2);
           }
           else if(x==1)
           {
               Range_Search(prof_root,n1,n2);
           }
           else
           {
               printf("Enter the valid type\n");
           }
           break;
        case 7:
           printf("Sorting Based On Name\n");
           printf("Press 0 for Personal and 1 for Professional\n");
           scanf("%d",&x);
           if(x==0)
           {
               name_root = name_based_sort(name_root,per_root);
               Display_Name_Increasing(name_root);
           }
           else if(x==1)
           {
               name_root = name_based_sort(name_root,prof_root);
               Display_Name_Increasing(name_root);
           }
           else
           {
               printf("Enter the valid type\n");
           }
           break;
         
       default:
           printf("Enter Valid Option\n");
       }
    } while(!flag);

    return 0;
}
