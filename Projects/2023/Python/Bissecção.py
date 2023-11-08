# Utilizando o método da bissecção, encontre a raiz da função:
# f(x) = Euler^x-x-2
# no intervalo I = [-2,0] e & < 10^-3

EULER = 2.71828
ERRO = 10 ** -3

def f(x):
    calculo = EULER**x - x - 2
    
    return calculo

def verificaSeDeveInterromper(valorAproximado):   
    acao = False
    
    if(valorAproximado < ERRO):
        acao = True
    
    return  acao

contInteracao = True
parar = False
intervalos = []
funcoes = []
valoresAproximados = []
intervaloFinal = []

a, b = -2, 0

while (contInteracao):
    if(parar == True):
        intervaloFinal = intervalo
        contInteracao = False
        continue
    
    x = (a + b) / 2
    
    # Armazena intervalos de uma linha.
    intervalos.append([a, x, b])
    
    resultadoFa = f(a)
    resultadoFx = f(x)
    resultadoFb = f(b)
    
    # Armazena funções de X desta mesma Linha.
    funcoes.append([resultadoFa, resultadoFx, resultadoFb])
    
    if(resultadoFa < 0 and resultadoFx >= 0):
        intervalo = [a , x]
        valorAproximado = x - a 
    elif(resultadoFx < 0 and resultadoFb >= 0):
        intervalo = [x , b]
        valorAproximado = b - x
    elif(resultadoFx < 0 and resultadoFa >= 0):
        intervalo = [a , x]
        valorAproximado = x - a
    elif(resultadoFb < 0 and resultadoFx >= 0):
        intervalo = [x , b]
        valorAproximado = b - x 
    
    a = intervalo[0]
    b = intervalo[1]
    
    # Armazena Valores aproximados desta mesma linha.
    valoresAproximados.append(valorAproximado)
        
    parar = verificaSeDeveInterromper(valorAproximado)

for iteracao in range (0, len(intervalos)):
    print(
        'iteração ',  iteracao, '\n',
        'a: ', intervalos[iteracao][0], '\n',
        'x: ', intervalos[iteracao][1], '\n',
        'b: ', intervalos[iteracao][2], '\n',
        'Fa: ', funcoes[iteracao][0], '\n',
        'Fx: ', funcoes[iteracao][1], '\n',
        'Fb: ', funcoes[iteracao][2], '\n',  
        'valor aprox.: ', valoresAproximados[iteracao],
        '\n\n',
    )
print('Resultado final: ', intervaloFinal)