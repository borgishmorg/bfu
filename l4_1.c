#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MASS_SIZE 75
#define MIN_VALUE 1
#define MAX_VALUE 10
#define PROBABILITY 50


int* random_mass(){
	int* res = (int*)malloc(sizeof(int)*MASS_SIZE);
	for(int i = 0; i < MASS_SIZE; i++) res[i] = rand()%(MAX_VALUE-MIN_VALUE+1) + MIN_VALUE;
	return res;
}

int aunt(){
	return rand()%100 + 1 >= PROBABILITY;
}

int main(){
	srand(clock()+time(NULL));
	
	int carloson = 60;
	int l_food, l_sport;
	int* food = random_mass();
	int* sport = random_mass();
	
	for(;;){
		if(aunt()){
			carloson -= sport[l_sport];
			printf("Time to sport: -%d\n", sport[l_sport++]);
		}else{
			carloson += food[l_food++];
			printf("Time to eat: %d\n", food[l_food++]);
		}
			
			
		if(carloson > 100 || carloson < 20) {
			printf("\nCarloson died");
			break;
		}
		if(l_sport == MASS_SIZE || l_food == MASS_SIZE){
			printf("\nLife is good");
			break;
		}
	}
	printf("\n\ncarloson = %d\nl_food = %d\nl_sport = %d", carloson, l_food, l_sport);
	free(food);
	free(sport);
	return 0;
}
