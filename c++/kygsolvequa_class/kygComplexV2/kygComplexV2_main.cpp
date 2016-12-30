#include "kygComplexV2_class.h"

void main (){
	kygComplex a,b,c;

	a.readkygComplex( "A =");
	b.readkygComplex( "B =");
	c.addkygComplex( a,b);

	a.printkygComplex ("  A =");
	b.printkygComplex ("  B =");
	c.printkygComplex (" A+B =");
}