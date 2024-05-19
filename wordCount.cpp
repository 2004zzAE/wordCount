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
    int inWord = 0; // ����Ƿ����ڶ�ȡ����  
  
    char ch;  
    while ((ch = fgetc(file)) != EOF) {  
        charCount++; // ÿ����ȡ���ַ��������ַ���  
  
        if (isspace(ch) || ch == ',') {  
            // �����ǰ�ַ��ǿո��Ʊ�������з��򶺺�  
            if (inWord) {  
                // ���֮ǰ���ڶ�ȡ���ʣ��򵥴ʽ�����������һ  
                wordCount++;  
                inWord = 0; // ���Ϊ���ڵ�����  
            }  
        } else {  
            // �����ǰ�ַ����Ƿָ���������Ϊ���ڶ�ȡ����  
            inWord = 1;  
        }  
    }  
  
    // ����ļ�ĩβ�Ƿ���һ��δ��ɵĵ���  
    if (inWord) {  
        wordCount++;  
    }  
  
    printf("�ַ���: %d\n", charCount);  
    printf("������: %d\n", wordCount);  
  
    fclose(file);  
    return 0;  
}
