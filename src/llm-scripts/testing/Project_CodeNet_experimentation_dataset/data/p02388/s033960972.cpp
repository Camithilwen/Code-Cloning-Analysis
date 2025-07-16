int main() {
    int a;
    __builtin_scanf("%d", &a);
    __builtin_printf("%d\n", static_cast<int>(__builtin_pow(a, 3)));
}