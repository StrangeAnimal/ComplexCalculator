#include <stdio.h>

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

	double length1 =0;
	double angle1 =0;

	for(int x=0;x<2;x++){

	length1 = sqrt( pow(cartesian[x][0],2) +pow(cartesian[x][1],2) );

     if(cartesian[x][0] != 0 ){
    angle1 = atan((cartesian[x][1])/(cartesian[x][0]));
     }else{continue;} // to prevent div 0 error skip and start the next number


    printf("%lf + %lfI = %lf angle %lf rad\n",cartesian[x][0],cartesian[x][1],length1,angle1);


	}
    getch();









}


void NumberInput(){

	int cartorpol;
	int raddeg;



	for(int x=0;x<2;x++){


	printf("Press one to enter a Cartesian form number or two to enter a polar form number\n");
	scanf("%d",&cartorpol);

	if(cartorpol == 1){
		printf("Please enter in form x space y for x + yI\n");
		scanf("%lf %lf",&cartesian[x][0],&cartesian[x][1]);


	}

	if(cartorpol == 2){

		printf("Press 1 to enter a number in degrees or 2 for a number in radians\n");
        scanf("%d",&raddeg);

        if(raddeg == 1){

        	polar[x][2] = 0; //indicate that the number is in degrees
        	printf("Please enter the value x space y for x angle y\n");
        			scanf("%lf %lf",&polar[x][0],&polar[x][1]);




        }
        if(raddeg == 2){
        	polar[x][2] = 1; //indicate that the number is in radians
        	printf("Please enter the value x space y for x angle y\n");
        	scanf("%lf %lf",&polar[x][0],&polar[x][1]);




        }




	}




	}

}



















    void calculationmode(){
        int mode = 0;

        printf("Press 1 to do calculations in cartesian form and 2 to calculate in polar form\n please enter the equation in the form a b operator c d for \n"
        		"for a +bI * c + dI  or a angle b * c angle d for root enter a +bI r blank\n");

        scanf("%d", &mode);





        if(mode ==1){
        	double real1,real2;
        	double im1,im2;
        	double ansreal,ansim;
        	char op;
        	printf("Please enter the calculation\n");
        	scanf("%lf %lf %c %lf %lf",&real1,&im1,&op,&real2,&im2);

        	switch(op){

        	case 'r':



            break;

        	case '+':
        		ansreal = real1 + real2;
        		ansim = im1 + im2;

        		printf("(%lf + %lfI) + (%lf + %lfI) = (%lf + %lfI) ",real1,im1,real2,im2,ansreal,ansim);



            break;

        	case '-':

        		ansreal = real1 - real2;
        		ansim = im1 - im2;

        	    printf("(%lf + %lfI) - (%lf + %lfI) = (%lf + %lfI) ",real1,im1,real2,im2,ansreal,ansim);



        	break;

        	case '*':

        		ansreal = (real1*real2)-(im1*im2);
        		ansim = (real1*im2) + (im1*real2);
        		printf("(%lf + %lfI) * (%lf + %lfI) = (%lf + %lfI) ",real1,im1,real2,im2,ansreal,ansim);



        	break;

        	case '/':

        		ansreal = ((real1*real2) + (im1*im2))/(real2*real2 + im2*im2);
        		ansim = (-(real1*im2) + (im1 * real2))/(real2*real2 + im2*im2);
        		printf("(%lf + %lfI) * (%lf + %lfI) = (%lf + %lfI) ",real1,im1,real2,im2,ansreal,ansim);


            break;












        	}





        }

        if(mode == 2){
        double real1,real2;
                	double im1,im2;
                	char op;
                	printf("Please enter the calculation\n");
                	scanf("%lf %lf %c %lf %lf",&real1,&im1,&op,&real2,&im2);

                	switch(op){

                	case 'r':



                    break;

                	case '+':



                    break;

                	case '-':



                	break;

                	case '*':



                	break;

                	case '/':



                    break;

                	}










                	}







        }


     void poltocartconverter(){

    	 double real;
    	 double im;


          for(int x=0;x<2;x++){

        	  if(polar[x][2] == 0){ //if the number is in degrees

                   real = polar[x][0] * cos((polar[x][1]/360) *(2 * M_PI));
        		   im   = polar[x][0] * sin((polar[x][1]/360) *(2 * M_PI));
        		   printf("%lf angle %lf = %lf + %lfI\n",polar[x][0],polar[x][1],real,im);
        	  }


        	  if(polar[x][2] == 1){ //if the number is in radians

        	                     real = polar[x][0] * cos(polar[x][1]);
        	          		   im   = polar[x][0] * sin(polar[x][1]);
        	          		   printf("%lf angle %lf = %lf + %lfI\n",polar[x][0],polar[x][1],real,im);
        	          	  }






          }



          getch();



     }






int main(int argc, char **argv)
{

	 //take in the numbers

	switch(mainmenu()){

	case 1:
		NumberInput();
		conversionmode();
		break;
	case 2:
			calculationmode();
			break;
	case 3:
            //graphing function to come
			break;






	}








	return 0;
}


