#include <stdio.h>  
#include <ctype.h>  
  
#define IN_FILE "input.txt"  
  
int main() {  
    FILE *file = fopen(IN_FILE, "r");  
    if (file == NULL) {  
        printf("Cannot open file %s\n", IN_FILE);  
        return 1;  
    }  
  
    int charCount = 0;  
    int wordCount = 0;  
    int inWord = 0; // 标记是否正在读取单词  
  
    char ch;  
    while ((ch = fgetc(file)) != EOF) {  
        charCount++; // 每个读取的字符都计入字符数  
  
        if (isspace(ch) || ch == ',') {  
            // 如果当前字符是空格、制表符、换行符或逗号  
            if (inWord) {  
                // 如果之前正在读取单词，则单词结束，计数加一  
                wordCount++;  
                inWord = 0; // 标记为不在单词中  
            }  
        } else {  
            // 如果当前字符不是分隔符，则标记为正在读取单词  
            inWord = 1;  
        }  
    }  
  
    // 检查文件末尾是否有一个未完成的单词  
    if (inWord) {  
        wordCount++;  
    }  
  
    printf("字符数: %d\n", charCount);  
    printf("单词数: %d\n", wordCount);  
  
    fclose(file);  
    return 0;  
}
