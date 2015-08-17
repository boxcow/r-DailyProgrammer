#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"


typedef struct{
	int numerator;
	int denominator;
}Fraction;

int getGCF(Fraction frac){
	int a = frac.numerator;
	int b = frac.denominator;
	int t;

	while(b != 0){
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}

Fraction addFractions(Fraction a, Fraction b){
	Fraction sum;
	sum.numerator = (a.numerator * b.denominator) + (a.denominator * b.numerator);
	sum.denominator = a.denominator * b.denominator;
	return sum;
}

Fraction reduceFraction(Fraction a){
	Fraction result;
	int GCF = getGCF(a);
	result.numerator = a.numerator / GCF;
	result.denominator = a.denominator / GCF;

	return result;
}

bool cleanDivision(Fraction a){
	if(a.numerator % a.denominator == 0)
		return true;
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int num;
	Fraction a, b, result;

	scanf_s("%d", &num);
	scanf_s("%d/%d", &a.numerator, &a.denominator);

	for(int i = 1; i < num; i++){
		scanf_s("%d/%d", &b.numerator, &b.denominator);
		a = addFractions(a, b);
	}
	result = reduceFraction(a);

	if(cleanDivision(result) == true)
		printf("Total Value: %d\n", result.numerator / result.denominator);
	else
		printf("Total Value: %d/%d\n", result.numerator, result.denominator);


	system("PAUSE");
	return 0;
}

