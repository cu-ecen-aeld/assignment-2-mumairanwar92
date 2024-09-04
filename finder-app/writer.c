#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        fprintf(stderr, "Error: Two arguments are required.\n");

        // Open syslog for logging with LOG_USER facility
        openlog("writer", LOG_PID | LOG_CONS, LOG_USER);
        syslog(LOG_ERR, "Invalid number of arguments: %d", argc - 1);
        closelog();

        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Open syslog for logging with LOG_USER facility
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    // Attempt to open the file for writing
    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s' for writing.\n", writefile);
        syslog(LOG_ERR, "Error opening file %s for writing", writefile);
        closelog();
        return 1;
    }

    // Write the string to the file
    if (fputs(writestr, file) == EOF) {
        fprintf(stderr, "Error: Could not write to file '%s'.\n", writefile);
        syslog(LOG_ERR, "Error writing to file %s", writefile);
        fclose(file);
        closelog();
        return 1;
    }

    // Log successful write operation
    syslog(LOG_DEBUG, "Writing '%s' to '%s'", writestr, writefile);

    // Close the file and syslog
    fclose(file);
    closelog();

    return 0;
}
