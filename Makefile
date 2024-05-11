# Variáveis
CXX = g++
CXXFLAGS = 
SRCS = src/alloc.cpp src/disciplina.cpp src/cromossomo.cpp src/professor.cpp src/sala.cpp
TARGET = output

# Regra padrão
all: $(TARGET)

# Regra para o target
$(TARGET): 
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Regra para limpar os arquivos compilados
clean:
	rm -f $(TARGET)
