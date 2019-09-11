#include <iostream>

using namespace std;

double eval(int* pj);

double eval(int* pj)
{
	static int solution[100];
	static int run_count = 0;
	int fitness = 0;

	int i;
	if( run_count == 0){
		for( i=0; i < 100; i++ ){
			solution[i] = 1;
		}
	}

	for( i=0; i < 100; i++ ){
		if( solution[i] == pj[i] ){
			fitness++;
		}
	}

	for( i=0; i < 100; i++ ){
		solution[i] = pj[i] ^ 1;
	}
	
	run_count++;

	return fitness;
}