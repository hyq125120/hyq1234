#include <stdio.h>
#include <libubus.h>
#include <libubox/uloop.h>

static struct ubus_context *ctx;

static int start_sweep(struct ubus_context *ctx, struct ubus_object *obj,
                      struct ubus_request_data *req, const char *method,
                      struct blob_attr *msg)
{
    printf("Starting sweep playback and recording on four speakers...\n");
    /*
     * Real implementation would trigger audio playback and recording here.
     */
    return 0;
}

static const struct ubus_method speaker_methods[] = {
    UBUS_METHOD_NOARG("start_sweep", start_sweep),
};

static struct ubus_object_type speaker_object_type =
    UBUS_OBJECT_TYPE("speaker_sync", speaker_methods);

static struct ubus_object speaker_object = {
    .name = "speaker.sync",
    .type = &speaker_object_type,
    .methods = speaker_methods,
    .n_methods = ARRAY_SIZE(speaker_methods),
};

int main(void)
{
    uloop_init();

    ctx = ubus_connect(NULL);
    if (!ctx) {
        fprintf(stderr, "Failed to connect to ubus\n");
        return 1;
    }

    ubus_add_object(ctx, &speaker_object);
    ubus_add_uloop(ctx);

    printf("Speaker sync service running. Call 'start_sweep' via ubus.\n");

    uloop_run();

    ubus_free(ctx);
    uloop_done();
    return 0;
}
