CXX = g++
CXXFLAGS = -std=c++14 -Wall -I /usr/X11R6/include -L /usr/X11R6/lib
LDFLAGS=-lX11
EXEC = mychess
OBJECTS = main.o subject.o board.o box.o chessPiece.o king.o queen.o knight.o pawn.o rook.o bishop.o displayGraphics.o window.o displayText.o cboard.o chessTestHarness.o chess.o chessMoves.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} 
