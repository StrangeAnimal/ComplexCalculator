#include <stdio.h>
#include <complex.h>

double cartesian[2][2]; //two polar and two Cartesian numbers
double polar[2][3];





int conversionmode (){

    int choice;
    printf("Press one to convert from Cartesian to Polar\n");
    printf("Press two to convert from polar to Cartesian\n");
    scanf("%d",&choice);

    return choice;




    }

int mainmenu(){


    int option;






    printf("Press 1 to enter conversion mode\n");
    printf("Press 2 to enter calculation mode\n");
    printf("Press 3 to enter graphing mode\n");
    scanf("%d",&option);
    return option;

    }



int main(int argc, char **argv)
{

	NumberInput();

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


void carttopolconverter (){}


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








