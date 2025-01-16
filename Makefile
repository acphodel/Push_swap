CC=gcc
CFLAGS=-Wall -Wextra -Werror
#-g -fsanitize=address
OBJS=butterfly.o shorting.o shorting2.o printer.o swapper.o sort.o sorter.o commands.o commands2.o commands3.o main.o messages.o ft/ft_split.o ft/ft_strcmp.o ft/ft_strjoin.o ft/long_atoi.o ft/ft_strlen.o
TARGET=push_swap

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

ft/%.o: ft/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
