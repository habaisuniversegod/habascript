BUILD_DIR = build/

COMP_CPP = g++
COMP_C = gcc

all: hsfront

hs_all_headers := $(wildcard **/*.h)

hs_front_obj = \
HSConstant.o \
HSLexer.o \
HSSpecialTokens.o \
HSToken.o \
HSTokenType.o \
HSAtomicExpression.o \
HSBinaryExpression.o \
HSExpression.o \
HSUnaryExpression.o \
HSNode.o \
HSParser.o \
HSReadSource.o \
HSFront.o \
HSTranslationModule.o \
HSErrorPrinter.o \
HSConstruct.o \
HSValue.o

hsfront: $(hs_all_headers) $(hs_front_obj)
	$(COMP_CPP) $(hs_front_obj) -o $@ 

# Front files

HSConstant.o: src/front/frontvalue/HSConstant.cpp src/front/frontvalue/HSConstant.h
	$(COMP_CPP) -c $@ $<

HSLexer.o: src/front/lexer/HSLexer.cpp src/front/lexer/HSLexer.h
	$(COMP_CPP) -c $@ $<

HSSpecialTokens.o: src/front/lexer/HSSpecialTokens.cpp src/front/lexer/HSSpecialTokens.h
	$(COMP_CPP) -c $@ $<

HSToken.o: src/front/lexer/HSToken.cpp src/front/lexer/HSToken.h
	$(COMP_CPP) -c $@ $<

HSTokenType.o: src/front/lexer/HSTokenType.cpp src/front/lexer/HSTokenType.h
	$(COMP_CPP) -c $@ $<

HSAtomicExpression.o: src/front/parser/expression/HSAtomicExpression.cpp src/front/parser/expression/HSAtomicExpression.h
	$(COMP_CPP) -c $@ $<

HSBinaryExpression.o: src/front/parser/expression/HSBinaryExpression.cpp src/front/parser/expression/HSBinaryExpression.h
	$(COMP_CPP) -c $@ $<

HSExpression.o: src/front/parser/expression/HSExpression.cpp src/front/parser/expression/HSExpression.h
	$(COMP_CPP) -c $@ $<

HSUnaryExpression.o: src/front/parser/expression/HSUnaryExpression.cpp src/front/parser/expression/HSUnaryExpression.h
	$(COMP_CPP) -c $@ $<

HSNode.o: src/front/parser/HSNode.cpp src/front/parser/HSNode.h
	$(COMP_CPP) -c $@ $<

HSParser.o: src/front/parser/HSParser.cpp src/front/parser/HSParser.h
	$(COMP_CPP) -c $@ $<

HSReadSource.o: src/front/reader/HSReadSource.cpp src/front/reader/HSReadSource.h
	$(COMP_CPP) -c $@ $<

HSFront.o: src/front/HSFront.cpp
	$(COMP_CPP) -c $@ $<

HSTranslationModule.o: src/front/HSTranslationModule.cpp src/front/HSTranslationModule.h
	$(COMP_CPP) -c $@ $<

# Global files

HSErrorPrinter.o: src/HSErrorPrinter.c src/HSErrorPrinter.h
	$(COMP_CPP) -c $@ $< 

# Back files

HSConstruct.o: src/back/value/HSConstruct.c src/back/value/HSConstruct.h
	$(COMP_CPP) -c $@ $< 

HSValue.o: src/back/value/HSValue.c src/back/value/HSValue.h
	$(COMP_CPP) -c $@ $< 

# Other

clean:
	rm -rf *.o