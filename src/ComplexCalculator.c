#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double cartesian[1][2] = { { 0, 0 } }; //polar and two Cartesian numbers
double polar[1][3] = { { 0, 0, 0 } };
int cartesianorpolar;



void conversionmode() {



	if (cartesianorpolar == 0)
		carttopolconverter(); // run convert to polar

	if (cartesianorpolar == 1)
		poltocartconverter();

}

int mainmenu() {

	int option;

	printf("Press 1 to enter conversion mode\n");
	printf("Press 2 to enter calculation mode\n");

	scanf("%d", &option);
	return option;

}

void carttopolconverter() {

	double length1 = 0;
	double angle1 = 0;

	int x = 0;

	length1 = sqrt(pow(cartesian[x][0], 2) + pow(cartesian[x][1], 2));

	if (cartesian[x][0] != 0) {
		angle1 = atan((cartesian[x][1]) / (cartesian[x][0]));
	} else {

	} // to prevent div 0 error skip and start the next number

	printf("%lf + %lfI = %lf angle %lf rad\n", cartesian[x][0], cartesian[x][1],
			length1, angle1);



}

void NumberInput() {

	int cartorpol;
	int raddeg;

	int x = 0;

	printf(
			"Press one to enter a Cartesian form number or two to enter a polar form number\n");
	scanf("%d", &cartorpol);

	if (cartorpol == 1) {
		printf("Please enter in form x space y for x + yI\n");
		scanf("%lf %lf", &cartesian[x][0], &cartesian[x][1]);
		cartesianorpolar =0;

	}

	if (cartorpol == 2) {
		cartesianorpolar =1;

		printf(
				"Press 1 to enter a number in degrees or 2 for a number in radians\n");
		scanf("%d", &raddeg);

		if (raddeg == 1) {

			polar[x][2] = 0; //indicate that the number is in degrees
			printf("Please enter the value x space y for x angle y\n");
			scanf("%lf %lf", &polar[x][0], &polar[x][1]);

		}
		if (raddeg == 2) {
			polar[x][2] = 1; //indicate that the number is in radians
			printf("Please enter the value x space y for x angle y\n");
			scanf("%lf %lf", &polar[x][0], &polar[x][1]);

		}

	}

}

