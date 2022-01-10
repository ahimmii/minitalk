CC := gcc
W := -Wall -Werror -Wextra
CFILES := client.c
SFILES = server.c
CFILES_B := client_bonus.c
SFILES_B = server_bonus.c
OCFILES := ${CFILES:.c=.o}
OSFILES := ${SFILES:.c=.o}
OCFILES_B := ${CFILES_B:.c=.o}
OSFILES_B := ${SFILES_B:.c=.o}
NAMES := server.a
NAMEC := client.a
NAMES_B := server_bonus.a
NAMEC_B := client_bonus.a
NAMEOS = server
NAMEOC = client
NAMEOS_B = server_bonus
NAMEOC_B = client_bonus
INC = Minitalk.h
INC_B = Minitalk_bonus.h

all : ${NAMES} ${NAMEC}

${NAMES} : ${OSFILES} ${INC}
	@${CC} ${W} ${SFILES} -o ${NAMEOS}

${NAMEC} : ${OCFILES}
	@${CC} ${W} ${CFILES} -o ${NAMEOC}

clean :
	@rm -f  ${OCFILES} ${OSFILES} ${OSFILES_B} ${OCFILES_B}

fclean : clean
	@rm -f ${NAMES} ${NAMEC} 

bonus : ${OSFILES_B} ${OCFILES_B} ${INC_B}
	@${CC} ${W} ${SFILES_B} -o ${NAMEOS_B}
	@${CC} ${W} ${CFILES_B} -o ${NAMEOC_B}
re : fclean all
