nasm -f elf64 ft_strlen.s -o ft_strlen.o
gcc ft_strlen.o main.c
./a.out
rm a.out *.o
