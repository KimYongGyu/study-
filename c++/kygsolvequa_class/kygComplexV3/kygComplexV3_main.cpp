#include "kygComplexV3_class.h"

void main (){
	kygComplex a,b,c;

	a.read( "A =");
	b.read( "B =");
	c.add( a,b);

	a.print ("  A =");
	b.print ("  B =");
	c.print (" A+B =");
}