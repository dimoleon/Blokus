project('blokus', 'cpp',
    default_options : ['cpp_std=c++14', 'warning_level=2'])

main_target_name = 'blokus'

sources = ['main.cpp', 'board.cpp', 'player.cpp', 'square.cpp', 'move.cpp', 'playerpieces.cpp', 'piece.cpp', 'computerplayer.cpp', 'randomplayer.cpp', 'humanplayer.cpp', 'game.cpp', 'smartplayer.cpp']

headers = ['board.h', 'move.h', 'piece.h', 'player.h', 'square.h', 'game.h', 'algorithms.h', 'smartplayer.h'] 

executable(main_target_name, sources,
    headers,
    install : true)
