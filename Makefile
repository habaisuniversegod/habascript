BUILD_DIR = build/

COMP_CPP = g++
COMP_C = gcc

all: hsfront

hs_all_headers := $(wildcard **/*.h)

hs_front_obj = \
HSConst.o \
HSConstNull.o \
HSConstBool.o \
HSConstInt.o \
HSConstFloat.o \
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
HSErrorPrinter.o

hsfront: $(hs_front_obj)
	$(COMP_CPP) $(hs_front_obj) -o $@ 

# Front files

HSConst.o: src/front/frontvalue/HSConst.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSConstNull.o: src/front/frontvalue/HSConstNull.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSConstBool.o: src/front/frontvalue/HSConstBool.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSConstInt.o: src/front/frontvalue/HSConstInt.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSConstFloat.o: src/front/frontvalue/HSConstFloat.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSLexer.o: src/front/lexer/HSLexer.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSSpecialTokens.o: src/front/lexer/HSSpecialTokens.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSToken.o: src/front/lexer/HSToken.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSTokenType.o: src/front/lexer/HSTokenType.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSAtomicExpression.o: src/front/parser/expression/HSAtomicExpression.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSBinaryExpression.o: src/front/parser/expression/HSBinaryExpression.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSExpression.o: src/front/parser/expression/HSExpression.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSUnaryExpression.o: src/front/parser/expression/HSUnaryExpression.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSNode.o: src/front/parser/HSNode.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSParser.o: src/front/parser/HSParser.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSReadSource.o: src/front/reader/HSReadSource.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

HSFront.o: src/front/HSFront.cpp
	$(COMP_CPP) -c $@ $<

HSTranslationModule.o: src/front/HSTranslationModule.cpp $(hs_all_headers)
	$(COMP_CPP) -c $@ $<

# Global files

HSErrorPrinter.o: src/HSErrorPrinter.c $(hs_all_headers)
	$(COMP_C) -c $@ $< 

# Other

clean:
	rm -rf *.o