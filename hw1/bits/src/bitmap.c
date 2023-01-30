#include "../include/bitmap.h"

// data is an array of uint8_t and needs to be allocated in bitmap_create
//      and used in the remaining bitmap functions. You will use data for any bit operations and bit logic
// bit_count the number of requested bits, set in bitmap_create from n_bits
// byte_count the total number of bytes the data contains, set in bitmap_create

/// Creates a bitmap to contain 'n' bits (zero initialized)
/// \param n_bits
/// \return New bitmap pointer, NULL on error
///
bitmap_t *bitmap_create(size_t n_bits)
{
    if(n_bits == 0) return NULL;

    bitmap_t *bitmap = malloc(sizeof(bitmap_t));

    bitmap->bit_count = n_bits;
    bitmap->byte_count = (n_bits/8);
    if(n_bits%8 != 0)
    {
        bitmap->byte_count++;
    }
    bitmap->data = calloc(bitmap->byte_count, sizeof(uint8_t));

    return bitmap;
}

///
/// Sets the requested bit in bitmap
/// \param bitmap The bitmap
/// \param bit The bit to set
///
bool bitmap_set(bitmap_t *const bitmap, const size_t bit)
{
    if(bitmap == NULL || bit > bitmap->bit_count) return false;

    size_t byte_index, bit_index;
    byte_index = bit/8;
    bit_index = bit%8;
    bitmap->data[byte_index] |= 1 << bit_index;
    return true;
}
///
/// Clears requested bit in bitmap
/// \param bitmap The bitmap
/// \param bit The bit to be cleared
///
bool bitmap_reset(bitmap_t *const bitmap, const size_t bit)
{
    if(bitmap == NULL || bit > bitmap->bit_count || bit < 0) return false;
    size_t byte_index, bit_index;
    byte_index = bit/8;
    bit_index = bit%8;
    bitmap->data[byte_index] &= ~(1 << bit_index);
    return true;
}

///
/// Returns bit in bitmap
/// \param bitmap The bitmap
/// \param bit The bit to queried
/// \return State of requested bit
///
bool bitmap_test(const bitmap_t *const bitmap, const size_t bit)
{
    if(bitmap == NULL || bit < 0) return false;
    size_t byte_index, bit_index;
    byte_index = bit/8;
    bit_index = bit%8;
    return (bitmap->data[byte_index] >> bit_index) & 1;

}
/// Find the first set bit
/// \param bitmap The bitmap
/// \return The first one bit address, SIZE_MAX on error/Not found
///
size_t bitmap_ffs(const bitmap_t *const bitmap)
{
    if(bitmap == NULL) return SIZE_MAX;
    size_t byte_index;

    for(size_t bit = 0; bit < bitmap->bit_count; bit++)
    {
        byte_index = bit/8;

        if(bitmap->data[byte_index] & (1 << (bit % 8)))
        {
            return bit;
        }
    }

    return SIZE_MAX;
}
/// Find first zero bit
/// \param bitmap The bitmap
/// \return The first zero bit address, SIZE_MAX on error/Not found
///
size_t bitmap_ffz(const bitmap_t *const bitmap)
{
    if(bitmap == NULL) return SIZE_MAX;
    for(size_t bit = 0; bit < bitmap->bit_count; bit++)
    {
        size_t byte_index = bit / 8;
        if(!(bitmap->data[byte_index] & (1 << (bit % 8))))
        {
            return bit;
        }
    }
    return SIZE_MAX;
}

bool bitmap_destroy(bitmap_t *bitmap)
{
    if(bitmap == NULL) return false;

    free(bitmap->data);
    free(bitmap);
    return true;
}
