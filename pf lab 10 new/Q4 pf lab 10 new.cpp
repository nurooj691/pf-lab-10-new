#include<stdio.h>
#include<string.h>
struct flight{
	int flightnumber;
	char departurecity[50];
	char arrivalcity[50];
	int departuretime;
	int arrivaltime;
	int seats;
	
};
void bookseat(struct flight f[]){
	int n, found=0;
	printf("enter the flight number to book the seat for that flight:\n");
	scanf("%d", &n);
	getchar();
	for(int i=0; i<3; i++){
		if(f[i].flightnumber==n){
			if(f[i].seats>0){
				printf("flight booked successfully!\n");
				f[i].seats--;
			}
			else {
                printf("Sorry, no seats available.\n");
            }
			found =1;
				break;
	}
	}
	if(!found){
		printf("there is no flight with flight number: %d\n", n);
	}	
}
void displayflight(struct flight f[]){
	char departurecity[50], arrivalcity[50];
	printf("enter departure city:\n");
	fgets(departurecity, 50, stdin);
	departurecity[strcspn(departurecity, "\n")]= '\0';
	printf("enter arrival city:\n");
	fgets(arrivalcity, 50, stdin);
		arrivalcity[strcspn(arrivalcity, "\n")]='\0';
		int found = 0;
		for(int i=0; i<3; i++){
			if(strcmp(f[i].departurecity,departurecity)==0){
				if(strcmp(f[i].arrivalcity,arrivalcity)==0){
					if(f[i].seats>0){
						printf("flight found between %s and %s\n", departurecity, arrivalcity);
						printf("%d, %s, %s, %d, %d\n", f[i].flightnumber, f[i].departurecity, f[i].arrivalcity, 
						f[i].departuretime);
						found =1;
					}
				}
			}
		}
		if(!found){
			printf("no flight found between %s and %s\n", departurecity, arrivalcity);
		}
}
void update(struct flight f[]){
	int departuretime, arrivaltime, n, found =0;
	printf("enter the flight number to change the schedule:\n");
	scanf("%d", &n);
	getchar();
	printf("enter the new departure time:\n");
	scanf("%d", &departuretime);
	printf("enter the new arrival time:\n");
	scanf("%d", &arrivaltime);
	getchar();
	for(int i=0; i<3; i++){
		if(f[i].flightnumber==n){
			f[i].departuretime=departuretime;
				f[i].arrivaltime=arrivaltime;
				found =1;
				printf("time updated successfully!\n");
				break;
		}
	}
	if(!found){
		printf("there is no flight with flight number: %d\n", n);
	}	
}
int main(){
	 struct flight f[3]= {
         {123, "New York", "Los Angeles", 830, 1145, 100},
        {456, "New York", "Chicago", 915, 1250, 50},
        {789, "Los Angeles", "New York", 700, 1530, 200}
    };
    int choice;
    do{
    	printf("flight booking system:\n");
    	printf("1. Book a seat:\n");
    	printf("2. display available fligts between 2 cities:\n");
    	printf("3. update flight details:\n");
    	printf("4. exit\n");
    	printf("enter a choice:\n");
    	scanf("%d", &choice);
    	getchar();
    	switch(choice){
    		case 1:
    			bookseat(f);
    			break;
    			case 2:
    				displayflight(f);
    				break;
    				case 3:
    					update(f);
    					break;
    					case 4:
    						printf("exiting the program....\n");
    						break;
    						default:
    							printf("invalid choice! try again.\n");	
		}	
	}while(choice!=4);
    	
}