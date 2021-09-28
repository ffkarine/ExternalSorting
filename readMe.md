Programa desenvolvido para o CCH(Complemento de Carga Hor�ria) da disciplina de Pesquisa e Ordena��o de Dados.
Curso de Engenharia de Computa��o.
UTFPR(Universidade Tecnol�gica Federal do Paran�) c�mpus Toledo. 
2018/1.

-----------------------------------------------------------------------------------------------------------------------
			
			#	Algor�timo de Ordena��o Externa

Notas:
* A entrada deve ser feita atrav�s de um arquivo chamado "entrada.txt" e os n�meros separados por espa�os.
A sa�da contendo a entrada ordenada ocorrer� atrav�s de um arquivo chamado "saida.txt", com os elementos separados por espa�os.

* O programa foi implementado tendo como base uma pilha de 100 elementos. 
Para trocar, basta alterar O #define MEM_MAX no "div-merge.h" colocando-se o valor desejado. 
OBS: Note que nem sempre ser� poss�vel ordenar uma quantia de n�meros com uma pilha de tamanho N, 
pois deve-se respeitar o seguinte c�lculo: 

P� = N�max. elementos, ou
sqrt(N�elementos) = P.m�nimo,  onde P � o tamanho da pilha

Ou seja, para uma pilha de tamanho 100, o n�mero m�ximo de elementos constando na entrada deve ser de 10000.
Em outras palavras, o tamanho m�nimo de sua pilha deve ser igual � raiz quadrada da quantidade de elementos
(Em caso de decimais o teto do seu valor).

-----------------------------------------------------------------------------------------------------------------------



