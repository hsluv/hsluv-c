
#include "acutest.h"
#include "hsluv.h"
#include "snapshot.h"


#define EPSILON             0.00000001

#define ABS(x)              ((x) >= 0 ? (x) : -(x))

#define TEST_CHANNEL(name, produced, expected)                              \
    do {                                                                    \
        if(!TEST_CHECK_(ABS((produced) - (expected)) < EPSILON,             \
                        "%s channel", name))                                \
        {                                                                   \
            TEST_MSG("Produced: %f", produced);                             \
            TEST_MSG("Expected: %f", expected);                             \
        }                                                                   \
    } while(0)


static void
test_hsluv2rgb(void)
{
    int i;

    for(i = 0; i < snapshot_n; i++) {
        double r, g, b;

        TEST_CASE(snapshot[i].hex_str);

        hsluv2rgb(snapshot[i].hsluv_h, snapshot[i].hsluv_s, snapshot[i].hsluv_l, &r, &g, &b);

        TEST_CHANNEL("red", r, snapshot[i].rgb_r);
        TEST_CHANNEL("green", g, snapshot[i].rgb_g);
        TEST_CHANNEL("blue", b, snapshot[i].rgb_b);
    }
}

static void
test_rgb2hsluv(void)
{
    int i;

    for(i = 0; i < snapshot_n; i++) {
        double h, s, l;

        TEST_CASE(snapshot[i].hex_str);

        rgb2hsluv(snapshot[i].rgb_r, snapshot[i].rgb_g, snapshot[i].rgb_b, &h, &s, &l);

        TEST_CHANNEL("hue", h, snapshot[i].hsluv_h);
        TEST_CHANNEL("saturation", s, snapshot[i].hsluv_s);
        TEST_CHANNEL("lightness", l, snapshot[i].hsluv_l);
    }
}

static void
test_hpluv2rgb(void)
{
    int i;

    for(i = 0; i < snapshot_n; i++) {
        double r, g, b;

        TEST_CASE(snapshot[i].hex_str);

        hpluv2rgb(snapshot[i].hpluv_h, snapshot[i].hpluv_s, snapshot[i].hpluv_l, &r, &g, &b);

        TEST_CHANNEL("red", r, snapshot[i].rgb_r);
        TEST_CHANNEL("green", g, snapshot[i].rgb_g);
        TEST_CHANNEL("blue", b, snapshot[i].rgb_b);
    }
}

static void
test_rgb2hpluv(void)
{
    int i;

    for(i = 0; i < snapshot_n; i++) {
        double h, s, l;

        TEST_CASE(snapshot[i].hex_str);

        rgb2hpluv(snapshot[i].rgb_r, snapshot[i].rgb_g, snapshot[i].rgb_b, &h, &s, &l);

        TEST_CHANNEL("hue", h, snapshot[i].hpluv_h);
        TEST_CHANNEL("saturation", s, snapshot[i].hpluv_s);
        TEST_CHANNEL("lightness", l, snapshot[i].hpluv_l);
    }
}


TEST_LIST = {
    { "hsluv2rgb", test_hsluv2rgb },
    { "rgb2hsluv", test_rgb2hsluv },
    { "hpluv2rgb", test_hpluv2rgb },
    { "rgb2hpluv", test_rgb2hpluv },
    { NULL, NULL }
};
