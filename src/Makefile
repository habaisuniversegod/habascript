FRONT_SRC = front/HSFront.cpp front/reader/HSReadSource.cpp front/lexer/HSToken.cpp front/lexer/HSSpecialTokens.cpp front/lexer/HSLexer.cpp front/lexer/HSTokenType.cpp HSErrorPrinter.cpp front/parser/HSNode.cpp front/parser/expression/HSExpression.cpp front/parser/expression/HSAtomicExpression.cpp front/parser/expression/HSUnaryExpression.cpp front/parser/expression/HSBinaryExpression.cpp front/HSTranslationModule.cpp front/parser/HSParser.cpp
FRONT_H = front/reader/HSReadSource.h front/lexer/HSToken.h front/lexer/HSSpecialTokens.h front/lexer/HSLexer.h front/lexer/HSTokenType.h HSErrorPrinter.h front/parser/HSNode.h front/parser/expression/HSExpression.h front/parser/expression/HSAtomicExpression.h front/parser/expression/HSExpressionTypes.h front/parser/expression/HSUnaryExpression.h front/parser/expression/HSAllExpressions.h front/parser/expression/HSBinaryExpression.h front/HSTranslationModule.h front/parser/HSParser.h
FRONT_OBJ = HSFront.o HSReadSource.o HSToken.o HSSpecialTokens.o HSLexer.o HSTokenType.o HSErrorPrinter.o HSNode.o HSExpression.o HSAtomicExpression.o HSUnaryExpression.o HSBinaryExpression.o HSTranslationModule.o HSParser.o
GLOBAL_H = HSGlobals.h

COMP_CPP = g++
COMP_C = gcc

hsinterp: hsfront hsback hscommon
	$(COMP_CPP) $(FRONT_OBJ) -o $@ -lc
	strip $@ -x -s -M

hsfront: $(FRONT_SRC) $(GLOBAL_H)
	$(COMP_CPP) -Wall $(FRONT_SRC) -c $(FRONT_OBJ)

hsback:
	echo "NO BACK FOR NOW!"

hscommon:
	echo "COMMON!"

clean:
	rm -rf *.o