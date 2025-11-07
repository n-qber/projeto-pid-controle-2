# PID line follower


## Contexto
the goal of the project is to implement a PID malha de controle, de um carro seguidor de linha


### Estruturação do código

*IMPORTANTE* o código é estruturado em SERVIÇOS, cada SERVIÇO representa uma CLASSE
*IMPORTANTE* TODA CLASSE TEM UM ARQUIVO CORRESPONDENTE CLASSE.H E CLASSE.CPP

Para todo arquivo.h é necessário flags para evitar dupla inclusão exemplo:

```
#ifndef HEADERFILE_H
#define HEADERFILE_H


... código aqui ...


#endif
```


## Descrição do código
Cada Serviço (representado por uma CLASSE), contará com poucos ou nenhum atributo privado nem público
*IMPORTANTE* NÃO GERAR CONSTRUTORES PARA OS SERVICOS APENAS QUANDO ESTRITAMENTE NECESSÁRIO

*IMPORTANTE* Os nomes de funções devem ser INFORMATIVOS e SUCINTOS: exemplo

```
// Função que funde os erros
void merge_errors()
```

SEMPRE COMENTE O CÓDIGO, O QUE UMA FUNÇÃO FAZ E QUAL A LÓGICA IMPLEMENTADA CASO HAJA



## Informações
*O CÓDIGO CONTARÁ COM UM ARQUIVO DE VARIÁVEIS GLOBAIS* NENHUMA CLASSE (RARAMENTE) DEVERÁ TER ATRIBUTOS PRÓPRIOS




## Obtenção de informações
*IMPORTANTE* não é necessário se preocupar em COMO um dado valor é obtido para uma variável global, ASSUMA QUE OS VALORES ESTARÃO SEMPRE CORRETOS, A NÃO SER EM CASOS ESPECÍFICOS COMO ENTRADA DE USUÁRIO EXPLÍCITA E ESPECIFICADA



## IDIOMA
Produza o código em INGLÊS


# Documentação
É de suma importância que na geração de documentação haja uma estrutura explicando a:
1. Finalidade do serviço
2. Finalidade dos métodos do serviço
2.1 Explicação de quais variáveis são utilizadas (lidas e atualizadas)
2.2 Como funciona o método
3. O que se assume sobre as variáveis utilizadas e a finalidade das atualizadas


### Contexto de projeto
Há dois erros que serão obtidos, cada um deverá ter sua variável global
1. erro em ângulo
2. erro em distância



# Majoritários
os Majoritários são serviçoes que cuidam de serviços menores e mais específicos. o projeto conta com 3 Majoritários
1. ServiceAwake (responsável pelos servicoes de inicialização de variáveis globais, entradas e referencia)
2. ServiceSafety (responsável pelo service de intertravamento)
3. ServiceOperation (responsável pela malha de controle que inclui receber os erros calcular erros de entrada, fundir os erros, o cálculo do PID, e envio para as rodas (fazer o carro andar))

*IMPORTANTE* NOTE QUE OS MAJORITÁRIOS CHAMAM OUTROS SERVIÇOS, E TAMBÉM É UM SERVIÇO


# Escalonador
um ServiceScheduler será a classe PRINCIPAL DO CÓDIGO, que irá chamar cada majoriário (ServiceAwake, ServiceSafety e ServiceOperation), de acordo
