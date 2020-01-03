#include <stdio.h>

double getAverage( int values[], int n);

int main() {
    
    int balance[] = {5, 10, 100, 200};
    double avg;

    avg = getAverage(balance, 4);

    printf("Average value is: %f\n", avg);
}

double getAverage( int values[], int n) {

    int i, sum = 0;
    double avg;

    for(i=0; i < n; i++) {
        sum += values[i];
    }

    avg = (double)sum / n;

    return avg;
}