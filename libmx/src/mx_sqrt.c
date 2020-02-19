#include "libmx.h"

int mx_sqrt(int x){
  int i = 0;
  int j = x/ 2 + 1;
  int temp;
    while(i<=j){
      temp = i + (j-i) / 2;
      ((temp * temp > x || temp > 46430) ? (j = temp - 1) : (i = temp + 1));
      if(temp*temp == x)
        return temp;
    }
    return 0;
}
