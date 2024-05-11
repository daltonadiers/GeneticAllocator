# Variáveis
CXX = g++
CXXFLAGS = 
SRCS = alloc.cpp disciplina.cpp cromossomo.cpp professor.cpp sala.cpp
TARGET = output

# Regra padrão
all: $(TARGET)

# Regra para o target
$(TARGET): 
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Regra para limpar os arquivos compilados
clean:
	rm -f $(TARGET)
