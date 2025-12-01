link de acesso : https://github.com/matheusj12/FACULDADE/tree/master/bancoDEdados
# 🐾 PetCare+ — Experiência Prática IV  
## Implementação e Manipulação de Dados com SQL


Matheus Julio de Oliveira Gomes
PetCare+ — Sistema de Gerenciamento para Pet Shop

Este repositório contém os scripts SQL desenvolvidos para a **Experiência Prática IV** da disciplina de **Modelagem de Banco de Dados**.

O projeto implementa o minimundo **PetCare+**, um sistema para gerenciamento de um Pet Shop, baseado no modelo lógico elaborado na Experiência Prática III.

---

## 📌 Objetivo da Etapa
A Experiência Prática IV tem como propósito:

- Criar e popular o banco de dados do PetCare+  
- Manipular dados utilizando comandos **INSERT**, **SELECT**, **UPDATE** e **DELETE**  
- Demonstrar compreensão de integridade relacional  
- Registrar tudo em um repositório com versionamento adequado  

---

## 🧱 Estrutura do Repositório

📁 /sql
├── 01_create_tables.sql
├── 02_insert_data.sql
├── 03_select_queries.sql
├── 04_update.sql
└── 05_delete.sql
README.md


---

## 🛠️ Ambiente Utilizado
- MySQL Workbench **ou** PostgreSQL (ambos aceitos)
- Linguagem SQL padrão
- Execução sequencial dos scripts:

1. **01_create_tables.sql**  
2. **02_insert_data.sql**  
3. **03_select_queries.sql**  
4. **04_update.sql**  
5. **05_delete.sql**

---

## 📚 Scripts Incluídos

### ✔ 1. Criação das tabelas  
Arquivo: `01_create_tables.sql`  
Contém as tabelas normalizadas conforme DER final.

### ✔ 2. Inserts de dados  
Arquivo: `02_insert_data.sql`  
Contém pelo menos **20 inserts** entre clientes, pets, serviços, produtos e vendas.

### ✔ 3. SELECTs  
Arquivo: `03_select_queries.sql`  
Contém consultas usando `WHERE`, `JOIN`, `ORDER BY`, `LIMIT`.

### ✔ 4. Updates  
Arquivo: `04_update.sql`  
Pelo menos **3 atualizações**.

### ✔ 5. Deletes  
Arquivo: `05_delete.sql`  
Pelo menos **3 exclusões** com `WHERE`.

---

## 🚀 Como Executar

