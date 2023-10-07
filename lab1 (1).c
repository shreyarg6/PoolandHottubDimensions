#include <math.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI acos (-1.0)
#endif

float main ()
{
	float W;
	float D;
	float L;
	float DS;
	float LD;
	float LS;
	float WI;
	float WHT;
	float DHT;
	float V1, V2, V3, PV;
	printf("Enter the width of the pool: ");
	scanf("%f", &W);
	printf("Enter the depth of the pool: ");
	scanf("%f", &D);
	printf("Enter the length of the pool: ");
	scanf("%f", &L);
	printf("Enter the depth of the shallow part of the pool: ");
	scanf("%f", &DS);
	printf("Enter the length of the deep end of the pool: ");
	scanf("%f", &LD);
	printf("Enter the length of the shallow end of the pool: ");
	scanf("%f", &LS);
	printf("Enter the length of the walk in section of the pool: ");
	scanf("%f", &WI);
	
	V1 = (D * LD) * W;
	V2 = ((D+DS)*(L-LD-LS-WI)/2)*W;
	V3 = (D*WI)/2*W;
	PV = V1 + V2 + V3;
	
	//printf("V1 = %f\n", V1); 
	//printf("V2 = %f\n", V2); 
	//printf("V3 = %f\n", V3);
	printf("PV = %f\n", PV);
	return 0;
}
