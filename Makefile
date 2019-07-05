OBJ      := obj
SRC      := src
INC      := include
CFLAGS   := -g -w -O3
EXE 	 := indexador
PROJETO  := trab2-AtilioDadalto-TiagoSantos
PROJETOZOADO  := trab3-AtilioDadalto-TiagoSantos
PROJETOLISTA  := trab4-AtilioDadalto-TiagoSantos
MENU  := menu-trab2-AtilioDadalto-TiagoSantos


# Cria objetos de todos os arquivos de código-fonte para então linká-los no programa final
main: $(OBJ)/lista_encadeada.o $(OBJ)/arvore_binaria.o $(OBJ)/arvore_AVL.o $(OBJ)/tabela_hash.o $(OBJ)/arvore_trie.o $(OBJ)/indexador.o $(OBJ)/arquivos.o $(OBJ)/$(PROJETO).o
	gcc $(OBJ)/*.o -o $(EXE) $(CFLAGS)

zoado: $(OBJ)/lista_encadeada.o $(OBJ)/arvore_binaria.o $(OBJ)/arvore_AVL.o $(OBJ)/tabela_hash.o $(OBJ)/arvore_trie.o $(OBJ)/indexador.o $(OBJ)/arquivos.o $(OBJ)/$(PROJETOZOADO).o
	gcc $(OBJ)/*.o -o $(EXE) $(CFLAGS)

lista: $(OBJ)/lista_encadeada.o $(OBJ)/indexador.o $(OBJ)/arquivos.o $(OBJ)/$(PROJETOLISTA).o
	gcc $(OBJ)/*.o -o $(EXE) $(CFLAGS)

menu: clean $(OBJ)/lista_encadeada.o $(OBJ)/arvore_binaria.o $(OBJ)/arvore_AVL.o $(OBJ)/tabela_hash.o $(OBJ)/arvore_trie.o $(OBJ)/indexador.o $(OBJ)/arquivos.o $(OBJ)/$(MENU).o
	gcc $(OBJ)/*.o -o $(EXE) $(CFLAGS)

$(OBJ)/indexador.o: $(SRC)/indexador.c $(INC)/indexador.h
	gcc -c $(CFLAGS) "$(SRC)/indexador.c" -o "$(OBJ)/indexador.o"

$(OBJ)/lista_encadeada.o: $(SRC)/lista_encadeada.c $(INC)/lista_encadeada.h
	gcc -c $(CFLAGS) "$(SRC)/lista_encadeada.c" -o "$(OBJ)/lista_encadeada.o"

$(OBJ)/arvore_binaria.o: $(SRC)/arvore_binaria.c $(INC)/arvore_binaria.h
	gcc -c $(CFLAGS) "$(SRC)/arvore_binaria.c" -o "$(OBJ)/arvore_binaria.o"

$(OBJ)/arvore_AVL.o: $(SRC)/arvore_AVL.c $(INC)/arvore_AVL.h
	gcc -c $(CFLAGS) "$(SRC)/arvore_AVL.c" -o "$(OBJ)/arvore_AVL.o"

$(OBJ)/arvore_trie.o: $(SRC)/arvore_trie.c $(INC)/arvore_trie.h
	gcc -c $(CFLAGS) "$(SRC)/arvore_trie.c" -o "$(OBJ)/arvore_trie.o"

$(OBJ)/tabela_hash.o: $(SRC)/tabela_hash.c $(INC)/tabela_hash.h
	gcc -c $(CFLAGS) "$(SRC)/tabela_hash.c" -o "$(OBJ)/tabela_hash.o"

$(OBJ)/arquivos.o: $(SRC)/arquivos.c $(INC)/arquivos.h
	gcc -c $(CFLAGS) "$(SRC)/arquivos.c" -o "$(OBJ)/arquivos.o"


$(OBJ)/$(PROJETO).o: $(PROJETO).c
	gcc -c $(CFLAGS) $(PROJETO).c -o "$(OBJ)/$(PROJETO).o"

$(OBJ)/$(PROJETOZOADO).o: $(PROJETOZOADO).c
	gcc -c $(CFLAGS) $(PROJETOZOADO).c -o "$(OBJ)/$(PROJETOZOADO).o"

$(OBJ)/$(PROJETOLISTA).o: $(PROJETOLISTA).c
	gcc -c $(CFLAGS) $(PROJETOLISTA).c -o "$(OBJ)/$(PROJETOLISTA).o"

$(OBJ)/$(MENU).o: $(MENU).c
	gcc -c $(CFLAGS) $(MENU).c -o "$(OBJ)/$(MENU).o"

# Executa o programa
run:
	./$(EXE)

# Compila e executa o programa
voado: main run

# Apenas Linux
time:
	time ./$(EXE)

# Executa o programa com valgrind e flags úteis
val:
	valgrind --leak-check=full -v --track-origins=yes \
	--show-leak-kinds=all ./$(EXE)

# Executa o programa com valgrind sem flags
valzin:
	valgrind ./$(EXE)

# Executa o programa com valgrind e salva resultados num .txt
valtxt:
	valgrind --leak-check=full -v --show-leak-kinds=all --track-origins=yes --verbose --log-file="valgrind-out.txt" ./$(EXE)

# Limpa objetos e o executável do programa (para Windows)
cleanW:
	del /F/Q/S "$(OBJ)\*.o"
	del /F/Q/S $(EXE).exe

# Limpa objetos e o executável do programa (para Linux)
clean:
	-rm $(OBJ)/*.o
	-rm $(EXE)