1. Crie um banco de dados:
```sql
CREATE DATABASE petcare;
USE petcare;
Execute o arquivo 01_create_tables.sql

Em seguida execute:

02_insert_data.sql

03_select_queries.sql

04_update.sql

05_delete.sql



✔ Licença
Uso acadêmico — Universidade.

pgsql
Copiar código

---

# 📦 **Agora os SQL, todos organizados**

---

# 📄 **01_create_tables.sql**
sql
CREATE TABLE Cliente (
    id_cliente INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(80) NOT NULL,
    telefone VARCHAR(20),
    email VARCHAR(120)
);

CREATE TABLE Pet (
    id_pet INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(60) NOT NULL,
    especie VARCHAR(40),
    raca VARCHAR(60),
    id_cliente INT NOT NULL,
    FOREIGN KEY (id_cliente) REFERENCES Cliente(id_cliente)
);

CREATE TABLE Servico (
    id_servico INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(80) NOT NULL,
    valor DECIMAL(10,2) NOT NULL
);

CREATE TABLE Veterinario (
    id_vet INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100),
    crmv VARCHAR(20)
);

CREATE TABLE Agendamento (
    id_agendamento INT PRIMARY KEY AUTO_INCREMENT,
    data DATE NOT NULL,
    horario TIME NOT NULL,
    id_pet INT,
    id_servico INT,
    id_vet INT,
    FOREIGN KEY (id_pet) REFERENCES Pet(id_pet),
    FOREIGN KEY (id_servico) REFERENCES Servico(id_servico),
    FOREIGN KEY (id_vet) REFERENCES Veterinario(id_vet)
);

CREATE TABLE Produto (
    id_produto INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    preco DECIMAL(10,2) NOT NULL,
    estoque INT NOT NULL
);

CREATE TABLE Venda (
    id_venda INT PRIMARY KEY AUTO_INCREMENT,
    data DATE NOT NULL,
    id_cliente INT,
    FOREIGN KEY (id_cliente) REFERENCES Cliente(id_cliente)
);

CREATE TABLE ItemVenda (
    id_item INT PRIMARY KEY AUTO_INCREMENT,
    id_venda INT,
    id_produto INT,
    quantidade INT,
    valor_unit DECIMAL(10,2),
    FOREIGN KEY (id_venda) REFERENCES Venda(id_venda),
    FOREIGN KEY (id_produto) REFERENCES Produto(id_produto)
);

📄 02_insert_data.sql
sql

INSERT INTO Cliente (nome, telefone, email) VALUES
('Carlos Mendes', '62999990000', 'carlos@email.com'),
('Ana Souza', '62988881111', 'ana@email.com'),
('Mariana Lima', '62977772222', 'mariana@email.com');

INSERT INTO Pet (nome, especie, raca, id_cliente) VALUES
('Rex', 'Cachorro', 'Labrador', 1),
('Luna', 'Gato', 'Persa', 2),
('Thor', 'Cachorro', 'Poodle', 3);

INSERT INTO Servico (nome, valor) VALUES
('Banho', 40.00),
('Tosa', 55.00),
('Consulta Veterinária', 120.00);

INSERT INTO Veterinario (nome, crmv) VALUES
('Dr. João Silva', 'CRMV12345'),
('Dra. Paula Ramos', 'CRMV99887');

INSERT INTO Agendamento (data, horario, id_pet, id_servico, id_vet) VALUES
('2025-12-10', '14:00:00', 1, 1, 1),
('2025-12-12', '09:00:00', 2, 3, 2);

INSERT INTO Produto (nome, preco, estoque) VALUES
('Ração Premium 5kg', 89.90, 30),
('Coleira Ajustável', 29.90, 50),
('Shampoo Pet', 19.90, 40);

INSERT INTO Venda (data, id_cliente) VALUES
('2025-12-01', 1),
('2025-12-02', 2);

INSERT INTO ItemVenda (id_venda, id_produto, quantidade, valor_unit) VALUES
(1, 1, 1, 89.90),
(1, 2, 1, 29.90),
(2, 3, 2, 19.90);
📄 03_select_queries.sql


-- Listar todos os clientes
SELECT * FROM Cliente;

-- Pets com seus donos
SELECT Pet.nome AS pet, Cliente.nome AS dono
FROM Pet
JOIN Cliente ON Pet.id_cliente = Cliente.id_cliente;

-- Serviços agendados com data e veterinário
SELECT A.data, S.nome AS servico, V.nome AS veterinario
FROM Agendamento A
JOIN Servico S ON A.id_servico = S.id_servico
JOIN Veterinario V ON A.id_vet = V.id_vet
ORDER BY A.data;

-- Produtos com baixo estoque
SELECT * FROM Produto
WHERE estoque < 20;

-- Itens de venda com JOIN completo
SELECT Venda.id_venda, Cliente.nome, Produto.nome, ItemVenda.quantidade
FROM ItemVenda
JOIN Venda ON ItemVenda.id_venda = Venda.id_venda
JOIN Cliente ON Venda.id_cliente = Cliente.id_cliente
JOIN Produto ON ItemVenda.id_produto = Produto.id_produto;
📄 04_update.sql
sql
Copiar código
UPDATE Produto SET estoque = estoque - 1 WHERE id_produto = 1;
UPDATE Cliente SET telefone = '62990001234' WHERE id_cliente = 3;
UPDATE Veterinario SET crmv = 'CRMV12300' WHERE id_vet = 1;
📄 05_delete.sql
sql
Copiar código
DELETE FROM ItemVenda WHERE id_item = 3;
DELETE FROM Agendamento WHERE id_agendamento = 1;
DELETE FROM Produto WHERE id_produto = 2;
