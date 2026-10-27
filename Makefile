# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/25 17:30:15 by daparici          #+#    #+#              #
#    Updated: 2026/10/27 00:52:33 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables de configuración
CC = clang
CFLAGS = -Wall -Wextra -Werror -I./include -I./Libft
SRC_DIR = src
OBJ_DIR = obj
TARGET = woody_woodpacker
LIB_DIR = include
LIBFT_DIR = Libft


SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIBFT_DIR)/*.c)
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

# Regla para construir el objetivo final
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) 

# Regla para generar archivos objeto
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

# Regla para limpiar completamente todo
fclean: clean
	rm -f $(TARGET)

# Regla para reconstruir el proyecto
re: fclean all

# Regla para mostrar la ayuda
help:
	@echo "make all: Compila el proyecto"
	@echo "make clean: Limpia los archivos de objeto"
	@echo "make fclean: Limpia completamente todo"
	@echo "make re: Reconstruye el proyecto"
	@echo "make help: Muestra esta ayuda"

# Regla predeterminada
.PHONY: all clean fclean re help
all: $(TARGET)