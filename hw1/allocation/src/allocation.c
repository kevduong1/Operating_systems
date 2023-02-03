#include "../include/allocation.h"
#include <stdlib.h>
#include <stdio.h>

/// Allocates an array of n elements of size member_size in bytes utilizing calloc if the clear flag is set, malloc otherwise.
///	Testing with certain values will show different behavior between calloc and malloc.
/// \param size_t - member size in bytes (can be gotten using the sizeof operator e.g. sizeof(int)
/// \param size_t - number of members in the array
///	\param bool -   1 will clear memory (calling calloc), 0 will not (calling malloc).
/// \return void* - pointer to allocated memory.
void* allocate_array(size_t member_size, size_t nmember,bool clear)
{
    if((int)nmember <= 0) return NULL;

    void *ptr;
    if(clear)
    {
        ptr = calloc(nmember, member_size);
    }
    else
    {   
        ptr = malloc(member_size);
    }

    return ptr;
}

/// Realloc
/// - Does not initialize expanded memory
/// - Original contents remain unchanged
/// - If passed a null pointer then a malloc will occur.
/// - May move memory to a new location

/// Simple wrapper around realloc.
/// \param void* - pointer to memory to resize.
/// \param size_t - size of memory to allocate
/// \return void* - pointer to reallocated memory region, may be same as original pointer.
void* reallocate_array(void* ptr, size_t size)
{
    if(size == 0) return NULL;
    if(ptr == NULL) return malloc(size);
    return realloc(ptr, size);
}

void deallocate_array(void** ptr)
{
  // If the received pointer is null, do nothing
  if (!ptr || !*ptr) return;

  // Free the memory and set the pointer to NULL
  free(*ptr);
  *ptr = NULL;
}

char* read_line_to_buffer(char* filename)
{
    // Open the file
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;

    // Determine the length of the file
    fseek(file, 0, SEEK_END);
    size_t len = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the buffer on the heap
    char* buffer = malloc(len + 1);
    if (!buffer) {
    fclose(file);
    return NULL;
    }

    // Read a line from the file into the buffer
    if (!fgets(buffer, len + 1, file)) {
    free(buffer);
    buffer = NULL;
    }

    // Close the file and return the buffer
    fclose(file);
    return buffer;
}
