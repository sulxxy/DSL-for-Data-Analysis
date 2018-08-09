
void collect(int n, ...);
void groupBy(char* c1, char* agrf, char* c2);



/* create c|| table abstraction*/
typedef struct nation_t{
	char* name;	
	int N_NATIONKEY;
}nation_t;

void generic_groupBy(){
	nation_t NATION[] ={};
	for(nation_t x : NATION){
		collect(2, "N_NATIONKEY", "N_NAME");
	}
	groupBy("N_NAME", "SUM", "N_NATIONKEY");
}
