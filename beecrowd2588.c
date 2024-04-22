#include <stdio.h>
#include <string.h>

int minPalindrome(char s[1001]);

int main(){
  char string[1001];
  
  while (scanf("%s", string) != EOF){
    printf("%d\n", minPalindrome(string));
  }
  
  return 0;
}

int minPalindrome(char s[1001]){
  int freq[26] = {0};
  
  for (int i = 0; i < strlen(s); i++){
    freq[s[i] - 'a']++;
  }
  
  int oddCount = 0; 
  
  for (int i = 0; i < 26; i++){
    if (freq[i] % 2 != 0){
      oddCount++;
    }
  }
  
  int minLetters;
  if (oddCount > 1){
    minLetters = oddCount - 1;
  }else{
    minLetters = 0;
  }
  
  return minLetters;
}
