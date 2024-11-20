#include <stdio.h>
#include <stdint.h>

typedef char* p_char;
// 打印32位二进制表示
void printBinary(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    p_char p;
    int32_t num;
    printf("请输入一个整数: ");
    scanf("%d", &num);

    // 32位原码
    printf("原码: ");
    printBinary((uint32_t)num);

    // 32位反码
    printf("反码: ");
    printBinary(~(uint32_t)num);

    // 32位补码
    printf("补码: ");
    printBinary((uint32_t)(~num + 1));

    return 0;
}