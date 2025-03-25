#include <fcntl.h>      // Provides declarations for open() and file flags
#include <unistd.h>     // Provides declarations for write() and close()
#include <stdio.h>      // Provides declarations for perror() and printf()
#include <stdlib.h>     // Provides declarations for exit() and EXIT_FAILURE
#include <string.h>     // Provides declarations for strlen()

int main(void) {
    const char *filename = "sample.txt"; // File to open or create

    // Open the file:
    // O_CREAT : Create the file if it doesn't exist.
    // O_RDWR  : Open for reading and writing.
    // O_TRUNC : If the file exists, truncate it to zero length.
    // 0644    : File permissions set to -rw-r--r--.
    int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening/creating file");
        exit(EXIT_FAILURE);
    }

    // Optionally, write some text to the file:
    const char *message = "Hello, Linux file operations!\n";
    ssize_t bytes_written = write(fd, message, strlen(message));
    if (bytes_written < 0) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    
    printf("File '%s' opened (or created) successfully and written to.\n", filename);

    // Close the file descriptor
    close(fd);

    return 0;
}
