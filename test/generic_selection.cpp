
#define DATA_PLACEHOLDER 0
typedef int data_t;
void collect(int n, ...);


/* create c|| table abstraction*/
typedef struct nation_t{
	char* name;	
	int N_NATIONKEY;
}nation_t;

void generic_selection(){
	nation_t NATION[] ={};
	for(nation_t x : NATION){
		if ( x.N_NATIONKEY > 5){
			collect(2, "N_NATIONKEY", "N_NAME");
		}
	}
}
