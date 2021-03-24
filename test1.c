
// gcc -o test1 test1.c
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  // 用來管理動態記憶體的指標
  int *dynArr;
  char key1,key2;
  // 指定空間大小
  int32_t arrLen = 250000000;  //about 1G byte

  // 取得記憶體空間
  dynArr = malloc( arrLen * sizeof(int32_t) );

  if( dynArr == NULL ) {
    // 無法取得記憶體空間
    fprintf(stderr, "Error: unable to allocate required memory\n");
    return 1;
  }

  // 使用動態取得的記憶體空間
  int32_t i;
  for (i = 0; i < arrLen; ++i) {
    dynArr[i] = 0x55;
    //printf("%d ", dynArr[i]);
  }
  printf(" Press key to free memory or c enter --> do not free and exit ....\n");
  key1 = getchar();
  key2 = getchar();
  
  if (key1 != 'c') 
  {
	// 釋放記憶體空間
	free(dynArr);
	printf("memory released!");
  }
  else
  {
	printf("memory do not release and exit!");	
  }
  return 0;
}