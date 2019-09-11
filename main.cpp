#include <iostream>

using namespace std;

double eval(int* pj);

void print_number(int* pj);

void flip_rand_n(int* new_string, int* old_string, int n_bits, int search_space);

void mountain_climber();

int main()
{
	srand(time(NULL));

	mountain_climber();
}

void mountain_climber()
{
	// initialize bit string
	int best_string[100];
	int new_string[100];
	int max_fit = -1;
	int new_fit = -1;
	int max_iterations = 1000;
	uint max_iterations2 = 3000000000;

	int i;
	for(i = 0; i < 100; i++){
		best_string[i] = 0;
  	}

  	// evaluate inital string
  	max_fit = eval(best_string);
  	
  	uint iteration = 0;
  	while(iteration < max_iterations && max_fit < 100){
  		// alter the best string and evaluate it
  		flip_rand_n(new_string, best_string, 1, 100);
  		new_fit = eval(new_string);
  		if( new_fit > max_fit ){
  			max_fit = new_fit;
  			for( i=0; i < 100; i++){
  				best_string[i] = new_string[i];
  			}
  		}
  		iteration++;
  	}

  	// Heuristic for solving eval1
  	if( max_fit < 100 && max_fit > 5){
  		cout << "Now entering think hard mode. Please hold." << endl;
	  	while(iteration < max_iterations2 && max_fit < 100){
	  		// alter the best string and evaluate it
	  		flip_rand_n(new_string, best_string, 1, 30);
	  		new_fit = eval(new_string);
	  		if( new_fit >= max_fit ){
	  			max_fit = new_fit;
	  			for( i=0; i < 30; i++){
	  				best_string[i] = new_string[i];
	  			}
	  		}
	  		iteration++;
	  		if(iteration % 5000000 == 0){
	  			cout << '.' << flush;
	  		}
	  	}
	  	cout << endl;
  	}
  	print_number(best_string);
  	cout << "maximum fitness: " << max_fit << endl;
  	cout << "iterations: " << iteration << endl;
}

void print_number(int* pj)
{
	int i;
	for(i=0; i < 100; i++){
		cout << pj[i];
	}
	cout << endl;
}

void flip_rand_n(int* new_string, int* old_string, int n_bits, int search_space)
{
	int i;
	for(i=0; i < 100; i++){
		new_string[i] = old_string[i];
	}
	for(i=0; i < n_bits; i++){
		int rand_num = rand() % search_space;
		new_string[rand_num] ^= 1;
	}
}