/*
 ============================================================================
 Name        : terzo.c
 Author      : piersilvio
 Version     :
 Copyright   : 
 Description : prova aereoporto
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define max_fly 100


//struct declaration
typedef struct{

	char cod_volo[10];
	char citta_partenza[10];
	char citta_arrivo[10];
	int tot_posti;
	int posti_occup;

}volo;

int n_voli = 0; //>0

//struct definition
volo vol[max_fly];

//inputs
int scelta;
int num_posti;

//working variables
int i = 0;

void prenotazione();
void inserimento();

int main(){


	do{
		printf(":: Insert the number of flys: \n");
		fflush(stdout);
		scanf("%d", &n_voli);

	}while(n_voli == 0);

    inserimento();

    for(i = 0; i < n_voli; i++){
    	printf(":: code of vole: %s\n", vol[i].cod_volo);
    	printf(":: city of the departure: %s\n", vol[i].citta_partenza);
    	printf(":: city of the arrival: %s\n", vol[i].citta_arrivo);
    	printf(":: total of seats: %d\n", vol[i].tot_posti);
    	printf(":: the number of occuped seats: %d\n", vol[i].posti_occup);
    	printf("\n");
    }

    do{

        prenotazione();
        printf(":: do you want to perform another operation? (1.yes) (2.no) \n");
        fflush(stdout);
        scanf("%d", &scelta);

    }while(scelta == 1);

    return 0;
}

void prenotazione(){

    int position = 0;
	char cod_volo = ' ';
	int tmp = 0;

	i = 0;

    printf(":: insert the code of fly: \n");
    fflush(stdout);
    scanf("%s", &cod_volo);

    do{
    	_Bool flag = 0;

        if(strcmp(&cod_volo, vol[i].cod_volo) == 0){

            printf(":: insert the number of seat to prenotate: \n");
            fflush(stdout);
            scanf("%d", &num_posti);

            position = i;

            tmp = num_posti + vol[position].posti_occup; //tiene conto del contatore all'interno del ciclo

            if(tmp <= vol[position].tot_posti){
                flag = 1;
                vol[position].posti_occup = vol[position].posti_occup + num_posti;
            }



            if(flag == 1){
            	//printf("%d", flag); debug
            	printf(":: fly rented with succesfuly! \n");
            }else{
                printf(":: Could not rent the fly! \n");
            }

            printf("\n");

            printf(":: code of vole: %s\n", vol[i].cod_volo);
            printf(":: city of the departure: %s\n", vol[i].citta_partenza);
            printf(":: city of the arrival: %s\n", vol[i].citta_arrivo);
            printf(":: total of seats: %d\n", vol[i].tot_posti);
            printf(":: the number of occuped seats: %d\n", vol[i].posti_occup);

        }


        i = i + 1;

    }while(i <= n_voli);


}

void inserimento(){

    for(i = 0; i < n_voli; i++){ //utilizzo il for per dbugguare

        printf(":: Insert code of vole: \n");
        fflush(stdout);
		scanf("%s", vol[i].cod_volo);
		printf(":: insert city of the departure: \n");
		fflush(stdout);
		scanf("%s", vol[i].citta_partenza);
		printf(":: insert city of the arrival: \n");
		fflush(stdout);
		scanf("%s", vol[i].citta_arrivo);
		printf(":: insert total of seats: \n");
		fflush(stdout);
		scanf("%d", &vol[i].tot_posti);
		printf("\n");

		vol[i].posti_occup = 0; //inizializza

    }
}

