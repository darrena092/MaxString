# MaxString

A simple C string utility library.

## Introduction

MaxString was born out of issues that I faced using other C string libraries on embedded devices. Lots of alternative libraries used string headers which seemed to cause some issues freeing allocated memory on the RP2040 specifically. I decided to put together several string manipulation functions instead of using an off-the-shelf solution, and figured I should offer them here for others to use.

## Docs

### Concatenating strings

```
const char* a = "The quick brown fox ";
const char* b = "jumps over the lazy dog!";

char* cat = mstrcat(a, b);

printf("mstrcat() - Output: %s\n", cat);
```

### Trimming strings

```
const char *input = "..--Trim Me--..";
char* output = mstrtrim(input, "-.");

printf("mstrtrim() - Output: %s\n", output);
```

### Creating substrings

```
const char *input = "The quick brown fox jumps over the lazy dog";
char *output = mstrsubstr(input, 4, 5);

printf("mstrsubstr() - Output: %s\n", output);
```

### Replacing characters

```
const char *input = "The;quick;brown;fox;jumps;over;the;lazy;dog";
char *output = mstrreplace(input, ';', ' ');

printf("mstrreplace() - Output: %s\n", output);
```

### Removing characters

```
const char *input = "The. quick. brown. fox. jumps. over. the. lazy. dog";
char *output = mstrremove(input, '.');

printf("mstrremove() - Output: %s\n", output);
```

### Splitting strings by a delimiter

```
int token_count = 0;
const char *input = "The;quick;brown;fox";
char** output = mstrsplit(input, ';', &token_count);

printf("mstrsplit() - Output: %d\n", token_count);

for (int i = 0; i < token_count; i++) {
    printf("mstrsplit() - Token %d: %s\n", i, output[i]);
}
```

### Other important things to note

MaxString allocates new buffers for everything and does not modify input strings, you're responsible for freeing anything returned by this library.

## Acknowledgments

Initially I was using SDS, and this was designed to be a (not quite drop-in) replacement for that in a project I was working on. So there's a lot of influence in here from that project, see: [SDS Github](https://github.com/antirez/sds)
