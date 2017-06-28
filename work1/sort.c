#include "sort.h"

void showVector(int * vector, int size){
	printf("( %d",vector[0]);
	int count = 1;
	while(count < size){
		printf(", %d ",vector[count]);
		count = count + 1;
	}
	printf(")\n");
}

double average(double * vector){
	int i;
	double total;

	total = 0;
	
	for(i=0;i<3;i++){
		total = total + vector[i];
	}

	return (total/3);
}

void copyVector(int * vector, int * newVector, int size){
	int i;

	for(i=0;i<size;i++){
		newVector[i] = vector[i];
	}
}

int belong(int * vector, int size, int element){ 
	int count = 0;
	while(count < size){
		if(vector[count]==element){
			return 1;
		}
		count = count + 1;
	}
	return 0;
}


void generateRandomDCR(int size, int percentage, int * vector){ 
	int i;
	int j;
	int randomized_size;
	if(percentage < 0){
		printf("ERRO [gerar_vetor_randomico_DECR]: Porcentagem_randomizacao invalido!\n");
		return;
	}
	if(percentage == 100){
		for(i=0;i<size;i++){
			vector[i] = rand()%size;
		}
		return;
	}
	else{
		randomized_size = (int)((double)(size)*((double)(percentage)/(double)(100))) ;
		int last_inserted = size;
		for(i=0;i<size;i++){
			if(i < randomized_size){
				vector[i] = rand()%size;
			}
			else{
				for(j=last_inserted;j>0;j--){
					
					if((belong(vector,randomized_size,j) == 0) && (last_inserted >= j)){
						vector[i] = j;
						last_inserted = j-1;
						break;
					}
				}
			}
		}
		
	}
}

void generateRandomCRS(int size, int percentage, int * vector) {
	int i;
	int j;
	int randomized_size;
	if(percentage < 0){
		printf("ERRO [gerar_vetor_randomico_CRES]: Porcentagem_randomizacao invalido!\n");
		return;
	}
	if(percentage == 100){
		for(i=0;i<size;i++){
			vector[i] = rand()%size;
		}
		return;
	}
	else{
		randomized_size = (int)((double)(size)*((double)(percentage)/(double)(100))) ;
		int last_inserted = 0;
		for(i=0;i<size;i++){
			if(i< randomized_size){
				vector[i] = rand()%size;
			}
			else{
				for(j=last_inserted;j<size;j++){
					if((belong(vector,randomized_size,j) == 0) && (last_inserted <= j)){
						vector[i] = j;
						last_inserted = j+1;
						break;
					}
				}
			}
		}
		
	}
}

void insertionSort(int * original, int size) {
	int i, j, current;

	for (i = 1; i < size; i++) {
		current = original[i];
		j = i - 1;

		while ((j >= 0) && (current < original[j])) {
			original[j + 1] = original[j];
			j = j - 1;
		}

		original[j + 1] = current;
	}

	return ;
}

void merge(int * vector, int start, int mid, int end) {
     int com1 = start, com2 = mid+1, comAux = 0;
     int vetAux[end-start+1];
 
     while(com1<=mid && com2<=end){
         if(vector[com1] <= vector[com2]){
             vetAux[comAux] = vector[com1];
             com1++;
         }else{
             vetAux[comAux] = vector[com2];
             com2++;
         }
         comAux++;
     }
     while(com1<=mid){ 
         vetAux[comAux] = vector[com1];
         comAux++;com1++;
     }
 
     while(com2<=end){   
         vetAux[comAux] = vector[com2];
         comAux++;com2++;
     }
 
     for(comAux=start;comAux<=end;comAux++){    
         vector[comAux] = vetAux[comAux-start];
     }
 }
 
 void mergeSort(int * vector, int start, int end){
     if (start < end) {
         int mid = (start+end)/2;
         mergeSort(vector, start, mid);
         mergeSort(vector, mid+1, end);
         merge(vector, start, mid, end);
     }
 }


