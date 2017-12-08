#include <stdio.h>
#include <complex.h>
#include <math.h>

double cartesian[2][2] = {{0,0},{0,0}}; //two polar and two Cartesian numbers
double polar[2][3] = {{0,0,0},{0,0,0}};





void conversionmode (){

    int choice;
    printf("Press one to convert from Cartesian to Polar\n");
    printf("Press two to convert from polar to Cartesian\n");
    scanf("%d",&choice);

    if(choice == 1)carttopolconverter(); // run convert to polar

    if(choice == 2)poltocartconverter();




    }

int mainmenu(){


    int option;






    printf("Press 1 to enter conversion mode\n");
    printf("Press 2 to enter calculation mode\n");
    printf("Press 3 to enter graphing mode\n");
    scanf("%d",&option);
    return option;

    }



void carttopolconverter (){
	double length1,length2;
	double angle1,angle2;

	length1 = sqrt( pow(cartesian[0][0],2) +pow(cartesian[0][1],2) );
    length2 = sqrt( pow(cartesian[1][0],2) +pow(cartesian[1][1],2) );

    angle1 = tan(cartesian[0][1]/cartesian[0][0]);
    angle2 = tan(cartesian[1][1]/cartesian[1][0]);

    printf("%lf + %lfI = %lf ∠ %lf\n",cartesian[0][0],cartesian[0][1],length1,angle1);
    printf("%lf + %lfI = %lf ∠ %lf\n",cartesian[1][0],cartesian[1][1],length2,angle2);










}


void NumberInput(){

	int cartorpol;
	int raddeg;



	for(int x=0;x<2;x++){


	printf("Press one to enter a Cartesian form number or two to enter a polar form number\n");
	scanf("%d",&cartorpol);

	if(cartorpol == 1){
		printf("Please enter the real part of the number\n");
		scanf("%lf",&cartesian[x][0]);
		printf("Please enter the complex part of the number\n");
		scanf("%lf",&cartesian[x][1]);

	}

	if(cartorpol == 2){

		printf("Press 1 to enter a number in degrees or 2 for a number in radians\n");
        scanf("%d",&raddeg);

        if(raddeg == 1){

        	polar[x][2] = 0; //indicate that the number is in degrees
        	printf("Please enter the distance from the origin\n");
        			scanf("%lf",&polar[x][0]);
        			printf("Please enter the angle\n");
        	        scanf("%lf",&polar[x][1]);



        }
        if(raddeg == 2){
        	polar[x][2] = 1; //indicate that the number is in radians
        	printf("Please enter the distance from the origin\n");
        	scanf("%lf",&polar[x][0]);
        	printf("Please enter the angle\n");
        	scanf("%lf",&polar[x][1]);




        }




	}




	}

}



















    char calculationmode(){
        char op;

        do{
        printf("Enter the operator e.g + * / - or r for square root\n");
        scanf("%c",&op);
        }while(op != '+' || op != '*' || op != '/' || op != '-' || op != 'r');




        return op;



        }


     void poltocartconverter(){









     }






int main(int argc, char **argv)
{

	NumberInput(); //take in the numbers

	switch(mainmenu()){

	case 1:
		conversionmode();
		break;
	case 2:
			//calculationmode();
			break;
	case 3:
            //graphing function to come
			break;






	}








	return 0;
}


