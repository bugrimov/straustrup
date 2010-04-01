#include <stdio.h>
int main (void) { char q='"'; puts("#include <stdio.h>"); char *x = "int main (void) { char q='%c'; puts(%c#include <stdio.h>%c); char *x = %c%s%c; printf (x,q,q,q,q,x,q,q,q); return puts(%c%c); }"; printf (x,q,q,q,q,x,q,q,q); return puts(""); }
