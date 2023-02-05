#include "../include/allocation.h"
#include <stdlib.h>
#include <stdio.h>

/// Allocates an array of n elements of size member_size in bytes utilizing calloc if the clear flag is set, malloc otherwise.
///	Testing with certain values will show different behavior between calloc and malloc.
/// \param size_t - member size in bytes (can be gotten using the sizeof operator e.g. sizeof(int)
/// \param size_t - number of members in the array
///	\param bool -   1 will clear memory (calling calloc), 0 will not (calling malloc).
/// \return void* - pointer to allocated memory.
void *allocate_array(size_t member_size, size_t nmember, bool clear)
{
    if ((int)nmember <= 0)
        return NULL;

    void *ptr;
    if (clear)
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
void *reallocate_array(void *ptr, size_t size)
{
    if (size == 0)
        return NULL;
    if (ptr == NULL)
        return malloc(size);
    return realloc(ptr, size);
}
// Free
// - Should not be called on a null pointer or a pointer not received from allocation.
// - Free does not reinitialize the memory region.
// - An "Invalid Pointer" error may be a sign of bad memory operations or an overflow from a memset, memcpy, or allocation or freeing a pointer twice.
// - If the received pointer is null no operation is performed.

/// Wrapper around free. Frees memory and sets received pointer to NULL.
/// \param void* - pointer to memory to free.
/// \return Nothing
void deallocate_array(void **ptr)
{
    if (!ptr || !*ptr)
        return;

    free(*ptr);
    *ptr = NULL;
}

// Heap & Stack
// - Local variables are allocated on the stack
// - Large local variable can overflow the stack as stack space is limited (the stack is shared with the functions your program calls as well)
// - When a stack variable leaves scope it is popped from the stack meaning you cannot return a local variable (stack variable) from a function.
// - Heap variables are allocated in memory (or in other places, e.g. using MMAP)
// - Heap variables can be vastly larger than stack variables
// - A heap variable remains available until it is freed, it is the programmers job to do so.
// - A heap variable that is not freed results in a memory leak, such leaks can be found using valgrind.
// - An overflow of the heap can cause serious issues in other parts of the program that may not be easily found. Such issues can usually be found with valgrind -v
// - Allocation of stack variables is faster as you only need to alter the stack pointer.

/// Takes a file name and reads a line into a newly allocated buffer
/// \param char* - filename to read from
/// \return char* - Pointer to malloced heap space containing buffer
char *read_line_to_buffer(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
        return NULL;

    fseek(file, 0, SEEK_END);
    size_t len = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(len + 1);
    if (!buffer)
    {
        fclose(file);
        return NULL;
    }

    if (!fgets(buffer, len + 1, file))
    {
        free(buffer);
        buffer = NULL;
    }

    fclose(file);
    return buffer;
}
