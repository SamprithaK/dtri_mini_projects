#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main(int argc,char * argv[])
{

if(argc==1)
{
    printf("you have not entered  any arguments for input\n");
 return 0;
}
{
    int side;
    side=atoi(argv[1]);
    float area =pow(side,2);
    printf("The area of the square of side %d is %f msq",side,area);
    return 0;
}
}
