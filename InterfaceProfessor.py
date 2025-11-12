import customtkinter as ctk
from tkinter import filedialog  # Biblioteca usada para abrir o explorador de arquivos do sistema


# ----------------------------------------------------
# CONFIGURAÇÃO DE APARÊNCIA / TEMA
# ----------------------------------------------------
# Define o modo visual como "dark" (fundo escuro)
ctk.set_appearance_mode("dark")

# Define o tema principal da interface (azul para botões e destaques)
ctk.set_default_color_theme("blue")

# ----------------------------------------------------
# ----------------------------------------------------
# JANELA 2 - PORTAL DO PROFESSOR (APÓS LOGIN)
# ----------------------------------------------------
def abrir_interface_alunos():
    """
    Abre a janela principal onde o professor pode carregar um arquivo .txt
    contendo notas dos alunos e o sistema calcula automaticamente a média
    e informa se o aluno está APROVADO ou REPROVADO.
    """

    # Janela principal
    janela_alunos = ctk.CTk()
    janela_alunos.title("Portal do Professor")
    janela_alunos.geometry("1000x750")  # Janela grande para visualização
    janela_alunos.configure(fg_color="#1a1a1a")  # Cor de fundo mais bonita

    # Frame central onde os widgets estão organizados
    frame = ctk.CTkFrame(janela_alunos, width=950, height=650, corner_radius=15)
    frame.pack(pady=20)

    # Título estilizado
    titulo = ctk.CTkLabel(
        frame,
        text="📊 Consulta de Notas e Situação dos Alunos",
        font=("Segoe UI", 22, "bold")
    )
    titulo.pack(pady=20)

    # Caixa de texto estilizada com rolagem automática
    caixa_texto = ctk.CTkTextbox(
        frame,
        width=900,
        height=500,
        corner_radius=12,
        border_width=2,
        border_color="#4f4f4f",
        font=("Consolas", 14)
    )
    caixa_texto.pack(pady=10)


    # Função: abrir arquivo e calcular média
    def abrir_arquivo():
        """
        Lê o arquivo selecionado, extrai dados dos alunos, calcula média e exibe formatado.
        """
        caminho_arquivo = filedialog.askopenfilename(
            title="Selecione o arquivo .txt",
            filetypes=[("Arquivos de texto", "*.txt")]
        )

        if caminho_arquivo:
            with open(caminho_arquivo, "r", encoding="utf-8") as arquivo:
                linhas = arquivo.readlines()

            caixa_texto.delete("0.0", "end")  # Limpa antes de mostrar novo conteúdo

            nome = ""
            np1 = np2 = pim = None

            for linha in linhas:
                linha = linha.strip()

                if linha.startswith("Nome:"):
                    nome = linha.replace("Nome:", "").strip()

                elif linha.startswith("NP1:"):
                    np1 = float(linha.replace("NP1:", "").strip())

                elif linha.startswith("NP2:"):
                    np2 = float(linha.replace("NP2:", "").strip())

                elif linha.startswith("PIM:"):
                    pim = float(linha.replace("PIM:", "").strip())

                    media = (np1 + np2 + pim) / 3

                    # Regras de aprovação 
                    status = "✅ APROVADO" if media >= 7 else "❌ REPROVADO"

                    # Exibição formatada com alinhamento bonito
                    caixa_texto.insert("end", f"\n👤 Aluno: {nome}\n")
                    caixa_texto.insert("end", f"📌 NP1: {np1:.1f}   |   NP2: {np2:.1f}   |   PIM: {pim:.1f}\n")
                    caixa_texto.insert("end", f"📈 Média Final: {media:.2f}\n")
                    caixa_texto.insert("end", f"🏅 Situação: {status}\n")
                    caixa_texto.insert("end", "─" * 80 + "\n")


    # Botão estilizado para abrir arquivo
    botao_abrir = ctk.CTkButton(
        frame,
        text="📂 Selecionar Arquivo de Notas",
        command=abrir_arquivo,
        width=280,
        height=40,
        corner_radius=10,
        font=("Segoe UI", 16, "bold"),
        fg_color="#0052cc",
        hover_color="#003d99"
    )
    botao_abrir.pack(pady=15)

    # Mantém a janela aberta
    janela_alunos.mainloop()


# ----------------------------------------------------
# JANELA 1 - TELA DE LOGIN
# ----------------------------------------------------
def validar_login():
    """
    Função responsável por validar o acesso.
    Se usuário e senha forem corretos, a tela de login é fechada
    e a interface do professor é aberta.
    """
    usuario = campo_usuario.get()
    senha = campo_senha.get()

    # Login simples (credenciais fixas)
    if usuario == "Professor1" and senha == "1234":
        aplicativo.withdraw() # Fecha a janela de login
        abrir_interface_alunos()  # Abre o portal
    else:
        # Exibe mensagem de erro caso as credenciais estejam incorretas
        resultado_login.configure(text="Usuário ou senha incorretos.", text_color="red")


# Criação da janela de login
aplicativo = ctk.CTk()
aplicativo.title("Login - Portal do Professor")
aplicativo.geometry("450x330")  # Dimensões da janela

# Frame central da tela de login
frame_login = ctk.CTkFrame(aplicativo, width=300, height=250)
frame_login.pack(pady=40)

# Título da tela de login
titulo = ctk.CTkLabel(frame_login, text="Acesso ao Sistema", font=("Arial", 18))
titulo.pack(pady=10)

# Campo Usuário
label_usuario = ctk.CTkLabel(frame_login, text="Usuário:")
label_usuario.pack(pady=5)
campo_usuario = ctk.CTkEntry(frame_login, width=200)
campo_usuario.pack(pady=5)

# Campo Senha
label_senha = ctk.CTkLabel(frame_login, text="Senha:")
label_senha.pack(pady=5)
campo_senha = ctk.CTkEntry(frame_login, width=200, show="*")  # show="*" oculta a senha
campo_senha.pack(pady=5)

# Botão de Login
botao_login = ctk.CTkButton(frame_login, text="Entrar", command=validar_login, width=200)
botao_login.pack(pady=15)

# Mensagem de erro (quando necessário)
resultado_login = ctk.CTkLabel(frame_login, text="", font=("Arial", 12))
resultado_login.pack(pady=5)

# Mantém a janela de login aberta
aplicativo.mainloop()
# ----------------------------------------------------
# ----------------------------------------------------