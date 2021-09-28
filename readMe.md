Programa desenvolvido para o CCH(Complemento de Carga Horária) da disciplina de Pesquisa e Ordenação de Dados.

Curso de Engenharia de Computação.

UTFPR(Universidade Tecnológica Federal do Paraná) câmpus Toledo.

2018/1.

-----------------------------------------------------------------------------------------------------------------------
			
# Algorítimo de Ordenação Externa

Notas:
* A entrada deve ser feita através de um arquivo chamado "entrada.txt" e os números separados por espaços.
A saída contendo a entrada ordenada ocorrerá através de um arquivo chamado "saida.txt", com os elementos separados por espaços.

* O programa foi implementado tendo como base uma pilha de 100 elementos. 
Para trocar, basta alterar O #define MEM_MAX no "div-merge.h" colocando-se o valor desejado. 
OBS: Note que nem sempre será possível ordenar uma quantia de números com uma pilha de tamanho N, 
pois deve-se respeitar o seguinte cálculo: 

P² = Nºmax. elementos, ou
sqrt(Nºelementos) = P.mínimo,  onde P é o tamanho da pilha

Ou seja, para uma pilha de tamanho 100, o número máximo de elementos constando na entrada deve ser de 10000.
Em outras palavras, o tamanho mínimo de sua pilha deve ser igual à raiz quadrada da quantidade de elementos
(Em caso de decimais o teto do seu valor).

-----------------------------------------------------------------------------------------------------------------------



