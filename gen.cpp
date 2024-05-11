#include "cabecalhos/gen.h"
#include "cabecalhos/professor.h"
#include "cabecalhos/sala.h"

Gen::Gen() : professor("Nome padrão"), sala(0, 0){}
Gen::Gen(Professor p, Sala s) : professor(p), sala(s){}