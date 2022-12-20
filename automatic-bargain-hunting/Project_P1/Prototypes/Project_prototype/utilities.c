#include <stdlib.h>
#include "utilities.h"

//This function will Exit the program if there is no file or no file found//

void validate_file_pointer(FILE *file) {
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
}

/**
 *
 * @param lat1
 * @param lon1
 * @param lat2
 * @param lon2
 * @return
 */
//This function is to measure the distance between the input (given in coordinates) and the supermarkets//

double distance(double lat1, double lon1, double lat2, double lon2) {
    double theta, dist;
    if ((lat1 == lat2) && (lon1 == lon2)) {
        return 0;
    } else {
        theta = lon1 - lon2;
        dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
        dist = acos(dist); //returns the arc cosine (inverse cosine) of a number in radians.
        dist = rad2deg(dist);
        dist = dist * 60 * 1.1515;
        dist = dist * 1.609344;
    }
    return dist;
}

//This function converts decimal degrees to radians//

double deg2rad(double deg) {
    return (deg * pi / 180);
}

//This function converts radians to decimal degrees//

double rad2deg(double rad) {
    return (rad * 180 / pi);
}