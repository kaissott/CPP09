NAME = btc

SRCS =	main.cpp \
		BitcoinExchange.cpp

OBJS = $(SRCS:%.cpp=obj/%.o)
HEADERS = BitcoinExchange.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

obj/%.o: %.cpp $(HEADERS) Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all