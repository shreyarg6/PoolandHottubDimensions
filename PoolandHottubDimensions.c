#include <math.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI acos (-1.0)
#endif

float main ()
{
	float hotTubWidth, hotTubDepth, hotTubVolume;
	char continuteFlag;
	float hotTubTotalCost, hotTubTotalGallons;
	float W, D, L, DS, LD, LS, WI, deepVolume, transitionVolume, bigTriangleVolume, shallowVolume, totalPoolVolume, littleTriangleVolume, poolGallons, poolCost;
	float getUserInput(float, float, char *, char *);
	do{
		//for the hot tub
		hotTubWidth = getUserInput(8,14,"width of the Hot Tub with a range of 8-14 feet","width of the Hot Tub");
		hotTubDepth = getUserInput(3,5,"depth of the Hot Tub with a range of 3-5 feet","depth of the Hot Tub" );
	
		//hot tub calculations
		hotTubVolume= (hotTubWidth/2)*(hotTubWidth/2)*3.14*(hotTubDepth-0.5);
		hotTubTotalGallons = hotTubVolume*7.481;
		hotTubTotalCost = hotTubTotalGallons*0.28;
		
		//hot tub display
		printf("Hot Tub Dimensions: width= %f and depth= %f\n", hotTubWidth, hotTubDepth);
		printf("Hot Tub Volume = %f\n", hotTubVolume);
		printf("Hot Tub Total Gallons = %f\n", hotTubTotalGallons);
		printf("Hot Tub Total Cost = $ %f\n", hotTubTotalCost);
		
		//for the pool
		DS = getUserInput(0,5,"depth of the shallow end of the Pool with a range of 0-5 feet","depth of the shallow end of the Pool");
		D = getUserInput(6,15,"depth of the deep end of the Pool with a range of 6-15 feet","depth of the deep end of the Pool");
		W = getUserInput(15,30,"width of the Pool with a range of 15-30 feet","width of the Pool");
		L = getUserInput(40,70,"length of the Pool with a range of 40-70 feet","length of the Pool");
		
		//ask for the length of the walk in
		char ll[9];
		gcvt((L/3),6,ll);
		char nStr[100];
		strcat(nStr,"length of the walk in of the Pool with a range of 5-");
		strcat(nStr, ll);
		strcat (nStr," of the length of pool in feet");
		WI = getUserInput(5,(L/3),nStr,"length of the walk in of the Pool");
		
		//ask for the length of the shallow end
		char lStr[100];
		gcvt((L/2),6,ll);
		strcat(lStr,"length of the shallow end of the Pool with a range of 10-");
		strcat(lStr, ll);
		strcat (lStr," of the shallow end of the pool in feet");
		LS = getUserInput(10,(L/2),lStr,"length of the shallow end of the pool Pool");
		
		//ask for the length of the deep end
		char dStr[100];
		gcvt((L/2),6,ll);
		strcat(dStr,"length of the deep end of the Pool with a range of 12-");
		strcat(dStr, ll);
		strcat (dStr," of the deep end of the pool in feet");
		LD = getUserInput(12,(L/2),dStr,"length of the deep end of the pool Pool");
		
		//pool calculations
		deepVolume = ((D) * LD) * W;
		transitionVolume = ((D)+(DS)*(L-LD-LS-WI)/2)*W;
		bigTriangleVolume = ((DS)*WI)/2*W;
		shallowVolume = ((DS) * LS) * W;
		littleTriangleVolume = (bigTriangleVolume*(0.5/(DS)))+(((WI-((0.5/(DS))*WI))+LS+(L-LD-LS-WI)+LD)*0.5);
		totalPoolVolume = deepVolume + transitionVolume + bigTriangleVolume + shallowVolume -((W*L*0.5)-littleTriangleVolume);
		poolGallons = totalPoolVolume * 7.481;
		poolCost = totalPoolVolume * 0.28;
		
		//pool display
		printf("Pool Dimensions: \n depth of the shallow end= %f\n depth of the deep end= %f\n width= %f\n length= %f\n length of the walk in= %f\n length of the shallow end= %f\n length of the deep end= %f\n"
		, DS, D, W, L, WI, LS, LD);
		printf("Total Pool Volume = %f\n", totalPoolVolume);
		printf("Total Pool Gallons = %f\n", poolGallons);
		printf("Total Pool Cost = $ %f\n", poolCost);
		
		printf("Do you want to continue? (y/n)");
		scanf(" %c", &continuteFlag);
	}while(continuteFlag=='y');
	return 0;
}

float getUserInput(float lowRange, float highRange, char* message, char* warning){
	float input;
	do
		{
			printf("Enter %s:",message);
			scanf("%f", &input);
		
			if(input <lowRange || input >highRange)
			{
				printf("Invalid %s!\n",warning);
			}
		}while(input <lowRange || input >highRange);
	return input;
}
