CC ?= $(CROSS)gcc
CFLAGS += -Wall -O2 `pkg-config libubus libubox --cflags`
LDFLAGS += `pkg-config libubus libubox --libs`

all: speaker_sync

speaker_sync: speaker_sync.c
$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
rm -f speaker_sync
