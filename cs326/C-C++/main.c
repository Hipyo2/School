#include <stdlib.h>
typedef struct  
{ 
 int x; 
 int y; 
} Foo; 
 
Foo *allocate_node ()  
{ 
 Foo *f;
 f = (Foo *) malloc (sizeof(Foo)); 
 return f;
} 
 
void main ()  
{ 
 Foo *p; 
 p = allocate_node(); 
 p->x = 2; 
 p->y = 3; 
 free(p); 
}

