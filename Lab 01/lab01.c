#include <stdio.h>
 
long long int calculaTotalAte(long long int numero) {
    long long int resultado = 0;
    long long int potencia = 1;
    
    while (numero >= potencia) {
        long long int blocos = numero / (potencia * 2);
        resultado += blocos * potencia;
        
        long long int sobra = numero % (potencia * 2);
        if (sobra >= potencia) {
            resultado += sobra - potencia + 1;
        }
        
        potencia *= 2;
    }
    
    return resultado;
}
 
int main() {
    long long int x, y;
    
    scanf("%lld %lld", &x, &y);
    
    printf("%lld\n", calculaTotalAte(y) - calculaTotalAte(x - 1));
    
    return 0;
}