void calculationmode() {
	int mode = 0;

	printf(
			"Press 1 to do calculations in cartesian form and 2 to calculate in polar form\n");

	scanf("%d", &mode);

	if (mode == 1) {
		double real1 = 0, real2 = 0;
		double im1 = 0, im2 = 0;
		double ansreal = 0, ansim = 0;
		char op;
		double length1 = 0;
		double angle1 = 0;
		int root;
		printf("press one for (+ - * /)  and 2 for root\n");
		scanf("%d", &root);

		if (root == 2) {

			printf("Please enter the equation in the form a +bi\n");
			scanf("%lf %lf", &real1, &im1);

			length1 = sqrt(pow(real1, 2) + pow(im1, 2));

			if (real1 != 0) {
				angle1 = atan(im1 / real1);
			}
			//converting to polar form as roots of polar form are much easier

			// to convert to square root

			length1 = sqrt(length1); //root the length
			angle1 = angle1 / 2; //divide the angle by 2

			ansreal = length1 * cos(angle1);
			ansim = length1 * sin(angle1);
			printf(" ROOT (%lf + %lfI) = %lf + %lfI", real1, im1, ansreal,
					ansim);

		} else {

			printf(
					"Please enter the equation in the form a +bi operator c + di = a b operator c d\n");
			scanf("%lf %lf %c %lf %lf", &real1, &im1, &op, &real2, &im2);

			switch (op) {

			case '+':
				ansreal = real1 + real2;
				ansim = im1 + im2;

				printf("(%lf + %lfI) + (%lf + %lfI) = (%lf + %lfI) ", real1,
						im1, real2, im2, ansreal, ansim);

				break;

			case '-':

				ansreal = real1 - real2;
				ansim = im1 - im2;

				printf("(%lf + %lfI) - (%lf + %lfI) = (%lf + %lfI) ", real1,
						im1, real2, im2, ansreal, ansim);

				break;

			case '*':

				ansreal = (real1 * real2) - (im1 * im2);
				ansim = (real1 * im2) + (im1 * real2);
				printf("(%lf + %lfI) * (%lf + %lfI) = (%lf + %lfI) ", real1,
						im1, real2, im2, ansreal, ansim);

				break;

			case '/':

				ansreal = ((real1 * real2) + (im1 * im2))
						/ (real2 * real2 + im2 * im2);
				ansim = (-(real1 * im2) + (im1 * real2))
						/ (real2 * real2 + im2 * im2);
				printf("(%lf + %lfI) * (%lf + %lfI) = (%lf + %lfI) ", real1,
						im1, real2, im2, ansreal, ansim);

				break;

			}

		}

	}

	if (mode == 2) {

		int degrad;
		printf("Press 1 for degrees and 2 for radians\n");
		scanf("%d", &degrad);

		double length1 = 0, length2 = 0, length3 = 0;
		double angle1 = 0, angle2 = 0, angle3 = 0;
		double anslength = 0, ansangle = 0;
		double ansreal, ansim;
		double real1, real2, im1, im2;
		char op;

		int root;
		printf("press one for + - * /  and 2 for root\n");
		scanf("%d", &root);

		if (root == 2) {

			printf("Please enter the equation in the form a angle b\n");
			scanf("%lf %lf", &length1, &angle1);

			// to convert to square root

			if (degrad == 2) {
				length3 = sqrt(length1); //root the length
				angle3 = angle1 / 2; //divide the angle by 2

				ansreal = length3 * cos(angle3);
				ansim = length3 * sin(angle3);
			}
			if (degrad == 1) {
				length3 = sqrt(length1); //root the length
				angle3 = angle1 / 2; //divide the angle by 2

				ansreal = length3 * cos((angle3 / 360) * (2 * M_PI));
				ansim = length3 * sin((angle3 / 360) * (2 * M_PI));

			}

			anslength = sqrt(pow(ansreal, 2) + pow(ansim, 2));

			if (ansreal != 0) {
				ansangle = atan((ansim) / (ansreal));
			} else {
			} // to prevent div 0 error

			printf(" ROOT (%lf angle %lf) = %lf angle %lf", length1, angle1,
					anslength, ansangle);

		} else {

			printf(
					"Please enter the equation in the form a angle b op c angle d = a b op c d\n");
			scanf("%lf %lf %c %lf %lf", &length1, &angle1, &op, &length2,
					&angle2);

			switch (op) {

			case '+':

				//convert to cartesian form to allow addition
				if (degrad == 1) { //if the number is in degrees

					real1 = length1 * cos((angle1 / 360) * (2 * M_PI));
					im1 = length1 * sin((angle1 / 360) * (2 * M_PI));
					real2 = length2 * cos((angle2 / 360) * (2 * M_PI));
					im2 = length2 * sin((angle2 / 360) * (2 * M_PI));

				}

				if (degrad == 2) { //if the number is in radians

					real1 = length1 * cos(angle1);
					im1 = length1 * sin(angle1);
					real2 = length2 * cos(angle2);
					im2 = length2 * sin(angle2);

				}

				ansreal = real1 + real2; //adding real and imaginary parts
				ansim = im1 + im2;

				anslength = sqrt(pow(ansreal, 2) + pow(ansim, 2));

				if (ansreal != 0) {
					ansangle = atan((ansim) / (ansreal));

					if (ansreal < 0) {
						ansangle = ansangle + M_PI;
					}
					if (ansreal > 0 && ansim < 0) {
						ansangle = ansangle + (2 * M_PI);
					} //corrections for tan-1

				} else {
				} // to prevent div 0 error skip and start the next number

				if (degrad == 1) {

					ansangle = (ansangle / (2 * M_PI)) * 360; //converting to degrees

				}

				printf("(%lf angle %lf) + (%lf angle %lf) = (%lf angle %lf) ",
						length1, angle1, length2, angle2, anslength, ansangle);

				break;

			case '-':

				//convert to cartesian form to allow addition
				if (degrad == 1) { //if the number is in degrees

					real1 = length1 * cos((angle1 / 360) * (2 * M_PI));
					im1 = length1 * sin((angle1 / 360) * (2 * M_PI));
					real2 = length2 * cos((angle2 / 360) * (2 * M_PI));
					im2 = length2 * sin((angle2 / 360) * (2 * M_PI));

				}

				if (degrad == 2) { //if the number is in radians

					real1 = length1 * cos(angle1);
					im1 = length1 * sin(angle1);
					real2 = length2 * cos(angle2);
					im2 = length2 * sin(angle2);

				}

				ansreal = real1 - real2; //subtracting real and imaginary parts
				ansim = im1 - im2;

				anslength = sqrt(pow(ansreal, 2) + pow(ansim, 2));

				if (ansreal != 0) {
					ansangle = atan((ansim) / (ansreal));
					if (ansreal < 0) {
						ansangle = ansangle + M_PI;
						if (ansreal > 0 && ansim < 0) {
							ansangle = ansangle + (2 * M_PI);
						}
					}
				} else {
				} // to prevent div 0 error skip and start the next number

				if (degrad == 1) {

					ansangle = (ansangle / (2 * M_PI)) * 360; //converting to degrees

				}

				printf("(%lf angle %lf) - (%lf angle %lf) = (%lf angle %lf) ",
						length1, angle1, length2, angle2, anslength, ansangle);

				break;

			case '*':

				anslength = length1 * length2;
				ansangle = angle1 + angle2;

				printf("(%lf angle %lf) * (%lf angle %lf) = (%lf angle %lf) ",
						length1, angle1, length2, angle2, anslength, ansangle);

				break;

			case '/':

				anslength = length1 / length2;
				ansangle = angle1 - angle2;

				printf("(%lf angle %lf) / (%lf angle %lf) = (%lf angle %lf) ",
						length1, angle1, length2, angle2, anslength, ansangle);

				break;

			}

		}

	}



}

void poltocartconverter() {

	double real;

	double im;

	int x = 0;

	if (polar[x][2] == 0) { //if the number is in degrees

		real = polar[x][0] * cos((polar[x][1] / 360) * (2 * M_PI));
		im = polar[x][0] * sin((polar[x][1] / 360) * (2 * M_PI));
		printf("%lf angle %lf = %lf + %lfI\n", polar[x][0], polar[x][1], real,
				im);
	}

	if (polar[x][2] == 1) { //if the number is in radians

		real = polar[x][0] * cos(polar[x][1]);
		im = polar[x][0] * sin(polar[x][1]);
		printf("%lf angle %lf = %lf + %lfI\n", polar[x][0], polar[x][1], real,
				im);
	}



}



int main(int argc, char **argv) {

	//take in the numbers

	switch (mainmenu()) {

	case 1:
		NumberInput();
		conversionmode();
		break;
	case 2:
		calculationmode();
		break;


	}

	return 0;

}

