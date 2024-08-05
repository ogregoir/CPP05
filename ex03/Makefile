NAME	=		AForm

CFLAGS	=		-Wall -Werror -Wextra	-std=c++98 -fsanitize=address

CC		=		c++

RM		=		rm -rf

SRCS	=		main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				PresidentialPardonForm.cpp \
				RobotomyRequestForm.cpp \
				ShrubberyCreationForm.cpp \
				Intern.cpp \

OBJC = ${SRCS:.cpp=.o}

all: ${NAME}

.cpp.o:
	${CC} -c $< -o $(<:.cpp=.o) ${CFLAGS}

${NAME}: ${OBJC}
	${CC} ${CFLAGS} ${OBJC} -o ${NAME}

clean: 
	 ${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all