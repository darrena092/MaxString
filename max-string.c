#include "max-string.h"
#include <string.h>
#include <malloc.h>
#include <assert.h>

/**
 * Concatenates two strings into a new buffer and returns a pointer to it.
 * Will create a new buffer, and not modify the inputs.
 *
 * @param a The first string.
 * @param b The second string.
 * @return A pointer to the concatenated string buffer.
 */
char* mstrcat(const char* a, const char *b) {
    size_t strlen_a = strlen(a);
    size_t strlen_b = strlen(b);
    char* ret = malloc(strlen_a + strlen_b + 1);

    memcpy(ret, a, strlen_a);
    memcpy((ret + strlen_a), b, strlen_b);

    ret[strlen_a + strlen_b] = '\0';

    return ret;
}

/**
 * Trims any occurrences of characters in the trim_set param at the start and end of a string.
 * Will create a new buffer, and not modify the input.
 *
 * @param input The input string.
 * @param trim_set The character set to trim.
 * @return A pointer to the buffer containing the trimmed string.
 */
char* mstrtrim(const char* input, const char* trim_set) {
    char* ret = malloc(strlen(input) + 1);
    strcpy(ret, input);

    char* start = ret;
    char* end = ret + strlen(ret) - 1;

    while (start <= end && strchr(trim_set, *start)) start++;
    while (end > start && strchr(trim_set, *end)) end--;

    size_t len = (start > end) ? 0 : ((end - start) + 1);
    if (ret != start) memmove(ret, start, len);

    ret[len] = '\0';

    return ret;
}

/**
 * Selects a substring from the input at the specified offset for the specified length.
 * Will return a new buffer and not modify the input.
 *
 * @param input Input string to select from.
 * @param offset The offset.
 * @param length The length of the substring.
 * @return A pointer to the new buffer containing the substring.
 */
char* mstrsubstr(const char *input, int offset, size_t length) {
    assert(strlen(input) >= (offset + length));
    char* ret = malloc(length + 1);

    memcpy(ret, (input + offset), length);
    ret[length] = '\0';

    return ret;
}

/**
 * Replaces a specified character with a specified replacement in a string.
 * Will return a new buffer and not modify the input.
 *
 * @param input The input string to use.
 * @param find The character to find.
 * @param replace The character to replace it with.
 * @return A pointer to the new buffer containing the modified string.
 */
char* mstrreplace(const char *input, char find, char replace) {
    char* ret = malloc(strlen(input) + 1);
    memcpy(ret, input, strlen(input) + 1);

    char* current_pos = strchr(ret, find);

    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos, find);
    }

    return ret;
}

/**
 * Remove a specified character from a string.
 * Will return a new buffer and not modify the input.
 *
 * @param input The input string to use.
 * @param garbage The character to remove.
 * @return A pointer to the new buffer containing the modified string.
 */
char* mstrremove(const char *input, char garbage) {
    char* ret = malloc(strlen(input) + 1);
    memcpy(ret, input, strlen(input) + 1);

    char *src, *dst;
    for (src = dst = ret; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage)
            dst++;
    }
    *dst = '\0';

    return ret;
}

/**
 * Splits a string into multiple substrings based on a delimiter.
 *
 * @param input The input string to use.
 * @param delimiter The delimiter to split the string at.
 * @param token_count The integer to update with the token count.
 * @return An array of strings.
 */
char** mstrsplit(const char *input, char delimiter, int* token_count) {
    const char* start = input;
    char* current_pos = strchr(input, delimiter);
    char** ret = malloc(sizeof(char*));

    int i = 0;
    while (current_pos) {
        ret = realloc(ret, sizeof(char*) * (i + 1));
        ret[i] = mstrsubstr(start, 0, (current_pos - start));
        start = current_pos + 1;
        current_pos = strchr(start, delimiter);
        i++;
    }

    if (start < (input + strlen(input))) {
        // Add the rest of the string
        ret = realloc(ret, sizeof(char*) * (i + 1));
        ret[i++] = mstrsubstr(start, 0, (input + strlen(input)) - start);
    }

    *token_count = i;

    return ret;
}