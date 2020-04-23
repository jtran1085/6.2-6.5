#include <stdio.h>
#include "tree.h"
#include "utils.h"
#include <string.h>
#include <stdbool.h>
#include "hashtable.h"
int main(int argc, const char* argv[]) {
  

  tree* t = tree_from_file(argc, argv);
  if (t == NULL){
    t = tree_from_stream(fgets, stdin);
  }
  //6.2 && 6.3
  tree_test(t); 
  tree_delete(t);

  //6.5
  
  printf("\n\n\n==========|UNDEF TEST|============\n");

  undef_test();
  printf("==========|END UNDEF TEST|============\n");
  


  return 0;
}
