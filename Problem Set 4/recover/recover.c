#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int isJPEG(BYTE buffer[]);

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open files
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    //Alocate memory and initialize variables
    BYTE buffer[BLOCK_SIZE];

    //Buffer for filename
    char filename[8];
    FILE *image;
    int counter = 0;

    // Read JPEG
    while (fread(buffer, BLOCK_SIZE, 1, file) == 1)
    {
        if (isJPEG(buffer) == 1)
        {
            // Close the image, unless it's the first JPEG.
            if (counter != 0)
            {
                fclose(image);
            }
            sprintf(filename, "%03i.jpg", counter++);
            image = fopen(filename, "w");
            fwrite(buffer, BLOCK_SIZE, 1, image);
        }
        // Next block of current JPEG file
        else if (counter > 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, image);
        }
    }
}

int isJPEG(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}