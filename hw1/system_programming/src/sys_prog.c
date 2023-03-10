#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../include/sys_prog.h"

// LOOK INTO OPEN, READ, WRITE, CLOSE, FSTAT/STAT, LSEEK
// GOOGLE FOR ENDIANESS HELP

//
// NOTE THE FILE I/O MUST USE OPEN, READ, WRITE, CLOSE, SEEK, STAT with file descriptors (NO FILE*)
// Make sure to uint8_t or uint32_t, you are dealing with system dependent sizes

// Read contents from the passed into an destination
// \param input_filename the file containing the data to be copied into the destination
// \param dst the variable that will be contain the copied contents from the file
// \param offset the starting location in the file, how many bytes inside the file I start reading
// \param dst_size the total number of bytes the destination variable contains
// return true if operation was successful, else false
bool bulk_read(const char *input_filename, void *dst, const size_t offset, const size_t dst_size)
{
    if (input_filename == NULL || dst == NULL || dst_size == 0 || *input_filename == '\n' || *input_filename == '\0' || offset > dst_size)
        return false;

    int file_desc = open(input_filename, O_RDONLY);

    if (file_desc == -1)
        return false;

    if (lseek(file_desc, offset, SEEK_SET) == -1)
    {
        close(file_desc);
        return false;
    }

    size_t bytes_read = read(file_desc, dst, dst_size);
    close(file_desc);

    return bytes_read == dst_size;
}

// Writes contents from the data source into the outputfile
// \param src the source of the data to be wrote to the output_filename
// \param output_filename the file that is used for writing
// \param offset the starting location in the file, how many bytes inside the file I start writing
// \param src_size the total number of bytes the src variable contains
// return true if operation was successful, else false
bool bulk_write(const void *src, const char *output_filename, const size_t offset, const size_t src_size)
{
    if (src == NULL || output_filename == NULL || src_size == 0 || *output_filename == '\n' || *output_filename == '\0' || strlen(output_filename) == 0)
        return false;

    int file_desc = open(output_filename, O_WRONLY);

    if (file_desc == -1)
        return false;

    if (lseek(file_desc, offset, SEEK_SET) == -1)
    {
        close(file_desc);
        return false;
    }

    ssize_t written_bytes = write(file_desc, src, src_size);

    close(file_desc);

    return written_bytes == src_size;
}

// Returns the file metadata given a filename
// \param query_filename the filename that will be queried for stats
// \param metadata the buffer that contains the metadata of the queried filename
// return true if operation was successful, else false
bool file_stat(const char *query_filename, struct stat *metadata)
{

    int file_desc = open(query_filename, O_RDONLY);

    if (file_desc == -1)
        return false;

    if (fstat(file_desc, metadata) == -1)
    {
        close(file_desc);
        return false;
    }

    close(file_desc);
    return true;
}

// Converts the endianess of the source data contents before storing into the dst_data.
// The passed source data bits are swapped from little to big endian and vice versa.
// \param src_data the source data that contains content to be stored into the destination
// \param dst_data the destination that stores src data
// \param src_count the number of src_data elements
// \return true if successful, else false for failure
bool endianess_converter(uint32_t *src_data, uint32_t *dst_data, const size_t src_count)
{
    if (src_data == NULL || dst_data == NULL || src_count == 0)
        return false;

    for (size_t i = 0; i < src_count; i++)
    {
        dst_data[i] = __builtin_bswap32(src_data[i]);
    }
    return true;
}
