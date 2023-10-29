#include <strings.h>
#include "stdio.h"
#define N 20
//void print( Developer *candidates );

//the type of struct
typedef struct recommender {
    char name [N];
    char family [N];
    char email[N];
}Recommender;

typedef struct developer {
    char name [N];
    char family[N];
    char degree[N];
    struct recommender *rec1,*rec2;
    struct developer *dev1 ,*dev2;
}developer;
//if the customer enters the number 1 he will receive  Print candidates.
void print( developer * candidates[] ){
    int i = 0;
    while (candidates[i] != NULL) {
        //print the candidates
        printf("\n-------------\nname : %s \n", candidates[i]->name);
        printf("family : %s \n", candidates[i]->family);
        printf("degree : %s \n", candidates[i]->degree);
//print the recommender inside the company
        if (candidates[i]->dev1 != NULL) {
            printf("dev 1 name inside the company : %s \n", candidates[i]->dev1->name);

        }
        if (candidates[i]->dev2 != NULL) {
            printf("dev 2 name inside the company: %s \n", candidates[i]->dev2->name);

        }
//print the recommender outside  the company
        if (candidates[i]->rec1 != NULL) {
            printf("\nrec 1 name : %s \n", candidates[i]->rec1->name);
            printf("rec 1 family : %s \n", candidates[i]->rec1->family);
            printf("rec 1 email : %s \n", candidates[i]->rec1->email);

        }
        if (candidates[i]->rec2 != NULL) {
            printf("\nrec 2 name : %s \n ", candidates[i]->rec2->name);
            printf("rec 2 family : %s \n ", candidates[i]->rec2->family);
            printf("rec 2 email : %s \n ", candidates[i]->rec2->email);

        }

        printf("\n-------------\n");

        i++;


    }
}

//if the customer enters the number 2 he will receive Print workers.
void print_workers( developer * employees[] ){
    int i = 0;
    while (employees[i] != NULL) {
        //print the employees
        printf("\n-------------\nname : %s \n", employees[i]->name);
        printf("family : %s \n", employees[i]->family);


        printf("\n-------------\n");

        i++;


    }
}

//if the customer enters the number 3 he will receive. Insert new Candidate.
void insert_new_candidate( developer * candidates[] ,developer *employees[]){
   int a;
    char name[N], family[N], email[N];
    developer * new_candidate =  (developer *) malloc(sizeof(developer));//malloc
//insert the candidates
    printf("\nenter name : ");
    scanf("%s", new_candidate -> name);


    printf("\nenter family name: ");
    scanf("%s", new_candidate -> family);


    printf("\nenter degree: ");
    scanf("%s", new_candidate -> degree);

    int i = 0;

    while (candidates[i] != NULL){
        i++;
    }

    candidates[i] = new_candidate;


//insert the recommender outside  the company
    printf("does this candidate have recommenders from outside the company if yes press 1 if not press 2\n\n");
    scanf("%d", &a);

    if(a == 1){

    candidates[i]->rec1=(Recommender *) malloc(sizeof(Recommender));//malloc
    printf("\nenter name :");
    scanf("%s",name);
    printf("\nenter family name: ");
    scanf("%s",family);
        printf("\nenter email: ");
    scanf("%s",email);
    strcpy(candidates[i]->rec1->name,name);
    strcpy(candidates[i]->rec1->family,family);
    strcpy(candidates[i]->rec1->email,email);
        printf("does this candidate have another recommenders from outside the company if yes press 1 if not press 2\n\n");
        scanf("%d", &a);
        if (a == 1) {
            candidates[i]->rec2 = (Recommender *) malloc(sizeof(Recommender));
            printf("\nenter name :");
            scanf("%s", name);
            printf("\nenter family name: ");
            scanf("%s", family);
            printf("\nenter email: ");
            scanf("%s", email);
            strcpy(candidates[i]->rec2->name, name);
            strcpy(candidates[i]->rec2->family, family);
            strcpy(candidates[i]->rec2->email, email);
        }
   }



//print the recommender inside the company
    printf("Does this candidate have recommenders from inside the company if yes press 1 if not press 2\n\n");
    scanf("%d", &a);

    if(a == 1) {

        printf("\nenter name :");
        scanf("%s", name);
        printf("\nenter family name: ");
        scanf("%s", family);


        for (int i = 0; i < N; i++) {
            if (((strcmp(employees[i]->name, name) == 0) && (strcmp(employees[i]->family, family) == 0))) {
                candidates[i]->dev1 = employees[i];

                break;

            }
        }

        printf("Does this candidate have another recommenders from inside the company if yes press 1 If not press 2\n\n ");
        scanf("%d", &a);

        if(a == 1){

            printf("\nenter name :");
            scanf("%s",name);
            printf("\nenter family name: ");
            scanf("%s",family);

            for(int i=0;i<N;i++){
                if( ((strcmp( employees[i]->name,name)==0)&&(strcmp(employees[i]->family,family)==0))){
                    candidates[i]->dev2=employees[i];

                    break;

                }
            }}

    }


}
//if the customer enters the number 4 he will receive Hire candidate.
void hire_candidate(developer * candidates[], developer * employees[]){

    char name[N], family[N];


    printf("\nenter name : ");
    scanf("%s", name);

    printf("\nenter family name : ");
    scanf("%s", family);



    int i = 0;

    while (candidates[i] != NULL){

        if ( strcmp(candidates[i] -> name, name) == 0 && strcmp(candidates[i] -> family, family) == 0 ){

            int k = 0;
            while (employees[k] != NULL){
                k ++;
            }
            employees[k] = candidates[i];

            while (candidates[i] != NULL){//This while  used to delete the candidates
                candidates[i] = candidates[i+1];
            }

            printf("\nMoved candidate %s to employees\n", name);
            return;

        }

        i ++;
    }

    printf("\nCandidate %s was not found !\n", name);
}

int main() {

    developer* employees[N], *candidates[N];

    for (int i = 0; i < N ; ++i) {
        employees[i] = NULL;

    }
    for (int i = 0; i < N ; ++i) {
        candidates[i] = NULL;

    }

    while (1){

        printf("\n--------------\n\nWelcome, what do you want to do?\n1. "
               "Print candidates.\n2. Print workers.\n"
               "3. Insert new Candidate.\n4. Hire candidate.\n5. Exit.\n\nEnter command number :");

        int rand;
        scanf("%d", &rand);



        if (rand == 1) {
            print(candidates);
        }

        else if (rand == 2) {
            print_workers(employees);

        }

        else if (rand == 3) {
            insert_new_candidate(candidates,employees);

        }

        else if (rand == 4) {

            hire_candidate(candidates, employees);


        }

        else{
            break;
        }


    }
//use free
    int k = 0;
    while (employees[k] != NULL){
        free(employees[k]);
        k ++;
    }

    int i = 0;
    while (candidates[i] != NULL){
        free(candidates[i]);
        i ++;
    }



}

