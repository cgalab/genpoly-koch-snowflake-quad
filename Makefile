make_koch_snowflake_quad: make_koch_snowflake_quad.c
	$(CC) -O2 -Wall -o "$@" $< -lm

clean:
	rm -f make_koch_snowflake_quad

.PHONY: clean
