//
//  calPi.c
//  
//
//  Created by Yixin Zhang on 2016-03-14.
//  This program will calculate the value of pi
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    double d;
    printf("Please input the smallest number : ");//Ask the user to enter the smallest number
    scanf("%le", &d);
    double s=1;
    double pi=d;
    double i=1;
    double n=1;
    while(fabs(i)>=1e-6){
        //Using fabs() to return the absolute value of double i
        pi+=i;//count all the values
        n=n+2;//get the next denominator by adding 2
        s=-s;//change the "+" to "-" or the reverse one
        i=s/n;
    }
    pi=4*pi; //Need to *4 to get the value of the pi
    printf("The value of pi is：%.6f\n",pi);
    
    return 0;
}