void rebuildHeap(int * vector, int limit, int pos)
{		
	int c1, c2;
	
	c1 = 2 * pos;
	c2 = c1 + 1;
	
	if(c1 > limit || (vector[pos - 1] >= vector[c1 - 1] && vector[pos - 1] >= vector[c2 - 1]))
		return;
	
	int greater_index = -1;
	
	if(c2 > limit)
		greater_index = c1;
	else
	{		
		if(vector[c1 - 1] > vector[c2 - 1])
			greater_index = c1;
		else
			greater_index = c2;
	}
	
	if(greater_index != -1)
	{
		int aux = vector[greater_index - 1];
		vector[greater_index - 1] = vector[pos - 1];
		vector[pos - 1] = aux;
		rebuildHeap(vector, limit, greater_index);
	}
}


void buildHeap(int * vector, int size)
{
	int left;
	
	if(size % 2 == 0)
		left = size / 2 + 1;
	else
		left = (size - 1) / 2 + 1;
	
	while(left > 1)
	{
		left--;
		rebuildHeap(vector, size, left);
	}
}

void heapSort(int * vector, int size)
{
	buildHeap(vector, size);

	int limit = size;
	
	while(1)
	{		
		int aux = vector[0];
		vector[0] = vector[limit - 1];
		vector[limit - 1] = aux;
		
		rebuildHeap(vector, limit - 1, 1);
			
		limit--;
		
		if(limit <= 2 && vector[0] <= vector[1])
			break;
	}
}

void quickSort(int * vector, int start, int end){
   
   int pivo, aux, i, j, mid;
   
   i = start;
   j = end;
   
   mid = (int) ((i + j) / 2);
   pivo = vector[mid];
   
   do{
      while (vector[i] < pivo) i = i + 1;
      while (vector[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vector[i];
         vector[i] = vector[j];
         vector[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(start < j) quickSort(vector, start, j);
   if(i < end) quickSort(vector, i, end);   

}

void radixSort(int * vector, int size) {
    int i;
    int *b;
    int maior = vector[0];
    int exp = 1;

    b = (int *)calloc(size, sizeof(int));

    for (i = 0; i < size; i++) {
        if (vector[i] > maior)
    	    maior = vector[i];
    }
 
    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < size; i++)
    	    bucket[(vector[i] / exp) % 10]++; 
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = size - 1; i >= 0; i--)
    	    b[--bucket[(vector[i] / exp) % 10]] = vector[i];
    	for (i = 0; i < size; i++)
    	    vector[i] = b[i];
    	exp *= 10;
    }

    free(b);
}

void bubbleSort(int * vector, int size){
         int i,j,temp,flag;
         if(size)
                 for(j=0;j<size-1;j++){
                         flag=0;
                         for(i=0;i<size-1;i++){
                                 if(vector[i+1]<vector[i]){
                                         temp=vector[i];
                                         vector[i]=vector[i+1];
                                         vector[i+1]=temp;
                                         flag=1;
                                 }
                         }
                         if(!flag)
                                 break;
                 }
 }

 void bucketSort(int * vector, int size){
    balde b[num_balde];
    int i,j,k;
    for(i=0;i<num_balde;i++)
        b[i].topo=0;

    for(i=0;i<size;i++){
        j=(num_balde)-1;
        while(1){
            if(j<0)
                break;
            if(vector[i]>=j*10){
                b[j].balde[b[j].topo]=vector[i];
                (b[j].topo)++;
                break;
            }
            j--;
        }
    }

    for(i=0;i<num_balde;i++)
        if(b[i].topo)
            insertionSort(b[i].balde,b[i].topo);

    i=0;
    for(j=0;j<num_balde;j++){
        for(k=0;k<b[j].topo;k++){
            vector[i]=b[j].balde[k];
            i++;
        }
    }
}

void countingSort(int * vector, int size){
	int i,maior = 0;
	int B[size];

	for(i=0; i<size; i++) {
		B[i] = 0;

	}

	for(i=0; i<size; i++){
		if(vector[i] > maior){

			maior = vector[i];
		}
	}

	int k = maior + 1;
	int C[k];
	
	for (i=0;i<maior+1; i++){
		C[i]=0;
	}
	
	for(i=0;i<size;i++){
		C[vector[i]]++;
	}

	for(i=1;i<k;i++){
		C[i] += C[i-1];
	}

	for(i=size-1;i>=0;i--){
		B[C[vector[i]]] = vector[i];
		C[vector[i]]--;
	}

	for(i=1;i<size+1;i++){
		vector[i-1]=B[i];
	}

}
