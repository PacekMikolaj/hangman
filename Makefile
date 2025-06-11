CC=gcc
CFLAGS=-Wall -Wextra -std=c17 -g
INCLUDES=-Iinclude
SRC_COMMON=$(wildcard common/*.c)

# Klient
CLIENT_SRC=$(SRC_COMMON) client/client.c client/main.c
CLIENT_OUT=client/hangman_client

# Serwer
SERVER_SRC=$(SRC_COMMON) server/server.c server/main.c server/ranking.c
SERVER_OUT=server/hangman_server

.PHONY: all clean

all: $(CLIENT_OUT) $(SERVER_OUT)

$(CLIENT_OUT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(SERVER_OUT): $(SERVER_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

clean:
	rm -f $(CLIENT_OUT) $(SERVER_OUT)
