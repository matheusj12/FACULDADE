Algoritmo "Atividade1_CestaBasica_NomeSobrenome"

Var
   nome_produto: caractere
   preco_anterior, preco_atual: real
   variacao: real
   situacao: caractere

Inicio
   Escreval("--- Analise do Produto ---")
   Escreval("Digite o nome do produto:")
   leia(nome_produto)

   Escreval("Digite o preco no mes anterior (ex: 20.00):")
   leia(preco_anterior)

   Escreval("Digite o preco no mes atual (ex: 22.50):")
   leia(preco_atual)
   
   variacao <- ((preco_atual - preco_anterior) / preco_anterior) * 100


   se variacao > 0 entao
      se variacao > 10 entao
         situacao <- "AUMENTO ABUSIVO"
      senao
         situacao <- "AUMENTO"
      fimse
   senao
      se variacao < 0 entao
         situacao <- "QUEDA"
      senao
         situacao <- "ESTAVEL"
      fimse
   fimse

   Escreval("--- Relatorio do Produto ---")
   Escreval("Nome do Produto: ", nome_produto)
   Escreval("Preco Anterior: R$ ", preco_anterior)
   Escreval("Preco Atual: R$ ", preco_atual)
   Escreval("Variacao Percentual: ", variacao, "%")
   Escreval("Situacao: ", situacao)

Fimalgoritmo