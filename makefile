all: 
	mkdir -p debug
	g++ -g src/*.cpp -framework SDL2 -framework SDL2_ttf -framework OpenGL -o debug/loz
	mkdir -p   release
	cp -r debug/* release
	
run: 
	debug/loz
	
debug: 
	gdb debug/loz.exe

commit:
	git commit -a -m "${m} "
	git push
