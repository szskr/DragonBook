/*
 * Program Contest- Algorithm and Data Structures
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#define ERROR -1
#define OK    0
#define TRUE  1
#define FALSE 0

int d_flag;

typedef long long llong;

#define LOG10_3 0.4771

#define swap(type, x, y) {type _t_; _t_ = x; x = y; y = _t_;}

int compute_shell_strides(int **, int);
int partition(int *, int, int);
void d_printf(char *, ...);
