# Restaurant Hours

![Badge License](https://img.shields.io/github/license/IgorGrandin/restaurant_hours)
![Badge issues](https://img.shields.io/github/issues/IgorGrandin/restaurant_hours)

## Índice 

  - [Descrição do Projeto](#descrição-do-projeto)
  - [Status do Projeto](#status-do-projeto)
  - [Funcionalidades](#funcionalidades)
  - [Aplicação](#aplicação)
  - [Ferramentas Utilizadas](#ferramentas-utilizadas)
  - [Acesso ao Projeto](#acesso-ao-projeto)
  - [Testes Unitários](#testes-unitários)
  - [Abrir e Rodar o Projeto](#abrir-e-rodar-o-projeto)
  - [Desenvolvedor](#desenvolvedor)

## Descrição do Projeto
<p align="justify">
 Projeto desenvolvido em C++ e QML utilizando o Framework Qt 5.15.0.<br>
 Permite filtrar uma lista de restaurantes fornecida por um arquivo .csv, a partir da comparação entre seus horários de abertura e fechamento e do horário desejado pelo usuário.<br>
 Tanto a inserção do horário a ser filtrado, quanto a lista retornada são gerenciadas via Interface Gráfica.
</p>

## Status do Projeto
<h4 align="center"> 
    :construction:  Projeto em construção  :construction:
</h4>

## Funcionalidades
:heavy_check_mark: `Funcionalidade 1:` Abrir e estruturar um arquivo .csv.

:heavy_check_mark: `Funcionalidade 2:` Exibir Interface Gráfica para inserção de filtro e exibição de resultados.

:heavy_check_mark: `Funcionalidade 3:` Filtrar lista de restaurantes comparando seus horários de funcionamento com o horário inserido.

:heavy_check_mark: `Funcionalidade 4:` Exibir lista com nomes e horários de funcionamento dos restaurantes filtrados.

## Aplicação
![](https://github.com/IgorGrandin/restaurant_hours/blob/master/restaurant_hours.gif)


### Funcionamento:
Após o [processo de instalação](#abrir-e-rodar-o-projeto), a Interface Gráfica ficará disponível em sua tela, contendo os seguintes elementos:



### Métodos:
 
 ```c++
 QStringList availableHours();
 ```

Método responsável por retornar um Lista de Strings contendo as informações dos restaurantes filtrados.<br>
 Na Interface Gráfica, o retorno dessa função será exibido na `ScrollView` e atualizado sempre que o Método `void availableHoursChanged();` for notificado por alguma mudança do Método `void setAvailableHours(QStringList resName);`.

 ```c++
 void setAvailableHours(QStringList resName);
 ```

Método responsável por receber uma Lista de Strings contendo os horários desejados para futura filtragem.<br>
Como a aplicação QML só permite a inserção de um horário, a lista sempre terá apenas uma posição, mas foi implementado dessa forma para ter autonomia de notificar o Método `void availableHoursChanged();` e permitir o retorno do Método `QStringList availableHours();` como sendo uma Lista de Strings.

 ```c++
 void availableHoursChanged();
 ```

Método responsável por monitorar as alterações realizadas pelo Método `void setAvailableHours(QStringList resName);` e notificar todos os objetos que utilizam o retorno do Método `QStringList availableHours();` para que atualizem seus valores.



## Ferramentas Utilizadas
<a href="https://www.qt.io/" target="_blank"> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/0b/Qt_logo_2016.svg/1280px-Qt_logo_2016.svg.png" alt="qt" width="40" height="35"/> </a> <br>
<a href="https://cplusplus.com/" target="_blank"> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/1822px-ISO_C%2B%2B_Logo.svg.png" alt="c++" width="40" height="40"/> </a> <a href="https://doc.qt.io/qt-6/qtqml-index.html" target="_blank"> <img src="https://s3-eu-west-1.amazonaws.com/qt-showroom/uploads/2014/08/qml_creator_icon512-300x300.png" alt="qml" width="40" height="40"/> </a> 

## Acesso ao Projeto
Você pode [acessar o código fonte do projeto](https://github.com/igorgrandin/restaurant_hours).

## Testes Unitários
Caso deseje, os Testes Unitários podem ser encontrados [aqui](https://github.com/igorgrandin/test_restaurant).

## Abrir e Rodar o Projeto
Após baixar o projeto, abra o `Qt Creator`. Na tela inicial clique em:

- `Open File or Project`;
- Procure o local onde o projeto está e o selecione (Caso o projeto seja baixado via zip, é necessário extraí-lo antes de procurá-lo);
- Execute o projeto clicando em `Run`.

O `Qt Creator` deve executar algumas etapas de configuração do projeto e, ao finalizá-las, o app já estará rodando em sua tela. 🏆 

## Desenvolvedor
| [<img src="https://avatars.githubusercontent.com/u/71189062?v=4" width=115><br><sub>Igor Grandin</sub>](https://github.com/igorgrandin) |
| :---: 
