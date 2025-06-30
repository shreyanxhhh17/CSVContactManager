#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_CONTACTS 100

// Structure to contact
struct Contact{
  char name[50];
  char phone[15];
  char email[50];
};

// Function declaration
void addToContact(struct Contact contact[], int *count);
void viewContact(struct Contact contact[],int count);
void intializeCSV();

int main(){
  struct Contact contact[MAX_CONTACTS];
  int count = 0;
  int choice;

  // Initialize CSV with header
  intializeCSV();

  do{
    printf("\n------Contact Log Menu--------\n");
    printf("1.Add to Contact\n");
    printf("2.View Contact\n");
    printf("3.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    getchar();      //Consume the newline after scanf

    switch(choice){
      case 1:
      if(count<MAX_CONTACTS){
        addToContact(contact,&count);
      }else{
        printf("Address book is full\n");
    }
    break;

    case 2:
    viewContact(contact,count);
    break;

    case 3:
    printf("Exiting Address\n");
    break;

    default:
    printf("Invalid choice.Please try again");
  }
  }while(choice!=3);
  return 0;
}


// FUnction Defination

void intializeCSV(){
  FILE *fp = fopen("contact.csv" ,"r");
  if(fp == NULL){
    fp = fopen("contact.csv","w");
    if(fp!=NULL){
      fprintf(fp,"Name,Phone,Email\n");
      fclose(fp);
    }else{
      printf("Error creating file");
    }
  }
  else{
    fclose(fp);
  }
}

void addToContact(struct Contact contact[], int *count){
  printf("Enter Name:");
  fgets(contact[*count].name,50,stdin);
  contact[*count].name[strcspn(contact[*count].name,"\n")] = '\0';

  printf("Enter Phone:");
  fgets(contact[*count].phone,15,stdin);
  contact[*count].phone[strcspn(contact[*count].phone,"\n")] = '\0';

  printf("Enter Email:");
  fgets(contact[*count].email,15,stdin);
  contact[*count].email[strcspn(contact[*count].email,"\n")] = '\0';

  // Save to File CSV
  FILE *file = fopen("contact.csv","a");
  if(file!=NULL){
    fprintf(file, "%s,%s,%s\n",contact[*count].name,contact[*count].phone,contact[*count].email);
    fclose(file);
    printf("Contact saved Successfully\n");
  }else{
    printf("Failed to save the contact to the file\n");
  }
  (*count)++;
}

void viewContact(struct Contact contact[],int count){
  if(count == 0){
    printf("NO Contact added,\n");
    return;
  }
  printf("\n--------Contact List---------\n");
  for(int i=0; i<count; i++){
    printf("Contact %d:\n",i+1);
    printf("Name:%s\n",contact[i].name);
    printf("Phone:%s\n",contact[i].phone);
    printf("Email:%s\n",contact[i].email);
    printf("------------------\n");
  }
}