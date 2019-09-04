#include <stdio.h>
#include <stdlib.h>


int factorial (int x);


int main()
{


    printf("%d", factorial (5));


    return 0;
}

int factorial (int x){

int fact = 1;

while( x > 1){

    fact = fact * x;
    x--;

}

return fact;

}

// factorial recursivo

//int factorial (int x){

//int fact = 1;

//if( x > 1){
    //fact = x * factorial (x-1);
//}

//return fact;

//}








