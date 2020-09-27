object=${1}
adds=${2}

gcc -Wall -Wextra -g -I./includes -I../libft/includes ./tests/$object.c $adds -L../libft -lft -g -o ./$object