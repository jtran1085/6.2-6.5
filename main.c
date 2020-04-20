#include <stdio.h>
#include "tree.h"
#include "utils.h"
#include <string.h>
#include <stdbool.h>
#include "hashtable.h"
int main(int argc, const char* argv[]) {
  
  //6.2 attempt

//wordFreq(argc,argv);


  //6.3  
  tree* t = tree_from_file(argc, argv);
  if (t != NULL) { tree_test(t);  tree_delete(t);  return 0; }
  
  char buf[BUFSIZ];
  char delims[] = " .,;?!\'\"()\n";
  int size = 0;
  int line = 0;
  memset(buf, 0, sizeof(buf));
  

  t = tree_create();
  while (fgets(buf, BUFSIZ, stdin)) {
    char* word = strtok(buf, delims);
    if(word == NULL) line++;
    if(isNoise(word)==0){
    tree_add(t, word);
    ++size;}
    while ((word = strtok(NULL, delims)) != NULL) {
      if(isNoise(word)==0){
      tree_add(t, word);
      ++size;
      }
    }
  }
  printf("%d words added...\n", size);

  tree_test(t);
  tree_delete(t);

  //6.5
  
  printf("\n\n\n==========|UNDEF TEST|============\n");

  undef_test();
  printf("==========|END UNDEF TEST|============\n");
  


  return 0;
}
