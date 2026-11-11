
#include <stdio.h>

int main() {
    char str[50];
    char res, arg1, op, arg2;
    int n, i;

    printf("Enter number of statements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter three address code: ");
        scanf("%s", str);

        if (sscanf(str, "%c=%c%c%c", &res, &arg1, &op, &arg2) == 4) {

            printf("\nMOV R0,%c\n", arg1);

            switch (op) {
                case '+': printf("ADD R0,%c\n", arg2); break;
                case '-': printf("SUB R0,%c\n", arg2); break;
                case '*': printf("MUL R0,%c\n", arg2); break;
                case '/': printf("DIV R0,%c\n", arg2); break;
                default:
                    printf("Unknown operator\n");
                    continue;
            }

            printf("MOV %c,R0\n", res);
        }
        else {
            printf("Invalid statement\n");
        }
    }

    return 0;
}
