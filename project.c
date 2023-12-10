#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define prs printf("press any key to continue...\n")
#define clr system("cls")
char pwd[]="admin";
char pswd[20];
int book=0;
int mmb=0;
void heading();
void login();
void home();
void add();
void see();
void memb();
void admmb();
void search();
void edit();
void delet();
void help();
void deldat();
void spc(int a);
int rt=0;
struct book_info{
 int id;
 char name[15];
 char author[15];
 int quantity;
 int rack;

};
struct book_info a;
FILE *file, *file2;


int main(){
//  printf("Library Management Project\n\n");

   login();


}

home(){
    clr;
    printf("\n\t\t\t\t************Main Menu************\n\n\n");
    printf("1. Add Book(s)\n2. View Books\n3. Search Book\n");
    printf("4. Edit Book\n5. Delete Book\n6. Exit\n7. Help\n8. Delete all data\n");
    int hin;
    fflush(stdin);
    scanf("%d", &hin);
    clr;
    switch(hin){
    case 1:
        add();
        break;
    case 2:
        see();
        break;
    case 3:
        search();
        break;
    case 4:
        edit();
        break;
    case 5:
        delet();
        break;
    case 6:
        exit(0);
        break;
    case 7:
        help();
        break;
    case 8:
        deldat();
        break;
    default:
        home();
}

}


heading(){
printf("\n\t\t\t\t\t\tLibrary Management System\n\n");
}

login(){
    heading();

 printf("Enter password:\n\n");

scanf("%s", pswd);

if(strcmp(pwd,pswd)==0){
    system("cls");
    printf("Password Matched!\n\n");
    printf("press any key...\n");
    getch();
    home();
}else{
    printf("Wrong password, Try again...\n\n");
    system("cls");
    login();
}

}
add(){
    clr;

  printf("\n\t\t************Add Book************\n\n\n");
  file= fopen("book.txt", "ab+");
  int d;
  printf("Enter ID:\n");
  scanf("%d", &d);

  while(fread(&a, sizeof(a), 1, file)==1){
    if(d==a.id){
        printf("\n\nThe book is already in the list\n");
        printf("\nPress any key to continue...\n");
        fclose(file);
        fflush(stdin);
        getchar();

        home();
    }

  }
    a.id=d;

    printf("Enter Name:\n");
    fflush(stdin);
    scanf("%s", a.name);

    printf("Enter Author:\n");
    fflush(stdin);
    scanf("%s", a.author);

    printf("Enter Quantity:\n");
    fflush(stdin);
    scanf("%d", &a.quantity);

    printf("Enter Rack:\n");
    fflush(stdin);
    scanf("%d", &a.rack);
    fseek(file, 0, SEEK_END);
    fwrite(&a, sizeof(a), 1, file);

    fclose(file);

    printf("Book added succesfully!\n");
    printf("\nPress any key to continue...\n");
        fflush(stdin);
        getchar();
        home();

}
see(){
  clr;
printf("\n\t\t*************Book list:*************\n\n\n");
printf("\tID\t\tName\t\t\tAuthor\t\tQuantity\tRack\n\n");
int count=0;
file= fopen("book.txt", "r");

while(fread(&a, sizeof(a), 1,file)==1){
        spc(8);
    printf("%d", a.id);
    char sid[15];
    sprintf(sid, "%d", a.id);
    int ld=strlen(sid);
        spc(16-ld);
    printf("%s", a.name);
    int tb=strlen(a.name);
    spc(24-tb);
    printf("%s", a.author);
    int la=strlen(a.author);
    spc(16-la);
    printf("%d", a.quantity);
    char sq[15];
    sprintf(sq, "%d", a.quantity);
    int lq=strlen(sq);
    spc(8-lq);
    printf("%d\n", a.rack);

    count=count+a.quantity;
}
fclose(file);

printf("\nTotal Books: %d\n", count);
//printf("press any key...\n");
getch();
 home();

}
search(){
clr;
int d;
int count=0;
printf("\n\t\t************Search book************\n\n\n");

file= fopen("book.txt", "rb+");



printf("Enter ID:\n");
scanf("%d", &d);

while(fread(&a, sizeof(a), 1, file)==1){
    if(d==a.id){
        printf("\nBook is found\n");
        printf("ID:\t\t%d\n", a.id);
        printf("Name:\t\t%s\n", a.name);
        printf("Author:\t\t%s\n", a.author);
        printf("Quantity:\t%d\n", a.quantity);
        printf("Rack:\t\t%d\n", a.rack);
        count++;
    }
}
fclose(file);
if(count==0){
     printf("\nBook is not found\n");
}
//printf("press any key...\n");
getch();
 home();

}

edit(){
clr;
int d,count=0;
printf("\n\t\t************Edit book************\n");
file= fopen("book.txt", "rb+");

printf("Enter ID:\n");
scanf("%d", &d);

while(fread(&a, sizeof(a), 1, file)==1){
    if(d==a.id){
        printf("\nBook is avaiable\n");
        printf("ID: %d\n", a.id);
        printf("Enter new Name:\n");
        scanf("%s", a.name);
        printf("Enter new Author:\n");
        scanf("%s", a.author);
        printf("Enter new Quantity:\n");
        scanf("%d", &a.quantity);
        printf("Enter new Rack:\n");
        scanf("%d", &a.rack);

        fseek(file, ftell(file)-sizeof(a), 0);
        fwrite(&a, sizeof(a), 1, file);
        fclose(file);
        count=1;
    }
}
if(count==0){
    printf("\nBook is not found\n\n");
}
    printf("\n\n\nPress any key...\n");
    getch();
    home();

}

delet(){
clr;
int d,count=0;
printf("\n\t\t************Delete book************\n\n\n");
printf("Enter ID:\n");
scanf("%d", &d);

file= fopen("book.txt", "rb+");
rewind(file);
while(fread(&a, sizeof(a), 1, file)==1){
    if(d==a.id){
        printf("\nBook is avaiable\n");
        printf("\nBook name is: %s", a.name);
        count=1;
    }
}
    if(count==0){
    printf("\nBook is not found\n\n");
}else{
    file2= fopen("bk2.txt", "wb+");
    rewind(file);

    while(fread(&a, sizeof(a), 1, file)==1){
        if(d!=a.id){
            fseek(file2, ftell(file2)-sizeof(a), 0);
            fwrite(&a, sizeof(a), 1, file2);
        }

    }
    fclose(file);
    fclose(file2);

    remove("book.txt");
    rename("bk2.txt", "book.txt");

    file= fopen("book.txt", "rb");
    fclose(file);
}
    printf("\nBook deleted succesfully\n");
    printf("\n\n\nPress any key...\n");
    getch();
    home();

}

help(){
clr;
printf("\n\t\t************Help************\n\n\n");

printf("\n\t\t\t\tThis is simple library project\n\n");

printf("Password is: admin\n\n");
printf("All features are in the main menu\n\n\n");
printf("Press any key... to back to main menu\n\n\n");


getch();
home();
}

deldat(){
remove("book.txt");

printf("\nData cleared succesfully\n\n");

getch();
home();


};


memb(){
 printf("\nNumber of Memebers:\n%d", mmb);
 printf("\nPress any key to continue...\n");
 getch();
 home();

}
admmb(){
printf("Number of members to be added:\n ");
int m;
scanf("%d", &m);
mmb+=m;
clr;
printf("\nPress any key to continue...\n");
getch();
home();

}
void spc(int a){
    for(int i=0;i<a;i++)
  printf(" ");
}
