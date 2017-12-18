 #include <iostream>
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
 char* substr(char* str, int i, int sub_size);
 int product(char* substr);

 
 int main() {
	 

	 char numbers[] = "3766581235885941622054540050228447514162777869412307699482907769113268717216818322831603491835999456015306915009196661427591452909871214219792485776087253286386945942663949956280302377388971714236415605168862773550156548824873689737766284562457836197902674997734737908387650371844408009421100914050765521827781655182806129058522352838472989652688571683680665438395803243794489830567998343203397981373552644309879795957322883020671901669290704497751685870539575543632177623725028726840870016429503564354896057020404025619555440159796686935523081354355119387766201895202371147907112778884969266539280935452003712638970422340890791962244529017494651550289995762505866212386393472458374741386036991340760970327022447106502711257671708182087831698677130077927731626466195021513131952322762659409302452718743061757527857578831917621650745174966732316231446870605534431568974878576006012026939455247174486040603096495646182217557200423380237313587369836078574982810508277521659834594761360129982400036745363";
	 int i, j;
	 int sub_size = 8;
	 int max = 0;
	 int cur = 1;
	 int max_index = 0;
	 char** substrs = (char**) malloc(sizeof(numbers)*sub_size*sizeof(char));
	 int* products = new int[strlen(numbers)];
	 char* cur_str = new char[sub_size];
	 
	 #pragma omp parallel for
	 for (i = 0; i < strlen(numbers) - sub_size; i++) {
		cur_str = substr(numbers, i, sub_size);
		substrs[i] = cur_str;

		 
		
		
	 }
	 #pragma omp parallel for
	 for (i = 0; i < strlen(numbers) - sub_size; i++) {
		 products[i] = product(substrs[i]);


	 }
	 for (i = 0; i < strlen(numbers) - sub_size; i++) {
		 if (products[i] > max) {
			 max = products[i];
			 max_index = i;
		 }
	 }
	 std::cout << "Max: " << max << " " << substrs[max_index] << "\n";

 }
 
 char* substr(char* str, int i, int sub_size) {
	char* ret = new char[sub_size];
	int j = 0;
	for (j = 0; j < sub_size; j++) {
		ret[j] = str[j + i];
	}
	return ret;
 }
 
 int product(char* substr) {
	 int i = 0;
	 int ret = 1;
	 for (i = 0; i < strlen(substr); i++) {
		 ret *= substr[i] - '0';
	 }

	 return ret;
	 
 }