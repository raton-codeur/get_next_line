all :
	cc -Wall -Wextra -Werror -fsanitize=address -g3 main.c get_next_line.c -o gnl

test :
	./gnl < test.txt

test-% :
	printf "$*" | ./gnl

clean :
	rm -rf gnl gnl.dSYM .vscode
