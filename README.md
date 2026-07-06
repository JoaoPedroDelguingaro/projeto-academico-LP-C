# Sistema de Gerenciamento de Produtos em C

## 📖 Sobre o projeto

Este projeto consiste em um sistema de gerenciamento de produtos desenvolvido em linguagem C como atividade acadêmica da disciplina de Linguagem de Programação.

O sistema utiliza uma **lista encadeada dinâmica** para armazenar os produtos durante a execução e **arquivos binários** para persistir os dados entre diferentes execuções do programa.

---

## 🎯 Objetivos

- Aplicar os conceitos de estruturas (`struct`);
- Utilizar alocação dinâmica de memória;
- Implementar listas encadeadas;
- Realizar leitura e gravação em arquivos binários;
- Desenvolver um sistema de cadastro utilizando menus em terminal.

---

## ⚙️ Funcionalidades

- ✅ Cadastro de produtos
- ✅ Listagem de produtos
- ✅ Exclusão de produtos por código
- ✅ Geração automática do código dos produtos
- ✅ Persistência dos dados em arquivo binário (`produtos.bin`)
- ✅ Carregamento automático dos produtos ao iniciar o sistema

---

## 🛠️ Tecnologias utilizadas

- Linguagem C
- GCC
- Biblioteca padrão da linguagem C
  - `stdio.h`
  - `stdlib.h`
  - `string.h`

---

## 📂 Estrutura do projeto

```text
projeto-academico-LP-C/
│
├── main.c
├── produtos.bin      # Gerado automaticamente pelo sistema
└── README.md
```

---

## ▶️ Como compilar

Utilizando o GCC:

```bash
gcc main.c -o sistema
```

---

## ▶️ Como executar

### Windows

```bash
sistema.exe
```

### Linux/macOS

```bash
./sistema
```

---

## 📋 Menu do sistema

```text
**** Menu de Cadastros ****

1 - Listar Produtos
2 - Adicionar Produtos
3 - Excluir Produtos
0 - Sair
```

---

## 💾 Persistência dos dados

Todos os produtos cadastrados são armazenados no arquivo:

```text
produtos.bin
```

Ao iniciar o programa, esse arquivo é lido automaticamente. Ao encerrar o sistema, todos os dados presentes na lista encadeada são gravados novamente no arquivo, garantindo que as informações sejam preservadas.

---

## 🧩 Estruturas de dados utilizadas

### Produto

Cada produto possui:

- Código
- Nome
- Quantidade
- Preço unitário

### Lista Encadeada

Os produtos são armazenados em uma lista simplesmente encadeada, permitindo:

- Inserção dinâmica;
- Remoção de elementos;
- Percurso para listagem;
- Gerenciamento eficiente da memória.

---

## 📚 Conceitos aplicados

- Structs
- Ponteiros
- Alocação dinâmica (`malloc` e `free`)
- Recursão
- Listas encadeadas
- Manipulação de arquivos binários (`fopen`, `fread`, `fwrite`)
- Modularização com funções
- Manipulação de strings

---

## 👨‍💻 Autor

**João Pedro Delguingaro de Oliveira**

---

## 📄 Licença

Este projeto foi desenvolvido exclusivamente para fins acadêmicos e educacionais.
