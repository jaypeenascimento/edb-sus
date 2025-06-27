# edb-sus

Projeto final para a disciplina EDB do Bacharelado em TI - IMD 2025.01

## Como funciona?

### Fluxo

- Temos inicialmente uma lista de pacientes, que são lidos de um arquivo de entrada.
- Eles são alocados em um repositório de pacientes e posteriormente, através de
  um sorteio, movidos para uma fila de espera.
- Na fila de espera, eles aguardam para poderem ir ao atendimento médico assim
  que uma vaga for aberta.
- Ao sairem do atendimento, eles são movidos para uma fila de alta e são liberados

### Estrutura (TODO: Ajustar informações, inventei umas coisas da minha cabeça)

- Todas essas movimentações podem acontecer simultâneamente, a medida de tempo
  escolhida é o ciclo.
- A cada ciclo diversas movimentações são executadas por diferentes gerenciadores
  seguindo as seguintes regras:
  - Gerenciador do repositório de pacientes:
    - TODO
  - Gerenciador da fila de espera:
    - TODO
  - Gerenciador do(s) leitos/atendimento:
    - TODO
  - Gerenciador da fila de alta:
    - TODO

Todos os gerenciadores possuem uma função "process" que é executada uma vez por ciclo.
A função process de cada gerenciador é responsável por executar as movimentações
de acordo com as regras de negócio definidas para cada um deles.
Inclusive, essa função também é responsável por logar informações pertinentes e
retornar para o caller se houve algum processamento executado ou não.

Abaixo, temos um diagrama que exemplifica a arquitetura do sistema:

![Diagrama que exemplifica a arquitetura do sistema](https://github.com/jaypeenascimento/edb-sus/blob/main/arquitecture-schema.png)

A função process de cada gerenciador é chamada no arquivo `main.c` a cada ciclo,
arquivo esse, que por sua vez, é quem inicializa as estruturas, gerenciadores e
controla os ciclos.

A cada ciclo, o processo principal analisa o retorno dos gerenciadores e caso
todos eles estejam ociosos simultâneamente, o ciclo é finalizado e o programa
é encerrado.

## Estrutura de pastas

O projeto possui um arquivo de entrypoint principal `main.c` na raiz do projeto,
além de uma estrutura de pastas organizadas sua função
Abaixo está a descrição de cada pasta:

- src/
  - Contém os arquivos de código fonte do projeto.
  - managers/
    - Contém os gerenciadores das estruturas, é onde se concentram as regras de negócio.
  - structures/
    - Contém as estruturas de dados utilizadas no projeto. Ex: listas ligadas, deques...
  - extensions/
    - Contém funções de alta reusabilidade, como loggers e leitores de arquivos.
- data/
  - Contém os arquivos de dados utilizados pelo projeto.
  - in/
    - É onde pode-se encontrar os dados de entrada do programa.
  - out/
    - É onde ficam os logs salvos em disco de saída do programa.
