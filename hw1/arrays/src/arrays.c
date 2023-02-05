#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/arrays.h"

// LOOK INTO MEMCPY, MEMCMP, FREAD, and FWRITE

// Copy the contents from source array into destination array
// \param src the array the will be copied into the destination array
// \param dst the array that will be copied from the source array
// \param elem_size the number of bytes each array element uses
// \param elem_count the number of elements in the source array
// return true if operation was successful, else false
bool array_copy(const void *src, void *dst, const size_t elem_size, const size_t elem_count)
{
    if (src == NULL || dst == NULL || elem_size == 0 || elem_count == 0)
        return false;

    for (size_t i = 0; i < elem_count; i++)
    {
        *(char *)(dst + (i * elem_size)) = *(const char *)(src + (i * elem_size));
    }
    return true;
}

// Compares if two arrays contain the same contents
// \param array_a the array that will be compared against array_b
// \param array_b the array that will be compared against array_a
// \param elem_size the number of bytes each array element uses in array_a
// \param elem_count the number of elements in array_a
// return true if operation was successful, else false
bool array_is_equal(const void *data_one, void *data_two, const size_t elem_size, const size_t elem_count)
{
    if (data_one == NULL || data_two == NULL || elem_size == 0 || elem_count == 0)
        return false;

    for (size_t i = 0; i < elem_count; i++)
    {
        if (memcmp(data_one + i * elem_size, data_two + i * elem_size, elem_size) != 0)
        {
            return false;
        }
    }
    return true;
}

// Attempts to locate the target from an array
// \param data the data that may contain the target
// \param target the target that may be in the data
// \param elem_size the number of bytes each array element uses and same as the target
// \param elem_count the number of elements in the data array
// returns an index to the located target, else return -1 for failure
ssize_t array_locate(const void *data, const void *target, const size_t elem_size, const size_t elem_count)
{
    if (data == NULL || target == NULL || elem_size == 0 || elem_count == 0)
        return -1;

    for (size_t i = 0; i < elem_count; i++)
    {
        if (memcmp((char *)data + (i * elem_size), target, elem_size) == 0)
        {
            return i;
        }
    }

    return -1;
}

// Writes an array into a binary file
// \param src_data the array the will be wrote into the destination file
// \param dst_file the file that will contain the wrote src_data
// \param elem_size the number of bytes each array element uses
// \param elem_count the number of elements in the source array
// return true if operation was successful, else false
bool array_serialize(const void *src_data, const char *dst_file, const size_t elem_size, const size_t elem_count)
{
    if (src_data == NULL || dst_file == NULL || elem_size == 0 || elem_count == 0 || dst_file[0] == '\n')
        return false;

    FILE *file = fopen(dst_file, "wb");
    if (file == NULL)
        return false;

    for (size_t i = 0; i < elem_count; i++)
    {
        fwrite((char *)src_data + (i * elem_size), elem_size, 1, file);
    }
    fclose(file);
    return true;
}
// Reads an array from a binary file
// \param src_file the source file that contains the array to be read into the destination array
// \param dst_data the array that will contain the data stored inthe source file
// \param elem_size the number of bytes each array element uses of the destination array
// \param elem_count the number of elements in the destination array
// return true if operation was successful, else false
bool array_deserialize(const char *src_file, void *dst_data, const size_t elem_size, const size_t elem_count)
{
    if (src_file == NULL || dst_data == NULL || elem_size == 0 || elem_count == 0 || src_file[0] == '\n')
        return false;
    FILE *fp = fopen(src_file, "r");
    if (fp == NULL)
    {
        return false;
    }

    size_t bytes_read = fread(dst_data, elem_size, elem_count, fp);
    fclose(fp);
    if (bytes_read != elem_count)
    {
        return false;
    }
    return true;
}
