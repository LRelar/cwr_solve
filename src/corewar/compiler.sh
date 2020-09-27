object=${1}
adds=${2}

gcc -Wall -Wextra -g -I./includes -I./libft/includes ./src/$object.c $adds -L./libft -lft -g -o ./$object