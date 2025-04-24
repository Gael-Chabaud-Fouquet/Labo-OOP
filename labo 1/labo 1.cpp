#include <iostream>
using namespace std;

/*done*/ void exercise1() {
	cout << "Exercise 1" << endl;
	//Variables
	int a;
	int b;
	int c;
	int d;
	int somme;
	double moy;
	int produit;
	int min;
	int max;
	//Getting the numbers
	cout << "Enter 4 numbers\nNumber 1: "; cin >> a;
	cout << "Number 2: "; cin >> b;
	cout << "Number 3: "; cin >> c;
	cout << "Number 4: "; cin >> d;
	//show nums
	cout << "\n" << a << " " << b << " " << c << " " << d << endl;
	//somme
	somme = (a + b + c + d);
	cout << "Somme: " << somme << endl;
	//moyenne	
	moy = ((a + b + c + d) / 4.0f);
	cout << "Moyenne: " << moy << endl;
	//produit
	produit = (a * b * c * d);
	cout << "Produit: " << produit << endl;
	//loop for finding minimum and maximum
	min = a;
	max = a;
	if (b > max) {
		max = b;
	}
	else {
		if (b < min) {
			b = min;
		}
	}
	if (c > max) {
		max = c;
	}
	else{
		if (c < min) {
			c = min;
		}
	}
	if (d > max) {
		max = d;
	}
	else {
		if (d < min) {
			d = min;
		}
	}
	//minimum
	cout << "Min: " << min << endl;
	//maximum
	cout << "Max: " << max << "\n\n" << endl;
}
/*done*/ void exercise2() {
	cout << "Exercise 2" << endl;
	int air;
	int rayon;
	int circonference;
	int diametre;

	cout << "Rayon: "; cin >> rayon;
	diametre = (2 * rayon);
	cout << "Diametre: " << diametre << endl;
	circonference = ((2 * 3.14159)* rayon);
	cout << "Circonference: " << circonference << endl;
	air = ((2.14159) * (rayon * rayon));
	cout << "Aire: " << air << endl;
	cout << "\n\n" << endl;
}
/*done*/ void exercise3() {
	cout << "Exercise 3" << endl;
	char name[32];
	cout << "Name: "; cin >> name;
	cout << "Bonjour " << name << ", j'espere que le programme fonctionne bien\n\n" << endl;
}
/*not done*/ void exercise4() {
	cout << "Exercise 4" << endl;
	cout << "nothing here but silence (for now)\n\n" << endl;
}
/*not done*/ void exercise5() {
	cout << "Exercise 5" << endl;
	cout << "nothing here but silence (for now)\n\n" << endl;
}
/*done*/ void exercise6() {
	cout << "Exercise 6" << endl;
	int BackupOfOriginalNumber;
	float NumberToCheckIfPowerOfTwo;
	cout << "Enter a number: "; cin >> NumberToCheckIfPowerOfTwo;
	BackupOfOriginalNumber = NumberToCheckIfPowerOfTwo;
	while (NumberToCheckIfPowerOfTwo > 1) {
		NumberToCheckIfPowerOfTwo = NumberToCheckIfPowerOfTwo / 2;
	}
	if (NumberToCheckIfPowerOfTwo == 1) {
		cout << BackupOfOriginalNumber << " is a power of 2\n\n" << endl;
	}
	else if (NumberToCheckIfPowerOfTwo < 1) {
		cout << BackupOfOriginalNumber << " is not a power of 2\n\n" << endl;
	}
}
/*done*/ void exercise7() {
	cout << "Exercise 7" << endl;
	cout << "    *" << endl;
	cout << "   * *" << endl;
	cout << "  *   *" << endl;
	cout << " *     *" << endl;
	cout << "*       *" << endl;
	cout << " *     *" << endl;
	cout << "  *   *" << endl;
	cout << "   * *" << endl;
	cout << "    *\n\n" << endl;
}
/*done*/ void exercise8() {
	cout << "Exercise 8" << endl;
	cout << "  *" << endl;
	cout << " ***" << endl;
	cout << "*****" << endl;
	cout << "  *" << endl;
	cout << "  *" << endl;
	cout << "  *" << endl;
	cout << "  *" << endl;
	cout << "  *\n\n" << endl;
}
/*done*/ void exercise9() {
	//explanaitions to understand how to do this (I just used the part where it was explained in writing in yellowish orange on the screen): https://www.youtube.com/watch?v=cM4KP3hnCI4
	cout << "Exercise 9" << endl; //Info: le labo demandait un nombre entre 0 et 999, mais mon programme fonctionne aussi avec des nombres plus grands que 999
	int TheNumberInQuestion;
	int Divider = 10;
	int RemainderOfDivision = 0;
	int QuotientOfDivision = 0;
	int OriginalNumber = 0;
	int TotalEx9 = 0; //At least for now
	cout << "Enter a number: ";  cin >> TheNumberInQuestion;
	OriginalNumber = TheNumberInQuestion;
	while (TheNumberInQuestion > 0) {
		RemainderOfDivision = (TheNumberInQuestion % Divider);
		TotalEx9 += RemainderOfDivision;
		QuotientOfDivision = TheNumberInQuestion / Divider;
		TheNumberInQuestion = QuotientOfDivision;
	}
	cout << "La somme des chiffres du nombres est " << TotalEx9 << "\n\n" << endl;
}
/*not done*/ void exercise10() {
	cout << "Exercise 10" << endl;
	cout << "nothing here but silence (for now)\n\n" << endl;
}

int main(int argc, char** argv) {
	int OptionToDoAkaTheExerciceOfThisLab;
	cout << "Les options 1 a 10 sont les exercices du labo. Il y a une option 11 qui sert a fermer le labo.\nEntrez votre choix: "; cin >> OptionToDoAkaTheExerciceOfThisLab;
	while (OptionToDoAkaTheExerciceOfThisLab != 11) {
	/*exercise 1*/	if (OptionToDoAkaTheExerciceOfThisLab == 1) {
			exercise1();
		}
	/*exercise 2*/	if (OptionToDoAkaTheExerciceOfThisLab == 2) {
			exercise2();
		}
	/*exercise 3*/	if (OptionToDoAkaTheExerciceOfThisLab == 3) {
			exercise3();
		}
	/*exercise 4*/	if (OptionToDoAkaTheExerciceOfThisLab == 4) {
			exercise4();
		}
	/*exercise 5*/	if (OptionToDoAkaTheExerciceOfThisLab == 5) {
			exercise5();
		}
	/*exercise 6*/	if (OptionToDoAkaTheExerciceOfThisLab == 6) {
			exercise6();
		}
	/*exercise 7*/	if (OptionToDoAkaTheExerciceOfThisLab == 7) {
			exercise7();
		}
	/*exercise 8*/	if (OptionToDoAkaTheExerciceOfThisLab == 8) {
			exercise8();
		}
	/*exercise 9*/	if (OptionToDoAkaTheExerciceOfThisLab == 9) {
			exercise9();
		}
	/*exercise 10*/	if (OptionToDoAkaTheExerciceOfThisLab == 10) {
			exercise10();
		}
	/*quit*/	if (OptionToDoAkaTheExerciceOfThisLab == 11) {
			cout << "Alright, closing programm" << endl;
			return 0;
		}
	/*Default, unknown option*/	if (OptionToDoAkaTheExerciceOfThisLab < 1 || OptionToDoAkaTheExerciceOfThisLab > 11) {
			cout << "This is not the option you're looking for\n\n" << endl;
		}
		cout << "Next option: "; cin >> OptionToDoAkaTheExerciceOfThisLab;
	}
}