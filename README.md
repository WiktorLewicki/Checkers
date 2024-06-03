Work time at the moment: 14h
Project is created in C++ Builder 6.

Presentation: https://youtu.be/BaGiwTuKq3o

I am the sole author of the entire code. Wiktor Lewicki.

The bot and the engine are located in the files bot.cpp and silnik.cpp.

The bot plays very well, practically unbeatable.
The bot's algorithm is graph traversal with a depth of 8 (minmax), with alpha-beta pruning optimization.

RUSSIAN CHECKERS

If you want to play: Warcaby/wersja z interfejsem/Program/Warcaby.exe

If there is no your pawn on the selected field, you will make an illegal move,
or if you don't use the mandatory capture - instructions will be displayed on the screen, and the move
will not be executed.

Russian checkers, additional information:
A pawn can capture backward
A pawn becomes a king immediately after reaching the last row, if it gets there through a capture, it can continue capturing in the same move.
When there are several possible captures, you can make any of them (not necessarily the maximum one).
Enjoy the game!
