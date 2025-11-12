# 📘 Manual do Usuário – Portal do Professor (Leitura de Notas e Cálculo de Média)

## 🎯 Visão Geral
Este sistema foi desenvolvido para auxiliar professores na visualização e análise de notas de alunos.  
A partir de um arquivo `.txt`, o sistema lê as notas (NP1, NP2 e PIM), calcula automaticamente a **média final** e informa se o aluno está **APROVADO ✅** ou **REPROVADO ❌**.

A interface foi construída utilizando **CustomTkinter**, proporcionando um visual moderno, organizado e simples de usar.

---

## 🖥️ Tela de Login

Ao abrir o programa, o usuário verá a **Tela de Login**.

### Campos de Acesso:
| Campo | Descrição |
|------|-----------|
| Usuário | Nome de acesso ao sistema |
| Senha | Senha do usuário (os caracteres são ocultados) |

### Credenciais Padrão:
Usuário: Professor1
Senha: 1234


### Funcionamento:
- Se o login for correto:
  → A tela de login será fechada e o usuário será direcionado ao **Portal do Professor**.
- Caso contrário:
  → Uma mensagem de erro será exibida.

---

## 📂 Portal do Professor (Interface Principal)

Após o login, a interface principal será exibida.

### Componentes da Tela:
| Elemento | Função |
|--------|--------|
| Caixa de Exibição | Mostra o conteúdo processado do arquivo |
| Botão "Selecionar Arquivo de Notas" | Permite escolher um arquivo `.txt` para leitura |

---

## 📄 Formato do Arquivo .TXT Aceito

O arquivo deve conter os seguintes campos para cada aluno:

Nome: João Silva
NP1: 7
NP2: 8
PIM: 6

Nome: Maria Santos
NP1: 9
NP2: 7
PIM: 8



### ✅ Regras Utilizadas:
- A média final é calculada assim:
Média = (NP1 + NP2 + PIM) / 3


- Critério de aprovação:
Aprovado: Média ≥ 7
Reprovado: Média < 7


---

## 🧠 Como Usar

1. Execute o programa.
2. Faça login usando as credenciais indicadas.
3. Na tela principal, clique em **Selecionar Arquivo de Notas**.
4. Escolha o arquivo `.txt` contendo as informações dos alunos.
5. O sistema irá:
   - Ler e interpretar os dados
   - Calcular a média
   - Informar se o aluno foi aprovado ou reprovado
   - Exibir tudo organizadamente na tela

---

## 🛡️ Segurança
- Apenas usuários autenticados têm acesso ao sistema.
- A tela principal só abre após login válido.
- Senha é ocultada durante a digitação.

---

## ⚙️ Requisitos do Sistema
| Item | Versão/Descrição |
|------|----------------|
| Python | 3.8 ou superior |
| Biblioteca | CustomTkinter instalada |
| Sistema Operacional | Windows, Linux ou MacOS |

### Instalação da Biblioteca:
pip install customtkinter

---

## 🟢 Fluxo Simplificado de Uso
Executar programa
→ Tela de Login
→ Digitar usuário e senha
→ Acesso ao Portal
→ Selecionar arquivo .txt
→ Visualizar médias e status dos alunos

---

Fim do Manual. 🎓
