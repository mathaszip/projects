#include <stdlib.h>
#include "utilities.h"

/**
 * validate_file_pointer checks if the given file pointer is valid.
 *
 * If the file pointer is NULL, this function displays an error message
 * and exits the program with EXIT_FAILURE.
 *
 * @param file Pointer to the file to validate
 */
void validate_file_pointer(FILE *file)
{
    if (file == NULL)
    {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
}

/**
 * distance calculates the distance between two points on the Earth's surface,
 * given their latitude and longitude.
 *
 * If the two points are the same, this function returns 0.
 *
 * The distance is calculated using the Haversine formula, which assumes a
 * perfect sphere for the Earth (i.e., it does not account for the Earth's
 * elliptical shape or any other distortions).
 *
 * @param lat1 Latitude of the first point, in degrees
 * @param lon1 Longitude of the first point, in degrees
 * @param lat2 Latitude of the second point, in degrees
 * @param lon2 Longitude of the second point, in degrees
 * @return The distance between the two points, in kilometers
 */
double distance(double lat1, double lon1, double lat2, double lon2)
{
    if ((lat1 == lat2) && (lon1 == lon2))
    {
        return 0;
    }

    // haversine formula
    double theta = lon1 - lon2;
    double dist =
            sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);

    // degrees * 60 = 0.6 nautical miles
    // 0.6 * 1.1515 = miles
    dist = dist * 60 * 1.1515;

    // miles to km
    dist = dist * 1.609344;

    return dist;
}

/**
 * deg2rad converts an angle in degrees to radians.
 *
 * @param deg The angle in degrees to convert
 * @return The angle in radians
 */
double deg2rad(double deg)
{
    return (deg * pi / 180);
}

/**
 * rad2deg converts an angle in radians to degrees.
 *
 * @param rad The angle in radians to convert
 * @return The angle in degrees
 */
double rad2deg(double rad)
{
    return (rad * 180 / pi);
}

