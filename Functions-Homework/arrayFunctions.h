#ifndef ARRAYFUNCTIONS_H
#define	ARRAYFUNCTIONS_H

int arr_min(int arr[], int length);
int arr_max(int arr[], int length);
void arr_clear(int arr[], int length);
float arr_average(int arr[], int length);
int arr_sum(int arr[], int length);
int arr_contains(int arr[], int length, int element);
int* arr_merge(int firstArr[], int firstArrLength, int secondArr[], int secondArrLength);

#endif