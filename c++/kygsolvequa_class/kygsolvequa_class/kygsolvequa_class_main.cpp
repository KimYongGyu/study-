#include "kygqua.h"

void main(){
	QuadFn p, q, r;
	p.read( " p = ");
	q.read( " q = ");
	r.add( p,q);
	

	p.print( "  p  = ");
	q.print( "  q  = ");
	r.print( " p+q = ");

	int n;
	Complex r1,r2;
	n = r.solve(r1,r2);
	printfResult(n, r1, r2);
	getchar();
	getchar();

}