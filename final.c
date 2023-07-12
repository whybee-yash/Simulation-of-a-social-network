#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    
    int L[n1], R[n2];

    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
       
        int m = l + (r - l) / 2;

        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
// Define the node structure of linked list
struct node
{
    int data;
    struct node *next;
    struct node *link;
    int arr[3];
    char *usern;
    char *pass;
    int first;
};
struct element
{
    int data;
    int freq;
    struct element *next ;

};

struct element* create(int a,int b){
struct element *head = malloc(sizeof(struct element));
head->data=a;
head->freq=b;
head->next=NULL;

}void addNodeAtTailelement(struct element *head, int k, int x)
{
    struct element *temp = malloc(sizeof(struct element));
    temp->data = k;
    temp->next = NULL;
    temp->freq= x;
    

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct element *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}void sort_freq(struct element *head){

  struct element *temp =head;
  struct element *temp2 =head;
  while(temp!=NULL){
         while (temp2!=NULL)
         {
            if(temp->freq>temp2->freq){
                int a=temp->freq;
                temp->freq=temp2->freq;
                temp2->freq=a;
                 int b=temp->data;
                temp->data=temp2->data;
                temp2->data=b;

            }temp2=temp2->next;
         }
         temp=temp->next;
         temp2=head;
  }


}
struct node *createList(int n, int x, int y, int z, char *k, char *l, int w)
{
    struct node *head = malloc(sizeof(struct node));
    head->data = n;
    head->next = NULL;
    head->link = NULL;
    head->arr[0] = x;
    head->arr[1] = y;
    head->arr[2] = z;
    head->usern = k;
    head->pass = l;
    head->first = w;
    return head;
}

