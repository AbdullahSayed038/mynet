CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = mynet

SRCS = src/tensor.c tests/main.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes


all			:	print_art $(NAME)

%.o			:	%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(NAME)	:	$(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@


clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re			:	fclean all

print_art	:
	@echo "                                                      "
	@echo "       ███████████                 ██████████        "
	@echo "    ████          ███            ███         ███     "
	@echo "   ██               ██         ██              ██    "
	@echo "  ██    █████████    ██       ██    ████████    ██   "
	@echo "  ██   ██       ██    ██     ██   ███       ██   ██  "
	@echo " ██   ██          █    ████████   █          █    ██ "
	@echo " ██   ██        ███               ███        █    ██ "
	@echo "  █    ██    ████████                ██     ██    █  "
	@echo "  ██    ████████████████     ████████████████    ██  "
	@echo "   ██     ████   ████  ██  ███   ███   ███      ██   "
	@echo "     ███  ██     ███     ███    ████    ███   ██     "
	@echo "        ████     ███     ███    ████     ████        "
	@echo "        ████    █████    ███    █████    ███         "
	@echo "        ██ ██   █████   ████    █████   ██ █         "
	@echo "        █   ██  ████   ██   ██  ████  ███  ██        "
	@echo "        ██    █████████       █████████    ██        "
	@echo "        ████████████████████████████████████         "
	@echo "         ██  ██ █    ███     ██     █ █   ██         "
	@echo "          ████  █   █  █     ███   █   ██ █          "
	@echo "           ██   ██ ██  ██   █  ██ ██    ██           "
	@echo "            ███  █ █    ██ ██   ████   ██            "
	@echo "              ██ ██      █ █    ███  ██              "
	@echo "                ████     ███     ████                "
	@echo "                    █████████████                    "
	@echo "                                                     "


PHONY: all clean fclean re print_art