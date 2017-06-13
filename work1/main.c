#include <stdio.h>
#include "sort.h"

int main(int argc, char *argv[]){
	if(argc < 5 || argc > 5){
		printf("%s\n", "Quantidade de argumentos invalido" );
		return 0;
	}

	//FILE *fp;
	//fp = fopen("log.txt","a+");
	
	time_t t;
	srand((unsigned) time(&t));
	
	int K = strtol(argv[1],NULL,10);
	
	int tamanho = pow(2,K);
	int vetor[tamanho];
	
	printf("%s\n", "--------------------VETOR ORIGINAL------------------- " );
	
	if(strtol(argv[2],NULL,10) == 1){
		generateRandomCRS(tamanho,strtol(argv[3],NULL,10),vetor);
	}
	else if(strtol(argv[2],NULL,10) == 2){
		generateRandomDCR(tamanho,strtol(argv[3],NULL,10),vetor);
	}
	else{
		printf("%s\n", "Parametro invalido");
		return 0;
	}

	
	showVector(vetor,tamanho);
	
	printf("%s\n", "--------------------VETOR ORDENADO------------------- " );

	if(strtol(argv[4],NULL,10) == 1){
		insertionSort(vetor,tamanho);
	}
	else if(strtol(argv[4],NULL,10) == 2){
		mergeSort(vetor,0,tamanho-1);
	}
	else if(strtol(argv[4],NULL,10) == 3){
		heapSort(vetor,tamanho);
	}
	else if(strtol(argv[4],NULL,10) == 4){
		quickSort(vetor,0,tamanho-1);
	}
	else if(strtol(argv[4],NULL,10) == 5){
		radixSort(vetor,tamanho);
	}
	else if(strtol(argv[4],NULL,10) == 6){
		printf("%s\n","IMPLEMENTAR COUNTING SORT" );
	}
	else if(strtol(argv[4],NULL,10) == 7){
		printf("%s\n","IMPLEMENTAR BUCKET SORT" );
	}
	else{
		printf("%s\n", "Parametro invalido" );
		return 0;
	}
	showVector(vetor,tamanho);
	//fprintf(fp,"%s","teste\n");
	
}