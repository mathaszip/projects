#ifndef P1_PROTOTYPE_DISTANCE_H
#define P1_PROTOTYPE_DISTANCE_H

#endif //P1_PROTOTYPE_DISTANCE_H

#include <math.h>
#include <stdio.h>

#define pi 3.14159265358979323846

double distance(double lat1, double lon1, double lat2, double lon2);

double deg2rad(double);

double rad2deg(double);

void validate_file_pointer(FILE *file);