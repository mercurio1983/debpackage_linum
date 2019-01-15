#include <stdlib.h>
#include <stdio.h>
#include "libresistance.h"
#include "libcomponent.h"
#include "libpower.h"

int main(){
	int antal_komponenter=0;
	char koppling='S';
	int spanning=0;
	float res_array[] = { 0, 0, 0};
	float orig_resistance=0;
	float *p;
	/*fråga anvandaren om varden och las in dessa*/
	printf("Ange spänningskälla i volt: ");
	scanf("%d", &spanning);
	printf("Ange koppling[S|P]: ");
	scanf("%s", &koppling);
	/*kolla stora och sma bokstaver, andra?*/
	printf("Antal komponenter: ");
	scanf("%d", &antal_komponenter);
	/*skaffa lagring till antal_komponenter*/
	p=(float*)malloc(antal_komponenter * sizeof(float));
	if(p == NULL)
		return -1;
	/*läs in angivet antal komponenter*/
	for (int i=0; i<antal_komponenter; i++){
		printf("Komponent %d i ohm ", i+1);
		scanf("%f",p + i);
	}
	printf("Ersättningsresistans\n %.1f ohm \n", orig_resistance=calc_resistance(antal_komponenter, koppling, p));
	/*anrop och skriv ut effekt */
	printf("Effekt: %.2f W\n", calc_power_r(spanning, orig_resistance));
	/*anrop och skriv ut ersattningsresistansen i for*/
	printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");
	int count = e_resistance(orig_resistance, res_array);
	for (int i=0; i<count; i++){
                /*skriv ut*/
                printf("%.0f\n", res_array[i]);
        }
	free(p);
}
