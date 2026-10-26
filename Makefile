# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/25 17:30:15 by daparici          #+#    #+#              #
#    Updated: 2026/10/26 21:00:39 by daparici         ###   ########.fr        #
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


# Busca todos los archivos .c en el directorio src
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIBFT_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Regla para construir el objetivo final
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) 

# Regla para generar archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos de objeto
clean:
	rm -f $(OBJS)

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