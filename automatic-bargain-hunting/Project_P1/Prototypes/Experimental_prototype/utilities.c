#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "utilities.h"

#define SECONDS_PER_WEEK   (7 * 24 * (60 * 60))
#define SECONDS_PER_DAY    (24 * (60 * 60))
#define SECONDS_PER_HOUR   (60 * 60)
#define SECONDS_PER_MINUTE (60)

const char *string_from_enum_transport(e_transport eTransport) {
    const char *strings[] = {"Walk", "Bicycle", "Car", "Bus"};
    return strings[eTransport];
}

void validate_file_pointer(FILE *file) {
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
}

int count_lines_in_file(FILE *file, char *file_name) {
    int count_lines = 0;

    file = fopen(file_name, "r");
    validate_file_pointer(file);

    char chr = getc(file);
    while (chr != EOF) {
        if (chr == '\n') {
            count_lines = count_lines + 1;
        }
        chr = getc(file);
    }
    fclose(file);

    return count_lines;
}

void session_time_calculator(int input) {
    int min, hour;

    input = input % SECONDS_PER_WEEK;
    input = input % SECONDS_PER_DAY;

    hour = input / SECONDS_PER_HOUR;
    input = input % SECONDS_PER_HOUR;

    min = input / SECONDS_PER_MINUTE;
    input = input % SECONDS_PER_MINUTE;

    printf("Session was active for %d hours, %d minutes, %d seconds\n\n", hour, min, input);
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double theta, dist;
    if ((lat1 == lat2) && (lon1 == lon2)) {
        return 0;
    } else {
        theta = lon1 - lon2;
        dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
        //returns the arc cosine (inverse cosine) of a number in radians.
        dist = acos(dist);
        dist = rad2deg(dist);
        dist = dist * 60 * 1.1515;
        dist = dist * 1.609344;
    }
    return dist;
}

double deg2rad(double deg) {
    return (deg * PI / 180);
}

double rad2deg(double rad) {
    return (rad * 180 / PI);
}