void addNodeAtTail(struct node *head, int k, int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = k;
    temp->next = NULL;
    temp->link = NULL;
    temp->first = x;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void addNodeAtTailmain(struct node *head, struct node *main)
{

    struct node *ptr = main;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = head;
}
int similar(struct node *node1, struct node *node2)
{
    struct node *ptr1 = node1;
    struct node *ptr2 = node2;
    int ctr = 0;
    int p = 0;
    for (int i = 0; i < 3; i++)
    {
        if (ptr1->arr[i] == ptr2->arr[i])
        {
            ctr++;
        }
    }
    p = ctr * 100 / 3;
    return p;
}
void deleteNode(struct node **head_ref, int position)
{
    if (*head_ref == NULL)
        return;

    struct node *temp = *head_ref;

    struct node *prev_node = NULL;
    int length = 0;

    // Traverse the linked list to find the node at the given position
    while (temp != NULL && length < position)
    {
        prev_node = temp;
        temp = temp->next;
        length++;
        // printf("%d",length);
        // printf("%d",temp->data);
    }

    // If the given position is out of range, return
    if (temp == NULL)
        return;

    // If the given position is the first node, update the head pointer and delete the node
    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // If the given position is the last node, update the previous node's next pointer and delete the node
    if (position == length)
    {
        temp->next = NULL;
        free(temp->next);
        return;
    }

    // If the given position is a middle node, update the previous node's next pointer and delete the node
    prev_node->next = temp->next;
    free(temp);
}
 int loginu(char *k, char *u,struct node* main){
struct node *temp9 = main->link;
            int value = 10;
            int valuep = 10;
            //  printf("%s \n",temp9->usern);
            while (temp9 != NULL)
            {
                value = strcmp(k, temp9->usern);
                if (value == 0)
                {
                    valuep = strcmp(u, temp9->pass);
                    //   printf("%d \n",valuep);
                    //     printf("%s \n",temp9->pass);
                }
                if (valuep == 0)
                {

                    break;
                }
                //      printf("%s \n",temp9->usern);
                temp9 = temp9->link;
            } return value;
 }
 int loginp(char *k, char *u,struct node* main){
struct node *temp9 = main->link;
            int value = 10;
            int valuep = 10;
            //  printf("%s \n",temp9->usern);
            while (temp9 != NULL)
            {
                value = strcmp(k, temp9->usern);
                if (value == 0)
                {
                    valuep = strcmp(u, temp9->pass);
                    //   printf("%d \n",valuep);
                    //     printf("%s \n",temp9->pass);
                }
                if (valuep == 0)
                {

                    break;
                }
                //      printf("%s \n",temp9->usern);
                temp9 = temp9->link;
            } return valuep;
 
 }
 struct node* logins(char *k, char *u,struct node* main){
struct node *temp9 = main->link;
            int value = 10;
            int valuep = 10;
            //  printf("%s \n",temp9->usern);
            while (temp9 != NULL)
            {
                value = strcmp(k, temp9->usern);
                if (value == 0)
                {
                    valuep = strcmp(u, temp9->pass);
                    //   printf("%d \n",valuep);
                    //     printf("%s \n",temp9->pass);
                }
                if (valuep == 0)
                {

                    break;
                }
                //      printf("%s \n",temp9->usern);
                temp9 = temp9->link;
            } return temp9;
 }
int main()
{
    struct node *main = createList(0, 1, 0, 1, "main", "y", 10);

    int ctrfirst = 0;
    int arr[1000];
    int MAX_LENGTH = 10;
    int u = 0;
    int w = 10;
    int ctri;
    int ctrf;
    int brr[1000];
    char *x = "user1";
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL)
    {
        printf("Failed to open file\n");
    }
    char line[1024];
    while (fgets(line, 1024, fp))
    {
        char *field = strtok(line, ",");
        int ctr = 1;
        int num1;
        int num2;
        int num3;
        int num4;
        char *x = malloc(sizeof(char) * MAX_LENGTH);
        ;
        char *y = malloc(sizeof(char) * MAX_LENGTH);
        ;
        int num7;
        while (field)
        {
            //  printf("%s ", field);

            switch (ctr)
            {
            case 1:
                num1 = atoi(field);
                ctr++;
                break;
            case 2:
                num2 = atoi(field);
                ctr++;
                break;

            case 3:
                num3 = atoi(field);
                ctr++;
                break;

            case 4:
                num4 = atoi(field);
                ctr++;
                break;
            case 5:
                strcpy(x, field);
                ctr++;
                break;

            case 6:
                strcpy(y, field);
                ctr++;
                break;

            case 7:
                num7 = atoi(field);
                ctr++;
                break;
            }
            field = strtok(NULL, ",");
        }
        //  printf("\n");
        struct node *head1 = createList(num1, num2, num3, num4, x, y, num7);
        addNodeAtTailmain(head1, main);
        ctri++;
    }

    fclose(fp);
    // printf("%s \n", main->link->link->link->usern);
    // printf("hi dev \n");
    FILE *fp1 = fopen("friend.csv", "r");
    if (fp1 == NULL)
    {
        printf("Failed to open file\n");
    }

    char line1[1024];
    struct node *head1 = main->link;
    while (fgets(line1, 1024, fp1))
    {
        char *field = strtok(line1, ",");
        int ct = 1;
        int used = 0;
        // printf("\n");
        while (field)
        {
            int num;
            int xd;
            switch (ct)
            {

            case 1:

                num = atoi(field);
                ct++;
                used++;
                break;

            case 2:
                xd = atoi(field);
                ct--;
                used++;
                break;
            }

            field = strtok(NULL, ",");
            if (used % 2 == 0)
            {
                // printf("%d ",num);
                // printf("%d ",xd);
                // printf(" fi ");
                addNodeAtTail(head1, num, xd);
            }
        }
        head1 = head1->link;
    }
    // printf("%d \n" ,main->link->link->data);
    fclose(fp1);

    int p = 0;
    //  printf("1 to signup and 0 to sign in \n") ;
    int first = 10;
    int c;
    int k = 10;
    int sys = 0;
label:
    while (sys == 0)
    {
        int k2 = k;
        if (ctrfirst == 0)
        {   printf("************************************************************\n");
            printf("*******************WELCOME TO OUR SYSTEM********************\n");
            printf("************************************************************\n");
            printf("\n");

            printf("+----------------------------------------------------------+\n");
            printf("PRESS 1 to signup and 0 to sign in: ");
            scanf("%d", &c);
            printf("+----------------------------------------------------------+\n");
        }
        else
        {   later:   
            printf("+----------------------------------------------------------+\n");
            printf("Please enter your username and password \n");
            c = 0;
        }

        while (c == 0)
        {
        retry:
            printf("Enter username: ");
            char *str = malloc(sizeof(char) * MAX_LENGTH);
            scanf("%s", str);

            printf("Enter password: ");
            char *str2 = malloc(sizeof(char) * MAX_LENGTH);
            scanf("%s", str2);
            printf("+----------------------------------------------------------+\n");
            int value=loginu(str,str2,main);
             int valuep=loginu(str,str2,main);
             struct node*temp9=logins(str,str2,main);
            // printf("%d",valuep);
            if (value == 0 && valuep == 0)
            {
                printf("************************************************************\n");
                int lenusrname = strlen(temp9->usern);
                int numstars = 62-13-lenusrname ;
                for(int i = 0;i<numstars;i++){printf("*");}
                printf("WELCOME BACK %s",temp9->usern);
                for(int i = 0;i<numstars;i++){printf("*");}
                printf("************************************************************\n \n");
                c = 2;
            back:
                struct node *temp8 = temp9->next;
                struct node *temp11 = temp9->next;
                struct node *temp16 = temp9->next;
                struct node *temp12 = main->link;

                printf("+----------------------------------------------------------+\n");
                printf(" 1)See  pending requests. \n");
                printf(" 2)View mutals and send requests. \n");
                printf(" 3)View your friends. \n");
                printf(" 4)To search for people. \n");
                printf("+----------------------------------------------------------+\n");
                int choice;
                printf("Enter choice: ");
                scanf("%d", &choice);
                printf("+----------------------------------------------------------+\n \n");


                switch (choice)

                {

                case 1:
                    int ctr = 0;
                    while (temp16 != NULL)

                    {
                        int ch;
                        if (temp16->first == 1)
                        {
                            temp16->first = 0;
                            struct node*ptr=main->link;
                            while(ptr!=NULL){
                                if(ptr->data==temp16->data){
                                    break;
                                }
                                ptr=ptr->link;

                            }
                            printf("Do u want to follow  %s", ptr->usern);
                            printf(" \n");
                            printf("Enter 1 to follow an 0 to not: ");

                            scanf("%d", &ch);
                            if (ch == 0)
                            {
                                printf("%d", ctr);
                                deleteNode(&temp9, ctr);
                            }
                        }
                        temp16 = temp16->next;
                        ctr++;
                        ch = 1;
                    }

                    printf("**********************You have no pending requests.*******************");
                    printf("\n");

                    break;
                case 2:
                    struct node *temp = temp9;
                    struct node *temp2 = main->link;
                    //  printf("%d \n",main->link->next->data);
                    if(temp->next==NULL){
                        printf(" You are following no one currently pls follow someone to see mutal \n");
                        break;
                    }
                    {
                        /* code */
                    }
                    
                    while (temp != NULL)
                    {
                        if (temp->data == temp2->data)
                        {
                            //   printf("%d",temp2->link->data);
                            struct node *temp3 = temp2->next;
                            while (temp3 != NULL)
                            {
                                //  printf("hh");
                                arr[p] = temp3->data;
                                p++;
                                temp3 = temp3->next;
                            }
                            temp = temp->next;
                            temp2 = main->link;
                        }
                        else
                        {
                            temp2 = temp2->link;
                        }

                    } // printf("%d",p);
                    mergeSort(arr, 0, p - 1);
                    int crr[100];
                    int ch = 0; 
                    int cr=0;
                    int cr_ctr=1;
                     struct element* head_e=create(0,0);
                      for (int i = 0; i < p; i++){
                      //  printf("%d",arr[i]);
                           if(arr[i]==arr[i+1]){
                            cr_ctr++;
                           }else{
                            crr[cr]=cr_ctr;
                           
                            cr_ctr=1;
                            addNodeAtTailelement(head_e,arr[i],crr[cr]);
                             cr++;
                           }}
                           printf("\n");
                           for(int i=0;i<cr;i++){
                    
                        
                      //  printf("%d ",brr[i]);
                     //   printf("%d ",arr[i]);

                       } printf("\n");

                      struct element * temp_e=head_e;
                      while(temp_e!=NULL){
                      //  printf("%d ",temp_e->data);
                        //printf("%d \n",temp_e->freq);
                        temp_e=temp_e->next;
                      }
                  
                  printf("\n");
                   
                     sort_freq(head_e);
                    temp_e=head_e;
                      while(temp_e!=NULL){
                      //  printf("%d ",temp_e->data);
                        //printf("%d \n",temp_e->freq);
                        temp_e=temp_e->next;
                      }

                   int ch_1;
                   int ch_2;
                   int ch_3;
                   int ctr_1=0;
                   filt :
                    printf("check");
                     int u=0;
                     int ptr=0;
                  
                    struct node * temp4=temp9;
                    struct element * temp1=head_e;
                    while(temp1!=NULL){
                        while(temp4!=NULL){
                            if(temp4->data==temp1->data){

                                ptr=1;

                            } temp4=temp4->next;
                        }if(ptr==0){
                            if(temp1->freq>0){
                            brr[u]=temp1->data;
                            u++;
                            }
                        }ptr=0;
                        temp1=temp1->next;
                        temp4=temp9;
                    }

                  if(u>5){
                    u=5;
                  }
                 

                    printf(" \n");
                    printf("Mutals: \n");
                    int x_1=1;
                    //similarity score calculation
                    for (int i = 0; i < u ; i++)
                    { 
                        int sim = 0;
                        struct node *temp4 = main->link;
                        char *s;
                        while (temp4 != NULL)
                        {
                            if (temp4->data == brr[i])
                            {
                                sim = similar(temp9, temp4);
                                s=temp4->usern;
                                if(ctr_1>0){
                                if((temp4->arr[0]==ch_1 || ch_1==2) && (temp4->arr[1]==ch_2 || ch_2==2) && (temp4->arr[2]==ch_3  || ch_3==2)){
                                    x_1=1;
                                }
                                else{
                                    x_1=0;
                                } }
                            }
                            temp4 = temp4->link;
                        }if(x_1==1){
                        printf("%s ",s);
                        printf("%d", sim);
                        printf("%% ");
                        printf(" \n \n");
                    }}
                    int y;
                    printf(" DO U WANT TO FILTER YOU MUTALS\n");
                    printf("ENTER 1 FOR YES AND 0 FOR NO \n");
                    int ch_4;
                    scanf("%d", &ch_4);
                    if(ch_4==1){
                        ctr_1++;

                        printf("HE SHOULD LIVE IN PUNE \n");
                        printf("1 for yes 0 for no 2 it does not matter \n");
                        scanf("%d",&ch_1);

                        if(ch_1==2){
                            
                        }
                          printf("HE SHOULD be in college \n");
                        printf("1 for yes 0 for no 2 it does not matter \n");
                        scanf("%d",&ch_2);
                    
                          printf("HE SHOULD like sports \n");
                        printf("1 for yes 0 for no 2 it does not matter \n");
                        scanf("%d",&ch_3);
                        

                        goto filt;
                    }

                    printf("Enter 1 to add friend or 0 to not:  \n");
                    scanf("%d", &y);
                    printf("\n");

                    while (y == 1)
                    {
                        printf("+----------------------------------------------------------+\n");
                        for (int i = 0; i < u; i++)
                        {
                            printf("Enter ");
                            printf("%d", i);
                            printf("for sending a request to ");
                            printf("%d \n", brr[i]);
                        }
                        printf("+----------------------------------------------------------+\n");
                        printf("\n");

                        int r;
                        printf("Input: ");
                        scanf("%d", &r);
                        printf("\n");

                        struct node *temp4 = main->link;
                        while (temp4 != NULL)
                        {
                            if (temp4->data == temp9->data)
                            {
                                addNodeAtTail(temp4, brr[r], 0);
                            }
                            temp4 = temp4->link;
                        }
                        //  printf(" does user ");
                        //  printf("%d ",brr[r]);
                        //  printf("would like to follow back user ");

                        //  printf("%d \n ",k);
                        //   printf("enter 1 to follow back and 0 to not");

                        struct node *temp5 = main->link;
                        while (temp5 != NULL)
                        {
                            if (temp5->data == brr[r])
                            {
                                addNodeAtTail(temp5, temp9->data, 1);
                            }
                            temp5 = temp5->link;
                        }

                        printf("Enter 1 to add more friend or 0 to exit: ");
                        scanf("%d", &y);
                        printf("\n");
                    }
                    break;

                case 3:
                if(temp11==NULL){
                        printf(" You have no friends currently\n");
                    }else{
                    while (temp11 != NULL)
                    {
                        temp12 = main->link;
                        while (temp12 != NULL)
                        {
                            if (temp12->data == temp11->data)
                            {
                                printf("%s \n", temp12->usern);
                            }
                            temp12 = temp12->link;
                        }
                        temp11 = temp11->next;
                    }}
                    break;
                    case 4:
                    sea:
                    printf("Enter username: ");
            char *st = malloc(sizeof(char) * MAX_LENGTH);
            scanf("%s", st);
             struct node *temp99 = main->link;
            int value1 = 10;
            
            //  printf("%s \n",temp9->usern);
            while (temp99 != NULL)
            {
                value1 = strcmp(st, temp99->usern);
               if(value1==0){
                break;
               }
                temp99  = temp99->link;

            } // printf("%d",valuep);
            if (value1==0){

                 printf(" Enter 1 to view profile \n");
                 printf(" Enter 2 to add hiim as friend \n");
                 int ch;
                 scanf("%d",&ch);
                 int v=0;
                 if(ch==1){
                     struct node *temp100 = temp9->next;
                     while(temp100!=NULL){
                        if (temp100->data==temp99->data)
                        {
                            printf("%s",temp99->usern);
                            v=1;
                            break;
                        }
                        temp100=temp100->next;
                     }if(v==0){
                        printf("U cant view the profile as u dont follow him");
                     }
                 }if (ch==2){
                    addNodeAtTail(temp9,temp99->data,0);
                     addNodeAtTail(temp99,temp9->data,1);
                 }

                }else{
                    printf("THIS USERNAME DOES NOT EXIST PLS ENTER A VALID NAME");
                     printf(" Enter 1 to retry or 0 to not");
                 
                 int ch;
                 scanf("%d",&ch);
                 if (ch==1){
                    goto sea;
                 }
                    
                }
            }}
            else
            {
                printf("******************Wrong password or user name pls try again****************\n");
                goto retry;
            }

            printf("Enter 1 to logout  or 0 to continue: ");
            int aa;
            scanf("%d", &aa);
            if (aa != 1)
            {
                goto back;
            }
            if (aa == 1)
            {   printf("************************************************************\n");
                int lenusrname = strlen(temp9->usern);
                int numstars = 62-9-lenusrname ;
                for(int i = 0;i<numstars;i++){printf("*");}
                printf("BYE BYE! %s",temp9->usern);
                for(int i = 0;i<numstars;i++){printf("*");}
                printf("************************************************************\n \n");

                goto end;
            }
        }

        while (c == 1)
        {
            ctrfirst = 1;
            printf("enter username  \n");
            ctrf++;
            
            char *str3 = malloc(sizeof(char) * MAX_LENGTH);
            sameusser:
            scanf("%s", str3);
             struct node* ptr_usse=main->link;
            int value;
            while(ptr_usse!=NULL){
                  value = strcmp(str3, ptr_usse->usern);
                if (value == 0)
                {
                    break;
                }
                ptr_usse = ptr_usse->link;
            }
              if(value==0){
                printf("USERNAME NOT AVALIBLE PLS TRY DIFFERENT USERNAME \n");
                goto sameusser;
              }
            printf("enter password  \n");
            char *str4 = malloc(sizeof(char) * MAX_LENGTH);
            scanf("%s", str4);
            int x;
            int w;
            int z;
            printf(" ENTER YOUR BASIC INFORMATION \n");
            printf(" ENTER 1 FOR YES AND 0 FOR NO \n");
            printf(" DO U LIVE IN PUNE \n");
            scanf("%d", &x);
            printf("ARE U IN COLLEGE  \n");
            scanf("%d", &w);
            printf("DO U LIKE TO PLAY SPORTS \n");

            scanf("%d", &z);
            int d = 10;
            k = ctri + ctrf;

            struct node *user = createList(k, x, w, z, str3, str4, d);
            addNodeAtTailmain(user, main);
            printf("Enter 1 to enter your friends now and 0 for later ");
            int dd;
            scanf("%d",&dd);
            if(dd==0){
                goto later;
            }

            printf("Enter  your friends \n");
            int s = 1;
            while (s == 1)
            {
                int f;
                scanf("%d", &f);

                addNodeAtTail(user, f, 0);
                printf(" press: 1 to continue or 0 to exit \n");
                scanf("%d", &s);
            }
            printf("THANKYOU FOR MAKING AN ACCOUNT \n");
            goto label;
            printf("enter 0 to continue in sys");
            scanf("%d", &sys);
            c = 3;
        }
    }
end:
    FILE *fp2 = fopen("friend.csv", "w");
    if (fp2 == NULL)
    {
        printf("Failed to open file.\n");
    }
    int ctrif = ctri + ctrf;
    int ctrif2 = ctrif;
    struct node *temp4 = main->link;

    while (ctrif > 0)
    {

        ctrif--;
        char str[16];
        char str1[16];

        struct node *temp3 = temp4->next;

        int num1;

        temp4 = temp4->link;

        while (temp3 != NULL)
        {
            int num = temp3->data;
            num1 = temp3->first;
            sprintf(str, "%d", num);

            sprintf(str1, "%d", num1);
            fprintf(fp2, "%s", str);
            fprintf(fp2, ",");
            fprintf(fp2, "%s", str1);
            if (temp3->next != NULL)
                fprintf(fp2, ",");
            temp3 = temp3->next;
        }

        fprintf(fp2, "\n");
    }
    fclose(fp2);
    FILE *fp3 = fopen("data.csv", "w");

    if (fp3 == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }
    struct node *temp5 = main->link;
    char str1[16];
    char str2[16];
    char str3[16];
    char str4[16];
    char str5[16];
    char *x1 = malloc(sizeof(char) * MAX_LENGTH);

    char *y1 = malloc(sizeof(char) * MAX_LENGTH);

    int count = 0;
    while (temp5 != NULL)
    {
        count++;

        int num = temp5->data;
        int num2 = temp5->arr[0];
        int num3 = temp5->arr[1];
        int num4 = temp5->arr[2];
        int num5 = temp5->first;
        x1 = temp5->usern;
        y1 = temp5->pass;
        sprintf(str5, "%d", num);
        sprintf(str1, "%d", num2);
        sprintf(str2, "%d", num3);
        sprintf(str3, "%d", num4);
        sprintf(str4, "%d", num5);

        fputs(str5, fp3);
        fputs(",", fp3);

        fputs(str1, fp3);
        fputs(",", fp3);

        fputs(str2, fp3);
        fputs(",", fp3);

        fputs(str3, fp3);
        fputs(",", fp3);

        fputs(x1, fp3);
        fputs(",", fp3);

        fputs(y1, fp3);
        fputs(",", fp3);

        fputs(str4, fp3);
        fputs("\n", fp3);

        temp5 = temp5->link;
    }
    fclose(fp3);
    return 0;
}