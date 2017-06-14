#include <stdio.h>
#include "sort.h"

int main(int argc, char *argv[]){
	if(argc < 5 || argc > 5){
		printf("%s\n", "Quantidade de argumentos invalido" );
		return 0;
	}

	//FILE *fp;
	//fp = fopen("log.txt","a+");
	
	clock_t initialTime, endTime;
	double totalTime;
	time_t t;
	double times[3];
	double avg;
	srand((unsigned) time(&t));
	int i;
	int K = strtol(argv[1],NULL,10);
	
	int tamanho = pow(2,K);
	int vetor[tamanho];
	int aux[tamanho];
	
	//printf("%s\n", "--------------------VETOR ORIGINAL------------------- " );
	
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

	
	//showVector(vetor,tamanho);
	
	//printf("%s\n", "--------------------VETOR ORDENADO------------------- " );

	if(strtol(argv[4],NULL,10) == 1){
		for(i=0; i<3; i++){
			copyVector(vetor, aux, tamanho);
			initialTime = clock();
			insertionSort(aux,tamanho);
			endTime = clock();
   			totalTime = (endTime-initialTime)*1000000/CLOCKS_PER_SEC;
   			times[i] = totalTime;
   			
		}
		
		avg = average(times);
   		printf("MEDIAAAAAA = %lf\n", avg);
	}
	else if(strtol(argv[4],NULL,10) == 2){
		for(i=0; i<3; i++){
			copyVector(vetor, aux, tamanho);
			initialTime = clock();
			mergeSort(aux,0,tamanho-1);
			endTime = clock();
	   		totalTime = (endTime-initialTime)*1000000/CLOCKS_PER_SEC;
	   		times[i] = totalTime;
		}
		avg = average(times);
   		printf("MEDIAAAAAA = %lf\n", avg);
	}
	else if(strtol(argv[4],NULL,10) == 3){
		for(i=0; i<3; i++){
			copyVector(vetor, aux, tamanho);
			initialTime = clock();
			heapSort(aux,tamanho);
			endTime = clock();
	   		totalTime = (endTime-initialTime)*1000000/CLOCKS_PER_SEC;
			times[i] = totalTime;
		}
		avg = average(times);
   		printf("MEDIAAAAAA = %lf\n", avg);
	}
	else if(strtol(argv[4],NULL,10) == 4){
		for(i=0; i<3; i++){
			copyVector(vetor, aux, tamanho);	
			initialTime = clock();
			quickSort(aux,0,tamanho-1);
			endTime = clock();
	   		totalTime = (endTime-initialTime)*1000000/CLOCKS_PER_SEC;
			times[i] = totalTime;
		}
		avg = average(times);
   		printf("MEDIAAAAAA = %lf\n", avg);
	}
	else if(strtol(argv[4],NULL,10) == 5){
		for(i=0; i<3; i++){
			copyVector(vetor, aux, tamanho);
			initialTime = clock();
			radixSort(aux,tamanho);
			endTime = clock();
	   		totalTime = (endTime-initialTime)*1000000/CLOCKS_PER_SEC;
			times[i] = totalTime;
		}
		avg = average(times);
   		printf("MEDIAAAAAA = %lf\n", avg);
	}
	else if(strtol(argv[4],NULL,10) == 6){
		for(i=0; i<3; i++){
			copyVector(vetor, aux, tamanho);
			initialTime = clock();
			countingSort(aux,tamanho);
			endTime = clock();
	   		totalTime = (endTime-initialTime)*1000000/CLOCKS_PER_SEC;
			times[i] = totalTime;
		}
		avg = average(times);
   		printf("MEDIAAAAAA = %lf\n", avg);
	}
	else if(strtol(argv[4],NULL,10) == 7){
		for(i=0; i<3; i++){
			copyVector(vetor, aux, tamanho);
			initialTime = clock();
			bucketSort(aux,tamanho);
			endTime = clock();
	   		totalTime = (endTime-initialTime)*1000000/CLOCKS_PER_SEC;
			times[i] = totalTime;
		}
		avg = average(times);
   		printf("MEDIAAAAAA = %lf\n", avg);
	}
	else{
		printf("%s\n", "Parametro invalido" );
		return 0;
	}
	//showVector(aux,tamanho);
	//fprintf(fp,"%s","teste\n");
	
}