/*
 * qsort usage
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct dict Dict;
struct dict {
  char *str;
  int num;
};

int
comp_int(const void *p1, const void *p2)
{
  int *i1 = (int *)p1;
  int *i2 = (int *)p2;

  return (*i1 - *i2);
}

int
comp_str(const void *i1, const void *i2)
{
  char **p1 = (char **)i1;
  char **p2 = (char **)i2;

  return (strcmp(*p1, *p2));
}

int
comp_dict_int(const void *p1, const void *p2)
{
  Dict **i1 = (Dict **)p1;
  Dict **i2 = (Dict **)p2;

  return ((*i1)->num - (*i2)->num);
}

int
comp_dict_int_str(const void *p1, const void *p2)
{
  Dict **i1 = (Dict **)p1;
  Dict **i2 = (Dict **)p2;

  return ((*i1)->num - (*i2)->num);
}

int
main(int argc, char *argv[])
{
  int nums[] = {1, 3, 2, 5, 4};
  char *strs[] = {"hello", "world", "I love you", "You love me", "Hello World"};
  int i;
  int num_nums = sizeof (nums)/sizeof (int);
  int num_strs = sizeof (strs)/sizeof (char *);

  Dict **d;
  Dict dict[] = {
    {"hello world", 7},
    {"i love you",  117},
    {"you love me", 117},
    {"abc",         11},
    {"lmn",         11},
    {"xyz",       11}};
  int num_dict = sizeof (dict)/sizeof (Dict);
    

  for (i = 0; i < sizeof (nums)/sizeof (int); i++)
    printf("nums[%d] = %d\n", i, nums[i]);

  printf("\n");
  for (i = 0; i < sizeof (strs)/sizeof (char *); i++)
    printf("strs[%d] = '%s'\n", i, strs[i]);

  printf("\n");
  printf("SORT nums and strs\n");
  qsort(nums, num_nums, sizeof (int), comp_int);

  for (i = 0; i < sizeof (nums)/sizeof (int); i++)
    printf("nums[%d] = %d\n", i, nums[i]);
  qsort(strs, num_strs, sizeof (char *), comp_str);

  printf("\n");
  for (i = 0; i < sizeof (strs)/sizeof (char *); i++)
    printf("strs[%d] = '%s'\n", i, strs[i]);

  printf("Num of dicts = %d\n", num_dict);
  d = (Dict **) malloc(num_dict * sizeof (Dict *));
  for (i = 0; i < num_dict; i++)
    d[i] = &dict[i];
  for (i = 0; i < num_dict; i++)
    printf(" Dict[%d]: num = %4d, str = '%s'\n", i, d[i]->num, d[i]->str);

  printf("Sort Dicts: numbers\n");
  qsort(d, num_dict, sizeof (Dict *), comp_dict_int);
  for (i = 0; i < num_dict; i++)
    printf(" Dict[%d]: num = %4d, str = '%s'\n", i, d[i]->num, d[i]->str);
}
