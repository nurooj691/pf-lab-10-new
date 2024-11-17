#include<stdio.h>
#include<string.h>
struct books{
	char title[50];
	char author[50];
	int isbn;
	int pyear;
	int isavailable;
};
void addbooks(struct books b[], int *count){
	if(*count>=100){
		printf("space full\n");
		return;
	}
	struct books newbook;
	printf("Enter book title: \n");
    fgets(newbook.title, sizeof(newbook.title), stdin);
    newbook.title[strcspn(newbook.title, "\n")] = '\0'; 
    printf("Enter book author:\n ");
    fgets(newbook.author, sizeof(newbook.author), stdin);
    newbook.author[strcspn(newbook.author, "\n")] = '\0';
	printf("enter book isbn:\n");
	scanf("%d", &newbook.isbn);
	printf("enter book year:\n");
	scanf("%d", &newbook.pyear);
	newbook.isavailable = 1;
	b[*count] = newbook;
    (*count)++;
	
}
void searchbooks(struct books b[], int count){
	if(count==0){
		printf("no book available to search\n");
		return;
	}
	char search[50];
	printf("enter author or title to search for book:\n");
	fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = '\0';
	int found =0;
	for(int i=0; i<count; i++){
	if (strcmp(b[i].title, search) == 0 || strcmp(b[i].author, search) == 0) {
		printf("book is available:\n");
		printf("book title: %s\n", b[i].title);
		printf("book author: %s\n", b[i].author);
		printf("book isbn: %d\n", b[i].isbn);
		printf("book publicataion year: %d\n", b[i].pyear);
		printf("Status: %s\n", b[i].isavailable ? "Available" : "Checked out");
		found=1;
	}	}
	if (!found) {
        printf("No books found matching.\n ");
    }
}
void update(struct books b[], int count) {
    int isbn, found = 0;
    printf("Enter book ISBN to return or checkout:\n");
    scanf("%d", &isbn);

    for (int i = 0; i < count; i++) {
        if (b[i].isbn == isbn) {
            found = 1;
            if (b[i].isavailable) {
                
                printf("Book is available. Checking out the book...\n");
                b[i].isavailable = 0;  
            } else {
                
                printf("Book is currently checked out. Returning the book...\n");
                b[i].isavailable = 1;
            }
            break;  
        }
    }

    if (!found) {
        printf("No book found with ISBN %d.\n", isbn);
    }
}

int main(){
	struct books b[100];
	int count =0;
	int choice;
	do{
		printf("Library management system:\n");
		 printf("1. Add a book\n");
        printf("2. Search for a book\n");
        printf("3. Update book availability\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                addbooks(b, &count);
                break;
            case 2:
                searchbooks(b, count);
                break;
            case 3:
                update(b, count);
                break;
            case 4:
                printf("Exiting the system.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                
    }
		
	}while(choice !=4);

}