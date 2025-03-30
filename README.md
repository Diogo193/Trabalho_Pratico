# Trabalho Prático

Licenciatura em Engenharia de Sistemas Informáticos 2024-25

Laboratórios de Informática 

Desenvolvedor: Diogo Malheiro Rocha nº 29339

## organização

[src/](./src/)  Código da solução desenvolvida 
[doxdoc/](./doxdoc/)  documentação com o relatórioi gerado pela ferramenta Doxygen
[doc/](./doc/)  documentação com o relatório

## Principais Comandos Utilizados

### 1. Criação do documento Doxyfile para documentação do código

```[bash]
doxygen ./doxdoc/Doxyfile
```
### 2. Comandos para Controle de Versão (Git)

1. **Clonar o Repositório**  
   Para obter uma cópia local do repositório:
   ```[bash]
   git clone https://github.com/utilizador/tp-16.git
   ```
2. **Verificar o estado do repositório**
    Para verificar o status dos arquivos (modificados, adicionados, não rastreados):
    ```[bash]
    git status
    ```
3. **Adicionar Arquivos ao Controle de Versão**
    Para adicionar arquivos específicos:
    ```[bash]
    git add nome_do_arquivo
    ```
4. **Registrar Alterações no Histórico (Commit)**
    Para criar um commit com uma mensagem descritiva:
    ```[bash]
    git commit -m "Mensagem descritiva do que foi feito"
    ```
5. **Enviar Alterações para o Repositório Remoto**
    Para sincronizar as alterações locais com o repositório remoto:
    ```[bash]
    git push origin main
    ```
6. **Atualizar a Cópia Local com Alterações do Repositório Remoto**
    Para obter as últimas alterações do repositório remoto:
    ```[bash]
    git pull origin main
    ```
7. **Criar e Alternar Entre Ramificações (Branches)**
    Para criar uma nova ramificação:
    ```[bash]
    git branch nome_da_branch
    ```
    Para alternar para outra ramificação:
    ```[bash]
    git checkout nome_da_branch
    ```
    Ou, para criar e alternar ao mesmo tempo:
    ```[bash]
    git checkout -b nome_da_branch
    ```

## Conclusão

O sistema foi desenvolvido com sucesso e todas as funcionalidades foram implementadas conforme o esperado. Durante o desenvolvimento, enfrentamos alguns desafios na implementação das listas, mas conseguimos resolvê-los através de pesquisa e testes. 
